#include "Elevator.h"
#include "system.h"

extern Building *building;
extern int capacityOfElevator;

Lock *lock = new Lock("elevator lock");

// Initialize an elevator
Elevator::Elevator(char *debugName, int numFloors, int myID)
{
	name = debugName;
	numfloors = numFloors;
	id = myID;

	currentfloor = 1;		// default: stop at ground floor at first
	occupancy = 0;
	state = SLEEP;
	capacity = capacityOfElevator;
	overload = FALSE;

	exitBarriers = new EventBarrier*[numFloors + 1];
	exitRequests = new bool[numFloors + 1];
	for (int i = 1; i <= numFloors; ++i)
	{
		exitBarriers[i] = new EventBarrier();
		exitRequests[i] = FALSE;
	}
}

// Destroy elevator
Elevator::~Elevator()
{
	for (int i = 1; i <= numfloors; ++i)
	{
		delete exitBarriers[i];
	}
	delete[] exitBarriers;
	delete[] exitRequests;
}

// Signal exiters and enterers to action
void Elevator::OpenDoors()
{
	printf("Elevator %d opens door\n", id);

	if (exitRequests[currentfloor] == TRUE)		// someone wants to exit
	{
		exitBarriers[currentfloor]->Signal();
		exitRequests[currentfloor] = FALSE;
	}

	if (building->callUpRequests[currentfloor] == TRUE && 
		(state == UP || state == SLEEP))		// come on, go up
	{
		building->elevatorUp[currentfloor] = id;
		building->upBarrier[currentfloor]->Signal(); // wake up up waiters
		building->HandleFloor(currentfloor, UP);
		if (overload == TRUE)
		{
			overload = FALSE;
			building->RecordCall(currentfloor, UP);	// Caz former records removed
			building->callUpRequests[currentfloor] = TRUE; // continue waiting
		}
		else
		{
			building->callUpRequests[currentfloor] = FALSE;
		}
	}
	else if (building->callDownRequests[currentfloor] == TRUE && 
			 (state == DOWN || state == SLEEP))	// come on, go down
	{
		building->elevatorDown[currentfloor] = id;
		building->downBarrier[currentfloor]->Signal(); // wake up down waiters
		building->HandleFloor(currentfloor, DOWN);
		if (overload == TRUE)
		{
			overload = FALSE;
			building->RecordCall(currentfloor, DOWN);
			building->callDownRequests[currentfloor] = TRUE; // continue waiting
		}
		else
		{
			building->callDownRequests[currentfloor] = FALSE;
		}
	}
}

// After exiters are out and enterers are in
void Elevator::CloseDoors()
{
	printf("Elevator %d closes door\n", id);

	if (currentfloor == 1 && state == DOWN)		// change state
		state = UP;
	else if (currentfloor == numfloors && state == UP)
		state = DOWN;
}

// Go to a particular floor
void Elevator::VisitFloor(int floor)
{
	printf("Elevator %d visits floor %d\n", id, floor);

	currentfloor = floor;
	OpenDoors();
	currentThread->Yield();		// stall here
	CloseDoors();
}

// Get in
bool Elevator::Enter()
{
	if (occupancy >= capacity)	// forbid entering
	{
		printf("*** Overload! Overload! Overload! ***\n");
		overload = TRUE;
		occupancy = capacity;
		if (state == UP)		// tell finished
			building->upBarrier[currentfloor]->Complete();
		else if (state == DOWN)
			building->downBarrier[currentfloor]->Complete();
		return FALSE;
	}
	else 						// welcome to elevator
	{
		overload = FALSE;
		occupancy += 1;			// add new rider
		if (state == UP)		// tell finished
			building->upBarrier[currentfloor]->Complete();
		else if (state == DOWN)
			building->downBarrier[currentfloor]->Complete();
		return TRUE;
	}
}

// Get out (iff destinationFloor)
void Elevator::Exit()
{
	occupancy -= 1;
	exitBarriers[currentfloor]->Complete();
}

// Tell the elevator our destinationFloor
void Elevator::RequestFloor(int floor)
{
	exitRequests[floor] = TRUE;
	exitBarriers[floor]->Wait();
}

// Start running of elevator
void Elevator::ElevatorStart()
{
	while (TRUE)
	{
		lock->Acquire();

		if (occupancy == 0)		// hmm, he's so relaxed
		{
			int nextCall = building->HandleCall();
			if (nextCall == 0)	// nobody calls
			{
				printf("Elevator %d goes to sleep\n", id);
				state = SLEEP;	// well, go to sleep
				building->sleepCond->Wait(lock);
				printf("Elevator %d wakes up\n", id);

				lock->Release();
			}
			else 				// ok, someone calls him, work!
			{
				int fromFloor = (nextCall > 0) ? nextCall : (-nextCall);
				if (nextCall > 0)
					state = UP;
				else
					state = DOWN;
				VisitFloor(fromFloor);		// go to pick up

				lock->Release();
				currentThread->Yield();		// elevator is running
			}
		}
		else 					// he's working
		{
			if (state == UP)
			{
				for (int i = currentfloor + 1; i <= numfloors; ++i)
				{
					if (exitRequests[i] == TRUE || 
						building->callUpRequests[i] == TRUE)
					{
						VisitFloor(i);
						break;
					}
				}
			}
			else if (state == DOWN)
			{
				for (int i = currentfloor - 1; i >= 1; --i)
				{
					if (exitRequests[i] == TRUE || 
						building->callDownRequests[i] == TRUE)
					{
						VisitFloor(i);
						break;
					}
				}
			}
			else
			{
				perror("Invalid state!");
			}

			lock->Release();
			currentThread->Yield();
		}
	}
}

// Create a elevator and start it
void CreateAndStartElevator(int which)
{
	building->elevator[which] = new Elevator(building->elevatorsName[which], 
		building->numfloors, which);
	building->elevator[which]->ElevatorStart();
}

// Initialize a building
Building::Building(char *debugname, int numFloors, int numElevators)
{
	name = debugname;
	numfloors = numFloors;
	numelevators = numElevators;

	elevator = new Elevator*[numElevators + 1];
	elevatorsName = new char*[numElevators + 1];
	for (int i = 1; i <= numelevators; ++i)
	{
		elevatorsName[i] = new char[15];
		sprintf(elevatorsName[i], "elevator %d", i);
		Thread *t = new Thread("fork thread");
		t->Fork(CreateAndStartElevator, i);
	}

	upBarrier = new EventBarrier*[numFloors + 1];
	downBarrier = new EventBarrier*[numFloors + 1];
	callUpRequests = new bool[numFloors + 1];
	callDownRequests = new bool[numFloors + 1];
	elevatorUp = new int[numFloors + 1];
	elevatorDown = new int[numFloors + 1];
	for (int i = 1; i <= numFloors; ++i)
	{
		upBarrier[i] = new EventBarrier();
		downBarrier[i] = new EventBarrier();
		callUpRequests[i] = FALSE;
		callDownRequests[i] = FALSE;
		elevatorUp[i] = 0;
		elevatorDown[i] = 0;
	}
	sleepCond = new Condition("elevator sleep cond");
}

// Destroy this building
Building::~Building()
{
	for (int i = 1; i <= numelevators; ++i)
	{
		delete elevator[i];
		delete elevatorsName[i];
	}
	delete[] elevator;
	delete[] elevatorsName;

	for (int i = 1; i <= numelevators; ++i)
	{
		delete upBarrier[i];
		delete downBarrier[i];
	}
	delete[] upBarrier;
	delete[] downBarrier;
	delete callUpRequests;
	delete callDownRequests;
	delete elevatorUp;
	delete elevatorDown;
	delete sleepCond;
}

// Signal an elevator we want to go up
void Building::CallUp(int fromFloor)
{
	callUpRequests[fromFloor] = TRUE;
	RecordCall(fromFloor, UP);
	lock->Acquire();
	sleepCond->Broadcast(lock);
	lock->Release();
}

// Signal an elevator we want to go down
void Building::CallDown(int fromFloor)
{
	callDownRequests[fromFloor] = TRUE;
	RecordCall(fromFloor, DOWN);
	lock->Acquire();
	sleepCond->Broadcast(lock);
	lock->Release();
}

// Wait for elevator arrival & going up
Elevator* Building::AwaitUp(int fromFloor)
{
	upBarrier[fromFloor]->Wait();
	int id = elevatorUp[fromFloor];
	printf("Rider %s chooses elevator %d\n", currentThread->getName(), id);
	return elevator[id];
}

// Wait for elevator arrival & going down
Elevator* Building::AwaitDown(int fromFloor)
{
	downBarrier[fromFloor]->Wait();
	int id = elevatorDown[fromFloor];
	printf("Rider %s chooses elevator %d\n", currentThread->getName(), id);
	return elevator[id];
}

// Record rider's call
void Building::RecordCall(int fromFloor, int direction)
{
	callQueue.push_back(fromFloor * direction);
}

// Call for a elevator
int Building::HandleCall()
{
	if (callQueue.empty() == TRUE)
		return 0;
	else
	{
		int record = callQueue.front();
		callQueue.pop_front();
		return record;
	}
}

// Handle call
void Building::HandleFloor(int fromFloor, int direction)
{
	callQueue.remove(fromFloor * direction);
}

// No. id rider stands on scrFloor, and wants to go to dstFloor
void rider(int id, int scrFloor, int dstFloor)
{
	Elevator *e;

	if (scrFloor == dstFloor)
		return;

	printf("Rider %d travelling from %d to %d\n",id, scrFloor, dstFloor);
	do {
		if (scrFloor < dstFloor)
		{
			printf("Rider %d CallUp on floor %d\n", id, scrFloor);
			building->CallUp(scrFloor);
			printf("Rider %d AwaitUp on floor %d\n", id, scrFloor);
			e = building->AwaitUp(scrFloor);
		}
		else
		{
			printf("Rider %d CallDown on floor %d\n", id, scrFloor);
			building->CallDown(scrFloor);
			printf("Rider %d AwaitDown on floor %d\n", id, scrFloor);
			e = building->AwaitDown(scrFloor);
		}
		printf("Rider %d Enter on floor %d\n", id, scrFloor);
	} while (!e->Enter());	// elevator might be full!

	printf("Rider %d RequestFloor to floor %d\n", id, dstFloor);
	e->RequestFloor(dstFloor); // doesn't return until arrival
	printf("Rider %d Exit on floor\n", id, dstFloor);
	e->Exit();
	printf("Rider %d finished\n", id);
}

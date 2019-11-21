/*

Here are the method signatures for the Elevator and Building classes.
You should feel free to add to these classes, but do not change the
existing interfaces.

*/
#include "synch-sem.h"
#include "EventBarrier.h"
#include <list>

using namespace std;

// macro definition of elevator state
#define UP 1
#define SLEEP 0
#define DOWN -1

class Elevator {
   public:
     Elevator(char *debugName, int numFloors, int myID);
     ~Elevator();
     char *getName() { return name; }
   
     // elevator control interface: called by Elevator thread
     void OpenDoors();           //   signal exiters and enterers to action
     void CloseDoors();          //   after exiters are out and enterers are in
     void VisitFloor(int floor); //   go to a particular floor
   
     // elevator rider interface (part 1): called by rider threads.
     bool Enter();               //   get in
     void Exit();                //   get out (iff destinationFloor)
     void RequestFloor(int floor); // tell the elevator our destinationFloor
   
     // insert your methods here, if needed
     void ElevatorStart();		 //   start running of elevator

   public:
     char *name;
   
     int currentfloor;           // floor where currently stopped
     int occupancy;              // how many riders currently onboard
   
     // insert your data structures here, if needed
     int numfloors;				 // number of floors of the building
     int id;					 // elevator ID
     int state;					 // current state of elevator
     int capacity;				 // maximum riders the elevator can hold
     bool overload;				 // check if overload
     EventBarrier **exitBarriers;// register the riders want to go to 
     							 //   specific floor
     bool *exitRequests;		 // note down whether somebody want to exit or not
};
   
class Building {
   public:
     Building(char *debugname, int numFloors, int numElevators);
     ~Building();
     char *getName() { return name; }
   
   				
     // elevator rider interface (part 2): called by rider threads
     void CallUp(int fromFloor);      //   signal an elevator we want to go up
     void CallDown(int fromFloor);    //   ... down
     Elevator *AwaitUp(int fromFloor); // wait for elevator arrival & going up
     Elevator *AwaitDown(int fromFloor); // ... down

     void RecordCall(int fromFloor, int direction);	// record rider's call
     int HandleCall();			 // call for a elevator
     void HandleFloor(int fromFloor, int direction);// handle call
   
   public:
     char *name;
     Elevator **elevator;         // the elevators in the building (array)
   
     // insert your data structures here, if needed
     char **elevatorsName;		 // name of each elevator
     int numfloors;				 // number of floors
     int numelevators;			 // number of elevators;

     EventBarrier **upBarrier;	 // make sure all uppers enter elevator in some floor
     EventBarrier ** downBarrier;// make sure all donwers enter in some floor
     bool *callUpRequests;		 // someone call up?
     bool *callDownRequests;	 // someone call down?
     int *elevatorUp;			 // up elevators' ID
     int *elevatorDown;			 // down elevators' ID
     Condition *sleepCond;		 // go to sleep if no one call

     list<int> callQueue;		 // record rider's calls
};

   // here's a sample portion of a rider thread body showing how we
   // expect things to be called.
   //
   // void rider(int id, int srcFloor, int dstFloor) {
   //    Elevator *e;
   //  
   //    if (srcFloor == dstFloor)
   //       return;
   //  
   //    DEBUG('t',"Rider %d travelling from %d to %d\n",id,srcFloor,dstFloor);
   //    do {
   //       if (srcFloor < dstFloor) {
   //          DEBUG('t', "Rider %d CallUp(%d)\n", id, srcFloor);
   //          building->CallUp(srcFloor);
   //          DEBUG('t', "Rider %d AwaitUp(%d)\n", id, srcFloor);
   //          e = building->AwaitUp(srcFloor);
   //       } else {
   //          DEBUG('t', "Rider %d CallDown(%d)\n", id, srcFloor);
   //          building->CallDown(srcFloor);
   //          DEBUG('t', "Rider %d AwaitDown(%d)\n", id, srcFloor);
   //          e = building->AwaitDown(srcFloor);
   //       }
   //       DEBUG('t', "Rider %d Enter()\n", id);
   //    } while (!e->Enter()); // elevator might be full!
   //  
   //    DEBUG('t', "Rider %d RequestFloor(%d)\n", id, dstFloor);
   //    e->RequestFloor(dstFloor); // doesn't return until arrival
   //    DEBUG('t', "Rider %d Exit()\n", id);
   //    e->Exit();
   //    DEBUG('t', "Rider %d finished\n", id);
   // }


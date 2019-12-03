// synch-sleep.cc
//      Routines for synchronizing threads.
// (using Thread::Sleep)
//      Two kinds of synchronization routines are defined here: 
//          locks and condition variables 
//

#include "copyright.h"
#include "synch-sleep.h"
#include "system.h"
//----------------------------------------------------------------------
// Semaphore_sleep::Semaphore_sleep
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore_sleep::Semaphore_sleep(char* debugName, int initialValue)
{
    name = debugName;
    value = initialValue;
    queue = new List;
}

//----------------------------------------------------------------------
// Semaphore_sleep::Semaphore_sleep
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore_sleep::~Semaphore_sleep()
{
    delete queue;
}

//----------------------------------------------------------------------
// Semaphore_sleep::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore_sleep::P()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts
    while (value == 0) { 			// semaphore not available
	queue->Append((void *)currentThread);	// so go to sleep
	currentThread->Sleep();
    }
    value--; 					// semaphore available, 
						// consume its value
    
    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
}

//----------------------------------------------------------------------
// Semaphore_sleep::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore_sleep::V()
{
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = (Thread *)queue->Remove();
    if (thread != NULL)	   // make thread ready, consuming the V immediately
	scheduler->ReadyToRun(thread);
    value++;
    (void) interrupt->SetLevel(oldLevel);
}

// Functions -- so we can compile our later assignments 
// Note -- without a correct implementation of Condition::Wait(), 
// the test case in the network assignment won't work!

//-----------------------------------------------------------------------------
// Lock_sleep::Lock_sleep
//    Initialize lock to be FREE
//-----------------------------------------------------------------------------
Lock_sleep::Lock_sleep(char* debugName)
{
    name = debugName;
    lockFlag = FREE;
    waitLockQueue  = new List();   // threads waiting on the lock
    heldLockThread = NULL;         // the current thread which is held the lock
}
	
//-----------------------------------------------------------------------------
// Lock_sleep::~Lock_sleep
//    Deallocate lock
//-----------------------------------------------------------------------------
Lock_sleep::~Lock_sleep()
{
    delete waitLockQueue;
}

//-----------------------------------------------------------------------------
// Lock_sleep::Acquire, Lock_sleep::Release
//    These are the only operations on  lockFlag, They are both "atomic".
//-----------------------------------------------------------------------------
void Lock_sleep::Acquire()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	  // disable interrupts
    ASSERT(!isHeldByCurrentThread());          // lock again!!

    while(lockFlag == BUSY) {  	// wait on lock
    	waitLockQueue->Append((void *)currentThread);
    	currentThread->Sleep();	
    }
    lockFlag = BUSY;                           // held the lock
    heldLockThread = currentThread;           
    
    (void) interrupt->SetLevel(oldLevel);	   // re-enable interrupts
}


void Lock_sleep::Release()
{
    Thread *thread;
	
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	  // disable interrupts
	
    ASSERT(isHeldByCurrentThread());            // crash eception
    lockFlag = FREE;                            // release the lock

    heldLockThread = NULL; 

    thread = (Thread *)waitLockQueue->Remove(); // waking up a thread 
                                                //       wating in the acquire
    if (thread != NULL)	                        // make thread ready
	scheduler->ReadyToRun(thread);		
	
    (void) interrupt->SetLevel(oldLevel);       // re-enable interrupts
}

//-----------------------------------------------------------------------------
// Lock_sleep::isHeldByCurrentThread 
//     Return true if the current thread holds this lock.
//     Useful for  checking in Release, and in Condition variable ops below.
//-----------------------------------------------------------------------------
bool Lock_sleep::isHeldByCurrentThread()
{
    if ((heldLockThread == currentThread) && (lockFlag == BUSY)) { 
	                       // if locked, check for the the held thread 
        return true;
    } else {
   	return false;
    }
}

//-----------------------------------------------------------------------------
// Condition_sleep::Condition_sleep
//     Initialize condition to "no one waiting".
//-----------------------------------------------------------------------------
Condition_sleep::Condition_sleep(char* debugName)
{
    name = debugName;
    waitQueue = new List();
}

//-----------------------------------------------------------------------------
// Condition_sleep::~Condition_sleep
//     Deallocate the condition.
//-----------------------------------------------------------------------------
Condition_sleep::~Condition_sleep()
{
    delete waitQueue;
}

//-----------------------------------------------------------------------------
//    These are the 3 operations on condition variables, releasing the 
//    lock and going to sleep are "atomic" in Wait().
//    ConditionLock must be held by the currentThread for all of 
//    these operations.
//    Using condition Lock object as the condition variable. 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Condition_sleep::Wait
//       release the lock, relinquish the CPU until signaled
//            then re-acquire the lock
//-----------------------------------------------------------------------------
void Condition_sleep::Wait(Lock_sleep* conditionLock) 
{ 
    Thread *thread;
	
    IntStatus oldLevel = interrupt->SetLevel(IntOff);// disable interrupts
	//ASSERT(FALSE);
    thread = currentThread;      // record current thread
    ASSERT(conditionLock->isHeldByCurrentThread());  // shold be current thread
	
    conditionLock->Release();                   // currentThread changed
    waitQueue->Append((void *) thread);

/*//---------------------- BoundedBuffer test---------------------------------
   printf("thread %s is going to sleep\n", currentThread->getName());
*///--------------------------------------------------------------------------

    thread->Sleep();                            // wait on the conditon queue 
    conditionLock->Acquire();
	
    (void) interrupt->SetLevel(oldLevel);       // re-enable interrupts
}
	
//-----------------------------------------------------------------------------
// Condition_sleep::Signal   
//      wake up a thread,
//          if there are any waiting on the condition
//-----------------------------------------------------------------------------
void Condition_sleep::Signal(Lock_sleep* conditionLock) 
{
    Thread *thread;
     
    thread = (Thread *)waitQueue->Remove();   // waking up a thread 
                                              //       wating in the acquire
    if (thread != NULL)	{                      // make thread ready
	scheduler->ReadyToRun(thread);	// put it on ready-list	
    }
}

//-----------------------------------------------------------------------------
// Condition_sleep::Broadcast
//      wake up all threads waiting on the condition
//-----------------------------------------------------------------------------
void Condition_sleep::Broadcast(Lock_sleep* conditionLock)
{
    Thread *thread;

    do {
        thread = (Thread *)waitQueue->Remove();   // wake up a thread
        if (thread != NULL) {                     //   in the wait queue
            scheduler->ReadyToRun(thread);
        }
    } while(thread != NULL);
}

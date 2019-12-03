#ifndef SYNCH-SLEEP_H
#define SYNCH-SLEEP_H

#include "list.h"
#include "thread.h"

#define  BUSY 0
#define  FREE 1


class Semaphore_sleep {
  public:
    Semaphore_sleep(char* debugName, int initialValue);	// set initial value
    ~Semaphore_sleep();   					// de-allocate semaphore
    char* getName() { return name;}			// debugging assist
    
    void P();	 // these are the only operations on a semaphore
    void V();	 // they are both *atomic*
    
  private:
    char* name;        // useful for debugging
    int value;         // semaphore value, always >= 0
    List *queue;       // threads waiting in P() for the value to be > 0
};

class Lock_sleep {
  public:
    Lock_sleep(char* debugName);  		// initialize lock to be FREE
    ~Lock_sleep();				// deallocate lock
    char* getName(){ return name; }	// debugging assist

    void Acquire(); // these are the only operations on a lock
    void Release(); // they are both *atomic*

    bool isHeldByCurrentThread();	// true if the current thread
					// holds this lock.  Useful for
					// checking in Release, and in
					// Condition variable ops below.

  private:
    char* name;				// for debugging
    int   lockFlag;                     // lock or not
    List* waitLockQueue;                // index of the threads waiting
                                        //   on the lock 
    Thread* heldLockThread;             // record the locker    
    // plus some other stuff you'll need to define
};


class Condition_sleep {
  public:
    Condition_sleep(char* debugName);		// initialize condition to 
					// "no one waiting"
    ~Condition_sleep();			// deallocate the condition
    char* getName() { return (name); }
    
    void Wait(Lock_sleep *conditionLock); 	// these are the 3 operations on 
					// condition variables; releasing the 
					// lock and going to sleep are 
					// *atomic* in Wait()
    void Signal(Lock_sleep *conditionLock);   // conditionLock must be held by
    void Broadcast(Lock_sleep *conditionLock);// the currentThread for all of 
					// these operations

  private:
    char* name;
    List* waitQueue;                    // index of the threads waiting 
                                        //     on the condition variable
    // plus some other stuff you'll need to define
};
#endif // SYNCH_H
// synch.h 
//	Data structures for synchronizing threads.
//
//	Three kinds of synchronization are defined here: semaphores,
//	locks, and condition variables.  The implementation for
//	semaphores is given; for the latter two, only the procedure
//	interface is given -- they are to be implemented as part of 
//	the first assignment.
//
//	Note that all the synchronization objects take a "name" as
//	part of the initialization.  This is solely for debugging purposes.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// synch.h -- synchronization primitives.  

#ifndef SYNCH_H
#define SYNCH_H

#include "copyright.h"
#include "thread.h"
#include "list.h"

/**
 * @object semaphore: is a non-negative integer
 * @member P(): waits until value > 0, then decrement
 *         V(): increment, waking up a thread waiting in P() if necessary
 * 
 * this interface does *not* allow a thread to read the value of the semaphore directly.
 * even if you did read the value, the only thing you would know is what the value used to be. 
 * because by the time you get the value into a register, a context switch might have occurred, 
 * and some other thread might have called P or V, so the true value might now be different.
 */


class Semaphore {
  public:
    Semaphore(char* debugName, int initialValue);
    ~Semaphore();   			
    char* getName() { return name;}		
    
    void P();	
    void V();	 
    
  private:
    char* name;        // semaphore name
    int value;         // semaphore value, always >= 0
    List *queue;       // threads waiting in P() for the value to be > 0
};

/**
 * @object lock: can be BUSY or FREE
 * @member Acquire(): wait until the lock is FREE, then set it to BUSY
 *         Release(): set lock to be FREE, waking up a thread waiting in Acquire if necessary
 *         isHeldByCurrentThread(): true if the current thread holds this lock.
 * 
 * only the thread that acquired the lock may release it.
 * As with semaphores, you can't read the lock value 
 * (because the value might change immediately after you read it). 
 */
class Lock {
  public:
    Lock(char* debugName);  		// initialize lock to be FREE
    ~Lock();				
    char* getName() { return name; }	

    void Acquire(); 
    void Release(); 
    bool isHeldByCurrentThread();	


  private:

    char* name;				// lock name
    bool isFree;      // true if lock is FREE, false if lock is BUSY
    List *queue;      // threads which are BUSY
    Semaphore *semaphore;
    Thread* currentHeldLockThread;  // current that hold lock   
};

/**
 * @object condition: a variable those threads in queue are waiting for
 * @member Wait(): release the lock, relinquish the CPU until signaled, then re-acquire the lock
 *         Signal(): wake up a thread, if there are any waiting on the condition
 *         Broadcast(): wake up all threads waiting on the condition
 * 
 * All operations on a condition variable must be made while the current thread has acquired a lock.
 * All accesses to a given condition variable must be protected by the same lock.
 * 
 * In Nachos: 
 *     When a Signal or Broadcast wakes up another thread, it simply puts the thread on the ready list, 
 *     and it is the responsibility of the woken thread to re-acquire the lock (this re-acquire is taken care of within Wait()). 
 */

class Condition {
  public:
    Condition(char* debugName);		// initialize condition to "no one waiting"
    ~Condition();			
    char* getName() { return (name); }
    
    // conditionLock must be held by the currentThread for all of these operations
    void Wait(Lock *conditionLock); 	// releasing the lock and going to sleep are *atomic* in Wait()
    void Signal(Lock *conditionLock);   
    void Broadcast(Lock *conditionLock);

  private:
    char *name;
    Semaphore *semaphore;
    Semaphore *wait_atom; // Ensure atomtic
    int numThreadWait; // Number of threads waiting on this condition
};
#endif // SYNCH_H

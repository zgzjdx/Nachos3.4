// synch-sleep.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables (the implementation of the last two
//	are left to the reader).
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

// Implement your locks and condition variables using the sleep/wakeup primitives.

#include "copyright.h"
#include "synch-sleep.h"
#include "system.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(char* debugName, int initialValue)
{
    name = debugName;
    value = initialValue;
    queue = new List;
}

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore()
{
    delete queue;
}

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore::P()
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
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore::V()
{
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = (Thread *)queue->Remove();
    if (thread != NULL)	   // make thread ready, consuming the V immediately
	scheduler->ReadyToRun(thread);
    value++;
    (void) interrupt->SetLevel(oldLevel);
}

// Dummy functions -- so we can compile our later assignments 
// Note -- without a correct implementation of Condition::Wait(), 
// the test case in the network assignment won't work!

//----------------------------------------------------------------------
// Lock::Lock
//  Initialize lock to be FREE.
//----------------------------------------------------------------------

Lock::Lock(char* debugName)
{
    name = debugName;
    value = FREE;
    queue = new List;
}

//----------------------------------------------------------------------
// Lock::~Lock
//  Deallocate lock
//----------------------------------------------------------------------

Lock::~Lock()
{
    delete queue;
}

//----------------------------------------------------------------------
// Lock::Acquire
//  Acquire a lock when lock is free, or put into wait queue.
//----------------------------------------------------------------------

void Lock::Acquire()
{
    ASSERT (isHeldByCurrentThread() == FALSE);          // forbide re-allocating lock

    IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts;

    while (value == BUSY)                               // lock is busy, waiting
    {
        queue->Append((void *)currentThread);           // put thread on wait queue
        currentThread->Sleep();                         // go to sleep
    }
    value = BUSY;                                       // when lock is free, grab it
    current = currentThread;

    (void) interrupt->SetLevel(oldLevel);               // enable interrupts
}

//----------------------------------------------------------------------
// Lock::Release
//  Release a lock.
//----------------------------------------------------------------------

void Lock::Release()
{
    Thread *thread;
    ASSERT (isHeldByCurrentThread() == TRUE);           // if not held by current thread, abort

    IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts

    thread = (Thread *)queue->Remove();                 // take thread off wait queue
    if (thread != NULL)                                 // if anyone on wait queue
        scheduler->ReadyToRun(thread);                  // place on ready queue
    value = FREE;                                       // release lock
    current = NULL;

    (void) interrupt->SetLevel(oldLevel);               // enable interrupts
}

//----------------------------------------------------------------------
// Lock::isHeldByCurrentThread
//  Return true if the current thread holds this lock, false otherwise.
//----------------------------------------------------------------------

bool Lock::isHeldByCurrentThread()
{
    if (current == currentThread)
        return TRUE;
    else
        return FALSE;
}

//----------------------------------------------------------------------
// Condition::Condition
//  Initinalize condition variable.
//----------------------------------------------------------------------

Condition::Condition(char* debugName)
{
    name = debugName;
    queue = new List;
}

//----------------------------------------------------------------------
// Condition::Condition
//  Delete condition variable.
//----------------------------------------------------------------------

Condition::~Condition()
{
    delete queue;
}

//----------------------------------------------------------------------
// Condition::Wait
//  Atomically release lock and go to sleep. Re-acquire lock later, 
//  before returning.
//----------------------------------------------------------------------

void Condition::Wait(Lock* conditionLock)
{
    ASSERT (conditionLock->isHeldByCurrentThread() == TRUE);

    IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts

    queue->Append((void *)currentThread);               // add this thread to queue
    conditionLock->Release();                           // release lock
    currentThread->Sleep();                             // go to sleep
    conditionLock->Acquire();                           // re-acquire lock

    (void) interrupt->SetLevel(oldLevel);               // enable interrupts
}

//----------------------------------------------------------------------
// Condition::Signal
//  Wake up one waiter, if any.
//----------------------------------------------------------------------

void Condition::Signal(Lock* conditionLock)
{
    Thread *thread;
    // ASSERT (conditionLock->isHeldByCurrentThread() == TRUE);

    IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts

    thread = (Thread *)queue->Remove();                 // take thread off wait queue
    if (thread != NULL)                                 // if anyone on wait queue
        scheduler->ReadyToRun(thread);                  // wake up thread, place on ready queue
    
    (void) interrupt->SetLevel(oldLevel);               // enable interrupts
}

//----------------------------------------------------------------------
// Condition::Broadcast
//  Wake up all waiters.
//----------------------------------------------------------------------

void Condition::Broadcast(Lock* conditionLock)
{
    Thread *thread;
    // ASSERT (conditionLock->isHeldByCurrentThread() == TRUE);

    IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts

    thread = (Thread *)queue->Remove();                 // remove from wait queue
    while (thread != NULL)
    {
        scheduler->ReadyToRun(thread);                  // wake up
        thread = (Thread *)queue->Remove();             // continue removing
    }

    (void) interrupt->SetLevel(oldLevel);               // enable interrupts
}

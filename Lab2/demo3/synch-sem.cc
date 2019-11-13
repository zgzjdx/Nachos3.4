// synch-sem.cc 
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

#include "copyright.h"
#include "synch-sem.h"
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
//  Initialize lock.
//----------------------------------------------------------------------

Lock::Lock(char* debugName) 
{
    name = debugName;
    sem = new Semaphore("lock semaphore", 1);   // initial semaphore value is 1
    current = NULL;
}

//----------------------------------------------------------------------
// Lock::~Lock
//  Deallocate lock.
//----------------------------------------------------------------------

Lock::~Lock()
{
    delete sem;
}

//----------------------------------------------------------------------
// Lock::Acquire
//  Acquire a lock, just do P()'s op, since binary semaphore quite looks
//  like a lock.
//----------------------------------------------------------------------

void Lock::Acquire()
{
    ASSERT (isHeldByCurrentThread() == FALSE);

    sem->P();
    current = currentThread;
}

//----------------------------------------------------------------------
// Lock::Release
//  Release a lock, do V()'s op.
//----------------------------------------------------------------------

void Lock::Release()
{
    ASSERT (isHeldByCurrentThread() == TRUE);

    sem->V();
    current = NULL;
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
    waiters = 0;
    s = new Semaphore("sem s", 0);      // counting semaphore
    x = new Semaphore("sem x", 1);      // binary semaphore, used as lock
    h = new Semaphore("sem h", 0);      // counting semaphore
}

//----------------------------------------------------------------------
// Condition::Condition
//  Delete condition variable.
//----------------------------------------------------------------------

Condition::~Condition()
{
    delete s;
    delete x;
    delete h;
}

//----------------------------------------------------------------------
// Condition::Wait
//  It's quite difficult for us to 'create' this algorithm individually, 
//  see A. D. Birrell, 2003 please, we just *refer* their work, ^_^. 
//----------------------------------------------------------------------

void Condition::Wait(Lock* conditionLock) 
{
    ASSERT (conditionLock->isHeldByCurrentThread() == TRUE);

    x->P();
    waiters++;
    x->V();
    conditionLock->Release();
    s->P();
    h->V();
    conditionLock->Acquire();
}

//----------------------------------------------------------------------
// Condition::Signal
//  See A. D. Birrell, 2003 too.
//----------------------------------------------------------------------

void Condition::Signal(Lock* conditionLock)
{
    // ASSERT (conditionLock->isHeldByCurrentThread() == TRUE);

    x->P();
    if (waiters > 0)
    {
        waiters--;
        s->V();
        h->P();
    }
    x->V();
}

//----------------------------------------------------------------------
// Condition::Broadcast
//  See A. D. Birrell, 2003. Hmm, I think we can propose it if we know
//  how to implement Signal primitive.
//----------------------------------------------------------------------

void Condition::Broadcast(Lock* conditionLock)
{
    // ASSERT (conditionLock->isHeldByCurrentThread() == TRUE);

    x->P();
    for (int i = 0; i < waiters; ++i)
        s->V();
    while (waiters > 0)
    {
        waiters--;
        h->P();
    }
    x->V();
}

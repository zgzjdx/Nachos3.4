#include "EventBarrier.h"

EventBarrier::EventBarrier()
{
    barrierState = UNSIGNALED;
    waiters = 0;
    lock = new Lock("barrier lock");
    signalCond = new Condition("signal condition");
    completeCond = new Condition("complete condition");
}

EventBarrier::~EventBarrier()
{
    delete lock;
    delete signalCond;
    delete completeCond;
}

// Wait until the event is signaled. 
// Return immediately if already in the signaled state.
void EventBarrier::Wait()
{
    lock->Acquire();

    waiters++;
    while (barrierState == UNSIGNALED)
        signalCond->Wait(lock);

    lock->Release();
}

// Signal the event and block until all threads that wait for 
// this event have responded. The EventBarrier reverts to 
// the unsignaled state when Signal() returns.
void EventBarrier::Signal()
{
    lock->Acquire();

    barrierState = SIGNALED;
    signalCond->Broadcast(lock);
    completeCond->Wait(lock);

    ASSERT (waiters == 0);      // waiters must be zero as now completed

    barrierState = UNSIGNALED;

    lock->Release();
}

// Indicate that the calling thread has finished responding to 
// a signaled event, and block until all other threads that 
// wait for this event have also responded.
void EventBarrier::Complete()
{
    lock->Acquire();

    waiters--;
    if (waiters == 0)
        completeCond->Broadcast(lock);
    else
        completeCond->Wait(lock);

    lock->Release();
}

// Return a count of threads that are waiting for the event 
// or that have not yet responded to it.
int EventBarrier::Waiters()
{
    return waiters;
}

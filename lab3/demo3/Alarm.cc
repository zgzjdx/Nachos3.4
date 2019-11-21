#include "Alarm.h"
#include "system.h"

// defined in threadtest.cc
extern Alarm *myalarm;

// A dummy function, just to cause idle.
static void IdleMaker(int arg)
{
    // prevent Nachos from exiting when 
    //  there are threads waiting for an alarm
    while (myalarm->GetWaiters() > 0)
        currentThread->Yield();
    myalarm->SetIsNecessaryToFork(TRUE);
}

Alarm::Alarm()
{
    waiters = 0;
    isNecessaryToFork = TRUE;
    waitQueue = new List();
}

Alarm::~Alarm()
{
    delete waitQueue;
}

// Threads call this function to go to sleep for a period of time. 
void Alarm::Pause(int howLong)
{
    ASSERT (howLong > 0);   // check whether howLong is vaild or not

    waiters++;
    if (isNecessaryToFork)
    {
        isNecessaryToFork = FALSE;
        Thread *t = new Thread("forked thread");
        t->Fork(IdleMaker, 0);
    }

    IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts

    int wake_up_time = stats->totalTicks + howLong;
    waitQueue->SortedInsert(currentThread, wake_up_time);
    currentThread->Sleep();

    (void) interrupt->SetLevel(oldLevel);   // re-enable interrupts
}

// called when interval has expired, bound in TimerInterruptHandler, system.cc
void Alarm::AlarmRing()
{
    int wake_up_time;

    IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts

    Thread *t = (Thread *) waitQueue->SortedRemove(&wake_up_time);
    while (t != NULL)
    {
        if (stats->totalTicks >= wake_up_time)
        {
            scheduler->ReadyToRun(t);
            waiters--;
            t = (Thread *) waitQueue->SortedRemove(&wake_up_time);
        }
        else
        {
            waitQueue->SortedInsert((void *)t, wake_up_time);
            (void) interrupt->SetLevel(oldLevel);   // re-enable interrupts
            return;
        }
    }
}

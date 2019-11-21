// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "dllist.h"
#include "Table.h"
#include "BoundedBuffer.h"
#include "EventBarrier.h"
#include "Alarm.h"
#include "Elevator.h"
#include <stdio.h>
#include <malloc.h>

// functions in dllist-driver.cc
extern void Insert(DLList *L, int N, int whichThread);
extern void Remove(DLList *L, int N, int whichThread);
extern int getRandom();

// function in Elevator.cc
extern void rider(int id, int scrFloor, int dstFloor);

// testnum is set in main.cc
int testnum = 1;

// those are set in main.cc
int threadnum = 2;	// number of threads, default: 2
int itemnum = 6;	// number of items, default: 6
int errorType = 0;	// type of error
int tableSize = 5;  // size of multireaded table, default: 5
bool allowSynch = TRUE; // allow using synchronous primitives, default: TRUE
int numFloors = 10;     // number of floors
int numElevators = 2;   // number of elevators
int capacityOfElevator = 20;    // maximum riders in elevator, default: 20

// global, pointer to doubly-linked list
DLList *L;
// muitireaded table
Table *table;
// bounded buffer using lock & condition variable
BoundedBuffer *buffer;
// bounded buffer using semaphore
semBoundedBuffer *sembuffer;
// event barrier
EventBarrier *barrier;
// alarm clock
Alarm *myalarm;
// building with elevators
Building *building;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// SimpleThread2
// 	Manipulate doubly-linked list here.
//----------------------------------------------------------------------

void
SimpleThread2(int which)
{
    Insert(L, itemnum, which);
    Remove(L, itemnum, which);
}

//----------------------------------------------------------------------
// SimpleThread3
//  Use synchronization primitives to ensure that the list is being 
//  updated consistently despite its use by multiple threads.
//----------------------------------------------------------------------

void
SimpleThread3(int which)
{
    L->lock->Acquire();                	  // enforce mutual exclusive access to the list

    while (L->count == itemnum)
        L->listFull->Wait(L->lock);       // wait until list is empty
    Insert(L, itemnum, which);
    L->count += itemnum;
    L->listEmpty->Signal(L->lock);        // tell that it's full, if any

    while (L->count == 0)
        L->listEmpty->Wait(L->lock);      // wait until list isn't empty
    Remove(L, itemnum, which);
    L->count -= itemnum;
    L->listFull->Signal(L->lock);         // tell that it's empty, if any

    L->lock->Release();
}

//----------------------------------------------------------------------
// Allocater
//  Insert item into table.
//----------------------------------------------------------------------

void
Allocater(int which)
{
    int num;
    int *item;
    int index;
    
    for (num = 0; num < itemnum; num++)   // insert item one by one
    {
        item = (int *)malloc(sizeof(int));
        *item = getRandom();
        index = table->Alloc((void *)item);
        if (index != -1)
            printf("thread %d inserts %d into table on entry %d\n", which, *item, index);
        else
            printf("thread %d fails to insert %d into table\n", which, *item);
    }
}

//----------------------------------------------------------------------
// Getter
//  Look up table.
//----------------------------------------------------------------------

void
Getter(int which)
{
    int num;
    int index;
    int *returnedItem;

    for (num = 0; num < itemnum; num++)   // look up one by one
    {
        index = getRandom() % tableSize;
        returnedItem = (int *)(table->Get(index));
        if (returnedItem != NULL)
            printf("thread %d looks up: table[%d] = %d\n", which, index, *returnedItem);
        else
            printf("thread %d fails to look up table[%d]\n", which, index);
    }
}

//----------------------------------------------------------------------
// Releaser
//  Release items.
//----------------------------------------------------------------------
void
Releaser(int which)
{
    int num;
    int index;

    for (num = 0; num < itemnum; num++)   // release one by one
    {
        index = getRandom() % tableSize;
        table->Release(index);
        printf("thread %d releases table[%d]\n", which, index);
    }
}

//----------------------------------------------------------------------
// Producer
//  Write something to buffer using lock & cv.
//----------------------------------------------------------------------

void
Producer(int which)
{
    int num;
    char *data;
    int size;

    data = (char *)malloc(105 * sizeof(int));
    for (num = 0; num < itemnum; num++)     // write into buffer
    {
        size = getRandom() % (tableSize * 2);
        for (int i = 0; i < size; ++i)
        {
            data[i] = getRandom() % ('z' - 'a' + 1) + 'a';
        }
        data[size] = 0;
        printf("*** thread %d wants to write %d bytes: \"%s\"\n", which, size, data);
        buffer->Write(data, size, which);
        printf("*** thread %d finishes writing %d bytes: \"%s\"\n", which, size, data);
    }
}

//----------------------------------------------------------------------
// Consumer
//  Read something to buffer using lock & cv.
//----------------------------------------------------------------------

void
Consumer(int which)
{
    int num;
    char *data;
    int size;

    data = (char *)malloc(105 * sizeof(int));
    for (num = 0; num < itemnum; num++)     // read from buffer
    {
        size = getRandom() % (tableSize * 2);
        printf("*** thread %d wants to read %d bytes\n", which, size);
        buffer->Read(data, size, which);
        data[size] = 0;
        printf("*** thread %d finishes reading %d bytes: \"%s\"\n", which, size, data);
    }
}

//----------------------------------------------------------------------
// semProducer
//  Write something to buffer using semaphore.
//----------------------------------------------------------------------

void
semProducer(int which)
{
    int num;
    char *data;
    int size;

    data = (char *)malloc(105 * sizeof(int));
    for (num = 0; num < itemnum; num++)     // write into buffer
    {
        size = getRandom() % (tableSize * 2);
        for (int i = 0; i < size; ++i)
        {
            data[i] = getRandom() % ('z' - 'a' + 1) + 'a';
        }
        data[size] = 0;
        printf("*** thread %d wants to write %d bytes: \"%s\"\n", which, size, data);
        sembuffer->semWrite(data, size, which);
        printf("*** thread %d finishes writing %d bytes: \"%s\"\n", which, size, data);
    }
}

//----------------------------------------------------------------------
// semConsumer
//  Read something to buffer using semaphore.
//----------------------------------------------------------------------

void
semConsumer(int which)
{
    int num;
    char *data;
    int size;

    data = (char *)malloc(105 * sizeof(int));
    for (num = 0; num < itemnum; num++)     // read from buffer
    {
        size = getRandom() % (tableSize * 2);
        printf("*** thread %d wants to read %d bytes\n", which, size);
        sembuffer->semRead(data, size, which);
        data[size] = 0;
        printf("*** thread %d finishes reading %d bytes: \"%s\"\n", which, size, data);
    }
}

//----------------------------------------------------------------------
// Kid
//  A child, arrives at meeting point, and wait for other kids. 
//  If all kids has arrived, then he/she gets on bus, and tells his/her
//  teacher that he/she has sat down.
//----------------------------------------------------------------------

void
Kid(int which)
{
    // just for delay, cause confusion
    for (int i = 1; i <= 20; ++i)
    {
        if (getRandom() % 10 < 5)
            currentThread->Yield();
    }
    
    printf("Kid %d is coming!\n", which);
    barrier->Wait();        // wait for other kids

    // just for delay, cause confusion
    for (int i = 1; i <= 20; ++i)
    {
        if (getRandom() % 10 < 5)
            currentThread->Yield();
    }
    
    printf("Kid %d gets on the bus!\n", which);
    barrier->Complete();    // tell teacher that "I'm on the bus"
}

//----------------------------------------------------------------------
// Bus
//  A bus, waits until all kids have arrived and got on the bus.
//----------------------------------------------------------------------

void
Bus(int which)
{
    while (barrier->Waiters() < threadnum)      // wait for all kids
        currentThread->Yield();
    
    printf("Everybody is here! Get on the bus!\n");
    barrier->Signal();      // wait for kids getting on bus
    printf("Let's go together!\n");
}

//----------------------------------------------------------------------
// AlarmTest
//  Go to sleep for a few ticks, and wake up after alarm ringing.
//----------------------------------------------------------------------

void
AlarmTest(int which)
{
    int howLong = getRandom() * 2 + 1;
    printf("Thread %d goes to sleep at %d tick, sleeps %d ticks, wakes up after %d tick\n", 
        which, stats->totalTicks, howLong, (stats->totalTicks + howLong));
    myalarm->Pause(howLong);
    printf("Thread %d wakes up at %d tick\n", which, stats->totalTicks);
}

//----------------------------------------------------------------------
// Rider
//  A rider who wants to go to dstFloor from srcFloor.
//----------------------------------------------------------------------

void
Rider(int which)
{
    int srcFloor, dstFloor;
    do {
        srcFloor = getRandom() % numFloors + 1;
        dstFloor = getRandom() % numFloors + 1;
    } while(srcFloor == dstFloor);
    rider(which, srcFloor, dstFloor);
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");
	
    Thread *t = new Thread("forked thread");

    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

//----------------------------------------------------------------------
// ThreadTest2
//  Create a doubly-linked list by calling Insert first, 
//  and then remove items at the top of the list by those threads.
//----------------------------------------------------------------------

void
ThreadTest2()
{
    DEBUG('t', "Entering ThreadTest2");
	
    // allocate the list
    L = new DLList();
	
    // fork thread
    for (int i = 1; i < threadnum; ++i)
    {
        Thread *t = new Thread("forked thread");
        t->Fork(SimpleThread2, i);
    }
    SimpleThread2(0);
}

//----------------------------------------------------------------------
// ThreadTest3
//  Synchronization test for doubly-linked list of lab 2, sec 2.1, 
//  not quite different from above.
//----------------------------------------------------------------------

void
ThreadTest3()
{
    DEBUG('t', "Entering ThreadTest3");
    
    // allocate the list
    L = new DLList();
    
    // fork thread
    for (int i = 1; i < threadnum; ++i)
    {
        Thread *t = new Thread("forked thread");
        t->Fork(SimpleThread3, i);
    }
    SimpleThread3(0);
}

//----------------------------------------------------------------------
// ThreadTest4
//  Test for multithreaded Table.
//----------------------------------------------------------------------

void
ThreadTest4()
{
    DEBUG('t', "Entering ThreadTest4");
    
    // create a table with tableSize entries
    table = new Table(tableSize);

    // alloc thread
    for (int i = 1; i < threadnum; ++i)
    {
        Thread *t = new Thread("alloc thread");
        t->Fork(Allocater, i);
    }

    // get thread
    for (int i = threadnum; i < 2 * threadnum; ++i)
    {
        Thread *t = new Thread("get thread");
        t->Fork(Getter, i);
    }

    // release thread
    for (int i = 2 * threadnum; i < 3 * threadnum; ++i)
    {
        Thread *t = new Thread("release thread");
        t->Fork(Releaser, i);
    }
    Allocater(0);
}

//----------------------------------------------------------------------
// ThreadTest5
//  Simple test for bounded buffer using lock & cv.
//----------------------------------------------------------------------

void
ThreadTest5()
{
    DEBUG('t', "Entering ThreadTest5");
    
    // create a bounded buffer with tableSize
    buffer = new BoundedBuffer(tableSize);

    // writer thread
    for (int i = 1; i < threadnum; ++i)
    {
        Thread *t = new Thread("writer thread");
        t->Fork(Producer, i);
    }

    // reader thread
    for (int i = threadnum; i < 2 * threadnum; ++i)
    {
        Thread *t = new Thread("reader thread");
        t->Fork(Consumer, i);
    }
    Producer(0);
}

//----------------------------------------------------------------------
// ThreadTest6
//  Simple test for bounded buffer using semaphore.
//----------------------------------------------------------------------

void
ThreadTest6()
{
    DEBUG('t', "Entering ThreadTest6");
    
    // create a bounded buffer with tableSize
    sembuffer = new semBoundedBuffer(tableSize);

    // writer thread
    for (int i = 1; i < threadnum; ++i)
    {
        Thread *t = new Thread("writer thread");
        t->Fork(semProducer, i);
    }

    // reader thread
    for (int i = threadnum; i < 2 * threadnum; ++i)
    {
        Thread *t = new Thread("reader thread");
        t->Fork(semConsumer, i);
    }
    semProducer(0);
}

//----------------------------------------------------------------------
// ThreadTest7
//  Simple test for barrier. The story is, threadnum kids go on a 
//  spring trip today, but some kids come fast while others are slow. 
//  Thus, their teacher need to wait for all kids coming, and then the
//  bus driver can set off for their destination.
//----------------------------------------------------------------------

void
ThreadTest7()
{
    DEBUG('t', "Entering ThreadTest7");

    barrier = new EventBarrier();

    for (int i = 1; i <= threadnum; ++i)
    {
        Thread *t = new Thread("kid thread");
        t->Fork(Kid, i);
    }
    Bus(0);
}

//----------------------------------------------------------------------
// ThreadTest8
//  A quick example of alarm.
//----------------------------------------------------------------------

void
ThreadTest8()
{
    DEBUG('t', "Entering ThreadTest8");

    for (int i = 1; i < threadnum; ++i)
    {
        Thread *t = new Thread("forked thread");
        t->Fork(AlarmTest, i);
    }
    AlarmTest(0);
}

//----------------------------------------------------------------------
// ThreadTest9
//  Run building and test elevators.
//----------------------------------------------------------------------

void
ThreadTest9()
{
    DEBUG('t', "Entering ThreadTest9");

    building = new Building("building", numFloors, numElevators);
    for (int i = 1; i <= threadnum; ++i)
    {
        char *name = new char[5];
        sprintf(name, "%d", i);
        Thread *t = new Thread(name);
        t->Fork(Rider, i);
    }
}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest()
{
    switch (testnum) {
    case 1:
        ThreadTest1();
	break;
    case 2:
        ThreadTest2();	// test for doubly-linked list goes here
	break;
    case 3:
        ThreadTest3();  // test for lab 2.1
    break;
    case 4:
        ThreadTest4();  // test for lab 2.2
    break;
    case 5:
        ThreadTest5();  // test for lab 2.3 using lock & conditon variable
    break;
    case 6:
        ThreadTest6();  // test for lab 2.3 using semaphore
    break;
    case 7:
        ThreadTest7();  // test for lab 3.1 of barrier
    break;
    case 8:
        ThreadTest8();  // test for lab 3.2 of alarm
    break;
    case 9:
        ThreadTest9();  // test for lab 3.3 of elevator
    break;
    default:
        printf("No test specified.\n");
	break;
    }
}


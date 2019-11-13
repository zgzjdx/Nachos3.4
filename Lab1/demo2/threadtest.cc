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
#include <stdio.h>

// functions in dllist-driver.cc
extern void Insert(DLList *L, int N, int whichThread);
extern void Remove(DLList *L, int N, int whichThread);

// testnum is set in main.cc
int testnum = 1;

// those are set in main.cc
int threadnum = 2;	// number of threads, default: 2
int itemnum = 6;	// number of items, default: 6
int errorType = 0;	// type of error

// global, pointer to doubly-linked list
DLList *L;

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
    default:
	printf("No test specified.\n");
	break;
    }
}


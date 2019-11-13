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
extern void genRandomNode(IN DLList *list, IN int n);
extern void delHdrNode(IN DLList *list, IN int n);
extern void dllistDriverTest();

int testnum = 1; // testnum is set in main.cc
int nodeNum = 6; // nodeNum is set in main.cc

//	"which" is simply a number identifying the thread, for debugging purposes.

void DllistThread1(int which)
{
    DLList *newList = new DLList();
    printf("[*] generate %d element in thread %d\n", nodeNum, which);
    genRandomNode(newList, nodeNum);

    currentThread->Yield();

    printf("[*] delete %d element in thread %d\n", nodeNum, which);
    delHdrNode(newList, nodeNum);
}

void DLListTest1()
{
    DEBUG('t', "Entering DLListThreadTest1");

    Thread *t = new Thread("forked thread 1");

    t->Fork(DllistThread1, 1);
    DllistThread1(0);
}

void DllistThread2(int which)
{
    DLList *newList = new DLList();

    // TODO:

    currentThread->Yield();

    // TODO:
}

void DLListTest2()
{
    DEBUG('t', "Entering DLListThreadTest2");

    Thread *t = new Thread("forked thread 2");

    t->Fork(DllistThread2, 1);
    DllistThread2(0);
}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void ThreadTest()
{

    switch (testnum)
    {
    case 1:
        DLListTest1();
        break;
    case 2:
        DLListTest2();
        break;
    default:
        printf("No test specified.\n");
        break;
    }
}

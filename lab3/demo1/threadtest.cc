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
#include "synch.h"
#include <assert.h>
#include <time.h> 
#include "system.h"
#include "dllist.h"
#include "EventBarrier.h"

int testnum = 1;
int threadNum=1;

Lock* dlistLock = new Lock("lock of dlist"); 
bool canYield = false;
EventBarrier *e = new EventBarrier(); 
char *
getName(int i)
{
    switch(i)
    {
        case 0: return "forked thread 0";
        case 1: return "forked thread 1"; 
        case 2: return "forked thread 2";
        case 3: return "forked thread 3"; 
        case 4: return "forked thread 4";
        case 5: return "forked thread 5"; 
        case 6: return "forked thread 6";
        case 7: return "forked thread 7"; 
        case 8: return "forked thread 8";
        case 9: return "forked thread 9"; 
        case 10: return "forked thread 10";
        default:
            return "forked thread 00";
    }
}


//================= test barriers ===============

void 
testBarrier(int which)
{
    if(which % 2 == 0){
        e->Wait();
        printf("[BARI] No.%d pass 1 barrier\n",which);
        e->Complete();
        e->Wait();
        printf("[BARI] No.%d pass 2 barrier\n",which);
        e->Complete();
    }else{
        e->Wait();
        printf("[BARI] No.%d pass 1 barrier\n",which);
        e->Complete();
    }
}



void
BarrieMain()
{
    Thread *t;
    for(int i=0 ;i < threadNum ;i++) {
        t = new Thread(getName(i+1));
        t->Fork(testBarrier,i+1);
        currentThread->Yield();
    }
    printf("[BARI] open 1 barrier\n"); 
    e->Signal();
    currentThread->Yield();
    printf("[BARI] open 2 barrier\n"); 
    e->Signal();
}


//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------
void 
toDllistTest(VoidFunctionPtr func)
{
    DEBUG('t', "Entering  toDllistTest\n");
    Thread *t;
    for(int i=0 ;i < threadNum ;i++) {
        t = new Thread(getName(i+1));
        t->Fork(func,i+1); 
    }
} 

void
ThreadTest()
{
    switch (testnum) {
    case 1:
        //test barrier
        BarrieMain(); 
        break;
    default:
    	printf("No test specified.\n");
    	break;
    }
}


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
#include "Elevator.h"
#include <assert.h>
#include <time.h> 
#include "system.h"
#include "dllist.h"
#include "EventBarrier.h"

int testnum = 1;
int threadNum=1;
int floorNums = 10;
Building *building;
extern int getRandNum(int range);
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

//================test alarm =================== 
// ./nachos -q 1 -t t1(the num of test threads) 
void 
testAlarm(int which)
{
    alarms->Pause(which*10000);
    printf("NO.%d thread finish its test\n",which);
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



//============test elevator==============
//--------------------------
// rider action
//------------------
void rider(int id, int srcFloor, int dstFloor) {
  Elevator *e;

  if (srcFloor == dstFloor)
     return;

  DEBUG('t',"Rider %d travelling from %d to %d\n",id,srcFloor,dstFloor);
  do {
     if (srcFloor < dstFloor) {
        DEBUG('t', "Rider %d CallUp(%d)\n", id, srcFloor);
        building->CallUp(srcFloor);
        DEBUG('t', "Rider %d AwaitUp(%d)\n", id, srcFloor);
        e = building->AwaitUp(srcFloor);
     } else {
        DEBUG('t', "Rider %d CallDown(%d)\n", id, srcFloor);
        building->CallDown(srcFloor);
        DEBUG('t', "Rider %d AwaitDown(%d)\n", id, srcFloor);
        e = building->AwaitDown(srcFloor);
     }
     DEBUG('t', "Rider %d Enter()\n", id);
  } while (!e->Enter()); // elevator might be full!

  DEBUG('t', "Rider %d RequestFloor(%d)\n", id, dstFloor);
  e->RequestFloor(dstFloor); // doesn't return until arrival
  DEBUG('t', "Rider %d Exit()\n", id);
  e->Exit();
  DEBUG('t', "Rider %d finished\n", id);
}

// elevator action
void 
elevatorAction(int id)
{
    building->RunElev(id);
}

void 
riderAction(int which)
{
    int from = getRandNum(floorNums), to = getRandNum(floorNums);
    alarms->Pause( getRandNum(20) * 100);
    printf("[PERS] No.%d %d->%d request\n",which,from,to);
    rider(which,from,to);
    printf("[PERS] No.%d %d->%d reach\n",which,from,to);
}


void 
riderCapa(int which)
{
    int from = 1, to = getRandNum(floorNums);
    alarms->Pause(1 * 100);
    printf("[PERS] No.%d %d->%d request\n",which,from,to);
    rider(which,from,to);
    printf("[PERS] No.%d %d->%d reach\n",which,from,to);
}
//---------------------
// main thread 
// command: ./nachos [-d t] -q 3 -t n1(the num of riders) -n n1(the num of floors)
// you can set capacity on Elevator.cc file
//---------------------
void 
mainThreadAction()
{
    // run elevator
    building = new Building("office buildings",floorNums,1);
    Thread *elev = new Thread("thread for elevator");
    elev->Fork(elevatorAction,1);
    // create riders
    Thread *t;
    for(int i=0 ;i < threadNum ;i++) {
        t = new Thread(getName(i+1));
        t->Fork(riderAction,i+1); 
    }
    printf("all rider has reached dest and exit\n");
}

void 
capaTest()
{
    // run elevator
    building = new Building("office buildings",floorNums,1);
    Thread *elev = new Thread("thread for elevator");
    elev->Fork(elevatorAction,1);
    // create riders
    Thread *t;
    for(int i = 0; i < 5; i++) {
        t = new Thread(getName(i+1));
        t->Fork(riderCapa, i+1); 
    }
    printf("all rider has reached dest and exit\n");
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
    printf("%d \n",testnum); 
    switch (testnum) {
    case 1:
        //test barrier
        BarrieMain(); 
        break;
    case 2:
        //test alarm
        toDllistTest(testAlarm);
        break;
    case 3:
        //test elevator
        mainThreadAction();
        break;
    case 4:
        capaTest();break;
    default:
    	printf("No test specified.\n");
    	break;
    }
}


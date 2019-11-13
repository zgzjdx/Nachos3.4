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
#include "synch.h"
#include "Table.h"
#include "BoundedBuffer.h"
#include <assert.h>  
//#include "thread.h" //newly added
extern void genRandomNode(IN DLList *list, IN int n, int which);
extern void delHdrNode(IN DLList *list, IN int n, int which);
extern void dllistDriverTest();

int testnum; // testnum is set in main.cc
int nodeNum; // nodeNum is set in main.cc
int threadNum; //threadnum is set in main.cc
//	"which" is simply a number identifying the thread, for debugging purposes.
static DLList* newList = new DLList();
Lock* outListLock =  new Lock("out of dlist define");
Lock* dlistLock = new Lock("lock of dlist"); 
Table* table = new Table(10);
BoundedBuffer* buffer = new BoundedBuffer(20);
int data[] = {1,3,4,13,12,17,18,23,19,20,13,33,27,43,26,21,16,14,10,29};


void DLListTest1(int which)
{
    outListLock->Acquire();
    printf("[*] generate %d element in thread %d\n", nodeNum, which);
    genRandomNode(newList, nodeNum, which);
    currentThread->Yield();
    printf("[*] delete %d element in thread %d\n", nodeNum, which);
    delHdrNode(newList, nodeNum, which);
    outListLock->Release();
}



void TestTable(int which) {
    int *object = new int, index;
    *object = data[which - 1];
    printf("add object %d to table in thread %d\n", *object, which);
    index = table->Alloc((void *)object);
    if (index != -1) {
        assert(((int *)table->Get(index))==object);
        printf("get object %d to table in thread %d\n", *(int *)(table->Get(index)), which);
        table->Release(index);
    }
}
 
void TestBoundedBuffer(int which) {
    // one is write and others is consumer the data 
    if (which == 1) {
        printf("produce begin in thread %d\n", which);
        buffer->Write((void *)data, 15);
    } else {
        printf("comsume begin in thread %d\n", which);
        int* consume = new int[which - 1];
        buffer->Read((void *)consume , which - 1); 
        printf("the datas from buffer in thread %d\n",which);
        for(int i = 0; i < which - 1; i++){
            printf("%d\n",consume[i]);
        }
        printf("consumer completed in thread %d\n", which);
    }
}


void 
toDllistTest(VoidFunctionPtr func)
{
    DEBUG('t', "Entering  toDllistTest\n");
    Thread *t;
    for(int i=0 ;i < threadNum ;i++) {
        t = new Thread("forked thread");
        t->Fork(func,i+1); 
    }
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
        toDllistTest(DLListTest1);
        break;
    case 2:
        toDllistTest(TestTable);
        break;
    case 3: 
        toDllistTest(TestBoundedBuffer);
        break;
    default:
        printf("No test specified.\n");
        break;
    }
}

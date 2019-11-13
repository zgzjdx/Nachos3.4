#include "BoundedBuffer.h"
#include "system.h"
#include <malloc.h>

// see threadtest.cc
extern int errorType;   // type of error
extern bool allowSynch; // whether allow using synchronous primitives or not

// create a bounded buffer with a limit of 'maxsize' bytes
BoundedBuffer::BoundedBuffer(int maxsize)
{
    maxSize = maxsize;
    buffer = (void *)malloc(maxsize);
    count = 0;
    nextin = nextout = 0;
    if (allowSynch)
    {
        notfull = new Condition("notfull cond");
        notempty = new Condition("notempty cond");
        lock = new Lock("condition lock");
    }
}
     
// destory bounded buffer
BoundedBuffer::~BoundedBuffer()
{
    free(buffer);
    if (allowSynch)
    {
        delete notfull;
        delete notempty;
        delete lock;
    }
}

// Thread which read 'size' bytes from the bounded buffer, storing into 'data'.
// ('size' may be greater than 'maxsize')
void BoundedBuffer::Read(void *data, int size, int which)
{
    for (int i = 0; i < size; ++i)
    {
        if (allowSynch)
        {
            lock->Acquire();
            while (count == 0)
                notempty->Wait(lock);
        }
        if (errorType == 1)
        {
            printf("Read: Switch to another thread!\n");
            currentThread->Yield();
        }
        *((char *)data + i) = *((char *)buffer + nextout);
        printf("Thread %d reads: %c\n", which, *((char *)data + i));
        if (errorType == 2)
        {
            printf("Read: Switch to another thread!\n");
            currentThread->Yield();
        }
        nextout = (nextout + 1) % maxSize;
        count--;
        if (allowSynch)
        {
            notfull->Signal(lock);
            lock->Release();
        }
    }
}
     
// Thread which write 'size' bytes from 'data' into the bounded buffer.
// ('size' may be greater than 'maxsize')
void BoundedBuffer::Write(void *data, int size, int which)
{
    for (int i = 0; i < size; ++i)
    {
        if (allowSynch)
        {
            lock->Acquire();
            while (count == maxSize)
                notfull->Wait(lock);
        }
        if (errorType == 11)
        {
            printf("Write: Switch to another thread!\n");
            currentThread->Yield();
        }
        *((char *)buffer + nextin) = *((char *)data + i);
        printf("Thread %d writes: %c\n", which, *((char *)data + i));
        if (errorType == 12)
        {
            printf("Write: Switch to another thread!\n");
            currentThread->Yield();
        }
        nextin = (nextin + 1) % maxSize;
        count++;
        if (allowSynch)
        {
            notempty->Signal(lock);
            lock->Release();
        }
    }
}


// Following codes are implementation of semBoundedBuffer

// create a bounded buffer with a limit of 'maxsize' bytes
semBoundedBuffer::semBoundedBuffer(int maxsize)
{
    semmaxSize = maxsize;
    sembuffer = (void *)malloc(maxsize);
    semnextin = semnextout = 0;
    if (allowSynch)
    {
        s = new Lock("lock s");
        n = new Semaphore("semaphore n", 0);
        e = new Semaphore("semaphore e", maxsize);
    }
}

// destory bounded buffer
semBoundedBuffer::~semBoundedBuffer()
{
    delete sembuffer;
    if (allowSynch)
    {
        delete s;
        delete n;
        delete e;
    }
}

// Thread which read 'size' bytes from the bounded buffer, storing into 'data'.
// ('size' may be greater than 'maxsize')
void semBoundedBuffer::semRead(void *data, int size, int which)
{
    for (int i = 0; i < size; ++i)
    {
        if (allowSynch)
        {
            n->P();
            s->Acquire();
        }
        if (errorType == 1)
        {
            printf("semRead: Switch to another thread!\n");
            currentThread->Yield();
        }
        *((char *)data + i) = *((char *)sembuffer + semnextout);
        printf("Thread %d reads: %c\n", which, *((char *)data + i));
        if (errorType == 2)
        {
            printf("semRead: Switch to another thread!\n");
            currentThread->Yield();
        }
        semnextout = (semnextout + 1) % semmaxSize;
        if (allowSynch)
        {
            s->Release();
            e->V();
        }
    }
}

// Thread which write 'size' bytes from 'data' into the bounded buffer.
// ('size' may be greater than 'maxsize')
void semBoundedBuffer::semWrite(void *data, int size, int which)
{
    for (int i = 0; i < size; ++i)
    {
        if (allowSynch)
        {
            e->P();
            s->Acquire();
        }
        if (errorType == 11)
        {
            printf("semWrite: Switch to another thread!\n");
            currentThread->Yield();
        }
        *((char *)sembuffer + semnextin) = *((char *)data + i);
        printf("Thread %d writes: %c\n", which, *((char *)data + i));
        if (errorType == 12)
        {
            printf("semWrite: Switch to another thread!\n");
            currentThread->Yield();
        }
        semnextin = (semnextin + 1) % semmaxSize;
        if (allowSynch)
        {
            s->Release();
            n->V();
        }
    }
}

/*

Implementation of Table.

*/
#include "Table.h"
#include "system.h"
#include <malloc.h>
#include <stdio.h>

// see threadtest.cc
extern int errorType;   // type of error
extern bool allowSynch; // whether allow using synchronous primitives or not

// create a table to hold at most 'size' entries.
Table::Table(int size)
{
    tableSize = size;
    // allocate memory
    if ( (table = (void **)malloc(tableSize * sizeof(void *))) == NULL)
    {
        perror("Table::Table");     // fail to create table
    }
    // initialize each slot with NULL
    memset(table, NULL, tableSize * sizeof(void *));
    if (allowSynch)
        lock = new Lock("table lock");
}


// delete table
Table::~Table()
{
    free(table);
    if (allowSynch)
        delete lock;
}


// allocate a table slot for 'object'.
// return the table index for the slot or -1 on error.
int Table::Alloc(void *object)
{
    int index;
    if (allowSynch)
        lock->Acquire();

    // find first unallocated entry
    for (index = 0; index < tableSize && table[index] != NULL; ++index);

    if (index < tableSize)      // has space, insert it into table
    {
        if (errorType == 1)
        {
            printf("Alloc: Switch to another thread!\n");
            currentThread->Yield();
        }
        table[index] = object;
        if (errorType == 2)
        {
            printf("Alloc: Switch to another thread!\n");
            currentThread->Yield();
        }

        if (allowSynch)
            lock->Release();
        return index;
    }
    else                        // no space to allcoate
    {
        if (errorType == 3)
        {
            printf("Alloc: Switch to another thread!\n");
            currentThread->Yield();
        }
        if (allowSynch)
            lock->Release();
        return -1;
    }
}


// return the object from table index 'index' or NULL on error.
// (assert index is in range).  Leave the table entry allocated
// and the pointer in place.
void *Table::Get(int index)
{
    void *item;

    ASSERT (index >= 0 && index < tableSize);
    if (allowSynch)
        lock->Acquire();
    item = table[index];
    if (errorType == 11)
    {
        printf("Get: Switch to another thread!\n");
        currentThread->Yield();
    }
    if (allowSynch)
        lock->Release();

    return item;
}


// free a table slot
void Table::Release(int index)
{
    ASSERT (index >= 0 && index < tableSize);

    if (allowSynch)
        lock->Acquire();
    table[index] = NULL;
    if (allowSynch)
        lock->Release();
}

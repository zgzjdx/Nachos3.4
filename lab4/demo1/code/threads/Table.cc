// Table.cc
//     Implement a simple fixed-size table,a common kernel data.
//     You can get the details in the Table.h
// 07-05-11

#include <iostream>
#include "Table.h"

using namespace std;


//------------------------------------------------------------------
// Table::Table
//     create a table to hold at most 'size' entries.        
//------------------------------------------------------------------
Table::Table(int size) 
{
    Size = size;           // max 
    tableHead = new void* [size];    // array for objects
    lock = new Lock_sleep("TableLock");    // lock for table operations

    for (int i = 0; i < size; i++ ) 
        tableHead[i] = NULL;
}

//------------------------------------------------------------------
// Table::Table
//     disallocate the Table        
//------------------------------------------------------------------
Table::~Table() 
{
    delete tableHead; 
}
//------------------------------------------------------------------
// Table::Alloc
//     Allocate a table slot for 'object'
//     Return the table index for the slot or -1 on error.
//------------------------------------------------------------------
int
Table::Alloc(void *object)
{   
    int i;

    lock->Acquire();             // avoid calling while allocing
                                 // or Releasing
    for (i = 0; (tableHead[i] != NULL) && (i < Size); i++ )
        ;                        // find current insert position
    if (i != Size) {
        tableHead[i] = object;
        lock->Release();
        return i; 
    } else {
        lock->Release();
        return -1;
    }
}

//------------------------------------------------------------------
// Table::Get
//     Return the object from table index 'index' or NULL on error.
//     (assert index is in range). Leave the table entry allocated
//     and the pointer in place.        
//------------------------------------------------------------------
void*
Table::Get(int index)
{
    void* tmp;

    lock->Acquire();             // avoid calling while allocing
                                 // or Releasing
    if (index < 0 || index >= Size) {
        lock->Release();  
        return NULL;               // out of range
    } else {
        tmp = tableHead[index];  // store 
        lock->Release();
    }
    
    return tmp;    
}
        
//------------------------------------------------------------------
// Table::Release
//     Free a table slot.   
//------------------------------------------------------------------
void 
Table::Release(int index)
{
    lock->Acquire();             // avoid calling while allocing
                                 // or Releasing
//    ASSERT(index < 0 || index >= size); 

    // because Release cannot return a value
    if (index < 0 || index >= Size) {
        cout<<"Out of range!!\n"
            <<"The range is [0,"<<Size-1<<"]"
            <<endl;
        lock->Release();
        return; 
    } else {
        tableHead[index] = NULL;
        lock->Release();
    }     
}




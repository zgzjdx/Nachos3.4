// memorymanager.cc
//    implement of the memory manager module.

#include <iostream>
#include "machine.h"
#include "memorymanager.h"

using namespace std;

//----------------------------------------------------------------
// MemoryManager::MemoryManager
//     initialization of MemoryManager.
//----------------------------------------------------------------

MemoryManager::MemoryManager()
{
    bitTable = new BitMap(NumPhysPages);
}

//----------------------------------------------------------------
// MemoryManager::~MemoryManager
//     disconstructor
//----------------------------------------------------------------

MemoryManager::~MemoryManager()
{
    delete bitTable;
}

//----------------------------------------------------------------
// MemoryManager::mark
//     mark a page frame with specific process
//----------------------------------------------------------------
void 
MemoryManager::mark(int pageNum)
{
    bitTable->Mark(pageNum);
}

//----------------------------------------------------------------
// MemoryManager::free
//     clear the mark of a frame
//----------------------------------------------------------------
void
MemoryManager::free(int pageNum)
{
    bitTable->Clear(pageNum);
}

//----------------------------------------------------------------
// MemoryManager::busy
//     is the page in use?
//----------------------------------------------------------------
void
MemoryManager::busy(int pageNum)
{
}

//----------------------------------------------------------------
// MemoryManager::print
//     print the number of the allocated page frames
//----------------------------------------------------------------
void MemoryManager::print()
{
    cout << "-- Used PhysMem pages' number:" << endl;
    for (int i = 0; i < NumPhysPages; i++) {
         if (test(i))
              cout << i << " ";
    }
    cout << endl;
}

//----------------------------------------------------------------
// MemoryManager::test
//     dirty or not
//----------------------------------------------------------------
bool
MemoryManager::test(int pageNum)
{
    return bitTable->Test(pageNum);
}

//----------------------------------------------------------------
// MemoryManager::nextFree
//     find a free page, and mark it
//----------------------------------------------------------------
int
MemoryManager::nextFree()
{
    return bitTable->Find();
}

//----------------------------------------------------------------
// MemoryManager::numFree
//     return the counter of total free framse
//----------------------------------------------------------------
int 
MemoryManager::numFree()
{ 
    return bitTable->NumClear();
}



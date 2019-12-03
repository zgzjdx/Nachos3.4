// memorymanager.h
//     we define the memory manager here.
//     we can use this module to allow kernel to allocate
//     page frames from simulated machine's memory for specific
//     processes, and to keep track of whick frames are free 
//     and which are in use.(we use bitmap to record)

#include "bitmap.h"

class MemoryManager {
  public:
    MemoryManager();
    ~MemoryManager();

    void mark(int pageNum);          // allocate
    void free(int pageNum);          // free a frame
    void busy(int pageNum);          // in using ?
    void print();         // current states of the allcated frames

    bool test(int pageNum);          // dirty or not

    int  nextFree();      // find a free frame, and mark it 
    int  numFree();       // number of total free framse

  private:
    BitMap * bitTable; 
};


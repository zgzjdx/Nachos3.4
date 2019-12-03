#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "syscall.h"
#include "thread.h"
#include "Table.h"
//#include "synch-sleep"
#define MAXPROCESS 100

typedef struct processCB {
    int spaceId;
    int numWait;
    int parent;
    int exitCode;
    Lock_sleep *lock;
    Condition_sleep *wait;
}PCB;

class ProcessManager {
  public:
    ProcessManager();
    ~ProcessManager();

    // the process ID table
    int  Alloc(PCB *object);
    PCB *Get(int spaceId);
    void Release(int id);

    void AdjustPCRegs(); // increase the pc after returns
  private:
    Table *processTable;
};
#endif


// processmanager.cc

#include <iostream>
#include "processmanager.h"
#include "system.h"
#include <stdio.h>
using namespace std;

//----------------------------------------------------------------------
// newProcess
//     fork will call this to run
//----------------------------------------------------------------------

void  
newProcess(int arg)
{
    OpenFile *executable = fileSystem->Open((char *)arg);
    AddrSpace *space;

    if (executable == NULL) {
        cout << "-- Unable to open file " << endl;
        puts((char *)arg);
        return;
    }

    space = new AddrSpace(executable);
    space->NewPages();
    currentThread->space = space;
 
    delete executable;

    space->InitRegisters();
    space->RestoreState();

    machine->Run();
    //currentThread->Yield();
    return;
}



//----------------------------------------------------------------------
// createProcess
//     set up PCB and space address then fork a thread(run newProcess)
//----------------------------------------------------------------------

int
createProcess(char *execFile)
{
    int id;
    PCB * pcb = new PCB;    
    Thread *t = new Thread("Process fork");
    
    id = pM->Alloc(pcb);

    if (id == -1) {
        cout << "-- The process manager Table is full!" << endl;
        return -1;
    }
    
    pcb->numWait = 0;
    pcb->spaceId = id; 
    pcb->parent  = currentThread->id;
    pcb->exitCode= 999;
    pcb->lock = new Lock_sleep("process");
    pcb->wait = new Condition_sleep("process");
    t->id = id;
     
    cout << "-- Create a new process, ID : " << id  << endl;
    t->Fork(newProcess, (int)execFile);
    currentThread->Yield();
    
    return id; 
}

//----------------------------------------------------------------------
// Exec
//     get the file name argument and run a process
//----------------------------------------------------------------------

int 
new_Exec(char *name)
{
    cout << "-- System Call : Exec" << endl;
    return createProcess(name);
}

//----------------------------------------------------------------------
// Exit
//     this user program is done(status = 0 means exited normally)
//     we put the return status in REG 2
//----------------------------------------------------------------------

void
new_Exit(int status)
{
    cout << "-- System Call : Exit!" << endl;
    
    cout << "-- Process id : "  << currentThread->id 
         << ", Process returns : " << status
         << endl;

    machine->WriteRegister(2, status); 

    PCB *pcb = pM->Get(currentThread->id);
  
    if (pcb != NULL) {    
	pcb->exitCode = status;
    	if (pcb->wait) {                      // wake up the process     
	    pcb->lock->Acquire();               //    wait on join
            pcb->wait->Broadcast(pcb->lock);
            pcb->lock->Release();                       
 	} else    { 
	    pM->Release(currentThread->id); 
}
    }

    int tmp;
    for (int j=0; j < currentThread->space->numPages; j++) {
         tmp = currentThread->space->physPages(j);
         memM->free(tmp);
    }

    delete currentThread->space;
    //memM->print();
    currentThread->Finish();
}

//----------------------------------------------------------------------
// Join
//     Only return once the user programe "id" has finished.
//     Return the exit status
//----------------------------------------------------------------------

int
new_Join(int id)
{
    //PCB *pcb = Get(currentThread->id);
    cout << "-- System Call : Join" << endl;
    PCB *waitPCB = pM->Get(id);
    
    if (waitPCB == NULL) {           // already finished or null
        cout << "     the PCB is NULL!" << endl
             << "     the process waited for had returned!" << endl;
        return -1;
    }
  
    if (waitPCB->exitCode == 999) {
        waitPCB->lock->Acquire();
        waitPCB->wait->Wait(waitPCB->lock);
        waitPCB->lock->Release();
    }
   
    pM->Release(id);
    return waitPCB->exitCode;
}

// methods
//----------------------------------------------------------------------
// ProcessManager::ProcessManager
//----------------------------------------------------------------------

ProcessManager::ProcessManager()    
{
    processTable = new Table(MAXPROCESS);
}

//----------------------------------------------------------------------
// ProcessManager::~ProcessManager
//----------------------------------------------------------------------

ProcessManager::~ProcessManager()
{
   delete processTable;
}

//----------------------------------------------------------------------
// ProcessManager::Alloc
//     store a new process PCB pointer, and return the spaceId
//----------------------------------------------------------------------

int
ProcessManager::Alloc(PCB *object)
{
    return processTable->Alloc((void *)object);
}

//----------------------------------------------------------------------
// ProcessManager::Get
//     get the process's PCB pointer
//----------------------------------------------------------------------

PCB *
ProcessManager::Get(int spaceId)
{
    return (PCB *)processTable->Get(spaceId);
}

//----------------------------------------------------------------------
// ProcessManager::Release
//     call the method when the process is exiting
//----------------------------------------------------------------------

void 
ProcessManager::Release(int spaceId)
{
    processTable->Release(spaceId);
}

//----------------------------------------------------------------------
// ProcessManager::AdjustPCRegs
//     increment the pc before system calls return
//----------------------------------------------------------------------

void 
ProcessManager::AdjustPCRegs()
{
    int pc;
  
    pc = machine->ReadRegister(PCReg);
    machine->WriteRegister(PrevPCReg, pc);
    pc = machine->ReadRegister(NextPCReg);
    machine->WriteRegister(PCReg, pc);
    pc += 4;
    machine->WriteRegister(NextPCReg, pc);
    
    cout << endl;
}


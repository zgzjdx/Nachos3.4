// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#define BufferMax 30
extern ProcessManager*Pm;
//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------
int ReadFile(char*buff,int address,int length)
{
    int i;
    for(i=0;i<length;i++,address++)
    {
	if(!machine->ReadMem(address,1,(int*)&(buff[i])))
	{
	    printf("Read Mem Failure\n");
	    return false;
	}
	if(buff[i]=='\0')
	    break;
    }
    if(i==length)
    {
	printf("The name too long");
	return false;
    }
    return true;
}
void AdjustPCRegs()
{
    int pc;
    pc=machine->ReadRegister(PCReg);
    machine->WriteRegister(PrevPCReg,pc);
    pc=machine->ReadRegister(NextPCReg);
    machine->WriteRegister(PCReg,pc);
    pc+=4;
    machine->WriteRegister(NextPCReg,pc);
}
void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);
    int arg1,id,status;
    char filename[BufferMax];

    if ((which == SyscallException) ) {
	switch(type)
	{
	    case SC_Halt:
    	    DEBUG('a', "Shutdown, initiated by user program.\n");
    	    interrupt->Halt();
	    break;
	    case SC_Exec:
	    arg1=machine->ReadRegister(4);
	    if(!ReadFile(filename,arg1,BufferMax))
	    {
		printf("failure");
		currentThread->Finish();
	    }
	    id=Pm->Exec(filename);
	    machine->WriteRegister(2,id);
	    AdjustPCRegs();
	    break;
	    case SC_Exit:
	    printf("Process %d End\n",currentThread->space->GetSpaceid());
	    arg1=machine->ReadRegister(4);
	    Pm->Exit(arg1);
	    break;
	    case SC_Join:
	    arg1=machine->ReadRegister(4);
	    status=Pm->Join(arg1);
	    printf("Process %d exit with Status %d\n",arg1,status);
	    machine->WriteRegister(2,status);
	    AdjustPCRegs();
	    break;
	    case SC_Print:
	    arg1=machine->ReadRegister(4);
	    if(!ReadFile(filename,arg1,BufferMax))
	    {
		printf("Failed to read string \n");
		machine->WriteRegister(2,-1);
	    }
	    printf("%s",filename);
	    AdjustPCRegs();
	    break;
	    default:
	    break;
	}
    } else {
	printf("Unexpected user mode exception %d %d\n", which, type);
	ASSERT(FALSE);
    }
}

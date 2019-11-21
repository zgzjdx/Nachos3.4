#include "EventBarrier.h"
#include "system.h"
EventBarrier::EventBarrier()
{
	status = false; 
	waitNum = 0; 
	value = 0;
	barrierLock = new Lock("barrier Lock");
	signal_con = new Condition("singal conditon");
	complete_con = new Condition("complete condition");
}

EventBarrier::~EventBarrier()
{
	delete barrierLock;
	delete signal_con;
	delete complete_con;
}

void
EventBarrier::Wait()
{
	barrierLock->Acquire();
	if(status == false){
		waitNum++;
		signal_con->Wait(barrierLock);
		waitNum--; 
	}
	barrierLock->Release();
}	

void
EventBarrier::Signal()
{// only one can call signal 
	DEBUG('t',"[EB] in EventBarrier signal\n");
	barrierLock->Acquire();
	status = true;
	if(waitNum!=0){
		// wake up other waiters
		signal_con->Broadcast(barrierLock);
		// blocked in complete condition 
		complete_con->Wait(barrierLock);
	}else{
		// if no one, just continue 
		status = false;
	}
	// resum the status of barrier	

	//changeStatus_con->Broadcast(barrierLock);
	// wake up the wating status change
	// make sure other wait one call wait another time
	//changeStatus_con->Broadcast(barrierLock); 
	barrierLock->Release();
	DEBUG('t',"[EB] out EventBarrier signal\n");
}

void
EventBarrier::Complete()
{
	barrierLock->Acquire();
	
	if(waitNum== 0){// is "if" suitable? 
		// the last one to release lock
		status = false;// change status 
		complete_con->Broadcast(barrierLock);
		//changeStatus_con->Wait(barrierLock);// make sure status change

	}else{
		// no the last one 
		complete_con->Wait(barrierLock);
		//changeStatus_con->Wait(barrierLock);
	}
	barrierLock->Release();
}

int
EventBarrier::Waiters()
{
	barrierLock->Acquire();
	int num = waitNum;
	barrierLock->Release();
	return num;
}





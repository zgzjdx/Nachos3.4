#include "synch.h"
#include "list.h"

#ifndef EVENTBARRIER_H
#define EVENTBARRIER_H

class EventBarrier {
	public:
		
		EventBarrier();// constructor

		~EventBarrier(); // destuctor

		void Wait();//Wait until the event is signaled.
					//if already in the signaled state,return immediately 

		
		void Signal();/*Signal the event and block until all threads 
						that wait for this event have responded. The
						EventBarrier reverts to the unsignaled state when Signal() returns.*/
		
		void Complete();/*Indicate that the calling thread has finished 
						responding to a signaled event, and block
						until all other threads that wait for this
						event have also responded*/
		
		int Waiters();/*Return a count of threads that are waiting 
						for the event or that have not yet responded to
						it.*/
	private:
		bool status;// true means barrier opening, false means barrier closed
		int waitNum; // the num of waiting thread
		int value; // same to Semaphore , record the num of operation of signal;
		Lock *barrierLock;
		Condition *signal_con;
		Condition *complete_con; 
};


#endif

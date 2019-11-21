 #include "synch.h"

#ifndef EVENTBARRIER_H
#define EVENTBARRIER_H

class EventBarrier {
	public:
		EventBarrier();
		~EventBarrier(); 

		void Wait();    // Wait 直到事件 signaled. 如果已经在 signaled 状态, 这立即返回

		void Signal();	// 对事件发出 Signal 并进入阻塞队列, 直到所有正等待该事件的线程都已响应(才解除阻塞). 
						// 当`Signal()`返回, EventBarrier需要重新恢复成初始态(unsignaled state)
		
		void Complete();	// 表明调用线程已经完成对事件的相应, 并进行阻塞, 直到其他所有等待该事件的线程也都响应为止.
		
		int Waiters();	// 返回正在等待事件, 或尚未对事件响应的线程数目.
	private:
		bool barrierIsOpen;    // 栅栏开启, 为true; 关闭, 为false
		int waitNum; // 正在等待的线程数量
		int semaphore_value; // same to Semaphore , record the num of operation of signal;
		Lock *barrier_lock;
		Condition *signal_cond;
		Condition *complete_cond; 
};

#endif
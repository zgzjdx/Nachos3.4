#include "EventBarrier.h"
#include "system.h"

EventBarrier::EventBarrier() {
	barrierIsOpen = false; // 默认关闭 
	waitNum = 0;    // 初始等待线程数量为 0 
	semaphore_value = 0;  // 初始化 信号量
	barrier_lock = new Lock("barrier Lock");    
	signal_cond = new Condition("singal conditon");
	complete_cond = new Condition("complete condition");
}

EventBarrier::~EventBarrier() {
	delete barrier_lock;
	delete signal_cond;
	delete complete_cond;
}

void EventBarrier::Wait() {
	barrier_lock->Acquire();
	if (barrierIsOpen == false) {
        // 调用线程 陷入等待直到被唤醒
		waitNum++;
		signal_cond->Wait(barrier_lock);
		waitNum--; 
	}
    // 栅栏已处于开放状态, 直接返回
	barrier_lock->Release();
}	

// 由 控制栅栏的线程 调用
void EventBarrier::Signal() {
	barrier_lock->Acquire();
	barrierIsOpen = true;
	if (waitNum != 0) {   
        // 唤醒 当前正在等待的所有线程
		signal_cond->Broadcast(barrier_lock);
		// 陷入等待 直到线程已被全部唤醒
		complete_cond->Wait(barrier_lock);
	} else {
		barrier_lock = false;
	}
	barrier_lock->Release();
}

// 从Wait返回(被唤醒)后应接着调用Complete
// 随后陷入另一种等待直到所有线程都被唤醒
void EventBarrier::Complete() {
	barrier_lock->Acquire();
	if (waitNum == 0) { // 所有线程都被唤醒
		// 最后一个线程需要释放锁
		barrierIsOpen = false;
		complete_cond->Broadcast(barrier_lock);
	} else {
		// 等待 直到线程已被全部唤醒
		complete_cond->Wait(barrier_lock);
	}
	barrier_lock->Release();
}

// 返回当前处于等待(或尚未被唤醒)的线程数量
// 用来标记线程是否已被全部唤醒
int EventBarrier::Waiters() {
	barrier_lock->Acquire();
	int num = waitNum;
	barrier_lock->Release();
	return num;
}
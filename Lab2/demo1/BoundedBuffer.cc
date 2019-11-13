#include "BoundedBuffer.h"
#include "system.h"
#include "synch.h"

extern int testnum; 

BoundedBuffer::BoundedBuffer(int maxsize) {
	monitor_lock  = new Lock("into buffer lock");	
	// condition for buffer empty
	not_full = new Condition("buffer full cond");
	not_empty = new Condition("buffer empty cond");
	buffer = new int[maxsize];
	maxSize = maxsize;
	readFrom = 0; // read position 
	writeTo = 0; // write position 
	hasCount = 0;
}

BoundedBuffer::~BoundedBuffer() {
	delete monitor_lock;
	delete not_full;
	delete not_empty;
	delete[] buffer;
}

void BoundedBuffer::Read(void *data, int size) {
	
	int *readData = (int *)data;
	while (size!=0) {
		// learn from others on net but he's paper still have many mistakes
		// condition for buffer empty
		// monitor Field
		monitor_lock->Acquire();
		while (hasCount == 0) {
			not_empty->Wait(monitor_lock);
		}
		*readData++ = buffer[readFrom]; 
		// printf("get %d from buffer\n", buffer[readFrom]);
		readFrom = (readFrom + 1) % maxSize; 
		hasCount--;
		not_full->Broadcast(monitor_lock); 	
		size--;
		monitor_lock->Release();
	}
}

void BoundedBuffer::Write(void *data, int size) {
	int* writeData  = (int *)data;
	while (size != 0) {
		monitor_lock->Acquire();
		//condition for buffer full
		while (hasCount == maxSize) {
			not_full->Wait(monitor_lock);
		}
		buffer[writeTo] = *writeData++;
		// printf("put %d to buffer\n",buffer[writeTo]);
		writeTo = (writeTo + 1) % maxSize;
		hasCount++;
		// to broadcast other readers
		not_empty->Broadcast(monitor_lock);
		size--;
		monitor_lock->Release();
	}
}
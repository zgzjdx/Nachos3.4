#include "Table.h"
#include "system.h"
#include <cstring>
#include "synch.h"
#include <assert.h>

extern int testnum; 

Table::Table(int size) {
	num = size;
	left = size;
	table = new void*[size];
	memset(table, 0, sizeof(void *)*size); 
	curr = 0;
	lock = new Lock("table lock");
}


Table::~Table() {
	delete[] table;
	delete lock;
}

int Table::Alloc(void *object) {
	lock->Acquire();

	if (testnum == 2) {
		currentThread->Yield();
	}

	if (!left) {
		return -1; 
	} else { 
        // find right place to insert data
		while (table[curr]) {
			curr = (curr+1) % num;
		}
		table[curr] = object;
		curr = (curr+1) % num;
		left--;
	}
	lock->Release();
	return curr - 1;
}

void 
Table::Release(int index)
{
	ASSERT(index < num && index > -1);
	lock->Acquire();
	table[index] = NULL;
	lock->Release();
}


void *
Table::Get(int index)
{
	ASSERT(index < num && index > -1);
	lock->Acquire();

	if (testnum == 2) { 
		currentThread->Yield();
	}


	void* r = table[index]; 
	lock->Release();
	return r;
}
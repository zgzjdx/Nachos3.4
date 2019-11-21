#include "dllist.h"
#include "system.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


// a list of the keys inserted into doubly-linked list, just for test
const int keyList[10] = {12, 3, 9, 22, 1, 11, 33, 2, 44, 13};


// generate a random number between 0~99
extern int getRandom()
{
	struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);
    return ((tv.tv_usec * 2 + 1) % 100);
}


// insert N items into L
extern void Insert(DLList *L, int N, int whichThread)
{
	int key;
	for (int i = 0; i < N; ++i)
	{
		key = getRandom();
		L->SortedInsert(NULL, key);
		printf("Thread %d inserts: %d\n", whichThread, key);
	}
}


// remove N items starting from the head of the list
//   and print out the removed items to the console
extern void Remove(DLList *L, int N, int whichThread)
{
	int key;
	int count = N;
	
	while (L->IsEmpty() && count)
	{
		L->Remove(&key);
		--count;
		printf("Thread %d removes: %d\n", whichThread, key);
	}
}

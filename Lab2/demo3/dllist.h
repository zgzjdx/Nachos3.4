#ifndef DLLIST_H
#define DLLIST_H

#include "synch-sem.h"      // use synch-sleep.h when testing section 1.1
                            // use synch-sem.h when testing section 1.2

class DLLElement {
public:
	DLLElement( void *itemPtr, int sortKey );	// initialize a list element
	
	DLLElement *next;			// next element on list
								// NULL if this is the last
	DLLElement *prev;			// previous element on list
								// NULL if this is the first
	
	int key;					// priority, for a sorted list
	void *item;					// pointer to item on the list
};

class DLList {
public:
	DLList();					// initialize the list
	~DLList();					// de-allocate the list

	void Prepend(void *item);	// add to head of list (set key = min_key-1)
	void Append(void *item);	// add to tail of list (set key = max_key+1)
	void *Remove(int *keyPtr);	// remove from head of list
								// set *keyPtr to key of the removed item
								// return item (or NULL if list is empty)

	bool IsEmpty(); // return true if list has elements
	
	// routines to put/get items on/off list in order (sorted by key)
	void SortedInsert(void *item, int sortKey);
	void *SortedRemove(int sortKey);	// remove first item with key==sortKey
										// return NULL if no such item exists
private:
	DLLElement *first;			// head of the list, NULL if empty
	DLLElement *last;			// last element of the list, NULL if empty

public:
	// enforce mutual exclusive access to the list
	Lock *lock;
	// wait if the list is empty
	Condition *listEmpty;
	// wait if the list is full
	Condition *listFull;
	// number of items inserted into list
	int count;
};

#endif


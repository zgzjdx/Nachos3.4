#include "dllist.h"
#include <stdio.h>
#include "system.h"


// reference for threadtest.cc
extern int errorType;


/** DLLElement class */
// initialize a list element
DLLElement::DLLElement(void *itemPtr, int sortKey)
{
	item = itemPtr;
	key = sortKey;
	next = prev = NULL;
}



/** DLList class */
// initialize the list
DLList::DLList()
{
	first = last = NULL;
	lock = new Lock("list lock");
    listEmpty = new Condition("list empty cond");
    listFull = new Condition("list full cond");
    count = 0;
}


// de-allocate the list
DLList::~DLList()
{
	int key;
	while (IsEmpty())
	{
		Remove(&key);
	}
	delete lock;
	delete listEmpty;
	delete listFull;
}


// add to head of list (set key = min_key-1)
void DLList::Prepend(void *item)
{
	DLLElement *element = new DLLElement(item, 0);
	
	if (!IsEmpty())		// list is empty
	{
		first = last = element;
	}
	else				// otherwise
	{
		element->key = first->key - 1;
		element->next = first;
		first->prev = element;
		first = element;
	}
}


// add to tail of list (set key = max_key+1)
void DLList::Append(void *item)
{
	DLLElement *element = new DLLElement(item, 0);
	
	if (!IsEmpty())		// list is empty
	{
		first = last = element;
	}
	else				// otherwise
	{
		element->key = last->key + 1;
		element->prev = last;
		last->next = element;
		last = element;
	}
}


// remove from head of list
//   set *keyPtr to key of the removed item
//   return item (or NULL if list is empty)
void* DLList::Remove(int *keyPtr)
{
	if (errorType == 101)	// out of order //
	{
		printf("Remove: Switch to another thread!\n");
		currentThread->Yield();
	}
	
	if (!IsEmpty())		// list is empty
	{
		keyPtr = NULL;
	}
	else				// otherwise
	{
		void *itemPtr;
		DLLElement *element;
		
		if (errorType == 102)	// out of order //
		{
			printf("Remove: Switch to another thread!\n");
			currentThread->Yield();
		}
		*keyPtr = first->key;
		itemPtr = first->item;
		element = first;
		if (errorType == 103)	// segment fault //
		{
			printf("Remove: Switch to another thread!\n");
			currentThread->Yield();
		}
		
		if (first->next)	// has more than one element
		{
			if (errorType == 104)	// segment fault //
			{
				printf("Remove: Switch to another thread!\n");
				currentThread->Yield();
			}
			first->next->prev = NULL;
			if (errorType == 105)	// segment fault // 
			{
				printf("Remove: Switch to another thread!\n");
				currentThread->Yield();
			}
			first = first->next;
			if (errorType == 106)	// out of order //
			{
				printf("Remove: Switch to another thread!\n");
				currentThread->Yield();
			}
		}
		else				// only one element in the list
		{
			if (errorType == 107)	// out of order //
			{
				printf("Remove: Switch to another thread!\n");
				currentThread->Yield();
			}
			first = last = NULL;
		}
		if (errorType == 108)	// out of order //
		{
			printf("Remove: Switch to another thread!\n");
			currentThread->Yield();
		}
		delete element;
		if (errorType == 109)	// out of order //
		{
			printf("Remove: Switch to another thread!\n");
			currentThread->Yield();
		}
	}
}


// return true if list has elements
bool DLList::IsEmpty()
{
	if (first == NULL && last == NULL)
		return false;
	else
		return true;
}


// routines to put/get items on/off list in order (sorted by key)
void DLList::SortedInsert(void *item, int sortKey)
{
	DLLElement *element = new DLLElement(item, sortKey);
	
	if (errorType == 1)		// switch before insertion //
	{
		printf("SortedInsert: Switch to another thread!\n");
		currentThread->Yield();
	}
	
	// list is empty
	if (!IsEmpty())
	{
		first = last = element;
		if (errorType == 2)		// after insert first element //
		{
			printf("SortedInsert: Switch to another thread!\n");
			currentThread->Yield();
		}

		return;
	}
	
	if (errorType == 3)		// switch in 2nd insertion and later //
	{
		printf("SortedInsert: Switch to another thread!\n");
		currentThread->Yield();
	}
	
	// insert at the top
	if (sortKey <= first->key)
	{
		if (errorType == 4)		// in 2nd insertion and later //
		{
			printf("SortedInsert: Switch to another thread!\n");
			currentThread->Yield();
		}
		element->next = first;
		if (errorType == 5)		// link list is damaged //
		{
			printf("SortedInsert: Switch to another thread!\n");
			currentThread->Yield();
		}
		first->prev = element;
		if (errorType == 6)		// sometimes let segment fault, or miss an item //
		{
			printf("SortedInsert: Switch to another thread!\n");
			currentThread->Yield();
		}
		first = element;
		if (errorType == 7)		// switch after second insertion, but not return //
		{
			printf("SortedInsert: Switch to another thread!\n");
			currentThread->Yield();
		}

		return;
	}
	
	if (errorType == 8)		// segment fault or switch in last thread but successfully //
	{
		printf("SortedInsert: Switch to another thread!\n");
		currentThread->Yield();
	}
	
	// inner node
	DLLElement *ptr = first;
	if (errorType == 9)		// segment fault or out of order or successful //
	{
		printf("SortedInsert: Switch to another thread!\n");
		currentThread->Yield();
	}
	while (ptr)
	{
		if (errorType == 10) // segment fault or out of order //
		{
			printf("SortedInsert: Switch to another thread!\n");
			currentThread->Yield();
		}
		if (ptr->key >= sortKey)	// insert before this node
		{
			if (errorType == 11)	// usually successful but sometimes segment fault //
			{
				printf("SortedInsert: Switch to another thread!\n");
				currentThread->Yield();
			}
			element->next = ptr;
			if (errorType == 12)	// usually successful but sometimes segment fault //
			{
				printf("SortedInsert: Switch to another thread!\n");
				currentThread->Yield();
			}
			element->prev = ptr->prev;
			if (errorType == 13)	// usually successful but sometimes segment fault //
			{
				printf("SortedInsert: Switch to another thread!\n");
				currentThread->Yield();
			}
			ptr->prev->next = element;
			if (errorType == 14)	// sometimes out of order //
			{
				printf("SortedInsert: Switch to another thread!\n");
				currentThread->Yield();
			}
			ptr->prev = element;
			if (errorType == 15)	// sometimes out of order //
			{
				printf("SortedInsert: Switch to another thread!\n");
				currentThread->Yield();
			}

			return;
		}
		if (errorType == 16)	// maybe out of order or segment fault //
		{
			printf("SortedInsert: Switch to another thread!\n");
			currentThread->Yield();
		}
		ptr = ptr->next;
		if (errorType == 17)	// maybe segment fault, or out of order, but successful occasionally //
		{
			printf("SortedInsert: Switch to another thread!\n");
			currentThread->Yield();
		}
	}
	
	if (errorType == 18)	//maybe out of order, segment fault, or so lucky to see success //
	{
		printf("SortedInsert: Switch to another thread!\n");
		currentThread->Yield();
	}
	
	// insert at the bottom
	last->next = element;
	if (errorType == 19)	// I have seen segment fault, out of order, and success luckily //
	{
		printf("SortedInsert: Switch to another thread!\n");
		currentThread->Yield();
	}
	element->prev = last;
	if (errorType == 20)	// out of order, segment fault, and successful at some time //
	{
		printf("SortedInsert: Switch to another thread!\n");
		currentThread->Yield();
	}
	last = element;
	if (errorType == 21)	// out of order, successful sometimes... //
							//   cannot believe that it's the last error... 
							//   why can we find so many error here... whyyyyyyyyyy
	{
		printf("SortedInsert: Switch to another thread!\n");
		currentThread->Yield();
	}
}


// remove first item with key==sortKey
//   return NULL if no such item exists
void* DLList::SortedRemove(int sortKey)
{
	// list is empty
	if (!IsEmpty())
	{
		return NULL;
	}
	
	DLLElement *ptr = first;
	while (ptr)
	{
		// found it
		if (ptr->key == sortKey)
		{
			return ptr->item;
		}
		
		ptr = ptr->next;
	}
	
	// Aoh, not found
	return NULL;
}


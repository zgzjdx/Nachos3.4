#include <iostream>
#include "dllist.h"
#include "utility.h"
#include "system.h"
#define H_DLLIST_INCLUDED
#define RANDOM_RANGE 256

#ifndef H_DLLIST_DRIVER_INCLUDED
#define H_DLLIST_DRIVER_INCLUDED

void genRandomNode(IN DLList *list, IN int n, int which);
void delHdrNode(IN DLList *list, IN int n, int which);
void dllistDriverTest();
#endif

int err_type2; // set in main.cc
// generate N node with random key value
void genRandomNode(IN DLList *list, IN int n, int which)
{
    int *item, key;
    // generating new rand() seed for each iteration
    // srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++)
    {
        item = new int;
        *item = Random() % RANDOM_RANGE;
        key = Random() % RANDOM_RANGE;
        std::cout << "[*] generated node key = " << key << " item = " << *(int *)item << " in thread " << which << std::endl;
	if(err_type2 == 3){
	    std::cout << "Switch in genRandomNode" << " in thread " << which << std::endl;
	    currentThread->Yield();
	}
        list->SortedInsert((void *)item, key);
	if(err_type2 == 5){
	    std::cout << "Switch in genRandomNode" << " in thread " << which << std::endl;
	    currentThread->Yield();
	}
    }
}

// delete N node from head to tail
void delHdrNode(IN DLList *list, IN int n, int which)
{
    void *item;
    int *key = new int;

    for (int i = 0; i < n; i++)
    {
        if (list->IsEmpty())
        {
            // list is empty NOW!
            std::cout << "[x] list is empty" << " in thread " << which << std::endl;
            return;
        }
        else
        {
	    if(err_type2 == 4){
	    	std::cout << "Switch in delHdrNod" << " in thread " << which << std::endl;
	    	currentThread->Yield();
	    }
            // list is not empty
            item = list->Remove(key);
	    if(err_type2 == 6){
	    	std::cout << "Switch in delHdrNod" << " in thread " << which << std::endl;
	    	currentThread->Yield();
	    }
            if (item != NULL)
            {
                std::cout << "[*] removed node key = " << *key << " item = " << *(int *)item << " in thread " << which << std::endl;
            }
            else
            {
                std::cout << "[*] removed node key = " << *key << " item = NULL" << " in thread " << which << std::endl;
            }
        }
    }
}

void dllistDriverTest()
{
    int n;
    int item1,item2;
    void *i1,*i2;
    std::cout << "[+] Created a DLList named list" << std::endl;
    DLList *list = new DLList();

    std::cout << "[*] Please input the value of n" << std::endl;
    std::cin >> n;
    std::cout << "[+] Just Create n node in the list" << std::endl;
    genRandomNode(list, n, 0);

    std::cin >> item1;
    i1 = &item1;
    list->Prepend(i1);
    std::cin >> item2;
    i2 = &item2;
    list->Append(i2);

    std::cout << "[*] How many node you want to remove?" << std::endl;
    std::cin >> n;
    delHdrNode(list, n, 0);
}

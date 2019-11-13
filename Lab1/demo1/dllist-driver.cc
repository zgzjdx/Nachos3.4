#include <iostream>
#include "dllist.h"
#include <ctime>
#include <cstdlib>

#define H_DLLIST_INCLUDED
#define RANDOM_RANGE 256

#ifndef H_DLLIST_DRIVER_INCLUDED
#define H_DLLIST_DRIVER_INCLUDED

void genRandomNode(IN DLList *list, IN int n);
void delHdrNode(IN DLList *list, IN int n);
void dllistDriverTest();
#endif


// generate N node with random key value
void genRandomNode(IN DLList *list, IN int n)
{
    int *item, key;
    // generating new rand() seed for each iteration
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        item = new int;
        *item = rand() % RANDOM_RANGE;
        key = rand() % RANDOM_RANGE;
        std::cout << "[*] generated node key = " << key << " item = " << *(int *)item << std::endl;
        list->SortedInsert((void *)item, key);
    }
}

// delete N node from head to tail
void delHdrNode(IN DLList *list, IN int n)
{
    void *item;
    int *key = new int;

    for (int i = 0; i < n; i++)
    {
        if (list->IsEmpty())
        {
            // list is empty NOW!
            std::cout << "[x] list is empty" << std::endl;
            return;
        }
        else
        {
            // list is not empty
            item = list->Remove(key);
            if (item != NULL)
            {
                std::cout << "[*] removed node key = " << *key << " item = " << *(int *)item << std::endl;
            }
            else
            {
                std::cout << "[*] removed node key = " << *key << " item = NULL" << std::endl;
            }
        }
    }
}

void dllistDriverTest()
{
    int n;

    std::cout << "[+] Created a DLList named list" << std::endl;
    DLList *list = new DLList();

    std::cout << "[*] Please input the value of n" << std::endl;
    std::cin >> n;
    std::cout << "[+] Just Create n node in the list" << std::endl;
    genRandomNode(list, n);

    std::cout << "[*] How many node you want to remove?" << std::endl;
    std::cin >> n;
    delHdrNode(list, n);
}

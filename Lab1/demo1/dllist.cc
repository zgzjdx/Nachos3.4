#include "dllist.h"

// initialize a list element
DLLElement::DLLElement(IN void *itemPtr, IN int sortKey)
{
    key = sortKey;  // priority, for a sorted list
    item = itemPtr; // pointer to item on the list
    next = NULL;    // next element on list
                    // NULL if this is the last
    prev = NULL;    // previous element on list
                    // NULL if this is the first
}

// initialize the list
DLList::DLList()
{
    first = NULL; // head of the list, NULL if empty
    last = NULL;  // last element of the list, NULL if empty
}

// de-allocate the list
DLList::~DLList()
{
    DLLElement *currElem = first; // current element in the DLList
    DLLElement *nextElem = NULL;  // next element in the DLList
    while (currElem != NULL)
    { // delete all the element in the DLList from head to the tail
        nextElem = currElem->next;
        delete currElem;
        currElem = nextElem;
    }
}

// return true if list is empty
bool DLList::IsEmpty()
{
    // when first == NULL and last == NULL
    // list is empty
    if (!first && !last)
    {
        return true;
    }

    // list is not empty
    return false;
}

// add to head of list (set key = min_key-1)
void DLList::Prepend(IN void *item)
{
    if (IsEmpty())
    {
        // list is empty
        DLLElement *newNode = new DLLElement(item, 0);
        first = newNode;
    }
    else
    {
        // list is not empty
        DLLElement *newNode = new DLLElement(item, first->key - 1);
        first->prev = newNode;
        newNode->next = first;
        first = newNode;
    }
}

// add to tail of list (set key = max_key+1)
void DLList::Append(IN void *item)
{
    if (IsEmpty())
    {
        // list is empty
        DLLElement *newNode = new DLLElement(item, 0);
        first = newNode;
    }
    else
    {
        // list is not empty
        DLLElement *newNode = new DLLElement(item, last->key - 1);
        last->prev = newNode;
        newNode->next = last;
        last = newNode;
    }
}

// remove from head of list
// set *keyPtr to key of the removed item
// return item (or NULL if list is empty)
void *DLList::Remove(OUT int *keyPtr)
{
    void *temp;
    if (IsEmpty())
    {
        // list is empty
        return NULL;
    }
    else
    {
        // list is not empty
        // first != NULL
        DLLElement *currNode = first;
        first = first->next;
        if (first == NULL)
        {
            // there are only one node in the list
            last = NULL;
        }
        else
        {
            first->prev = NULL;
        }
        currNode->next = NULL;
        *keyPtr = currNode->key;

        temp = currNode->item;
        delete currNode;

        return temp;
    }
}

// routines to put/get items on/off list in order (sorted by key)
void DLList::SortedInsert(void *item, int sortKey)
{
    DLLElement *newNode = new DLLElement(item, sortKey);
    if (IsEmpty())
    {
        // list is empty
        first = newNode;
        last = newNode;
    }
    else
    {
        // list is not empty
        DLLElement *currNode = first;
        while (currNode != NULL)
        {
            if (currNode->key <= sortKey)
            {
                // when currNode == last
                // or
                // the currNode->next->key >= sortKey
                if (currNode->next == NULL || currNode->next->key >= sortKey)
                {
                    break;
                }
                currNode = currNode->next;
            }
            else
            {
                // there are not suitable elementm, we break;
                // so we will insert the newNode to the head of list
                currNode = NULL;
            }
        }

        if (currNode == NULL)
        {
            first->prev = newNode;
            newNode->next = first;
            first = newNode;
        }
        else
        {
            if (currNode == last)
            {
                // we will insert newNode to the tail of list
                newNode->prev = last;
                last->next = newNode;
                last = newNode;
            }
            else
            {
                // we found the suitable element
                // currNode <-> newNode <-> otherNode(sortKey)
                //                ^
                newNode->next = currNode->next;
                newNode->next->prev = newNode;
                newNode->prev = currNode;
                currNode->next = newNode;
            }
        }
    }
}

// remove first item with key==sortKey
// return NULL if no such item exists
void *DLList::SortedRemove(int sortKey)
{
    void *temp; // save the removed Node item
    if (!IsEmpty())
    {
        // list is not empty
        DLLElement *currNode = first;

        // find the Node with key == sortKey
        // or
        // currNode == NULL
        while (currNode != NULL && currNode->key != sortKey)
        {
            currNode = currNode->next;
        }

        if (currNode == NULL)
        {
            return NULL;
        }
        else
        {
            // we find the suitable node
            if (currNode == first)
            {
                first = first->next;
                currNode->next = NULL;
                if (first == NULL)
                {
                    // there are only one element in the list
                    last = NULL;
                }
                else
                {
                    first->prev == NULL;
                }
            }
            else if (currNode == last)
            {
                last = currNode->prev;
                currNode->prev = NULL;
                last->next = NULL;
            }
            else
            {
                currNode->next->prev = currNode->prev;
                currNode->prev->next = currNode->next;
            }
            temp = currNode->item;
            delete currNode;
            return temp;
        }
    }

    // list is empty
    return NULL;
}
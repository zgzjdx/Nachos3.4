#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H
#include"bitmap.h"
#include"translate.h"
class MemoryManager
{
    public:
	MemoryManager();
	~MemoryManager();
	int Get();
	void Release(int pn);
	void Print();
    private:
	BitMap *bitmap;
};
#endif

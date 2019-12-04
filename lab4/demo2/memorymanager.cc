#include"memorymanager.h"
#include"system.h"
MemoryManager::MemoryManager()
{
    bitmap=new BitMap(NumPhysPages);
}
MemoryManager::~MemoryManager()
{
    delete bitmap;
}
int MemoryManager::Get()
{
    int i=bitmap->Find();
    if(i!=-1)
    {
    	bitmap->Mark(i);
	return i;
    }
    else
    	return -1;
}
void MemoryManager::Release(int pn)
{
    bitmap->Clear(pn);
}
void MemoryManager::Print()
{
    bitmap->Print();
}

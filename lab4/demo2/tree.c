#include "syscall.h"
int a[10];
int main()
{
    int id,i;
    Print("Tree Start:\n");
    for(i=0;i<5;i++)
    {
	id=Exec("../test/tree-nojoin");
	Join(id);
	a[i]=i;
    }
    Print("Tree End!\n");
    return 0;
}

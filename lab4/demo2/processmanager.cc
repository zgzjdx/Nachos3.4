#include"processmanager.h"
ProcessManager::ProcessManager()
{
    t=new Table(ProcessNum);
    plist=new List();
    lock=new Lock("process lock");
}
ProcessManager::~ProcessManager()
{
    delete t;
    delete plist;
    delete lock;
}
void UserProgExec(int id)
{
    if(!currentThread->space)
    {
	printf("User Prog error id is %d\n",id);
	currentThread->Finish();
    }
    currentThread->space->InitRegisters();
    currentThread->space->RestoreState();
    //Mm->Print();
    printf("Start Process %d\n",currentThread->space->GetSpaceid());
    machine->Run();
    ASSERT(FALSE);
}
int ProcessManager::GetPid(int ppid)
{
    Process *p=new Process();
    int id=t->Alloc((void*)p);
    if(id==-1)
	return id;
    ASSERT(id>=0&&id<ProcessNum);
    p->ppid=ppid;
    p->pid=id;
    p->status=1;
    p->active=1;
    p->joined=0;
    p->joinsem=new Semaphore("joinsema",0);
    plist->Append((void*)p);
    return id;
}
/*void ProcessManager::Release(int pid,int status)
{
    Process*p=(Process*)t->Get(pid);
    if(pid==0)
	return;
    p->status=status;
    p->active=0;
    t->Release(pid);
}
bool ProcessManager::getStatus(int pid,int ppid,int*status)
{
    return true;
}
void ProcessManager::PListController(int pid,int ppid)
{
    
}*/
SpaceId ProcessManager::Exec(char*filename)
{
    OpenFile *executable=fileSystem->Open(filename);
    AddrSpace*space;
    if(executable==NULL)
    {
	printf("Unable to open file %s\n",filename);
	return 0;
    }
    int id=GetPid(currentThread->space->GetSpaceid());
    space=new AddrSpace(id);
    if(!space->AdminSpace(executable))
    {
	printf("space not enough for Process %d\n",id);
	return 0;
    }
    Thread*thread=new Thread("Process id");
    thread->space=space;
    delete executable;
    thread->Fork(UserProgExec,id);
    return id;
}
int ProcessManager::Join(int id)
{
    int status;
    Process*p=(Process*)t->Get(id);
    p->joined=1;
    if(p->active)
	p->joinsem->P();
    status=p->status;
    delete p;
    return status;
}
void ProcessManager::Exit(int status)
{
    Process*q;
    int i;
    Process*p=(Process*)t->Get(currentThread->space->GetSpaceid());
    p->status=status;
    for(i=1;i<ProcessNum;i++)
    {
	q=(Process*)t->Get(i);
	if(q&&q->ppid==p->pid&&q->active)
	    q->ppid=0;
    }
    delete currentThread->space;
    if(p->joined)
	p->joinsem->V();
    p->active=0;
    currentThread->Finish();
}

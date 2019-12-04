#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H
#include"synch.h"
#include"Table.h"
#include"syscall.h"
#include"system.h"
#define ProcessNum 10
class Process
{
    public:
	int ppid;
	int pid;
	int status;
	int active;
	int joined;
	Semaphore*joinsem;
};
class ProcessManager
{
    public:
	ProcessManager();
	~ProcessManager();
	int GetPid(int ppid);
	void Release(int pid,int status);
	bool getStatus(int pid,int ppid,int*status);
	void PListController(int pid,int ppid);
	SpaceId Exec(char*filename);
	int Join(int id);
	void Exit(int status);
    private:
	Table *t;
	List*plist;
	Lock *lock;
};
#endif

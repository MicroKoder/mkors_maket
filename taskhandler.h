#ifndef _TASKHANDLER_
#define _TASKHANDLER_
#define MAX_TASKS 10


typedef struct  
{
	void (*pFunc)();
	unsigned short period;
	unsigned short et;
} callback_t;

class TaskHandler
{
  private:
    callback_t callbacks[MAX_TASKS];
    int taskCount=0;
  unsigned long lastMS=0;
  public:
    void RegisterTask(void* pFunc, int period_ms);
    void Poll();
};

#endif
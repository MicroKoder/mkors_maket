#include "taskhandler.h"
#include <Arduino.h>
void TaskHandler::RegisterTask(void* pFunc, int period_ms)
{
  callbacks[taskCount].pFunc = pFunc;
  callbacks[taskCount].period = period_ms;
  taskCount++;
}
void TaskHandler::Poll()
{
  unsigned long ms = millis();
  for(int i = 0; i< taskCount; i++)
  {
    callbacks[i].et += (ms-lastMS);
    if (callbacks[i].et >= callbacks[i].period)
		{
			callbacks[i].et  = 0;
			callbacks[i].pFunc();
		}
  }
  lastMS = ms;
}
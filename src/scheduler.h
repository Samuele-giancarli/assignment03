#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "Task/Task.h"
#include "TimerOne.h"

#define MAX_TASKS 10 //numero di task da poter aggiungere allo scheduler

class  Scheduler
{
    int basePeriod; //intervallo di tempo per un'esecuzione completa
    int nTasks; //numero di task da eseguire totali
    Task* taskList[MAX_TASKS]; //vettore di puntatori ai task da eseguire
    TimerOne timer;

    public:
    void init(int basePeriod);
    virtual bool addTask(Task* Task);
    virtual void schedule();
    
};

#endif
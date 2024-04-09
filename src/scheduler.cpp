#include "scheduler.h"

volatile bool timer_Flag;

void timerHandler(void){
  timer_Flag = true;
}

void Scheduler::init(int basePeriod){
  ///////////////////////////////
  this->basePeriod = basePeriod;
  timer_Flag = false;
    //long period = basePeriod;
    //period dovrebbe essere sui 100 millisecondi
  timer.initialize(this->basePeriod);
  timer.attachInterrupt(timerHandler);
  nTasks = 0;
}

bool Scheduler::addTask(Task* task){
  if (nTasks < MAX_TASKS-1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}
  
void Scheduler::schedule(){

  while (!timer_Flag) {
  }
  
  timer_Flag = false;

  for (int i = 0; i < nTasks; i++) {
    if (taskList[i]->updateAndCheckTime(basePeriod)){
          
      taskList[i]->tick();
    } 
  }
}
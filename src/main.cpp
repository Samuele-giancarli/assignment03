#include "Arduino.h"
#include "Config.h"
#include "scheduler.h"

#include "task/ReadingTask.h"
#include "task/UpdateTask.h"
#include "task/SendingTask.h"
#include "task/ButtonTask.h"
#include "changeStateTask.h"

Scheduler scheduler;
ChangeStateTask* stateHandler;


void setup() {

  pinMode(BUTTONPORT,INPUT);
  pinMode(POTPORT,INPUT);

  stateHandler = new ChangeStateTask();
  stateHandler->init();

  scheduler.init(100);
  //baseperiod in millisecondi
  
  Task* t0 = new ButtonTask(stateHandler);
  t0->init(100);
  scheduler.addTask(t0);

  Task* t1 = new ReadingTask(stateHandler);
  t1->init(100);
  scheduler.addTask(t1);

  Task* t2 = new UpdateTask(stateHandler);
  t2->init(100);
  scheduler.addTask(t2);

  Task* t3 = new SendingTask(stateHandler);
  t3->init(100);
  scheduler.addTask(t3);

  stateHandler->setStateManual();

  Serial.begin(9600);
}

void loop() {
  scheduler.schedule();
}
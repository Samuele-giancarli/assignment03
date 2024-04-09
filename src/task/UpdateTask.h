#ifndef __UPDATETASK__
#define __UPDATETASK__

#include <ServoTimer2.h>
#include <LiquidCrystal_I2C.h>

#include "task.h"
#include "changeStateTask.h"
#include "Config.h"
#include "Arduino.h"

class UpdateTask: public Task {
 
public: 
  UpdateTask(ChangeStateTask* stateHandler);
  void tick();

  void setLCD();
  void setServo();
  int getPot();
  
 private:
  long stateTimeStamp;
  ChangeStateTask* stateHandler;
};

#endif
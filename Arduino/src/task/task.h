#ifndef __TASK__
#define __TASK__

#include "Config.h"
#include "Arduino.h"

class Task {
  private:
    //int myPeriod;
    int startPeriod;
    int timeElapsed;
    int myPeriod;

  public:
    long elapsedTimeInState();
    
    virtual void init(int period)
    {
      /*
        in una task generica ho bisogno di:
        - lo start time tramite millis();
        - timeElapsed settato inizialmente a 0
          (aumentano ad ogni tick di Period)
      */
    startPeriod = millis();
    timeElapsed = 0;
    myPeriod = period;
    }

    virtual void tick() = 0;

    bool updateAndCheckTime(int basePeriod)
    {
      timeElapsed += basePeriod;
      if (timeElapsed >= myPeriod){
        timeElapsed = 0;
        return true;
      } else {
        return false; 
      }
    }
};

#endif
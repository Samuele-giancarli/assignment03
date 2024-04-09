#ifndef __READINGTASK__
#define __READINGTASK__

#include "task.h"
#include "changeStateTask.h"

class ReadingTask: public Task {
 
public: 
  ReadingTask(ChangeStateTask* stateHandler);
  void tick();


  private:
  long stateTimeStamp;
  ChangeStateTask* stateHandler;
  void read();
  void sendSerial();

};

#endif
#ifndef __SENDINGTASK__
#define __SENDINGTASK__

#include "task.h"
#include "changeStateTask.h"

class SendingTask: public Task {
 
public: 
  SendingTask(ChangeStateTask* stateHandler);
  void tick();

  private:
  long stateTimeStamp;
  ChangeStateTask* stateHandler;
};

#endif
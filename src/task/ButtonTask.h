/* To check button and seriale */
#ifndef __BUTTONTASK__
#define __BUTTONTASK__

#include "task.h"
#include "ChangeStateTask.h"

class ButtonTask: public Task {

    public:
    ButtonTask(ChangeStateTask* stateHandler); 
    void tick(); 

    private:
    long stateTimestamp;
    ChangeStateTask* stateHandler;

};

#endif
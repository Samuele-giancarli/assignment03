#include "ButtonTask.h"
#include "Arduino.h"

ButtonTask::ButtonTask(ChangeStateTask* stateHandler) {
    this->stateHandler = stateHandler;
}

void ButtonTask::tick()
{
    if (digitalRead(BUTTONPORT) == HIGH)
    {
        if(stateHandler->isStateManual()) {
            stateHandler->setStateAutomatic();
        } else {
            stateHandler->setStateManual();
        }
        
    }
}
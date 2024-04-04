#include "asyncFsm.h"
#include "devices/buttonImpl.h"
#include "devices/serial.h"
#include "Arduino.h"


#define BUTTON_PIN 4

class ButtonLedAsyncFSM : public AsyncFSM {
  public:
    ButtonLedAsyncFSM(Button* button){
      count = 0;  
      currentState = OFF;
      this->button = button;
      button->registerObserver(this);
    }
  
    void handleEvent(Event* ev) {
      switch (currentState) {
      case OFF:  
        if (ev->getType() == BUTTON_PRESSED_EVENT){
          currentState = ON;
          //TO DO! Define the actions of the event
        }
        break; 
      case ON: 
        if (ev->getType() == BUTTON_RELEASED_EVENT){
          currentState = OFF;
        }
      }
    }

  private:
    int count; 
    Button* button;
    enum  { ON, OFF} currentState;
};

ButtonLedAsyncFSM* myAsyncFSM;

void setup() {
  Button* button = new ButtonImpl(BUTTON_PIN);
  myAsyncFSM = new ButtonLedAsyncFSM(button);

  SerialImpl* serial = new SerialImpl();
  
}

void loop() {
  myAsyncFSM->checkEvents();
}
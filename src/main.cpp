#include "asyncFsm.h"
#include "devices/buttonImpl.h"
#include "devices/serial.h"
#include "deviceManager.h"
#include "Arduino.h"
#include "Config.h"


#define BUTTON_PIN 4

SerialImpl* mainSerial;
DeviceManager* manager;

enum  { MAN, AUTO} currentState;

class ButtonLedAsyncFSM : public AsyncFSM {
  public:
    ButtonLedAsyncFSM(Button* button){
      count = 0;  
      currentState = AUTO;
      this->button = button;
      button->registerObserver(this);
    }
  
    void handleEvent(Event* ev) {
      switch (currentState) {
      case AUTO:  
        if (ev->getType() == BUTTON_PRESSED_EVENT){
          currentState = MAN;
          mainSerial->setMode(MANUALCODE);
        }
        break; 
      case MAN: 
        if (ev->getType() == BUTTON_RELEASED_EVENT){
          currentState = AUTO;
          mainSerial->setMode(AUTOMATICCODE);
        }
      }
    }

  private:
    int count; 
    Button* button;
};

ButtonLedAsyncFSM* myAsyncFSM;

void setup() {
  Button* button = new ButtonImpl(BUTTON_PIN);
  myAsyncFSM = new ButtonLedAsyncFSM(button);

  mainSerial = new SerialImpl();
  manager = new DeviceManager(mainSerial);
}

void loop() {

  manager->setLCD();
  manager->setServo();

  myAsyncFSM->checkEvents();

  switch (currentState) {
    case MAN:
      mainSerial->read();
      break;
    case AUTO:
      manager->getPot();
      break;
  }
  
  mainSerial->sendSerial();
}
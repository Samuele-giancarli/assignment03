#include "asyncFsm.h"
#include "devices/buttonImpl.h"
#include "devices/serial.h"
#include "deviceManager.h"
#include "Arduino.h"
#include "Config.h"


#define BUTTON_PIN 4

SerialImpl* mainSerial;
DeviceManager* manager;

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
          Serial.write(MANUAL);
        }
        break; 
      case MAN: 
        if (ev->getType() == BUTTON_RELEASED_EVENT){
          currentState = AUTO;
          Serial.write(AUTOMATIC);
        }
      }
    }

  private:
    int count; 
    Button* button;
    enum  { MAN, AUTO} currentState;
};

ButtonLedAsyncFSM* myAsyncFSM;

void setup() {
  Button* button = new ButtonImpl(BUTTON_PIN);
  myAsyncFSM = new ButtonLedAsyncFSM(button);

  mainSerial = new SerialImpl();
  manager = new DeviceManager(mainSerial);
  Serial.write("Hello");
}

void loop() {
  myAsyncFSM->checkEvents();
  mainSerial->read();
  manager->setLCD();
  manager->setServo();
  mainSerial->sendSerial();
}
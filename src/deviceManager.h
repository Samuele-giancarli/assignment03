#ifndef __DEVICEMANAGER__
#define __DEVICEMANAGER__

#include <ServoTimer2.h>
#include <LiquidCrystal_I2C.h>
#include "devices/serial.h"
#include "Config.h"
#include "Arduino.h"

class DeviceManager {
 
public: 
  DeviceManager(SerialImpl* serial);
  void setLCD();
  void setServo();
  int getPot();
};

#endif
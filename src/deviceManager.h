#ifndef __DEVICEMANAGER__
#define __DEVICEMANAGER__

#include <ServoTimer2.h>
#include <LiquidCrystal_I2C.h>

#define MAXANGLE 1800
#define MINANGLE 0

class DeviceManager {
 
public: 
  DeviceManager(ServoTimer2 servo, LiquidCrystal_I2C lcd);

  int getAngle();
  void setAngle(int angle);
  bool getMode();
  void setMode(bool mode);
};

#endif
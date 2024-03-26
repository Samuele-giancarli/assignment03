#ifndef __DEVICEMANAGER__
#define __DEVICEMANAGER__

#include <ServoTimer2.h>
#include <Print.h>
#include <LiquidCrystal_I2C.h>

#define MAXANGLE 1800
#define MINANGLE 0
class DeviceManager {
 
public:

  DeviceManager(ServoTimer2* servo, LiquidCrystal_I2C* lcd);
  int getAngle() {
    return servoAngle;
  };
  void setAngle(int angle) {
    servoAngle = angle;
  };
  bool getMode() {
    return autoMode;
  };
  void setMode(bool mode) {
    autoMode = mode;
  }

private:
  int servoAngle = 0;
  bool autoMode = true;
  ServoTimer2* servo;
};

#endif
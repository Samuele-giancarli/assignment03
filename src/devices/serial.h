#ifndef __SERIAL__
#define __SERIAL__

#include "string.h"
class SerialImpl {
 
public: 
  SerialImpl();
  bool read();
  int getAngle();
  bool getMode();
  void sendSerial();
  void setMode(bool mode);
  void setAngle(int angle);
};

#endif
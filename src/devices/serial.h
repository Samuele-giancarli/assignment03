#ifndef __SERIAL__
#define __SERIAL__

class SerialImpl {
 
public: 
  SerialImpl();
  bool read();
  int getAngle();
  bool getMode();
  void sendSerial();

private:
  String incomingByte;
  int angle;
  String mode;
};



#endif
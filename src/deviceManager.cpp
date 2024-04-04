#include <deviceManager.h>
#include <ServoTimer2.h>
#include <LiquidCrystal_I2C.h>
#define MAXANGLE 1800
#define MINANGLE 0   

int servoAngle = 0;
bool autoMode = true;
ServoTimer2 servo;
LiquidCrystal_I2C lcd(0x27,20,4); 


DeviceManager::DeviceManager(ServoTimer2 servo, LiquidCrystal_I2C lcd) {
      // Initialize servo and LCD here if necessary
      servo.attach(9); // Attach servo to pin 9
      lcd.init(); // Initialize the LCD
      lcd.backlight(); // Turn on the backlight
  }

int getAngle() {
return servoAngle;
}

void setAngle(int angle) {
if (angle >= MINANGLE && angle <= MAXANGLE) {
    servoAngle = angle;
    servo.write(angle); // Update the servo position
}
}

bool getMode() {
return autoMode;
}

void setMode(bool mode) {
autoMode = mode;
}

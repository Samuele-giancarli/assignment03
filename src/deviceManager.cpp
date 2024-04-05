#include <deviceManager.h>

int servoAngle = 0;
bool autoMode = true;
ServoTimer2 servo;
LiquidCrystal_I2C lcd(0x27,20,4); 
SerialImpl* serial;

DeviceManager::DeviceManager(SerialImpl* serial) {
    serial = serial;
      // Initialize servo and LCD here if necessary
      servo.attach(SERVOPORT); // Attach servo to pin 9
      lcd.begin(2, 1); // Initialize the LCD
      lcd.backlight(); // Turn on the backlight
}

void DeviceManager::setLCD() {
    lcd.print(serial->getAngle());
    lcd.print(", ");
    lcd.print(serial->getMode() ? MANUAL : AUTOMATIC);
    lcd.setCursor(2, 1);
}

void DeviceManager::setServo() {
    servoAngle = serial->getAngle();
    if (servoAngle >= MINANGLE && servoAngle <= MAXANGLE) {
        servo.write(servoAngle);
    }
}
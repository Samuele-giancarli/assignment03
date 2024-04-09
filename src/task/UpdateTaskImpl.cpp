#include "UpdateTask.h"

int servoAngle = 0;
bool autoMode = true;
ServoTimer2 servo;
LiquidCrystal_I2C lcd(0x27,20,4); 

UpdateTask::UpdateTask(ChangeStateTask* stateHandler) {
    this->stateHandler = stateHandler;

    servo.attach(SERVOPORT); // Attach servo to pin 

    lcd.init(); // Initialize the LCD
    lcd.backlight(); // Turn on the backlight
}

void UpdateTask::tick() {
   setLCD();
   setServo();
}

void UpdateTask::setLCD() {
    lcd.setCursor(2,1);
    lcd.print(stateHandler->getAngle());
    lcd.print(", ");
    lcd.print(stateHandler->isStateManual() ? MANUAL : AUTOMATIC);
}

void UpdateTask::setServo() {
    servoAngle = stateHandler->getAngle();
    if (servoAngle >= MINANGLE && servoAngle <= MAXANGLE) {
        servo.write(servoAngle);
    }
}
//#include <Servo.h> // Arduino
#include <ESP32Servo.h> // ESP32
#define BAUD 115200
#define servo_pin 13 // analogico

String receivedString;
Servo servoMotor;
int angle = 0;

void setup() {
  Serial.begin(BAUD);
  servoMotor.attach(servo_pin);
}

void loop() {
  if (Serial.available() > 0) {
    receivedString = Serial.readStringUntil('\n');
    angle = receivedString.toInt();
    angle = angle < 0 ? 0 : angle > 180 ? 180 : angle;
    servoMotor.write(angle);
  }
}
#include "BluetoothSerial.h"
#define motor 15
#define analogx 14
#define analogy 27
#define button 26

String device_name = "ESP32-BT";
String receivedString;
int buttonState = 0;
int ax = 0;
int ay = 0;

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin(device_name);  //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  pinMode(button, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
}

void loop() {
  if (SerialBT.available() > 0) {
    receivedString = SerialBT.readStringUntil('\n');
    if (receivedString.equals("read")) {
      ax = analogRead(analogx);
      ay = analogRead(analogy);
      buttonState = digitalRead(button);
      SerialBT.printf("%04d-%04d-%d\n", ax, ay, buttonState);
    }
    if (receivedString.equals("vibra")) {
      digitalWrite(motor, HIGH);
    }
    if (receivedString.equals("!vibra")) {
      digitalWrite(motor, LOW);
    }
  }
}
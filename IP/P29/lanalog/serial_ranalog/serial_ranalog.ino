#define BAUD 115200
#define led 2
#define analog 13

String receivedString;
int sensorValue = 0;

void setup() {
  Serial.begin(BAUD);
  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    receivedString = Serial.readStringUntil('\n');
    if (receivedString.equals("analog")) {
      sensorValue = analogRead(analog);
      Serial.println(sensorValue);
    }
    if (receivedString.equals("on") || receivedString.equals("ON")) {
      digitalWrite(led, HIGH);
    }
    if (receivedString.equals("off") || receivedString.equals("OFF")) {
      digitalWrite(led, LOW);
    }
  }
}

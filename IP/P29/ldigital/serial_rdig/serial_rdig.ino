#define BAUD 115200
#define led 2
#define button 13

String receivedString;
int buttonState = 0;

void setup() {
  Serial.begin(BAUD);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    Serial.write("1\n");
  } else {
    Serial.write("0\n");
  }
  if (Serial.available() > 0) {
    receivedString = Serial.readStringUntil('\n');
    if (receivedString.equals("on") || receivedString.equals("ON")) {
      digitalWrite(led, HIGH);
    }
    if (receivedString.equals("off") || receivedString.equals("OFF")) {
      digitalWrite(led, LOW);
    } 
  }
  delay(100);
}

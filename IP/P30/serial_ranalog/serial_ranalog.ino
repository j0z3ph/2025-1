#define BAUD 115200
#define motor 15
#define analogx 14
#define analogy 27
#define button 26

String receivedString;
int buttonState = 0;
int ax = 0;
int ay = 0;

void setup() {
  Serial.begin(BAUD);
  pinMode(button, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    receivedString = Serial.readStringUntil('\n');
    if (receivedString.equals("read")) {
      ax = analogRead(analogx);
      ay = analogRead(analogy);
      buttonState = digitalRead(button);
      Serial.printf("%04d-%04d-%d\n", ax, ay, buttonState);
    }
    if (receivedString.equals("vibra")) {
      digitalWrite(motor, HIGH);
    }
    if (receivedString.equals("!vibra")) {
      digitalWrite(motor, LOW);
    }
  }
}

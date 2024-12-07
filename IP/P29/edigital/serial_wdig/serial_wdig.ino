#define BAUD 115200
#define led 2

String receivedString;

void setup() {
  Serial.begin(BAUD);
  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    receivedString = Serial.readStringUntil('\n');
    if (receivedString.equals("on") || receivedString.equals("ON")) {
      digitalWrite(led, HIGH);
      Serial.write("Led encendido.\n");
    } else if (receivedString.equals("off") || receivedString.equals("OFF")) {
      digitalWrite(led, LOW);
      Serial.write("Led apagado.\n");
    } else if (receivedString.equals("q") || receivedString.equals("Q")) {
      Serial.write("Adios.\n");
    } else {
      Serial.write("Comando no valido.\n");
    }
  }
}
#include <WiFi.h>

TaskHandle_t Task1;
TaskHandle_t Task2;

WiFiClient localClient;

const char* ssid = "Wi-Fi IPN";
const char* password = "";

const uint port = 80;
const char* ip = "13.59.181.74";


void setup() {
  Serial.begin(115200);

  pinMode(2, OUTPUT);

  Serial.println("Conectando a Internet");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());


  // Tarea a ejecutarse en el core 0. Enviar mensajes al servidor.
  xTaskCreatePinnedToCore(
    Task1code, /* Task function. */
    "Task1",   /* name of task. */
    10000,     /* Stack size of task */
    NULL,      /* parameter of the task */
    1,         /* priority of the task */
    &Task1,    /* Task handle to keep track of created task */
    0);        /* pin task to core 0 */

  delay(500);

  //c Tarea a ejecutarse en el core 1. Recibir mensajes del servidor.
  xTaskCreatePinnedToCore(
    Task2code, /* Task function. */
    "Task2",   /* name of task. */
    10000,     /* Stack size of task */
    NULL,      /* parameter of the task */
    1,         /* priority of the task */
    &Task2,    /* Task handle to keep track of created task */
    1);        /* pin task to core 1 */

  delay(500);
}

void loop() {
  if (!localClient.connected()) {
    Serial.println("Conectando al servidor");
    while (!localClient.connect(ip, port)) {
      Serial.print(".");
      delay(500);
    }
    localClient.print("<name>ESP32");
  }
}



// Tarea 1. Mandar mensajes al server
void Task1code(void* pvParameters) {
  Serial.print("Tarea 1 corriendo en el core ");
  Serial.println(xPortGetCoreID());
  while (1) {
    if (localClient.connected()) {
      localClient.print("Estoy listo!");
    }
    delay(10000);
  }
}

// Tarea 2. Esperar mensajes del server
void Task2code(void* pvParameters) {
  Serial.print("Tarea 2 corriendo en el core ");
  Serial.println(xPortGetCoreID());

  while (1) {
    if (localClient.connected()) {
      while (!localClient.available());
      String str = localClient.readStringUntil('\n');
      if(str.startsWith("<command>on")) {
        digitalWrite(2, HIGH);
      } else if(str.startsWith("<command>off")) {
        digitalWrite(2, LOW);
      } else {
        Serial.println(str);
      }
    }
    delay(100);
  }
}


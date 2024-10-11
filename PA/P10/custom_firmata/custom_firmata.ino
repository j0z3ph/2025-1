/*
 * ConfigurableFirmata standard example file, for serial communication.
 */

#include <ConfigurableFirmata.h>

// Use this to enable WIFI instead of serial communication. Tested on ESP32, but should also
// work with Wifi-enabled Arduinos
// #define ENABLE_WIFI

const char* ssid     = "your-ssid";
const char* password = "your-password";
const int NETWORK_PORT = 27016;

// Use these defines to easily enable or disable certain modules

// #define ENABLE_ONE_WIRE

// Note that the SERVO module currently is not supported on ESP32. So either disable this or patch the library
#ifndef ESP32
#define ENABLE_SERVO 
#endif

// #define ENABLE_ACCELSTEPPER

// This is rarely used
// #define ENABLE_BASIC_SCHEDULER
#define ENABLE_SERIAL
#define ENABLE_I2C
#define ENABLE_SPI
#define ENABLE_ANALOG
#define ENABLE_DIGITAL
#define ENABLE_DHT
#define ENABLE_FREQUENCY

// Currently supported for AVR and ESP32
#if defined (ESP32) || defined (ARDUINO_ARCH_AVR)
#define ENABLE_SLEEP
#endif

#ifdef ENABLE_DIGITAL
#include <DigitalInputFirmata.h>
DigitalInputFirmata digitalInput;

#include <DigitalOutputFirmata.h>
DigitalOutputFirmata digitalOutput;
#endif

#ifdef ENABLE_SLEEP
#include "ArduinoSleep.h"
ArduinoSleep sleeper(39, 0);
#endif

#ifdef ENABLE_ANALOG
#include <AnalogInputFirmata.h>
AnalogInputFirmata analogInput;

#include <AnalogOutputFirmata.h>
AnalogOutputFirmata analogOutput;
#endif


#ifdef ENABLE_WIFI
#include <WiFi.h>
#include "utility/WiFiClientStream.h"
#include "utility/WiFiServerStream.h"
WiFiServerStream serverStream(NETWORK_PORT);
#endif

#ifdef ENABLE_I2C
#include <Wire.h>
#include <I2CFirmata.h>
I2CFirmata i2c;
#endif

#ifdef ENABLE_SPI
#include <Wire.h>
#include <SpiFirmata.h>
SpiFirmata spi;
#endif

#ifdef ENABLE_ONE_WIRE
#include <OneWireFirmata.h>
OneWireFirmata oneWire;
#endif

#ifdef ENABLE_SERIAL
#include <SerialFirmata.h>
SerialFirmata serial;
#endif

#ifdef ENABLE_DHT
#include <DhtFirmata.h>
DhtFirmata dhtFirmata;
#endif

#include <FirmataExt.h>
FirmataExt firmataExt;

#ifdef ENABLE_SERVO
#include <Servo.h>
#include <ServoFirmata.h>
ServoFirmata servo;
#endif

#include <FirmataReporting.h>
FirmataReporting reporting;

#ifdef ENABLE_ACCELSTEPPER
#include <AccelStepperFirmata.h>
AccelStepperFirmata accelStepper;
#endif

#ifdef ENABLE_FREQUENCY
#include <Frequency.h>
Frequency frequency;
#endif

#ifdef ENABLE_BASIC_SCHEDULER
// The scheduler allows to store scripts on the board, however this requires a kind of compiler on the client side.
// When running dotnet/iot on the client side, prefer using the FirmataIlExecutor module instead
#include <FirmataScheduler.h>
FirmataScheduler scheduler;
#endif

// Jose Luis Cruz
void sysexCallback(byte command, byte argc, byte *argv) {

  switch (command) {
    case 0x01:
      {  // DIGITALWRITE = DIGITALOUTPUT
        byte digitalPin;
        byte pinState;

        digitalPin = argv[0];  //buffer[2]
        pinState = argv[1];    //buffer[3]

        pinMode(digitalPin, OUTPUT);
        digitalWrite(digitalPin, pinState);

        Firmata.sendSysex(command, argc, argv);  // callback

        break;
      }
    case 0x02:
      {  // Analog Read Command
        byte adcPin = argv[0];

        unsigned short rawV;
        rawV = analogRead(adcPin);  //0-1023
        // pin does not need to callback, therefore argv is modified here
        byte i = 0;
        byte nBytes = rawV / 127;
        byte lastByte = rawV % 127;
        //nBytes is the number of full 7 bit bytes and lastByte is the offset (difference) for the last 7-bit byte
        for (; i < nBytes; i++) {
          argv[i] = 127;
        }
        // generates dynamic argv with 127 slices
        if (nBytes >= 1) {
          argv[i] = lastByte;
        } else argv[i] = rawV;

        argc = i + 1;

        Firmata.sendSysex(command, argc, argv);
        break;
      }
    case 0x03:
      {  // Digital Read Command
        byte digitalPin = argv[0];
        byte pinState[1];
        pinMode(digitalPin, INPUT);
        pinState[0] = digitalRead(digitalPin);
        Firmata.sendSysex(command, argc, pinState);
        break;
      }
    case 0x04:
      {  // PWM output
        byte pwmPin = argv[0];
        byte pwmChannel = argv[1];
        int pwnFreqMult = argv[2] == 0 ? 1 : (argv[2] == 1 ? 1000 : 1000000);  
        byte pwmFreq = argv[3];
        byte pwmResolution = argv[4];
        unsigned short pwmValue = 0;

        for (byte i = 5; i < argc; i++) {
          pwmValue += argv[i];  //from buffer[5]...
        }

        ledcSetup(pwmChannel, pwmFreq * pwnFreqMult, pwmResolution);
        ledcAttachPin(pwmPin, pwmChannel);
        ledcWrite(pwmChannel, pwmValue);
        Firmata.sendSysex(command, argc, argv);
      }
    default:
      break;
  }
}

void systemResetCallback()
{
// Does more harm than good on ESP32 (because may touch pins reserved
// for memory IO and other reserved functions)
#ifndef ESP32 
	for (byte i = 0; i < TOTAL_PINS; i++) 
	{
		if (IS_PIN_ANALOG(i)) 
		{
			Firmata.setPinMode(i, PIN_MODE_ANALOG);
		} 
		else if (IS_PIN_DIGITAL(i)) 
		{
			Firmata.setPinMode(i, PIN_MODE_OUTPUT);
		}
	}
#endif
	firmataExt.reset();
}

void initTransport()
{
	// Uncomment to save a couple of seconds by disabling the startup blink sequence.
	// Firmata.disableBlinkVersion();
  
#ifdef ESP8266
	// need to ignore pins 1 and 3 when using an ESP8266 board. These are used for the serial communication.
	Firmata.setPinMode(1, PIN_MODE_IGNORE);
	Firmata.setPinMode(3, PIN_MODE_IGNORE);
#endif
#ifdef ENABLE_WIFI
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, password);
	pinMode(VERSION_BLINK_PIN, OUTPUT);
	bool pinIsOn = false;
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(100);
		pinIsOn = !pinIsOn;
		digitalWrite(VERSION_BLINK_PIN, pinIsOn);
	}
	Firmata.begin(serverStream);
	Firmata.blinkVersion(); // Because the above doesn't do it.
#else 
	Firmata.begin(57600); // Jose Luis Cruz
#endif
}

void initFirmata()
{
#ifdef ENABLE_DIGITAL
	firmataExt.addFeature(digitalInput);
	firmataExt.addFeature(digitalOutput);
#endif
	
#ifdef ENABLE_ANALOG
	firmataExt.addFeature(analogInput);
	firmataExt.addFeature(analogOutput);
#endif
	
#ifdef ENABLE_SERVO
	firmataExt.addFeature(servo);
#endif
	
#ifdef ENABLE_I2C
	firmataExt.addFeature(i2c);
#endif
	
#ifdef ENABLE_ONE_WIRE
	firmataExt.addFeature(oneWire);
#endif

#ifdef ENABLE_SERIAL
	firmataExt.addFeature(serial);
#endif
	
#ifdef ENABLE_BASIC_SCHEDULER
	firmataExt.addFeature(scheduler);
#endif
	
  firmataExt.addFeature(reporting);
#ifdef ENABLE_SPI
	firmataExt.addFeature(spi);
#endif
#ifdef ENABLE_ACCELSTEPPER
	firmataExt.addFeature(accelStepper);
#endif
	
#ifdef ENABLE_DHT
	firmataExt.addFeature(dhtFirmata);
#endif

#ifdef ENABLE_FREQUENCY
	firmataExt.addFeature(frequency);
#endif

#ifdef ENABLE_SLEEP
	firmataExt.addFeature(sleeper);
#endif

	Firmata.attach(SYSTEM_RESET, systemResetCallback);
  // Jose Luis Cruz
  Firmata.attach(START_SYSEX, sysexCallback);
  analogReadResolution(10); // Jose Luis Cruz
}

void setup()
{
	// Set firmware name and version.
	// Do this before initTransport(), because some client libraries expect that a reset sends this automatically.
	Firmata.setFirmwareNameAndVersion("ConfigurableFirmata", FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
	initTransport();
	Firmata.sendString(F("Booting device. Stand by..."));
  initFirmata();

	Firmata.parse(SYSTEM_RESET);
}

void loop()
{
	while(Firmata.available()) 
	{
		Firmata.processInput();
		if (!Firmata.isParsingMessage()) 
		{
			break;
		}
	}

	firmataExt.report(reporting.elapsed());
#ifdef ENABLE_WIFI
	serverStream.maintain();
#endif
}



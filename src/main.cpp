#include <Arduino.h>

#include <../lib/led/QwiicLedStick.h>
#include <../lib/SoilMoistureSensor/SoilMoistureSensor.h>

static LED *_leds;
static SoilMoisureSensor _soilMoisureSensor;

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println("Zio Qwiic Soil Moisture Sensor Master Awake");

  Wire.begin();
  _soilMoisureSensor.testForConnectivity();
  // _soilMoisureSensor.ledOn();
  // delay(1000);

  // Serial.begin(115200);
  // Wire.begin();

  // Serial.println("Initializing");
  // _leds = new LED();
  // _leds->begin();
  // Serial.println("Starting");
}

void loop()
{
  // put your main code here, to run repeatedly:

  _soilMoisureSensor.getValue();
  _soilMoisureSensor.ledOn();
  delay(1000);
  _soilMoisureSensor.ledOff();
  delay(1000);

  // Serial.println("Red");
  // _leds->setLEDColor(255, 0, 0);
  // delay(500);
  // Serial.println("Green");
  // _leds->setLEDColor(0, 255, 0);
  // delay(500);
  // Serial.println("Blue");
  // _leds->setLEDColor(0, 0, 255);
  // delay(500);
}
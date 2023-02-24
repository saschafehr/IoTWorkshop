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
}

void loop()
{
  // put your main code here, to run repeatedly:

  _soilMoisureSensor.getValue();
  _soilMoisureSensor.ledOn();
  delay(1000);
  _soilMoisureSensor.ledOff();
  delay(1000);
}
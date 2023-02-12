/*
  Library made with love and help from
  Qwiic LED Stick Library : https://github.com/sparkfun/SparkFun_Qwiic_LED_Stick_Arduino_Library
  and
  Qwiic Soil Moisture Sensor Example: https://github.com/sparkfun/Zio-Qwiic-Soil-Moisture-Sensor
*/

#include "SoilMoistureSensor.h"

// Constructor
SoilMoisureSensor::SoilMoisureSensor()
{
  _sensorAddress = 0x28; // default address
}

// Start I2C communication
boolean SoilMoisureSensor::begin(uint8_t address, TwoWire &wirePort)
{
  if (address < 0x08 || address > 0x77)
    return false;           // invalid I2C addresses
  _sensorAddress = address; // store the address in a private global variable
  _i2cPort = &wirePort;     // Grab which port the user wants us to use

  return isConnected();
}

boolean SoilMoisureSensor::isConnected()
{
  _i2cPort->beginTransmission(_sensorAddress);
  if (_i2cPort->endTransmission() == 0)
    return true;
  return false;
}

// GetValue
uint16_t SoilMoisureSensor::getValue()
{
  uint16_t ADC_VALUE = 0;

  Wire.beginTransmission(_sensorAddress);
  Wire.write(COMMAND_GET_VALUE);
  Wire.endTransmission();

  Wire.requestFrom(_sensorAddress, 2);

  while (Wire.available())
  { // slave may send less than requested
    uint8_t ADC_VALUE_L = Wire.read();
    //  Serial.print("ADC_VALUE_L:  ");
    //  Serial.println(ADC_VALUE_L,DEC);
    uint8_t ADC_VALUE_H = Wire.read();
    //  Serial.print("ADC_VALUE_H:  ");
    //  Serial.println(ADC_VALUE_H,DEC);
    ADC_VALUE = ADC_VALUE_H;
    ADC_VALUE <<= 8;
    ADC_VALUE |= ADC_VALUE_L;
    Serial.print("ADC_VALUE:  ");
    Serial.println(ADC_VALUE, DEC);
  }
  uint16_t x = Wire.read();
  return ADC_VALUE;
}

void SoilMoisureSensor::ledOn()
{
  Wire.beginTransmission(_sensorAddress);
  Wire.write(COMMAND_LED_ON);
  Wire.endTransmission();
}

void SoilMoisureSensor::ledOff()
{
  Wire.beginTransmission(_sensorAddress);
  Wire.write(COMMAND_LED_OFF);
  Wire.endTransmission();
}

void SoilMoisureSensor::testForConnectivity()
{
  Wire.beginTransmission(_sensorAddress);
  // check here for an ACK from the slave, if no ACK don't allow change?
  if (Wire.endTransmission() != 0)
  {
    Serial.println("Check connections. No slave attached.");
    while (1)
      ;
  }
}
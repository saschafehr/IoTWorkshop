/*
	Library made with love and help from
	Qwiic LED Stick Library : https://github.com/sparkfun/SparkFun_Qwiic_LED_Stick_Arduino_Library
	and
	Qwiic Soil Moisture Sensor Example: https://github.com/sparkfun/Zio-Qwiic-Soil-Moisture-Sensor
*/

#ifndef Qwiic_Soil_Moisture_Sensor_h
#define Qwiic_Soil_Moisture_Sensor_h

#include "Arduino.h"
#include <Wire.h>

#define COMMAND_LED_OFF (0x00)
#define COMMAND_LED_ON (0x01)
#define COMMAND_GET_VALUE (0x05)
#define COMMAND_NOTHING_NEW (0X99)

class SoilMoisureSensor
{
	// user-accessible "public" interface
public:
	SoilMoisureSensor();
	// Initialize parameters such as I2C address and port for communication
	boolean begin(uint8_t address = 0x23, TwoWire &wirePort = Wire); // If user doesn't specificy then 0x23 and Wire will be used

	// Test I2C connection on I2C address
	boolean isConnected();

	// get then Value of de Sensor
	uint16_t getValue();

	// turn on/off the LED
	void ledOn();
	void ledOff();

	void testForConnectivity();

private:
	// This stores the current I2C address of the LED Stick
	uint8_t _sensorAddress;
	// This stores the requested i2c port
	TwoWire *_i2cPort;
};

#endif
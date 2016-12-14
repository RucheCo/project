#include "tempSonde.h"
#include <DallasTemperature.h>
#include <OneWire.h> // librairie pour capteur OneWire

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setupSonde()
{
  sensors.begin();
}


float getTempSonde()
{
  float tempetf = 0.0;
  
  sensors.requestTemperatures(); // Send the command to get temperatures

  tempetf = sensors.getTempCByIndex(0); 
  return (tempetf);
  
}

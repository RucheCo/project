#include "HX711.h"
#include "weightScale.h"
#include "tempSonde.h"
#include "DHT22.h"


void setup() 
{
  setupSonde();
  weightScale_init();
  Serial.begin(9600);
}

void loop() 
{
  float temp = 0.0;
  float weight = 0.0;
  float humidity = 0.0;
  temp = getTempSonde();
  weight = weightScale_value();
  humidity = Humidity_value();
  Serial.println(weight);
  Serial.println(temp);
  Serial.println(humidity);
}

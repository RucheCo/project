#include "HX711.h"
#include "weightScale.h"
#include "tempSonde.h"



void setup() 
{
  setupSonde();
  weightScale_init();
  Serial.begin(9600);
}

void loop() 
{
  getTempSonde();
  weightScale_value();
  Serial.println(weightScale_value());

}

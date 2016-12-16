//#include "HX711.h"
//#include "weightScale.h"
//#include "tempSonde.h"
//#include "RTC.h"
#include "DHT11.h"


void setup() 
{
  //setupSonde();
  //setRtcTime();
  //weightScale_init();
  Serial.begin(9600);
}

void loop() 
{
  //unsigned long int TS = 0;
  //float temp = 0.0;
  //float weight = 0.0;
  float humidity = 0.0;
  //TS = get_timestamp();
  //temp = getTempSonde();
  //weight = weightScale_value();
  humidity = Humidity_value();
  //Serial.println(weight);
  //Serial.print("temperature : ");
  //Serial.println(temp);
  //Serial.print("timestamp : ");
  //Serial.println(TS);
  //Serial.println();
  Serial.println(humidity);
}

//#include "HX711.h"
//#include "weightScale.h"
//#include "tempSonde.h"
//#include "RTC.h"
//#include "DHT11.h"
//#include "lcdI2C.h"

void setup() 
{
  Serial.begin(9600);
  Serial.println("setup begin");
  //setupSonde();
  //setRtcTime();
  //weightScale_init();
  setupLcdI2C();
  Serial.println("setup done");

}

void loop() 
{
  Serial.println("main start");
  
  char sentenceRow1[16] = "that is how";
  char sentenceRow2[16] = "it is done";  
  //unsigned long int TS = 0;
  //float temp = 0.0;
  //float weight = 0.0;
  //int humidity = 0;
  //TS = get_timestamp();
  //temp = getTempSonde();
  //weight = weightScale_value();
  //humidity = GetHumidity();
  //Serial.println(weight);
  //Serial.print("temperature : ");
  //Serial.println(temp);
  //Serial.print("timestamp : ");
  //Serial.println(TS);
  //Serial.println();  
  lcdPrint(sentenceRow1,sentenceRow2);
  Serial.println("main done");
  
  delay(1000);
}

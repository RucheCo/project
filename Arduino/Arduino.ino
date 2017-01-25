//#include "HX711.h"
//#include "weightScale.h"
//#include "tempSonde.h"
//#include "RTC.h"
//#include "DHT11.h"
//#include "lcdI2C.h"
#include "vol.h"
#include "states.h"

State state = Start;

void setup() 
{
  attachInterrupt(digitalPinToInterrupt(3), fonctionVol, RISING);
  Serial.begin(9600);
  Serial.println("setup begin");
  //setupSonde();
  //setRtcTime();
  //weightScale_init();
  //setupLcdI2C();
  Serial.println("setup done");

}

void loop() 
{
  
  //char sentenceRow1[16] = "that is how";
  //char sentenceRow2[16] = "it is done";  
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
  //lcdPrint(sentenceRow1,sentenceRow2);
  //delay(1000);

  ///////////////////////////////////////////////////////////////////

  // Machine a état

switch(state)
    {
      case Start:
        Serial.println("State Start");
        //TODO Test jour ou nuit

        //TODO SI jour, Etat suivant = DeepSleepShort
        //TODO SI nuit, Etat suivant = DeepSleepLong
        delay(1000);
        break;
      case DeepSleepShort:
        Serial.println("State DeepSleepShort");
        //TODO Ajouter appel à standby(...)

        //TODO Etat suivant = Start
        delay(1000);
        break;
      case DeepSleepLong:
        Serial.println("State DeepSleepLong");
        //TODO Ajouter appel à standby(...)

        //TODO Etat suivant = Start
        delay(1000);
        break;
      case MesPHT:
        Serial.println("State MesPHT");
        //TODO Ajouter appel à mesPHT(...)

        //TODO Test poids

        //TODO SI poids < 5 Kg, Etat suivant = MesGPS
        //TODO SINON Etat suivant = Send
        delay(1000);
        break;
      case MesGPS:
        Serial.println("State MesGPS");
        //TODO Ajouter appel à mesGPS(...)
        delay(1000);
        break;
      case Send:
        Serial.println("State Send");
        //TODO Ajouter appel à send(...)

        //TODO Test jour ou nuit

        //TODO SI jour, Etat suivant = DeepSleepShort
        //TODO SI nuit, Etat suivant = DeepSleepLong
        delay(1000);
        break;
      default:
        Serial.println("State Error");
        //TODO Etat suivant = Start
    }//end switch
}//end loop

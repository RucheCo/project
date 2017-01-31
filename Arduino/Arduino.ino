#include "HX711.h"
#include "weightScale.h"
#include "tempSonde.h"
#include "RTC.h"
#include "DHT11.h"
#include "lcdI2C.h"
//#include "rapine.h"
#include "states.h"

State state = Start;
int nbrOfLoop = 0;
bool theft = false;

//HX711 scale(PIN_BAL_DATA, PIN_BAL_CLK);

void setup() 
{
/*  pinMode(PIN_ALIM_CAPTEUR, OUTPUT);
  digitalWrite(PIN_ALIM_CAPTEUR, HIGH);
  
  pinMode(PIN_ALIM_GPS, OUTPUT);
  digitalWrite(PIN_ALIM_GPS, HIGH);
  
  pinMode(PIN_ALIM_SIGFOX, OUTPUT);
  digitalWrite(PIN_ALIM_SIGFOX, HIGH);*/
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);  
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);  
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);

  attachInterrupt(digitalPinToInterrupt(3), fonctionVol, RISING);
  Serial.begin(9600);
  Serial.println("setup begin");
  /*
  setupSonde();
  setupRTC();
  setRtcTime();
  weightScale_init();
  setupLcdI2C();
  */
  //delay(2000);
  Serial.begin(9600);
  Serial.println("setup done");
}

void loop() 
{
  nbrOfLoop++;
  Serial.print("\n\nLoop : ");
  Serial.println(nbrOfLoop);
  
  char sentenceRow1[16] = "that is how";
  char sentenceRow2[16] = "it is done";  
  char trameSigFox[255] = "it is done";  
  unsigned long int TS = 123456789;
  float temp = 19.74;
  float weight = 50.9;
  int humidity = 93;
  int tempInt = 0;
  double gpsLong = 48.814519;
  double gpsLat = 2.378518;
  int batterie = 73;
  
//  TS = get_timestamp();
//  temp = getTempSonde();
  tempInt = convTemp(temp);
//  weight = weightScale_value();
//  humidity = GetHumidity();
//  Serial.print("poids : ");
//  Serial.println(weight);
//  Serial.print("temperature : ");
//  Serial.println(temp);
//  Serial.print("humidity : ");
//  Serial.println(humidity);
//  Serial.print("timestamp : ");
//  Serial.println(TS);
//  Serial.println(theft);
  Serial.println();
  
  if (theft == false)
  {
    Serial.write("AT$SF=1234\n\r");
    sprintf(trameSigFox, "AT$SF=%.2X %.4X %.2X %.2X %.8X %.2X \n", theft, (int)(weight*10), humidity, tempInt, TS, batterie);
    //sprintf(trameSigFox, "vol %.2X; poids %.4X; humm %.2X; temp %.2X; TS %.8X; batterie %.2X; \n", theft, (int)(weight*10), humidity, tempInt, TS, batterie);
    Serial.write(trameSigFox);    
  }
  else
  {
    sprintf(trameSigFox, "AT$SF= %.2X %.8X %.8X %.2X; \n", theft, (int)(weight*10), (long)(gpsLong*1000000), (long)(gpsLat*1000000), batterie);
    //sprintf(trameSigFox, "vol %.2X; GPS Long %.8X; GPS Lat %.8X; batterie %.2X; \n", theft, (int)(weight*10), (long)(gpsLong*1000000), (long)(gpsLat*1000000), batterie);
    Serial.write(trameSigFox);
  }

  //lcdPrint(sentenceRow1,sentenceRow2);
  delay(300);

  ///////////////////////////////////////////////////////////////////

  // Machine a état
/*
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
  }//end switch*/
}//end loop

void fonctionVol()
{
    theft = true;
    Serial.println("!!!interupt!!!");

    //truc
    //*pointeurState = MesGPS;
}

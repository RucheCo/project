#include "HX711.h"
#include "weightScale.h"
#include "tempSonde.h"
#include "states.h"
#include "standby.h"
#include "period.h"
#include "constants.h"
#include "DHT22.h"


State state = Start;        // état de base : start


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
  //humidity = Humidity_value();
  Serial.print("Poids = ");
  Serial.println(weight);
  Serial.print("Temperature = ");
  Serial.println(temp);
  Serial.print("Humidité = ");
  Serial.println(humidity);
  switch(state)
  {
    case Start:
        Serial.println("State Start");
        //TODO Test jour ou nuit

        //TODO SI jour, Etat suivant = DeepSleepShort
        //TODO SI nuit, Etat suivant = DeepSleepLong
        break;
    case DeepSleepShort:
        Serial.println("State DeepSleepShort");
        standby(DEEPSLEEP_SHORT_DURATION);
        state = Start;
        break;
    case DeepSleepLong:
        Serial.println("State DeepSleepLong");
        standby(DEEPSLEEP_LONG_DURATION);
        state = Start;
        break;
    case MesPHT:
        Serial.println("State MesPHT");
        //TODO Ajouter appel à mesPHT(...)

        //TODO Test poids

        //TODO SI poids < 5 Kg, Etat suivant = MesGPS
        //TODO SINON Etat suivant = Send
        break;
    case MesGPS:
        Serial.println("State MesGPS");
        //TODO Ajouter appel à mesGPS(...)
        break;
    case Send:
        Serial.println("State Send");
        //TODO Ajouter appel à send(...)

        //TODO Test jour ou nuit

        //TODO SI jour, Etat suivant = DeepSleepShort
        //TODO SI nuit, Etat suivant = DeepSleepLong
        break;
    default:
        Serial.println("State Error");
        state = Start;
  }
}

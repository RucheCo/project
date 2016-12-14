#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

// fonction qui déclare le RTC
void setupRTC ()
{
  //RTC_DS1307 rtc;
  char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
}

// fonction pour mettre a jour l'heure du RTC en fonction de la date et heure de la compilation
void setRtcTime ()
{
  if (! rtc.begin()) 
  {
    Serial.println("Erreur : Pas de RTC trouvé");
  }
  // récupération de la date et heure courante au moment de la compilation
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

// fonction pour recupérer le timestamp (nb de secondes depuis 00:00:00 01/01/1970)
int get_timestamp () 
{
    int timestamp;
    DateTime now = rtc.now();

//    // decommenter pour verifier
//    Serial.print(now.year(), DEC);
//    Serial.print('/');
//    Serial.print(now.month(), DEC);
//    Serial.print('/');
//    Serial.print(now.day(), DEC);
//    Serial.print(" (");
//    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
//    Serial.print(") ");
//    Serial.print(now.hour(), DEC);
//    Serial.print(':');
//    Serial.print(now.minute(), DEC);
//    Serial.print(':');
//    Serial.print(now.second(), DEC);
//    Serial.println();
//    
//    Serial.print(" depuis minuit 1/1/1970 = ");
//    Serial.print(now.unixtime());
//    Serial.print("s = ");

    timestamp = now.unixtime();
    return timestamp;
}

// fonction qui récupère un binaire ( 1 si jour, 0 si nuit)
int get_day ()
{
    int jour;
    DateTime now = rtc.now();
    
    if ( (now.hour() < 6) || (now.hour() > 22) )
    {
      jour = 0;
    }
    else
    {
      jour = 1;
    }
    
    return jour;
}

//////////////////////////////////////////////////////
//    Serial.print(now.unixtime() / 86400L);
//    Serial.println("d");

//    //Pour calculer une date dans le futur
//    DateTime future (now + TimeSpan(7,12,30,6));
//    
//    Serial.print(" now + 7d + 30s: ");
//    Serial.print(future.year(), DEC);
//    Serial.print('/');
//    Serial.print(future.month(), DEC);
//    Serial.print('/');
//    Serial.print(future.day(), DEC);
//    Serial.print(' ');
//    Serial.print(future.hour(), DEC);
//    Serial.print(':');
//    Serial.print(future.minute(), DEC);
//    Serial.print(':');
//    Serial.print(future.second(), DEC);
//    Serial.println();

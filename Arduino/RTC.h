#ifndef RTC_H_INCLUDE
#define RTC_H_INCLUDE

// fonction qui déclare le RTC
void setupRTC ()

// fonction pour mettre a jour l'heure du RTC en fonction de la date et heure de la compilation
void setRtcTime ()

// fonction pour recupérer le timestamp (nb de secondes depuis 00:00:00 01/01/1970)
int get_timestamp () 

// fonction qui récupère un binaire ( 1 si jour, 0 si nuit)
int get_day ()

#endif //RTC_H_INCLUDE

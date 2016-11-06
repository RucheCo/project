/*
    ETATS DE LA MACHINE A ETAT
 */

#ifndef CODE_HEADERS_STATES_H_
#define CODE_HEADERS_STATES_H_

typedef enum				// définit des états pour la machine à état
{
	Start,                  // départ
	DeepSleepShort,         // mise en veille courte (le jour)
	DeepSleepLong,          // mise en veille longue (la nuit)
	MesPHT,              	// mesure du poids, humidité et température
	MesGPS,					// mesure de la position GPS
	Send					// envoi sur sigfox
}
State;

#endif /* CODE_HEADERS_STATE_H_ */

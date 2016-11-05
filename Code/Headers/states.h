/*
    ETATS DE LA MACHINE A ETAT
*/
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

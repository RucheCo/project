/*
    ETATS DE LA MACHINE A ETAT
*/
	typedef enum				// d�finit des �tats pour la machine � �tat
	{
	    Start,                  // d�part
		DeepSleepShort,         // mise en veille courte (le jour)
		DeepSleepLong,          // mise en veille longue (la nuit)
		MesPHT,              	// mesure du poids, humidit� et temp�rature
		MesGPS,					// mesure de la position GPS
		Send					// envoi sur sigfox
	}
	State;

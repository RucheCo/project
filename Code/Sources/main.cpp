/*
    main.cpp comportant la machine d'état.
    Les fonctions appelées par ce main doivent être déclarées dans des headers.
 */

#include <stdio.h>
#include "mbed.h"
#include "../Headers/period.h"
#include "../Headers/states.h"
#include "../Headers/constants.h"

Serial pc(USBTX, USBRX);    // serie USB (ne pas oublier de souder sur la carte)

State state = Start;		// état de base : start

int main ()
{
	while(true)
	{
		switch(state)
		{
			case Start:
				printf("State Start\n");
				//TODO Test jour ou nuit

				//TODO SI jour, Etat suivant = DeepSleepShort
				//TODO SI nuit, Etat suivant = DeepSleepLong
				break;
			case DeepSleepShort:
				printf("State DeepSleepShort\n");
				//TODO Ajouter appel à standby(...)

				//TODO Etat suivant = Start
				break;
			case DeepSleepLong:
				printf("State DeepSleepLong\n");
				//TODO Ajouter appel à standby(...)

				//TODO Etat suivant = Start
				break;
			case MesPHT:
				printf("State MesPHT\n");
				//TODO Ajouter appel à mesPHT(...)

				//TODO Test poids

				//TODO SI poids < 5 Kg, Etat suivant = MesGPS
				//TODO SINON Etat suivant = Send
				break;
			case MesGPS:
				printf("State MesGPS\n");
				//TODO Ajouter appel à mesGPS(...)
				break;
			case Send:
				printf("State Send\n");
				//TODO Ajouter appel à send(...)

				//TODO Test jour ou nuit

				//TODO SI jour, Etat suivant = DeepSleepShort
				//TODO SI nuit, Etat suivant = DeepSleepLong
				break;
			default:
				printf("State Error\n");
				//TODO Etat suivant = Start
		}//end switch
	}//end while
}//end main

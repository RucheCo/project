/*
    main.cpp comportant la machine d'�tat.
    Les fonctions appel�es par ce main doivent �tre d�clar�es dans des headers.
 */

#include <stdio.h>
#include "mbed.h"
#include "../Headers/period.h"
#include "../Headers/states.h"
#include "../Headers/constants.h"

Serial pc(USBTX, USBRX);    // serie USB (ne pas oublier de souder sur la carte)

State state = Start;		// �tat de base : start

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
				//TODO Ajouter appel � standby(...)

				//TODO Etat suivant = Start
				break;
			case DeepSleepLong:
				printf("State DeepSleepLong\n");
				//TODO Ajouter appel � standby(...)

				//TODO Etat suivant = Start
				break;
			case MesPHT:
				printf("State MesPHT\n");
				//TODO Ajouter appel � mesPHT(...)

				//TODO Test poids

				//TODO SI poids < 5 Kg, Etat suivant = MesGPS
				//TODO SINON Etat suivant = Send
				break;
			case MesGPS:
				printf("State MesGPS\n");
				//TODO Ajouter appel � mesGPS(...)
				break;
			case Send:
				printf("State Send\n");
				//TODO Ajouter appel � send(...)

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

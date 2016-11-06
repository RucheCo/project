/*
    main.cpp comportant la machine d'�tat.
    Les fonctions appel�es par ce main doivent �tre d�clar�es dans des headers.
 */

#include <stdio.h>
#include "mbed.h"
#include "../Headers/period.h"
#include "../Headers/states.h"
#include "../Headers/constants.h"

State state = Start;		// �tat de base : start

int main ()
{
	while(true)
	{
		switch(state)
		{
			case Start:
				printf("State Start\n");
				break;
			case DeepSleepShort:
				printf("State DeepSleepShort\n");
				//TODO Ajouter appel � standby(...)
				break;
			case DeepSleepLong:
				printf("State DeepSleepLong\n");
				//TODO Ajouter appel � standby(...)
				break;
			case MesPHT:
				printf("State MesPHT\n");
				//TODO Ajouter appel � mesPHT(...)
				break;
			case MesGPS:
				printf("State MesGPS\n");
				//TODO Ajouter appel � mesGPS(...)
				break;
			case Send:
				printf("State Send\n");
				//TODO Ajouter appel � send(...)
				break;
			default:
				printf("State Error\n");
		}
	}
}

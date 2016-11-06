/*
    main.cpp comportant la machine d'état.
    Les fonctions appelées par ce main doivent être déclarées dans des headers.
 */

#include <stdio.h>
#include "mbed.h"
#include "../Headers/period.h"
#include "../Headers/states.h"
#include "../Headers/constants.h"

State state = Start;		// état de base : start

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
				//TODO Ajouter appel à standby(...)
				break;
			case DeepSleepLong:
				printf("State DeepSleepLong\n");
				//TODO Ajouter appel à standby(...)
				break;
			case MesPHT:
				printf("State MesPHT\n");
				//TODO Ajouter appel à mesPHT(...)
				break;
			case MesGPS:
				printf("State MesGPS\n");
				//TODO Ajouter appel à mesGPS(...)
				break;
			case Send:
				printf("State Send\n");
				//TODO Ajouter appel à send(...)
				break;
			default:
				printf("State Error\n");
		}
	}
}

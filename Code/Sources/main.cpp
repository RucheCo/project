/*
    main.cpp comportant la machine d'état.
    Les fonctions appelées par ce main doivent être déclarées dans des headers.
 */

#include <stdio.h>
#include "mbed.h"
#include "../Headers/period.h"
#include "../Headers/states.h"

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
			break;
		case DeepSleepLong:
			printf("State DeepSleepLong\n");
			break;
		case MesPHT:
			printf("State MesPHT\n");
			break;
		case MesGPS:
			printf("State MesGPS\n");
			break;
		case Send:
			printf("State Send\n");
			break;
		default:
			printf("State Error\n");
		}
	}
}

/*
    main.cpp comportant la machine d'état.
    Les fonctions appelées par ce main doivent être déclarées dans des headers.
 */

#include <stdio.h>
#include "mbed.h"
#include "states.h"
#include "period.h"


int main ()
{
	while(true)
	{
		switch(State)
		{
		case Start:
			printf("State Start");
			break;
		case DeepSleepShort:
			printf("State DeepSleepShort");
			break;
		case DeepSleepLong:
			printf("State DeepSleepLong");
			break;
		case MesPHT:
			printf("State MesPHT");
			break;
		case MesGPS:
			printf("State MesGPS");
			break;
		case Send:
			printf("State Send");
			break;
		}
	}
}

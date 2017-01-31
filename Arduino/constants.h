/*
 * constants.h
 *
 *  Created on: 6 nov. 2016
 *      Author: mathieusab
 */

#ifndef CODE_HEADERS_CONSTANTS_H_
#define CODE_HEADERS_CONSTANTS_H_

// assignation PIN
#define PIN_HUMIDITY 0
#define PIN_SIGFOX_TX 1
#define PIN_TEMPERATURE 2
#define PIN_INTERUPT 3
#define PIN_ALIM_CAPTEUR 4
#define PIN_ALIM_GPS 5
#define PIN_ALIM_SIGFOX 6
#define PIN_BUTTON 7
#define PIN_GPG_RX 9
#define PIN_GPS_TX 10

#define PIN_GPS_TX 10
#define PIN_BAL_DATA 11
#define PIN_BAL_CLK 12

// durée courte de veille en minutes
#define DEEPSLEEP_SHORT_DURATION (8*60)

// durée courte de veille en minutes
#define DEEPSLEEP_LONG_DURATION (60*60)

// Heure du lever du soleil min (au solstice 2016) (https://www.kalendrier.com/heure-lever-coucher-soleil/2016/juin/paris.html)
#define DAY_THRESHOLD (6) //06h00 du matin

// Heure du coucher du soleil max (au solstice 2016) (https://www.kalendrier.com/heure-lever-coucher-soleil/2016/juin/paris.html)
#define NIGHT_THRESHOLD (22) //22h00

#endif /* CODE_HEADERS_CONSTANTS_H_ */

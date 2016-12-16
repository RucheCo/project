
#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
//		100nF entre VDD et GND
//		R: 1.5 Kohm
int pinDHT11 = 2;
SimpleDHT11 dht11;

unsigned int GetHumidity() {
  
  // read without samples.
  byte humidity = 0;
  if (dht11.read(pinDHT11, &humidity, NULL)) {
    Serial.print("Read DHT11 failed.");
    return;
  }
 return((unsigned int)humidity);
}

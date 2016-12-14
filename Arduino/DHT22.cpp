#include "DHT.h"   // Librairie des capteurs DHT
#define DHTPIN 2    // Changer le pin sur lequel est branché le DHT
#define DHTTYPE DHT22     // DHT 22  (AM2302)
 
DHT dht(DHTPIN, DHTTYPE); 

unsigned int Humidity_value() {
  // Délai de 2 secondes entre chaque mesure. La lecture prend 250 millisecondes
  delay(2000);
 
  // Lecture du taux d'humidité
  float h = dht.readHumidity();
  // Lecture de la température en Celcius
 // float t = dht.readTemperature();
  // Pour lire la température en Fahrenheit
//  float f = dht.readTemperature(true);
  
  // Stop le programme et renvoie un message d'erreur si le capteur ne renvoie aucune mesure
  if (isnan(h)) {
    Serial.println("Echec de lecture !");
    return;
  }
 

  Serial.print("Humidite: "); 
  Serial.print(h);
  Serial.print(" %\t");
  
  return((unsigned int)h);
  
}

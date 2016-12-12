#include "HX711.h"
#include "weightScale.h"



void setup() {
  weightScale_init();
  Serial.begin(9600);
}

void loop() {
  weightScale_value();
  Serial.println(weightScale_value());

}

#include "weightScale.h"
#include "HX711.h"

#define DOUT  3
#define CLK  2

float calibration_factor = 6300; //-7050 worked for my 440lb max scale setup
HX711 scale(DOUT, CLK);


void weightScale_init()
{
  scale.set_scale();
  scale.tare(); //Reset the scale to 0  
}

double weightScale_value()
{
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  double pesee =scale.get_units()*0.45359237;
  return pesee;
}

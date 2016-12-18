bool ds = false;

void setup() 
{
  if(ds)
  {
    pinMode(LED_BUILTIN,OUTPUT);
    for (int i = 0; i < 14 ; i++)
    {
      pinMode(i, OUTPUT);
    }
  }
  else
  {
    pinMode(LED_BUILTIN,OUTPUT);
  }
}

void loop() 
{
  if(ds)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN,LOW);
    delay(500);
    
    ADCSRA &= ~(1<<7); // desactive les ADC
    SMCR |= (1<<2); // power down mode
    SMCR |= 1; // active le DS

    MCUCR |= (3<<5); // desactive BOD
    MCUCR = (MCUCR & ~(1<<5)) | (1<<6); // desactive BOD
    
    __asm__ __volatile__("sleep");
  }
  else
  {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN,LOW);
    delay(500);
  }
  
}

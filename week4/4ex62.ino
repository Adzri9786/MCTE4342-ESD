unsigned long previousTime;
unsigned char *E_dir = (unsigned char *)0x2a;     //Points to DDRE
unsigned char *E_writer = (unsigned char *)0x2b;  //Points to PORTE

void setup()
{
  *E_dir = 0b00010000; // make PE4 as output
for(;;)
{
  unsigned long currentTime = millis();
  
  if (((*E_writer) & 0b00010000) == 0)  //If the LED is currently OFF
  {
    if (currentTime - previousTime >= 2000)  //2000 is OFF duration
    {
      *E_writer |= 0b00010000;     //Turn ON the LED (pin PE4)
      previousTime = currentTime;  //Take note of the time
    }
  }
  else  //LED is currently ON
  {
    if (currentTime - previousTime >= 2000)  //2000 is ON duration
    {
      *E_writer &= 0b11101111;     //Turn OFF the LED (pin PE4)
      previousTime = currentTime;  //Take note of the time
    }
  }
}
}
  
void loop ()
  {}

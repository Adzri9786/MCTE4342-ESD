/*
There are two LEDs whose anodes are connected to PD5 and PD6 respectively. The LED 1
needs to be flashing with ON time 750 ms and OFF time 350 ms. The LED 2 needs to be
flashing with ON time 400 and OFF time 600 ms
*/


/* 
 * Supported port: B, C, D
 * Supported pin: 1-7
 *
 */
class LedBlinky {
  char port;
  int pin;
  int pinBin;
  int onDurationMs;
  int offDurationMs;
  unsigned char *writer;  // Port data register
  unsigned long previousMillis;


public:
  LedBlinky(char Port, int Pin, int onDur, int offDur) {
    Port = Port;
    Pin = Pin;
    onDurationMs = onDur;
    offDurationMs = offDur;

    previousMillis = 0;
    
   switch (Port) {
      case 'B': writer = (unsigned char *)0x25; break;
      case 'C': writer = (unsigned char *)0x28; break;
      case 'D': writer = (unsigned char *)0x2b; break;
    }
    // hardcode the binary representation for now
    switch (Pin) {
      case 0: pinBin = 0b00000001; break;
      case 1: pinBin = 0b00000010; break;
      case 2: pinBin = 0b00000100; break;
      case 3: pinBin = 0b00001000; break;
      case 4: pinBin = 0b00010000; break;
      case 5: pinBin = 0b00100000; break;
      case 6: pinBin = 0b01000000; break;
      case 7: pinBin = 0b10000000; break;
    }

   
  }
  void Run() {
    unsigned long currentTime = millis();

    
    if (((*writer) & pinBin) == 0)  //when LED is OFF
    {
      if (currentTime - previousMillis >= offDurationMs)  // OFF duration
      {
        *writer |= pinBin;             // Turn ON LED
        previousMillis = currentTime;  
      }
    } else  //when LED is ON
    {
      if (currentTime - previousMillis >= onDurationMs)  // ON duration
      {
        // inevrt the pinBin value, for instance 01110011 to 10001100
        *writer &= ~pinBin;            // Turn OFF Led. 
        previousMillis = currentTime;  
      }
    }
  }
};

LedBlinky led1('D', 3, 750, 350); //red led, Pb3
LedBlinky led2('D', 4, 400, 600); //yellow led, Pb4

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  led1.Run();
  led2.Run();
}

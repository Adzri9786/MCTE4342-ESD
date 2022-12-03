unsigned char *B_dir = (unsigned char* ) 0x24;
unsigned char *B_port = (unsigned char* ) 0x25;
unsigned char *B_pin = (unsigned char* ) 0x23;
unsigned char *C_dir = (unsigned char* ) 0x27;
unsigned char *C_port = (unsigned char* ) 0x28;
unsigned char *C_pin = (unsigned char* ) 0x26;

unsigned long debounceDelay = 50;    // the debounce duration, increase if the output flickers

class PortButton {
  public:
    int binPin;
    int lastButtonState = LOW;  // the previous reading from the input pin
    int buttonState;            // the current reading from the input pin
    unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
    int count = 0;
    unsigned char *read;
    int classpin = classpin;

    
    
    PortButton(int pin, int classpin) {
     switch (classpin) {
        case 'B': read = (unsigned char *)0x23; break;      //converts to point address for reading
        case 'C': read = (unsigned char *)0x26; break;
        case 'D': read = (unsigned char *)0x29; break;
    }

      switch (pin) {
        case 0: binPin = 0b00000001; break;
        case 1: binPin = 0b00000010; break;
        case 2: binPin = 0b00000100; break;
        case 3: binPin = 0b00001000; break;
        case 4: binPin = 0b00010000; break;
        case 5: binPin = 0b00100000; break;
        case 6: binPin = 0b01000000; break;
        case 7: binPin = 0b10000000; break;
      }
    }
};

void setup() {
 
  *B_dir = 0b00000000;   //or *dir = 32 or *dir = 0x20
  *B_port = 0b11111111; //Pb 2,3,4 as output

  *C_dir = 0b00000000;   //or *dir = 32 or *dir = 0x20
  *C_port = 0b11111111; //PC 4,5 as output
  
  Serial.begin(9600);
}

// For now, port B, C and D are supported but only able to run one port at a time
PortButton btns[] = {
  PortButton(2, 'B'), PortButton(3, 'B'), PortButton(4, 'B'), PortButton(5, 'C')
};

int numOfBtns = sizeof(btns) / sizeof(int);

void loop() {

  for (int i = 0; i < numOfBtns; i++) {
    int reading = (((*B_pin) & btns[i].binPin) != 0); //B_pin or C_pin
 

    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (reading != btns[i].lastButtonState) {
      // reset the debouncing timer
      btns[i].lastDebounceTime = millis();
    }

    if ((millis() - btns[i].lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:

      //    Serial.println(buttonState);
      // if the button state has changed:
      if (reading != btns[i].buttonState) {
        btns[i].buttonState = reading;
        if (btns[i].buttonState == LOW) btns[i].count += 1;
      }
    }

    // save the reading. Next time through the loop, it'll be the lastButtonState:
    btns[i].lastButtonState = reading;
  }

  char str[80];
  sprintf(str, "Btn B2: %d, Btn B3: %d, Btn B4: %d, Btn C5: %d", btns[0].count, btns[1].count, btns[2].count, btns[3].count);
  Serial.println(str);

}

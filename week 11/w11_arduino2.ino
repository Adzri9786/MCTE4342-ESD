const int buttonPin = 2; // pin to read the button input

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  // set the button pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the value of the button:
  int buttonState = digitalRead(buttonPin);
  // send the value of the button over the serial port:
  Serial.write(buttonState);
  // delay for a little while:
  delay(100);
}

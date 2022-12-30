const int ledPin = 13; // pin to control the LED

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  // set the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // check if there is data available to read:
  if (Serial.available() > 0) {
    // read the data and store it in a variable:
    int data = Serial.read();
    // turn the LED on or off based on the value of the data:
    if (data == 1) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}

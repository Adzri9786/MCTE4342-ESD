int motorPin = 3;  // pin to control the motor
int speed = 0;    // variable to store the speed of the motor

void setup() {
  // set the motor pin as an output:
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // increase the speed of the motor from 0 to 255:
  for (speed = 0; speed < 256; speed++) {
    analogWrite(motorPin, speed);
    delay(10);
  }
  // decrease the speed of the motor from 255 to 0:
  for (speed = 255; speed >= 0; speed--) {
    analogWrite(motorPin, speed);
    delay(10);
  }
}

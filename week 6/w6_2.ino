
int servoPin = 3;
void setup() {
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 180; i++) {
    int pwm = map(i, 0, 180, 0, 255); // converting angle to pwm(duty cycle)
    analogWrite(servoPin, pwm);
    delayMicroseconds(1500);
  }
  delay(2000);

  for (int i = 180; i >= 0; i--) {
    int pwm = map(i, 0, 180, 0, 255);// converting angle to pwm(duty cycle)
    analogWrite(servoPin, pwm);
    delayMicroseconds(1500);
  }
  delay(2000);
}

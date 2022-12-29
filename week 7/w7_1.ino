int buttonPin = 2;
int buttonLED = 11;
int blinkLED = 12;
volatile int buttonState;

void buttonInterrupt() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(buttonLED, LOW);
  }
  if (buttonState == LOW) {
    digitalWrite(buttonLED, HIGH);
  }
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonLED, OUTPUT);
  pinMode(blinkLED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE);
}

void loop() {
  digitalWrite(blinkLED, HIGH);
  delay(200);
  digitalWrite(blinkLED, LOW);
  delay(200);
}

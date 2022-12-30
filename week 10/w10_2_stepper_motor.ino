const int motorPin1 = 2;  // pin to control the first coil of the stepper motor
const int motorPin2 = 3;  // pin to control the second coil of the stepper motor
const int motorPin3 = 4; // pin to control the third coil of the stepper motor
const int motorPin4 = 5; // pin to control the fourth coil of the stepper motor

void step(int direction, int delayTime) {
  // define the sequence of steps for the motor to rotate in one direction
  static const int steps[4][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
  };

  // loop through the sequence of steps:
  for (int i = 0; i < 4; i++) {
    int step = steps[i][0];
    digitalWrite(motorPin1, step);
    step = steps[i][1];
    digitalWrite(motorPin2, step);
    step = steps[i][2];
    digitalWrite(motorPin3, step);
    step = steps[i][3];
    digitalWrite(motorPin4, step);
    delay(delayTime);  // delay between steps (in milliseconds)
  }
}

void setup() {
  // set the motor pins as outputs:
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  // rotate the motor at a slow speed:
  step(1, 100);
  delay(500);

  // rotate the motor at a faster speed:
  step(-1, 50);
  delay(500);

  /*This code will make the motor rotate at a slow speed for half a 
  second, then rotate at a faster speed for half a second,and so on. 
  The speed of the motor can be adjusted by changing the value of the 
  delayTime argument passed to the step() function.*/
}

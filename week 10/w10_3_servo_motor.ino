#include <Servo.h>

Servo myServo;  // create a servo object

void setup() {
  myServo.attach(2);  // attach the servo to pin 2

}

void loop() {
    // move the servo to the 0 degree position slowly:
  myServo.writeMicroseconds(1000); //1000 is fully counter-clockwise
  delay(1000);
  
  // move the servo to the 90 degree position quickly:
  myServo.writeMicroseconds(1500);//1500 is in the middle
  delay(1000);
  
  // move the servo to the 180 degree position slowly:
  myServo.writeMicroseconds(2000);  //2000 is fully clockwise 
  delay(1000);
  
  
  // move the servo to the 90 degree position:
  myServo.write(90);
  delay(1000);
  
  // move the servo to the 180 degree position:
  myServo.write(180);
  delay(1000);
  
  // move the servo to the 0 degree position:
  myServo.write(0);
  delay(1000);
 
}

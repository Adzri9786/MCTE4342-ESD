void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3, 0); //duty cycle 0 to 255. conected to pin 3 which have pwm
  delay(1000);
  analogWrite(3, 50);
  delay(1000);
  analogWrite(3, 200);
  delay(1000);
  analogWrite(3, 250);
  delay(1000);
  analogWrite(3, 255);
  delay(1000);
 
}

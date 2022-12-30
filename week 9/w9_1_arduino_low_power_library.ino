// Arduino Idle Sleep Mode Example. 
// The following code automatically enables and disables the Idle Sleep Mode.

#include <LowPower.h>


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  pinMode(2,OUTPUT);
  
}
void loop() {

  digitalWrite(LED_BUILTIN,HIGH);
  digitalWrite(2,HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(2,LOW);
  Serial.println("Going to sleep for 8 seconds");
  delay(100);
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,SPI_OFF, USART0_OFF, TWI_OFF);
  delay(1000);
  Serial.println("Arduino: Hey I just Woke up");
  Serial.println("");
  delay(2000);
}

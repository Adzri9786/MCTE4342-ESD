// constants won't change
const int trigPin = 6; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int echoPin = 7; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int ledPin  = 12; // Arduino pin connected to LED's pin
const int disLim = 50; // distacne limit centimeters
const int timelim = 30000; //set time limit, 30 s

int highscore, finalscore;
int scorecomp; //compare score
int test;

unsigned long oldtime;


#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

// variables will change:
float duration_us, distance_cm;

//interrupts 
int buttonPin = 2;

//serial communication
#include "MegunoLink.h"
#include "ArduinoTimer.h"
RecordTable MyTable;
ArduinoTimer TableRefreshTimer;

//define motor and fsr pin
#define FSR  A0
#define EN1  9
#define M1A  8
#define M1B  4

//intialize velocity and value of fsr
int veloc,value;

void setup() {
  Serial.begin (9600);      
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(ledPin, OUTPUT);  

  pinMode(M1A, OUTPUT); //motor flick
  pinMode(M1B, OUTPUT); //motor return
  pinMode(FSR, INPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, LOW);
  //pinMode(buttonPin, INPUT);
  //attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, RISING);

 lcd.begin(); // initialize the LCD

 lcd.backlight();  // Turn on the blacklight and print a message.
  
  //lcd.setCursor(1, 0); //set space (x,y)
  //lcd.print("SCORE : ");
  //lcd.clear();

   // Read the highscore from the first location in the EEPROM memory
  highscore = EEPROM.read(0);

  test = 0; 
  scorecomp = 0;
  MyTable.SetNumberOfDecimalPlaces(5);
}

void loop() {
  //read fsr value and flick motor
  value = analogRead(FSR);
  delay(10);
  veloc = map(value, 0, 255, 0, 255);
  analogWrite(EN1, veloc); //adjust speed
  digitalWrite(M1A, HIGH);   
  digitalWrite(M1B, LOW);  
  delay(100);
  digitalWrite(M1A, HIGH);   
  digitalWrite(M1B, HIGH);  
  delay(100);
  digitalWrite(M1A, LOW);   
  digitalWrite(M1B, HIGH);  
  delay(100);
  digitalWrite(M1A, HIGH);   
  digitalWrite(M1B, HIGH);  
  delay(100);

  
  // generate 10-microsecond pulse to trig pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from echo pin
  duration_us = pulseIn(echoPin, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;



  //if the ball is within the range of distance limit,the led will light up
  if(distance_cm < disLim)
    digitalWrite(ledPin, HIGH); // turn on LED
  else
    digitalWrite(ledPin, LOW);  // turn off LED

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.print(" cm ");
  Serial.print(test);
  Serial.print("  max: ");
  Serial.println(highscore);


int score = map(distance_cm,50,0,0,100); //map distance in cm to score inversely

//prevent-ve value of score
if(score <0)
{score = 0;}
else;


if(score > highscore)
{
highscore = score;

EEPROM.write(0, highscore); // Write the highscore to the EEPROM memory
}
else;

  //lcd.setCursor(1, 0); //set space (x,y)
  lcd.print("SCORE:     MAX: ");
  lcd.setCursor(1, 1);
  //display score
  lcd.print(score);
  lcd.setCursor(12, 1);
  lcd.print(highscore);
  delay(500);
  lcd.clear();

   //set game duration, time limit
   if ( (millis()-oldtime) > timelim) {
       oldtime = millis();

      // Do something every after 30s, based on time limit
      lcd.clear();
      lcd.print("Final Score!! ");
      lcd.setCursor(6, 1);
    //display final score
    finalscore = highscore;
    lcd.print(finalscore);
      delay(10000);
      MyTable.ClearAllRows();
      lcd.clear();
      
      
    }

if(scorecomp<score)    
 {MyTable.AddRow(score,highscore,finalscore);
 //send serial data to megunoLink to generate score board
}
else;

scorecomp = score;



}

void handleInterrupt() {
  test = test +1; //test interrupt
   highscore = 0;
   EEPROM.write(0, highscore);
   }

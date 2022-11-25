#include <IRremote.h>
 
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define TRIG A5
#define ECHO A4
 
const int L = 25;
const int d = 12*L;
const int robotSpeedA = 180;
const int robotSpeedB = 175;
double duration, distance;
double travelled = 0;
 
int forwardTime = 600;
int turnTimeLeft = 700;
int turnTimeRight = 675;
 
void setup() {
Serial.begin(9600);
Serial.println("Task 3");
 
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
 
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
 
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
 
delay(1000);
}
 
void moveForward() {
 
  analogWrite(ENA, robotSpeedA);
  analogWrite(ENB, robotSpeedB);
 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
 
  delay(forwardTime);
 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 
  delay(500);
 
}
 
void moveBackward() {
  analogWrite(ENA, robotSpeedA);
  analogWrite(ENB, robotSpeedB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(forwardTime);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
}
void turnRight() {
 
  analogWrite(ENA, robotSpeedA);
  analogWrite(ENB, robotSpeedB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(turnTimeRight);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
}
 
void turnLeft() {
 
  analogWrite(ENA, robotSpeedA);
  analogWrite(ENB, robotSpeedB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(turnTimeLeft);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
}
 
 
 
 
 
 
 
 
 
void loop() {
  while(travelled < d)
{
  dist_calc();
 
  if(distance<0.5*L){
    Serial.println("Obstsacle detected within 10 cm");
 
    turnLeft();
 
    moveForward();
 
    turnRight();
 
    moveForward();
   
    travelled = travelled +60;
 
    turnRight();
 
    moveForward();
 
    turnLeft();
  }
  moveForward();
  travelled = travelled + 20;
  }
  delay(10000);
}
double dist_calc(){
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG,LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = 100.0*(343.0*(duration/2.0))/1000000.0;
  return distance;
}


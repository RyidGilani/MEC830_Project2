#include <IRremote.h>
 
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
 
#define IRrec 12
 
const int L = 25;
const int d = 6*L;
const int robotSpeedA = 180;
const int robotSpeedB = 190;
 
int forwardTime = 3550;
int turnTimeRight = 900;
int turnTimeLeft = 1100;
 
IRrecv irrecv(IRrec);
decode_results results;
 
void setup() {
Serial.begin(9600);
Serial.println("Task 1");
 
 
irrecv.enableIRIn();
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
void loop()
{
if(irrecv.decode(&results))
{
Serial.println(results.value, HEX);
 
switch (results.value) {
  case 0xFF629D:
    moveForward();
    break;
 
  case 0xFF22DD:
    turnLeft();
    break;
 
  case 0xFFC23D:
    turnRight();
    break;
 
  case 0xFFA857:
    moveBackward();
    break;
}
irrecv.resume();
}
}









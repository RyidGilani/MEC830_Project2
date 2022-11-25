 
#define ENA 5
#define ENB 6
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 12
 
const int L = 20;
const int d = 6*L;
const int robotSpeedA = 180;
const int robotSpeedB = 190;
const int robotSpeedC = 150;
const int robotSpeedD = 150;
 
int forwardTime = 3550;
int turnTimeRight = 900;
int turnTimeLeft = 1100;
 
void setup() {
Serial.begin(9600);
Serial.println("Task 2");
 
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
 
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
 
delay(1000);
 
}
 
 
 
void moveForward() {
 
  analogWrite(ENA, robotSpeedA);
  analogWrite(ENB, robotSpeedB);
 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
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
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
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
 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
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
 
moveForward();
Serial.println("Robot moved 120 cm to p1");
turnRight();
Serial.println("Robot turned 90 degrees CW");
moveForward();
Serial.println("Robot moved 120 cm to p2");
turnLeft();
Serial.println("Robot turned 90 degrees CCW");
moveForward();
Serial.println("Robot moved 120 cm to p3");
int i=0;
for(i = 0; i<=30; i++) {
  Serial.println("Goal position reached");
  delay(100);
  }
}

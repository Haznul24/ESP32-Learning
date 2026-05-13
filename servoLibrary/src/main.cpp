#include <Arduino.h>
#include <myServo.h>

int basePot = 32;
int shoulderPot = 35;
int elbowPot = 34;
myServo baseServo(27, 0, 0, 180);
myServo shoulderServo(26, 1, 0, 180);
myServo elbowServo(25, 2, 0, 180);

void setup() {
  Serial.begin(115200);
  pinMode(basePot, INPUT);
  pinMode(shoulderPot, INPUT);
  pinMode(elbowPot, INPUT);
}

void loop() {
  int baseAngle = map(analogRead(basePot), 0, 4095, 0, 180);
  int shoulderAngle = map(analogRead(shoulderPot), 0, 4095, 0, 180);
  int elbowAngle = map(analogRead(elbowPot), 0, 4095, 0, 180);

  Serial.println(baseAngle);
  Serial.println(shoulderAngle);
  Serial.println(elbowAngle);
  
  baseServo.move(baseAngle);
  shoulderServo.move(shoulderAngle);
  elbowServo.move(elbowAngle);
}
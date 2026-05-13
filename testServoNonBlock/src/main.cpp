#include <Arduino.h>

#define pinServo 25
#define channel1 0

int angle = 0;
int direction = 1;
unsigned long lastTime = 0;
int interval = 100;

int angleToPulse(int ang) {
  return map(ang, 0, 180, 500, 9000);
}

void setup() {
  Serial.begin(115200);
  ledcSetup(channel1, 50, 16);
  ledcAttachPin(pinServo, channel1);
  Serial.println("Setup done");
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastTime >= interval) {
    lastTime = currentTime;

    ledcWrite(channel1, angleToPulse(angle));
    Serial.println("Angle: " + angle);

    angle += direction;

    if (angle >= 180) direction = -1;
    if (angle <= 0)   direction = 1;
  }
}


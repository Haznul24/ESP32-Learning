#include <Arduino.h>

int pinButton1 = 18;    // Change Mode
int pinButton2 = 19;    // Record Waypoint
int pinButton3 = 5;

bool rawB1 = false, lastRawB1 = false, stableB1 = false;
bool rawB2 = false, lastRawB2 = false, stableB2 = false;
bool rawB3 = false, lastRawB3 = false, stableB3 = false;
unsigned long lastChangeB1 = 0, lastChangeB2 = 0, lastChangeB3 = 0;
const unsigned long DEBOUNCE_MS = 10;

void readButtons()  {
  unsigned long currentTime = millis();

  // PB 1
  rawB1 = (digitalRead(pinButton1)) == LOW;
  if (rawB1 != lastRawB1) {
    lastChangeB1 = currentTime;
    lastRawB1 = rawB1;
  }
  else if (currentTime - lastChangeB1 > DEBOUNCE_MS) {
    stableB1 = rawB1;
  } 
}

void setup() {
  Serial.begin(115200);
  pinMode(pinButton1, INPUT_PULLUP);
}

void loop() {
  readButtons();
  if (stableB1) {
    Serial.println("Button 1 Pressed");
  }

}
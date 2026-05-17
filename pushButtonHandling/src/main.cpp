#include <Arduino.h>

int pinButton1 = 18;    // Change Mode
int pinButton2 = 19;    // Record Waypoint
int pinButton3 = 5;

unsigned long ignoreUntilB1 = 0;
bool stateB1 = HIGH, prevStateB1 = HIGH;
const unsigned long DEBOUNCE_MS = 100;

void readButtons()  {
  unsigned long now = millis();

  // PB 1
  if (now >= ignoreUntilB1 && digitalRead(pinButton1) != stateB1) {
    ignoreUntilB1 = now + DEBOUNCE_MS;
    stateB1 = !stateB1;
  }
}

void handleButtons()  {
  if (stateB1 != prevStateB1) {
    prevStateB1 = stateB1;
    if (stateB1 == LOW ){
      Serial.println("Button 1 Pressed");
    }
  }
}



void setup() {
  Serial.begin(115200);
  pinMode(pinButton1, INPUT_PULLUP);
}

void loop() {
  readButtons();
  handleButtons();
}
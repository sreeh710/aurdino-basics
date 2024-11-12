// C++ code
//

#define LED 12
#define BUTTON 2
byte LEDState = HIGH;
volatile boolean release;
volatile unsigned long lastTimePressed = millis();
unsigned long bounceDelay = 50;

void toggle() {
  if(LEDState == LOW){
  LEDState = HIGH;
  } else {
      LEDState = LOW;
  }
  digitalWrite(LED,LEDState);
}
void buttonReleaseInterrupt()
{
  unsigned long timeNow = millis();
  if(timeNow-lastTimePressed > bounceDelay) {
      release = true;
      lastTimePressed = timeNow;
  }
}

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON),
                  buttonReleaseInterrupt,
                  FALLING);

}

void loop()
{
  if(release) {
    toggle();
    release = false;
  }
}
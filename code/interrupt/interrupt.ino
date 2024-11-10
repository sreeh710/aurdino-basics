// C++ code
//

#define LED 12
#define BUTTON 2
byte LEDState = HIGH;
volatile boolean release;
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
  release = true;
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

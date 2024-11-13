#include <EEPROM.h>

#define ADDRESS 100
#define LED 11
#define POTENTIOMETER A2
byte maxBrightness;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED, OUTPUT);
  maxBrightness = EEPROM.read(ADDRESS);
  Serial.println(maxBrightness);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    int data = Serial.parseInt();
    if(data >= 0 && data <= 255) {
      EEPROM.write(ADDRESS, data);
      maxBrightness = data;   
    }
  }
  byte brightness = analogRead(POTENTIOMETER)/4;
  if(brightness< maxBrightness){  
    analogWrite(LED, brightness);
  }
}

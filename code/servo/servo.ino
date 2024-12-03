#include <Servo.h>
#define SERVO 6

Servo servo;


void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Clockwise rotation
  for(int deg = 0; deg<= 180; deg++) {
    servo.write(deg);
    delay(15);  
  }  

  // AntiClockwise rotation

  for(int deg = 180; deg>=0 ; deg-- ) {
    servo.write(deg);
    delay(15);
  }
}

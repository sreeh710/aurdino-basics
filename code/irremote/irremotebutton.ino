#include <IRremote.hpp>
#define IR_RECEIVE_PIN 2

#define BUTTON_0 12
#define BUTTON_1 16
#define BUTTON_2 17
#define BUTTON_PLAY 5


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // // Establish serial communication
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver

}

void loop() {
  // put your main code here, to run repeatedly:
if(IrReceiver.decode()) {
  IrReceiver.resume();
  int command = IrReceiver.decodedIRData.command;
  if(command == BUTTON_0 ) {
      Serial.println("BUTTON_0 Is Pressed !");
      }
 else if(command == BUTTON_1 ) {
      Serial.println("BUTTON_1 Is Pressed !");
      }
 else if(command == BUTTON_2 ) {
      Serial.println("BUTTON_2 Is Pressed !");
      }
 else if(command == BUTTON_PLAY ) {
      Serial.println("BUTTON_PLAY Is Pressed !");
      }
  else {
          Serial.println("Press a valid Button !");

  }                     
  Serial.println("----------");
}
}

#include<LiquidCrystal.h>

#define RS A5
#define E A4
#define D4 2
#define D5 3
#define D6 4
#define D7 5

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Hello World !");
  }

void loop() {
  // put your main code here, to run repeatedly:

}

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
  lcd.setCursor(0,0);
  lcd.print("Welcome Aurdino!");
  lcd.setCursor(5,1);
  lcd.print("Awesome ! ");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("   You Are        ");

  }

void loop() {
  // put your main code here, to run repeatedly:

}

#define BUTTON 2

volatile bool pressed = false;
volatile unsigned long timePressed = millis();
volatile unsigned long bounceDelay = 50;
unsigned long count = 0;

void buttonPressed() {
  unsigned long timeNow = millis();
  if(timeNow - timePressed > bounceDelay) {
    timePressed = timeNow;
    pressed = true;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON),
   buttonPressed,
   RISING);

}


void loop() {
  // put your main code here, to run repeatedly:
  if(pressed) {
    count++;
    pressed = false;
    Serial.print("The counter is :");
    Serial.println(count); 
  }
}

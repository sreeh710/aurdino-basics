#define PR A3
#define LED 7
#define THRESHOLD 600

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinmMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(PR);
  if(value > threshold) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

}

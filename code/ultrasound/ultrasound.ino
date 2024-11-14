#define TRIGGER 3
#define ECHO 2
unsigned long timeBegin = millis();
unsigned long ultrasonicTriggerDelay = 100;

void triggerUltraSound() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

}
double getDistance() {
  double time = pulseIn(ECHO,HIGH);
  double distance = time/58.0;
  return distance;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

}

void loop() {
   unsigned long timeNow = millis();
  // put your main code here, to run repeatedly:
  if(timeNow - timeBegin > ultrasonicTriggerDelay) {
      timeBegin = timeNow;
      triggerUltraSound();
      Serial.println(getDistance());
  }

}

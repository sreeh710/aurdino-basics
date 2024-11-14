#define TRIGGER 2
#define ECHO 3
unsigned long timeBegin = millis();
unsigned long ultrasonicTriggerDelay = 100;

void triggerUltraSound() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

}

volatile unsigned long pulseBegin;
volatile unsigned long pulseEnd;
volatile bool distAvailable = false;
double distance;
double previousDistance = 400;

double getDistance() {
  if(distAvailable) {
  distAvailable = false;
  double time = pulseEnd - pulseBegin;
  distance = time/58.0;
  }
  if(distance> 400) {  // Filtering greater than max value
    return previousDistance;
  }
  distance = previousDistance * 0.7 + distance * 0.3; // Complimentary Filter
  previousDistance = distance;
  return distance;
}

void echoPinInterrupt() {
  if(digitalRead(ECHO) == HIGH) {
    pulseBegin = micros();

  } else {
    pulseEnd =  micros();
    distAvailable = true;
  }


}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  attachInterrupt(digitalPinToInterrupt(ECHO),
                  echoPinInterrupt,
                  CHANGE
                  );

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
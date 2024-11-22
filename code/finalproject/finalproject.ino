#define ECHO 3
#define TRIGGER 2

unsigned long ultrasonicStart = millis();
unsigned long ultrasonicDelay = 60;
volatile unsigned long pulseBegin;
volatile unsigned long pulseEnd;
volatile boolean distanceAvailable;
double previousDistance = 400.0;

void triggerUltrasonic() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);  
  digitalWrite(TRIGGER, LOW);

}
double getDistance() {
  double duration = pulseEnd - pulseBegin;
  double distance = duration/58.0;
  if(distance > 400) {
    return previousDistance;
  }
  distance = 0.6 * previousDistance + 0.4 * distance;
  previousDistance = distance;
  return distance;
}

void ultrasonicInterrupt() {
  if(digitalRead(ECHO) == HIGH) {
    pulseBegin = micros();
  } else {
    pulseEnd = micros();
    distanceAvailable = true;
  }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1145200);
  pinMode(TRIGGER , OUTPUT);
  pinMode(ECHO , INPUT);
  attachInterrupt(digitalPinToInterrupt(ECHO),
  ultrasonicInterrupt,
  CHANGE
  );
}


void loop() {
  // put your main code here, to run repeatedly:
  unsigned long ultrasonicNow = millis();
  if(ultrasonicNow - ultrasonicStart > ultrasonicDelay ) {
    ultrasonicStart = ultrasonicNow;
    triggerUltrasonic();
  }
  if(distanceAvailable) {
    distanceAvailable = false;
    double dist = getDistance();
    Serial.println(dist);
  }

}

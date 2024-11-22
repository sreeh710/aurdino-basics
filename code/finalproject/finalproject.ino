#define ECHO 3
#define TRIGGER 2
#define YELLOW 11

unsigned long ultrasonicStart = millis();
unsigned long ultrasonicDelay = 60;
volatile unsigned long pulseBegin;
volatile unsigned long pulseEnd;
volatile boolean distanceAvailable;
double previousDistance = 400.0;


unsigned long yellowBegin = millis();
unsigned long yellowDelay = 100;
byte yellowState = LOW

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
void toggleYellow() {
  yellowState = (yellowState == HIGH) ? LOW: HIGH;
  digitalWrite(YELLOW, yellowState);
}
void setYellowRateFromDist(double distance) {
  // 0 ... 400 cm -> 0 - 1600 ms
  yellowDelay = distance * 4;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1145200);
  pinMode(TRIGGER , OUTPUT);
  pinMode(ECHO , INPUT);
  pinMode(YELLOW , OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ECHO),
  ultrasonicInterrupt,
  CHANGE
  );
}


void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeNow = millis();
  if(timeNow - ultrasonicStart > ultrasonicDelay ) {
    ultrasonicStart = timeNow;
    triggerUltrasonic();
  }
  if(timeNow - yellowBegin > yellowDelay) {
    yellowBegin = timeNow;
    toggleYellow();
  }

  if(distanceAvailable) {
    distanceAvailable = false;
    double dist = getDistance();
    setYellowRateFromDist(dist);
    Serial.println(dist);
  }

}

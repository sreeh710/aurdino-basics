#define PR A3
#define SIZE 100

unsigned int long lastTimeRead = millis();
unsigned int long  sampledelay = 50;
int lindex[SIZE] = {0};
int counter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(1145200);
}
int computeAverage( ) {
  long sum = 0;
  for (int i= 0; i< SIZE;i++) {
    sum = sum + lindex[i];
  }
  return sum/SIZE;
}


void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timenow = millis();
  if(timenow- lastTimeRead > sampledelay) {
    lindex[counter] = analogRead(PR);
    counter ++;
    if(counter == 100) {
      counter = 0;
      Serial.print("Average :");
      Serial.println(computeAverage());
    }
    lastTimeRead = timenow;
  }

}

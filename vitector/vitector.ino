const int curPin = A0;

double LI, PI, maxCur, minCur = 0.0;

void setup(){
  pinMode(curPin, INPUT);

  Serial.begin(9600);
  Serial.println("Ready to measure. Start within 3 seconds.");

  for (int count=3; count>0; count--) Serial.print(count); Serial.print(" ");
}

void loop(){
  LI = (2.5 - (analogRead(curPin) * (5.0 / 1024.0))) / 0.066;
  if (LI > maxCur){
    maxCur = LI;
  } else if (LI < minCur){
    minCur = LI;
  }
  Serial.print("Current: "); Serial.print(LI); Serial.print("A, di/dt: "); Serial.println(LI - PI);
  PI = LI;
}
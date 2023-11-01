const int curPin = A0;

const int MEASURE_ITERATION = 10000;

double I, pI, maxCur, minCur = 0.0;

void setup(){
  pinMode(curPin, INPUT);

  Serial.begin(9600);
}

void loop(){
  Serial.println("Ready to measure. Start within 3 seconds.");
  for (int count=3; count>0; count--){
    Serial.print(count); Serial.print(" ");
    delay(1000);
  }

  for (int iter = 0; iter < MEASURE_ITERATION; iter++){
    I = (2.5 - (analogRead(curPin) * (5.0 / 1024.0))) / 0.066;

    if (I > maxCur) maxCur = I;
    else if (I < minCur) minCur = I;

    if (I - pI)

    Serial.print("Current: "); Serial.print(I); Serial.print("A, di/dt: "); Serial.println(I - pI);
    pI = I;
  }
  
  Serial.print("Measure Current 10000 iteration, Max of Current: "); Serial.print(maxCur); Serial.print("A / Min of Current: "); Serial.print(minCur); Serial.println("A");
}
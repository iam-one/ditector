// ACS712, ZMPT101B sensor sampling >> get data and save
// it will analyzed by python

const int resVolPin = A0;
const int indVolPin = A1;
const int resCurPin = A2;
const int indCurPin = A3;

double resVolAvg, indVolAvg, resCurAvg, indCurAvg,
  resVolSum, indVolSum, resCurSum, indCurSum = 0.0;

void setup(){
  pinMode(resVolPin, INPUT);
  pinMode(indVolPin, INPUT);
  pinMode(resCurPin, INPUT);
  pinMode(resCurPin, INPUT);

  Serial.begin(9600);
  Serial.println("Ready to measure. Start within 3 seconds.");

  for (int count=3; count>0; count--) Serial.println(count);

  Serial.print("resVolAvg\tindVolAvg\tindCurAvg\tresCurAvg\tTime");
}

void loop(){
  // Serial.print((((int)(analogRead(resVolPin) / 4.092) % 100) / 10));
  // Serial.print("\t");
  // Serial.print((((int)(analogRead(indVolPin) / 4.092) % 100) / 10));
  // Serial.print("\t");
  // Serial.print((2.5 - (analogRead(resCurPin) * (5.0 / 1024.0))) / 0.066);
  // Serial.print("\t");
  Serial.println((2.5 - (analogRead(indCurPin) * (5.0 / 1024.0))) / 0.066);
}
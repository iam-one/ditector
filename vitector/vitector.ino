// ACS712, ZMPT101B sensor sampling >> get data and save
// it will analyzed by python

const int resVolPin = A0;
const int indVolPin = A1;
const int resCurPin = A2;
const int indCurPin = A3;

unsigned long int currentTime, observeTime = 0;
float resVolAvg, indVolAvg, resCurAvg, indCurAvg,
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
    if (millis() - currentTime > 200){
        observeTime = currentTime;
        currentTime = millis();

        for (int i; i<100; i++){
            resVolSum += analogRead(resVolPin);
            indVolSum += analogRead(indVolPin);
            resCurSum += analogRead(resCurPin);
            indCurSum += analogRead(indCurPin);
            delayMicroseconds(2500);
        }

        resVolAvg = (((int)(resVolSum / 4.092) % 100) / 10);
        indVolAvg = (((int)(indVolSum / 4.092) % 100) / 10);
        resCurAvg = (2.5 - ((resCurSum / 100.0) * (5.0 / 1024.0))) / 0.066;
        indCurAvg = (2.5 - ((indCurSum / 100.0) * (5.0 / 1024.0))) / 0.066;

        Serial.print(resVolAvg);
        Serial.print("\t");
        Serial.print(indVolAvg);
        Serial.print("\t");
        Serial.print(resCurAvg);
        Serial.print("\t");
        Serial.print(indCurAvg);
        Serial.print("\t");
        Serial.println(observeTime);

        resCurSum, indCurSum, resVolSum, indVolSum = 0;
    }
}
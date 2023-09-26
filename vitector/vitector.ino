// ACS712, ZMPT101B sensor sampling >> get data and save
// it will analyzed by python

const int resVolPin = A0;
const int indVolPin = A1;
const int resCurPin = A2;
const int indCurPin = A3;

float resVol, indVol, resCur, indCur = 0.0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    checkCur(resCurPin);
    checkCur(indCurPin);
}

float checkVol(int pin){
    
}

float checkCur(int pin){
    float acsValue, samples, avgAcs = 0.0;

    for (int x; x < 150; x++){
        acsValue = analogRead(pin);
        samples += acsValue;
        delayMicroseconds(3000);
    }
    avgAcs = (2.5 - ((samples / 150.0) * (5.0 / 1024.0))) / 0.185;
    return avgAcs;
}
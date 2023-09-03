const int resVolPin = A0;
const int indVolPin = A1;
const int resIntPin = A2;
const int indIntPin = A3;

float acs = 0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    AcsValueF = (2.5 - (avgAcs * (5.0 / 1024.0)) ) / 0.185;
}
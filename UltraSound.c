const int epin=2;
const int tpin=3;

int distance;

void setup(){

Serial.begin (9600);

pinMode(epin, INPUT);
pinMode(tpin, OUTPUT);


}

void loop() {

long duration, cm;
digitalWrite(tpin, LOW);
delayMicroseconds(2);

digitalWrite(tpin, HIGH);
delayMicroseconds(10);

digitalWrite(tpin, LOW);

duration = pulseIn(epin, HIGH);
distance = duration * .034/2;

Serial.print(distance);
Serial.print("cm");
Serial.println();
delay(300);
}

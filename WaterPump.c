
const int epin = 2;
const int tpin = 3;
const int pumpPin = 7;

const int tankHeight = 20;
const int pumpOnLevel = 15;
const int pumpOffLevel = 5;

long duration;
int distance;
int waterPercent;

bool pumpState = false;

void setup() {
  Serial.begin(9600);

  pinMode(epin, INPUT);
  pinMode(tpin, OUTPUT);
  pinMode(pumpPin, OUTPUT);

  digitalWrite(tpin, LOW);
  digitalWrite(pumpPin, LOW);
}

void loop() {
  digitalWrite(tpin, LOW);
  delayMicroseconds(2);

  digitalWrite(tpin, HIGH);
  delayMicroseconds(10);

  digitalWrite(tpin, LOW);

  duration = pulseIn(epin, HIGH, 30000);

  if (duration == 0) {
    Serial.println("Sensor reading error!");
    digitalWrite(pumpPin, LOW);
    pumpState = false;
    delay(500);
    return;
  }

  distance = duration * 0.034 / 2;

  waterPercent = (tankHeight - distance) * 100 / tankHeight;
  waterPercent = constrain(waterPercent, 0, 100);

  if (distance > pumpOnLevel) {
    pumpState = true;
  }
  else if (distance <= pumpOffLevel) {
    pumpState = false;
  }

  digitalWrite(pumpPin, pumpState ? HIGH : LOW);

  Serial.println("----------------------");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Water Level: ");
  Serial.print(waterPercent);
  Serial.println("%");

  Serial.print("Water Pump: ");
  Serial.println(pumpState ? "ON" : "OFF");

  delay(500);
}

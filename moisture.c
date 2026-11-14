
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int SensorPin = A0;

void setup()
{
  lcd.begin(20, 4);

  lcd.setCursor(0, 0);
  lcd.print("Test");

  lcd.setCursor(0, 1);
  lcd.print("SOIL MOISTURE SENSOR");
}

void loop()
{
  int val = analogRead(SensorPin);

  int moisture = map(val, 1023, 0, 0, 100);
  moisture = constrain(moisture, 0, 100);

  lcd.setCursor(0, 3);
  lcd.print("Soil Moisture:     ");

  lcd.setCursor(0, 3);
  lcd.print("Moisture: ");
  lcd.print(moisture);
  lcd.print("%   ");

  delay(500);
}

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" Hello World! ");

}

void loop() {
  lcd.setCursor(0,1);
  lcd.print(analogRead(A0));
  Serial.println(analogRead(A0));
  delay(200);
}

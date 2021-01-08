#include <LiquidCrystal.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int c=10,value;
//
void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0); lcd.print("How Many Left");
  Serial.begin(9600);
  Serial.println("Welcome!Arduino Uno Serial Test Program..");
  Serial.print("ECHO>>");
}
//
void loop(){
  if(Serial.available()){ value=Serial.read(); }
  if(value=='o'){ if(++c>10)c=0; }
  if(value=='x'){ if(--c<0)c=10; }
  Serial.println(c);
  lcd.setCursor(7,1);
  if(c<10)lcd.print(0); // if(c<10)lcd.print(" ");
  lcd.print(c);
  delay(500);
}

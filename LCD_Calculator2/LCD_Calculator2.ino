#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD의 이름,주소,크기를 설정합니다

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("calculation : ");
  delay(100);
}

void loop(){
  if(Serial.available()){
    int value1 = Serial.parseInt();
    int value2 = Serial.parseInt();
    int result = value1 + value2;
    Serial.print("value 1 : ");
    Serial.println(value1);
    Serial.print("value 2 : ");
    Serial.println(value2);
    Serial.print("value1 + value2 = ");
    Serial.println(result);

    lcd.setCursor(0,1);
    lcd.print(value1);
    lcd.print(" + ");
    lcd.print(value2);
    lcd.print(" = ");
    lcd.print(result);

    
  }    
}

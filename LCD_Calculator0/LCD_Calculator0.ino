#include <LiquidCrystal_I2C.h>


#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD의 이름,주소,크기를 설정합니다
int num1 = 0;    // 정수형 num1변수를 만들고 초기값을 0으로 설정합니다
int num2 = 0;    // 정수형 num2변수를 만들고 초기값을 0으로 설정합니다
int result = 0;  // 정수형 result변수를 만들고 초기값을 0으로 설정합니다
char sign = 0;  // 문자형 sign변수를 만들고 초기값을 0으로 설정합니다         
boolean flag = 1;

void setup() {
  Serial.begin(9600);    //시리얼 통신속도를 설정합니다
  Wire.begin();
  lcd.init();            //LCD를 초기화 합니다
  lcd.backlight();        //LCD의벡라이트를 켭니다
  lcd.setCursor(0, 0);    //커서의 위치를 0,0위치에 놓습니다.
  lcd.print("Calculation :");  //""안의 문자열을 출력합니다.
  delay(1000);
}

void loop() {
  while(Serial.available()){  //아두이노로 전송된 시리얼 버퍼에 데이터가 있다면 
      if(!flag) {
        calReset();
        flag = 1;
      }
      lcd.setCursor(0,1);   //커서의 위치를 0, 1위치에 놓습니다.
      num1 = Serial.parseInt();  //입력값을 정수값으로 전달합니다.
      sign = Serial.read();      //입력값을 아스키값으로 전달합니다.
      num2 = Serial.parseInt();  //입력값을 정수값으로 전달합니다.
      
      lcd.print(num1);   
      lcd.print(sign);
      lcd.print(num2);            //화면에 입력받은 값을 출력합니다.
      lcd.print(" = ");

      Serial.print(num1);
      Serial.print(sign);
      Serial.print(num2);
      Serial.print(" = ");
     // Serial.flush();
  
      switch(sign){
        case '+' :  //sign이 +일 경우 +계산
            result = num1 + num2;     
            break;
        case '-' :    //sign이 -일 경우 -계산
            result = num1 - num2;
            break;
        case '*' :    //sign이 *일 경우 *계산
            result = num1 * num2;
            break;
        case '/' :    //sign이 /일 경우 /계산
            result = (double)num1 / num2;
            break;
        case '%' :    //sign이 %일 경우 %계산
            result = num1 % num2;
            break;
        case 0 :
            lcd.print("                ");
            break;
        default :    //아무것도 해당안되면 에러메시지
            lcd.print("ERROR");
            result = '\0';
            break;
      }
      lcd.print(result); 
     
      Serial.println(result);
      delay(500); 
      flag = 0;
  }
}

void calReset(){
  num1 = 0;
  num2 = 0;
  sign = 0;
  lcd.setCursor(0,1);
  lcd.print("                "); //result값이 겹쳐서 출력되는것을 방지하기위해
}

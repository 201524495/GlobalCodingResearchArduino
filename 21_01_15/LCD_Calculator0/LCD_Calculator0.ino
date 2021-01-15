/*Arduino Serial Port에서 전송버튼을 눌렀을 때 설정을
  No line ending : 아무것도 보내지 않습니다.
  새 줄(new line) : 새 줄, 즉 줄 바꿈 문자('LF' = 0xa or '\n')가 추가됩니다.
  캐리지 리턴(Carriage return) : 캐리지 리턴 문자('CR' = 0xd or '\n')가 추가됩니다. (커서를 맨 앞으로 이동)
  Both LN & CR : 새 줄과 캐리지 리턴, 둘 다 수행합니다.
*/
//쓰레기 값(원하지 않은 값)이 리턴될 경우 전송 설정을 "No line ending"(line ending 없음)으로 설정합니다.
//LCD 화면이 나오지 않을 경우 뒤에있는 가변 저항기를 돌려줍니다.
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD의 이름,주소,크기를 설정합니다
int num1 = 0;    // 정수형 num1변수를 만들고 초기값을 0으로 설정합니다
int num2 = 0;    // 정수형 num2변수를 만들고 초기값을 0으로 설정합니다
int result = 0;  // 정수형 result변수를 만들고 초기값을 0으로 설정합니다
char sign = 0;  // 문자형 sign변수를 만들고 초기값을 0으로 설정합니다 

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
      calReset();
      delay(2000);
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
  }
}

void calReset(){
  num1 = 0;
  num2 = 0;
  sign = 0;
  lcd.setCursor(0,1);
  lcd.print("                "); //result값이 겹쳐서 출력되는것을 방지하기위해
}

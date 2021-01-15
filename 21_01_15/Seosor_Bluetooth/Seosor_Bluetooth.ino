#include <DHT.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); // (Tx, Rx)
char set;

//HDT 센서
#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//LED 제어
//red, greed, blue pin
#define red 13
#define green 12
#define blue 11
#define dht_dpin 7
//High - LOW
int rbutton = 0;
int bbutton = 0;
int gbutton = 0;

unsigned long time_previous, time_current;

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  
  pinMode(red,INPUT);
  pinMode(green,INPUT);
  pinMode(blue,INPUT);
  delay(300);
  pinMode(dht_dpin, INPUT);
  delay(700);
  time_previous = millis();
}

void loop() {
  time_current = millis();
  double humid = dht.readHumidity(); //습도
  double temp = dht.readTemperature(); //온도
  double bright = analogRead(A0);//조도
  
  //if(bluetooth.available()) {
  if((time_current - time_previous >= 1000) && (bluetooth.available() > 0)) {
     /*    
    set = bluetooth.read(); 
   
    Serial.print("블루투스 값 : ");
    Serial.println(set); // 휴대폰에서 입력 값
    switch(set) {
      case 'g' :
        if(gbutton == 0){
            gbutton = 1;
        }
        else if(gbutton == 1){
            gbutton = 0;
        }
        digitalWrite(green,gbutton);
        break;
      case 'b' :
        if(bbutton == 0){
            bbutton = 1;
        }
        else if(bbutton == 1){
            bbutton = 0;
        }
        digitalWrite(blue,bbutton);
        break;
      case 'r' :
        if(rbutton == 0){
            rbutton = 1;
        }
        else if(rbutton == 1){
            rbutton = 0;
        }
        digitalWrite(red,rbutton);
        break;
      case 'n' :
        rbutton = 0;
        bbutton = 0;
        gbutton = 0;
        digitalWrite(red, rbutton);
        digitalWrite(blue, bbutton);
        digitalWrite(green, gbutton);
        break;
    }*/

    Serial.print("temperature : ");       // ‘시리얼 플로터’ 사용위해 이 부분 주석 필요
    Serial.println(temp);                // 온도 값 출력 
    Serial.print("humidity : ");          // ‘시리얼 플로터’ 사용위해 이 부분 주석 필요
    Serial.println(humid);                  // 습도 값 출력
    Serial.print("light : ");       //'시리얼 플로터'
    Serial.println(bright);         // 조도 값 출력

    bluetooth.print(temp);
    bluetooth.print(",");
    bluetooth.print(humid);
    bluetooth.print(",");
    bluetooth.print(bright);
    bluetooth.println();
    
  }delay(2000); 
}

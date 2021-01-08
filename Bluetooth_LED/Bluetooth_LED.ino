#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3);
char set;
int rbutton = 0;
int bbutton = 0;
int gbutton = 0;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
if(bluetooth.available()){
  set = bluetooth.read();
  Serial.print("입력값 : ");
  Serial.println(set);
  switch(set){
      case '1' :
        if(gbutton == 0){
            gbutton = 1;
        }
        else if(gbutton == 1){
            gbutton = 0;
        }
        digitalWrite(5,gbutton);
        break;
      case '2' :
        if(bbutton == 0){
            bbutton = 1;
        }
        else if(bbutton == 1){
            bbutton = 0;
        }
        digitalWrite(7,bbutton);
        break;
      case '3' :
        if(rbutton == 0){
            rbutton = 1;
        }
        else if(rbutton == 1){
            rbutton = 0;
        }
        digitalWrite(9,rbutton);
        break;
      case '4' :
        rbutton = 0;
        bbutton = 0;
        gbutton = 0;
        digitalWrite(5, LOW);
        digitalWrite(7, LOW);
        digitalWrite(9, LOW);
        break;
      }
  }
}

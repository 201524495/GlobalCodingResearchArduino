#include <SoftwareSerial.h>
#define R_LED 6
#define B_LED 7
#define G_LED 8

SoftwareSerial bluetooth(2,3);
char set;
int rbutton = 0;
int bbutton = 0;
int gbutton = 0;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(R_LED,OUTPUT);
  pinMode(B_LED,OUTPUT);
  pinMode(G_LED,OUTPUT);
}

void loop() {
if(bluetooth.available()){
  set = bluetooth.read();
  
  Serial.print("입력값 : ");
  Serial.println(set);
  switch(set){
      case 'g'  :
        if(gbutton == 0){
            gbutton = 1;
        }
        else if(gbutton == 1){
            gbutton = 0;
        }
        digitalWrite(G_LED,gbutton);
        break;
      case 'b' :
        if(bbutton == 0){
            bbutton = 1;
        }
        else if(bbutton == 1){
            bbutton = 0;
        }
        digitalWrite(B_LED,bbutton);
        break;
      case 'r' :
        if(rbutton == 0){
            rbutton = 1;
        }
        else if(rbutton == 1){
            rbutton = 0;
        }
        digitalWrite(R_LED,rbutton);
        break;
      case 'n' :
        rbutton = 0;
        bbutton = 0;
        gbutton = 0;
        digitalWrite(R_LED, LOW);
        digitalWrite(B_LED, LOW);
        digitalWrite(G_LED, LOW);
        break;
      }
  }
}

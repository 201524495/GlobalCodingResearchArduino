#include <SimpleTimer.h>

#define BUTTON 4
#define ALARAM 5
#define R_LED 6
#define B_LED 7

SimpleTimer timer;
int prevState = LOW;
boolean isBooked = false;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(R_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
}

void loop() {
  digitalWrite(B_LED, HIGH);
  delay(1000);
  digitalWrite(B_LED, LOW);
  delay(1000);

  int state = digitalRead(BUTTON);
  if((prevState == LOW) && (state == HIGH)) {
    if(isBooked == false) {
      isBooked = true;
      digitalWrite(R_LED, HIGH);
      timer.setTimeout(5000, beep);
    }
  }
  prevState = state;
  timer.run();
}

void beep() {
  isBooked = false;
  digitalWrite(R_LED, LOW);
  tone(ALARAM, 1000, 20);
  delay(100);
  tone(ALARAM, 1000, 20);
  delay(100);
  tone(ALARAM, 1000, 20);
}

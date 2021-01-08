int touchSensor = 8; // 터치센서 핀 설정
int ledPin = 13; // LED 핀 설정
int state = LOW; // LED 상태
int reading; // 터치센서 상태
int previous = LOW; // 터치센서 이전 상태

void setup(){
  pinMode(touchSensor, INPUT); // 터치센서 를 설정
  pinMode(ledPin, OUTPUT); // ledPin 설정
}

void loop(){
  reading = digitalRead(touchSensor); // touchSensor 상태 읽음
  if (reading == HIGH && previous == LOW) {
      if (state == HIGH) // ledPin 가 HIGH 면 LOW 로 바꿔준다.
      state = LOW;
      else // ledPin 가 LOW 면 HIGH 로 바꿔준다.
      state = HIGH;
  }
  digitalWrite(ledPin, state);
  previous = reading;
}

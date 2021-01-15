#define TRIG 10
#define ECHO 9
#define RED 13
#define GREEN 12
#define BLUE 11

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long distance = pulseIn(ECHO, HIGH)/58.2;
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
  Serial.println(distance);
  if(distance < 10) {
      analogWrite(RED, 255);
  }
  else if(distance < 20) {
      analogWrite(GREEN, 255);
  }
  else if(distance < 30) {
      analogWrite(BLUE, 255);
  }
  delay(100);
}

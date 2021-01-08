#define DELAY_TIME 100

void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, INPUT);
}

void loop(){
  digitalWrite(13, HIGH);
  delay(DELAY_TIME);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(DELAY_TIME);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(DELAY_TIME);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(DELAY_TIME);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(DELAY_TIME);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(DELAY_TIME);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(DELAY_TIME);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(DELAY_TIME);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(DELAY_TIME);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(DELAY_TIME);
  digitalWrite(12, LOW);

if(digitalRead(6) == HIGH) {
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  delay(DELAY_TIME);
}
}

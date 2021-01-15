int soundValue = 0;
int LED[6] = {6, 7, 8, 11, 12, 13};

void setup() {
  Serial.begin(9600);
  for(int i=0; i<5; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  soundValue = analogRead(A2);
  Serial.println(soundValue);

  for(int i=0; i<6; i++) {
    digitalWrite(LED[i], LOW);
  }
  delay(50);
  if(soundValue > 100) {
    digitalWrite(LED[0], HIGH);
  }
  if(soundValue > 200) {
    digitalWrite(LED[1], HIGH);
  }
  if(soundValue > 300) {
    digitalWrite(LED[2], HIGH);
  }
  if(soundValue > 400) {
    digitalWrite(LED[3], HIGH);
  }
  if(soundValue > 500) {
    digitalWrite(LED[4], HIGH);
  }
  if(soundValue > 600) {
    digitalWrite(LED[5], HIGH);
  }
  delay(50);
}

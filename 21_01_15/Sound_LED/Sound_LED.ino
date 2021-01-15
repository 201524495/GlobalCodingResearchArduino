int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if(analogRead(A2) >= 250) {
    state = 1 - state;
    digitalWrite(6, state);
    Serial.println(analogRead(A2));
    delay(1000);
  }
}

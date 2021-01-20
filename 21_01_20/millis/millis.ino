unsigned long time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Time : ");
time = millis();
;
;
;
;
Serial.println(time);
delay(1000);

}

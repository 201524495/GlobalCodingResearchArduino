#define red 11
#define green 12
#define blue 13

void setup() {
  Serial.begin(9600);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}

void loop() {
  delay(1000);
  digitalWrite(red,1);
  digitalWrite(blue,0);
  Serial.println("red");
  delay(1000);
  digitalWrite(green,1);
  digitalWrite(red,0);
  Serial.println("green");
  delay(1000);
  digitalWrite(blue,1);
  digitalWrite(green,0);
  Serial.println("blue");
  delay(1000);
  digitalWrite(red,1);
  digitalWrite(green,1);
  digitalWrite(blue,0);
  Serial.println("yello");
  delay(1000);
  digitalWrite(red,0);
  digitalWrite(blue,1);
  digitalWrite(green,1);
  Serial.println("cyan");
  delay(1000);
  digitalWrite(red,1);
  digitalWrite(blue,1);
  digitalWrite(green,0);
  Serial.println("magenta");
  delay(1000);
  digitalWrite(blue,1);
  digitalWrite(green,1);
  digitalWrite(red,1);
  Serial.println("white");
  delay(1000);
  digitalWrite(red,0);
  digitalWrite(blue,0);
  digitalWrite(green,0);  
  Serial.println("OFF");
  
}

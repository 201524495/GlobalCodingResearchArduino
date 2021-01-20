#include <Keypad.h>

#define ROWS 4
#define COLS 4
char keys[][4] = {{'1','2','3','A'},
                  {'4','5','6','B'},
                  {'7','8','9','C'},
                  {'*','0','#','D'}};
byte colPins[COLS] = {6,7,8,9};
byte rowPins[ROWS] = {2,3,4,5};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = myKeypad.getKey();
  if(key != NO_KEY) {
    Serial.print(key);
  }
}

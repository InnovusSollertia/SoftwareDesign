#include <Servo.h>

Servo Servo1;

int IR = 9;
int Servo1Pin = 8;
int Val;

void setup() {
  pinMode(IR,INPUT);
  Servo1.attach(Servo1Pin);
} 

void loop() {
  Val = digitalRead(IR);
  if (Val == 1) {
    Servo1.write(270);
  }
  if (Val == 0) {
    Servo1.write(180);
    delay(1500);
    Servo1.write(270);
    delay(500);
  }
}

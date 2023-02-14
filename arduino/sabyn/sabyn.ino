#include <Servo.h>

Servo distribute_servo;

int ir_pin = 9;
int distribute_servo_pin = 8;
int val;

void setup() {
  pinMode(ir_pin,INPUT);
  distribute_servo.attach(distribute_servo_pin);
} 

void loop() {
  val = digitalRead(ir_pin);
  if (val==1)
  {distribute_servo.write(90);
  }
  if (val==0)
  {distribute_servo.write(180);
  delay(1500);
  {distribute_servo.write(90);
  delay(500);
  }
}
}

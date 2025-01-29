#include <SoftwareSerial.h>
SoftwareSerial Blue(2, 3); // RX, TX
 
int ena = 5; 
int enb = 6; 
 
int in1 = 8; 
int in2 = 9; 
int in3 = 10; 
int in4 = 11; 

long int data;
long int command1 = 92; // вперед
long int command2 = 79; // влево
long int command3 = 71; // вправо
long int command4 = 91; // назад
long int command5 = 10; // стоп
char state = 0;
 
 
void setup()
{
Serial.begin(9600);
Blue.begin(9600);
 
  pinMode(ena, OUTPUT); 
  pinMode(enb, OUTPUT); 
 
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
 analogWrite(ena, 255); 
 analogWrite(enb, 255);
 delay(1000);
}
 
void loop()
{
 
  if(Blue.available()>0) {
  data = Blue.parseInt();
  }
 
delay(100);
//Serial.print(data);

// вперед
if (data == command1) {
  
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  //delay(100);
  }

// влево
if( data == command2) {
  digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(100); 
  }

// вправо
if( data == command3){
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(100); 
  }

// назад
if( data == command4) {
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100); 
  }

// стоп
if( data == command5) {
  digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  //delay(100); 
  }
}

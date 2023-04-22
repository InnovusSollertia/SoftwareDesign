const int motor1Pin1 = 7; 
const int motor1Pin2 = 6; 
const int enablem1Pin3 = 11; 
const int motor2Pin1 = 5; 
const int motor2Pin2 = 4; 
const int enablem2Pin3 = 9;
byte serialA;
int Y;
//int state; //Bluetooth cihazından gelecek sinyalin değişkeni

void setup() 
{
Serial.begin(9600);
pinMode(motor1Pin1, OUTPUT); 
pinMode(motor1Pin2, OUTPUT); 
pinMode(enablem1Pin3, OUTPUT); 
pinMode(motor2Pin1, OUTPUT); 
pinMode(motor2Pin2, OUTPUT); 
pinMode(enablem2Pin3, OUTPUT);    
}
 
void loop() 
{
//if(digitalRead(BTState)==LOW) { state='S'; }
//Gelen veriyi 'state' değişkenine kaydet

if(Serial.available() > 0)
{     
serialA = Serial.read();
Serial.println(serialA);   
}
  
switch (serialA)
{ 
case '0': 
Y=0;  
break; 
case '1': 
Y=28;  
break; 
case '2': 
Y=57;  
break; 
case '3': 
Y=85; 
break; 
case '4': 
Y=113 ; 
break; 
case '5': 
Y=142;  
break; 
case '6':  
Y=170; 
break; 
case '7': 
Y=198;
break; 
case '8':  
Y=226; 
break; 
case '9': 
Y=255;
break;
break;  
// forward 
case 'F': 
digitalWrite(motor1Pin1, HIGH); 
digitalWrite(motor1Pin2, LOW); 
digitalWrite(motor2Pin1, LOW); 
digitalWrite(motor2Pin2, HIGH);
analogWrite(enablem1Pin3, Y); 
analogWrite(enablem2Pin3, Y);  
break; 
// left 
case 'L': 
digitalWrite(motor1Pin1, HIGH); 
digitalWrite(motor1Pin2, LOW); 
digitalWrite(motor2Pin1, HIGH); 
digitalWrite(motor2Pin2, LOW);
analogWrite(enablem1Pin3, Y); 
analogWrite(enablem2Pin3, Y); 
break; 
// right 
case 'R': 
digitalWrite(motor1Pin1, LOW); 
digitalWrite(motor1Pin2, HIGH); 
digitalWrite(motor2Pin1, LOW); 
digitalWrite(motor2Pin2, HIGH);
analogWrite(enablem1Pin3, Y); 
analogWrite(enablem2Pin3, Y); 
break; 

// forward left 
case 'G': 
digitalWrite(motor1Pin1, HIGH); 
digitalWrite(motor1Pin2, LOW); 
digitalWrite(motor2Pin1, LOW); 
digitalWrite(motor2Pin2, LOW);
analogWrite(enablem1Pin3, Y); 
analogWrite(enablem2Pin3, Y);
break; 
// forward right 
case 'I': 
digitalWrite(motor1Pin1, LOW); 
digitalWrite(motor1Pin2, LOW); 
digitalWrite(motor2Pin1, LOW); 
digitalWrite(motor2Pin2, HIGH);
analogWrite(enablem1Pin3, Y); 
analogWrite(enablem2Pin3, Y); 
break; 


// backward left 
case 'H': 
digitalWrite(motor1Pin1, HIGH); 
digitalWrite(motor1Pin2, LOW); 
digitalWrite(motor2Pin1, HIGH); 
digitalWrite(motor2Pin2, LOW);
analogWrite(enablem1Pin3, Y); 
analogWrite(enablem2Pin3, Y); 
break; 

// backward right 
case 'J': 
digitalWrite(motor1Pin1, LOW); 
digitalWrite(motor1Pin2, HIGH); 
digitalWrite(motor2Pin1, LOW); 
digitalWrite(motor2Pin2, HIGH);
analogWrite(enablem1Pin3, Y); 
analogWrite(enablem2Pin3, Y); 
break; 

// backward 
case 'B': 
digitalWrite(motor1Pin1, LOW); 
digitalWrite(motor1Pin2, HIGH); 
digitalWrite(motor2Pin1, HIGH); 
digitalWrite(motor2Pin2, LOW); 
analogWrite(enablem1Pin3, Y); 
analogWrite(enablem2Pin3, Y);
break; 

// Stop 
case 'S': 
digitalWrite(motor1Pin1, LOW); 
digitalWrite(motor1Pin2, LOW); 
digitalWrite(motor2Pin1, LOW); 
digitalWrite(motor2Pin2, LOW); 
digitalWrite(enablem1Pin3, LOW); 
digitalWrite(enablem2Pin3, LOW); 
break;
break;
}
}

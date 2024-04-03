#define SENSOR A0
#define LED 9
unsigned int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT); // green
  pinMode(9, OUTPUT); // red
  pinMode(SENSOR, INPUT); // sensor
}

void loop() {
  
  value = analogRead(SENSOR);
  if(value<250){
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  }
  if(value>250) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
  Serial.println(value);
}

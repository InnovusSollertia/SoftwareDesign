int trigPin = 9;
int echoPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(7, OUTPUT); //green
  pinMode(6, OUTPUT); //yellow
  pinMode(5, OUTPUT); //red 
}

void loop() {
  int duration, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = duration/58;
  Serial.println("Cm:");
  Serial.print(cm);
  delay(100);
  
  
  if(cm<=50) {
    digitalWrite(7, HIGH);
    delay(200);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  if(cm<=20) {
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(7, LOW);
    digitalWrite(5, LOW);
  }
  if(cm<=10) {
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
  }
}

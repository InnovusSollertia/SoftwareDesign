#define pinX A4
#define pinY A5
#define swPin 2
#define ledPin 13
int IN1 = 5;
int IN2 = 4;
int ENA = 3;

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
}

void loop() {
  bool ledState = digitalRead(swPin);
  digitalWrite(ledPin, ledState);
  int X = analogRead(pinX);
  int Y = analogRead(pinY);
  if(pinX < 250 && pinY < 250) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 50);
    Serial.print(X);
    Serial.print("\t");
    Serial.println(Y);
    }
  if(pinX > 250 && pinY > 250) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 25);
    Serial.print(X);
    Serial.print("\t");
    Serial.println(Y);
    }
  else {
    analogWrite(ENA, 0);
    delay(1000);
    Serial.print(X);
    Serial.print("\t");
    Serial.println(Y);
    }

}

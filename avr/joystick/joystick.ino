#define pinX A4
#define pinY A5
#define swPin 2
#define ledPin 13



void setup() {
  Serial.begin(9600);

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

  Serial.print(X);
  Serial.print("\t");
  Serial.println(Y);

}

void setup() {
  pinMode(2, OUTPUT); // red
  pinMode(4, OUTPUT); // yellow
  pinMode(6, OUTPUT); // green
}


void loop() {
  digitalWrite (2, HIGH); // red on
  delay(500);
  digitalWrite (4, HIGH); // yellow on
  delay(500);
  digitalWrite (6, HIGH); // green on
  delay(500);
}

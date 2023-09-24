void setup() { // Выполняется один раз
  pinMode(2, OUTPUT); // синий верхний
  pinMode(4, OUTPUT); // красный верхний
  pinMode(6, OUTPUT); // белый верхний
  pinMode(8, OUTPUT); // белый нижний
  pinMode(10, OUTPUT); // красный нижний
  pinMode(12, OUTPUT); // синий нижний

}
void loop() { // Цикл
  // синие
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2, LOW);
  delay(200);
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(12, LOW);
  delay(200);
  // красные
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(10, LOW);
  delay(200);
  // белые
  digitalWrite(6, HIGH);
  delay(200);
  digitalWrite(6, LOW);
  delay(200);
  digitalWrite(8, HIGH);
  delay(200);
  digitalWrite(8, LOW);
  delay(200);
}

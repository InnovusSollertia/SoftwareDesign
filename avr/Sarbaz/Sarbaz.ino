/*
   L = влево
   R = вправо
   F = вперед
   B = назад
*/

int pinLB = 12;
int pinLF = 3;
int pinRB = 13;
int pinRF = 11;
int val;

void setup() {
  Serial.begin(9600); // Настраиваем соединение с HC-06
  pinMode(pinLB, OUTPUT); // 12
  pinMode(pinLF, OUTPUT); // 3 с ШИМ
  pinMode(pinRB, OUTPUT); // 13
  pinMode(pinRF, OUTPUT); // 11 с ШИМ
}

void advance() { // Вперед 
  digitalWrite(pinLB, LOW);
  digitalWrite(pinRB, LOW);
  analogWrite(pinLF, 255);
  analogWrite(pinRF, 255);
}

void stopp() { // Стоп
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinRB, HIGH);
  analogWrite(pinLF, 0);
  analogWrite(pinRF, 0);
}

void right() { // Направо
  digitalWrite(pinLB, LOW);
  digitalWrite(pinRB, HIGH);
  analogWrite(pinLF, 255);
  analogWrite(pinRF, 255);
}

void left() {  // Налево
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinRB, LOW);
  analogWrite(pinLF, 255);
  analogWrite(pinRF, 255);
}

void back() { // Назад
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinRB, HIGH);
  analogWrite(pinLF, 255);
  analogWrite(pinRF, 255);
}

void loop() {
  val = Serial.read();
  if (val == 'f') {
    advance();
  }
  if (val == 'b') {
    back();
  }
  if (val == 'l') {
    left();
    delay(600);
    stopp();
  }
  if (val == 'r') {
    right();
    delay(600);
    stopp();
  }
  if ( val == 's') {
    stopp();
  }
}

#include <Keyboard.h>
//РЕВЕРС И КРАН
#define potention_pin 2
#define potent_pinn 1
//реверс
int revval;
int revLastVal;
//кран
int valve;
int lastval;
//контроллер
int pinIn     = A0;
int keyValue  =  0; // Состояние покоя
int lasti;
int state;
int i;
//переключатель двери
boolean butt_flag = 0;
boolean butt;
//ТУМБЛЕР СТОРОНЫ ДВЕРЕЙ
boolean butt_flag1 = 0;
boolean butt1;

//

void setup() {
  //КОНТРОЛЛЕР
  pinMode(pinIn, INPUT);
 // БЛОКИРОВКА ДВЕРЕЙ
  pinMode(12, INPUT_PULLUP);
  //ПЕДАЛЬ
   pinMode(11, INPUT_PULLUP);
  //КНОПКИ СТОРОНЫЙ ДВЕРЕЙ
  pinMode(8, INPUT_PULLUP);
   pinMode(7, INPUT_PULLUP);
   //ИНФОРМАТОР
   pinMode(5, INPUT_PULLUP);
   //ТУМБЛЕР СТОРОНЫ ДВЕРЕЙ
   pinMode(4, INPUT_PULLUP);
   //свисток и вз1
   pinMode(3, INPUT_PULLUP);
   pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);

  
  
}
void PrintValue(int value2){
  char symbol = value2 + '0';
  Keyboard.press(symbol);
  delay(50);
  Keyboard.release(symbol);
  delay(200);
}

void loop() {
  int newKeyValue =  GetKeyValue(); // Получаем актуальное состояние кнопок с коррекцией дребезга

  if (keyValue != newKeyValue) {  // Если новое значение не совпадает со старым - реагируем на него
    keyValue = newKeyValue;        //Актуализируем переменную хранения состояния
    if (keyValue > 0) {            //Если значение больше 0, значит кнопка нажата
      Serial.println("Key pressed: " + String(keyValue));
    }
    else if (keyValue < 0) {        //Если -1 - неизвестное состояние, незапрограммированное нажатие
      Serial.println("unknown pressed");
    }
    else {                       // Если 0, то состояние покоя
      Serial.println("all keys are not pressed");
    }
      
     
  
  }
    if(lasti != i){
  lasti = i;
  switch(lasti){
    case 1 : state = 7; break;
    case 2 : state = 6; break;
    case 3 : state = 5; break;
    case 4 : state = 4; break;
    case 5 : state = 1; break;
    case 6 : state = 2; break;
    case 7 : state = 3; break;
  }
  PrintValue(state);
}

//РЕВЕРС И КРАН
 valve = analogRead(potention_pin);
  if((lastval != valve)&& (valve == 1000 || valve == 500))
      {
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(200);
  Keyboard.press('l');
  delay(100);
  Keyboard.releaseAll();
}


  revval = analogRead(potent_pinn);
  revval = map(revval, 100, 1000, 0, 5);
    constrain(revval, 0, 5);
  Serial.println(revval);
//

      
            
      if(revval > revLastVal)
      {
        Keyboard.press('0');
     delay(200);
      Keyboard.release('0');
     if(revLastVal != revval){
  revLastVal = revval;
            }
      }
      
      else if (revval < revLastVal){
          Keyboard.press('9');
     delay(200);
      Keyboard.release('9'); 
      if(revLastVal != revval){
  revLastVal = revval;
      }
      }
  //ЗАКРЫТИЕ ДВЕРЕЙ
 butt = !digitalRead(12);
      if(butt == 1 && butt_flag ==0) {
        butt_flag = 1;
        Keyboard.press('v');
      delay(100);
      Keyboard.release('v');
     
      
      }
      else if(butt ==0 && butt_flag ==1)
      {
        butt_flag =0;
         Keyboard.press('v');
      delay(100);
      Keyboard.release('v');
      }
    //ПЕДАЛЬ
        if(!digitalRead(11) == HIGH){
          Keyboard.press(32);
          delay(100);
      Keyboard.release(32);
       
      }
// КНОПКИ СТОРОНА ДВЕРЕЙ
if (!digitalRead(8)== HIGH) {
  
  Keyboard.press('d');
  delay(100);
Keyboard.release('d');
}
if (!digitalRead(7)== HIGH) {
  
  Keyboard.press('a');
  delay(100);
Keyboard.release('a');
}
// CВИСТОК И ВЗ№1
  if (digitalRead(3) == HIGH) {
  
  Keyboard.press('n');
  delay(100);
Keyboard.release('n');
}
if (digitalRead(2) == HIGH) {
  
  Keyboard.press('l');
  delay(100);
Keyboard.release('l');
}
//ИНФОРМАТОР
if (!digitalRead(5) == HIGH) {
  
  Keyboard.press('=');
  delay(100);
Keyboard.release('=');
}
//ТУМБЛЕР СТОРОНЫ ДВЕРЕЙ
butt1 = !digitalRead(4);
if (butt1 == 1 && butt_flag1 ==0){
        butt_flag1 = 1;
        Keyboard.press('d');
      delay(100);
      Keyboard.release('d');
    }
    
   
      else if(butt1 ==0 && butt_flag1 ==1)
      {
        butt_flag1 = 0;
      Keyboard.press('a');
      delay(100);
      Keyboard.release('a');
      }
    //dadada  vd
}

int GetKeyValue() {         // Функция устраняющая дребезг
  static int   count;
  static int   oldKeyValue; // Переменная для хранения предыдущего значения состояния кнопок
  static int   innerKeyValue;
  
  // Здесь уже не можем использовать значение АЦП, так как оно постоянно меняется в силу погрешности
  int actualKeyValue = GetButtonNumberByValue(analogRead(pinIn));  // Преобразовываем его в номер кнопки, тем самым убирая погрешность
  
  if (innerKeyValue != actualKeyValue) {  // Пришло значение отличное от предыдущего
    count = 0;                            // Все обнуляем и начинаем считать заново
    innerKeyValue = actualKeyValue;       // Запоминаем новое значение
  }
  else {
    count += 1;                           // Увеличиваем счетчик
  }

  if ((count >= 10) && (actualKeyValue != oldKeyValue)) {
    oldKeyValue = actualKeyValue;         // Запоминаем новое значение
  }
  return    oldKeyValue;
 
}


int GetButtonNumberByValue(int value) {   // Новая функция по преобразованию кода нажатой кнопки в её номер
  int values[8] = {0, 640, 681, 730, 787, 853, 931,1023};
  int error     = 15;                     // Величина отклонения от значений - погрешность
  for ( i = 0; i <= 7; i++) {
    // Если значение в заданном диапазоне values[i]+/-error - считаем, что кнопка определена
    if (value <= values[i] + error && value >= values[i] - error) return i;
  }
  return -1;                              // Значение не принадлежит заданному диапазону




}

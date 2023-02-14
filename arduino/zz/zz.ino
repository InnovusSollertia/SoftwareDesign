// пин аналогового выхода датчика уровня воды
#define pinWaterLevel A0 
//пин аналогового выхода датчика влажности почвы
#define pinSoilMoisture A1
//пин реле для управления насосом
#define pinRelayPump 12 
 
const int delayPumpBefore=2; //время полива (в секундах)
const int delayPumpAfter=3; //время после полива, чтобы
const int minMoisture=600; //минимальный порог влажности почвы в секундах
 
int aLevel = 0; // значение датчика уровня воды
int aMoisture = 0; // состояние датчика влажности почвы
int levels[3]={600,500,400}; //массив значений уровней воды
 
void setup() { 
  //объявляем пин реле для включения насоса как выход: 
  pinMode(pinRelayPump, OUTPUT); 
  //объявляем пины датчиков глубины и влажности почвы как входы: 
  pinMode(pinWaterLevel, INPUT);
  pinMode(pinSoilMoisture, INPUT);
  Serial.begin(9600);
} 
 
void loop() { 
  // считываем значение датчика уровня воды
  aLevel = analogRead(pinWaterLevel);
  // считываем состояния датчика влажности почвы
  aMoisture = analogRead(pinSoilMoisture);
  Serial.println(aMoisture); //выводим для тестирования
  delay(100);
  // если почва сухая, и вода в банке есть, то включаем полив
  if ((aMoisture >= minMoisture)&&(aLevel >= levels[2])) { 
    digitalWrite(pinRelayPump, HIGH); //включаем насос
    delay(delayPumpBefore*1000); //задержка на полив
    digitalWrite(pinRelayPump, LOW); //выключаем насос
    delay(delayPumpAfter*1000); //задержка на слив воды из шланга после выключения насоса
    }
  else { 
    digitalWrite(pinRelayPump, LOW);
    }
}

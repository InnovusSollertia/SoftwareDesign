#include "tm1637.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#define POINT_ON   1
uint8_t Cmd_SetAddr = STARTADDR;
uint8_t Cmd_DispCtrl;
uint8_t PointFlag = POINT_ON; 	//_PointFlag=1:the clock point on
uint8_t _DispType  = D4056A;
uint8_t DecPoint;
uint8_t BlankingFlag;
//
//      A
//     ---
//  F |   | B
//     -G-
//  E |   | C
//     ---
//      D
const uint8_t digitToSegment[] = {
 // XGFEDCBA
  0x3f,    // 0 0b00111111
  0x06,    // 1 0b00000110
  0x5b,    // 2 0b01011011
  0x4f,    // 3 0b01001111
  0x66,    // 4 0b01100110
  0x6d,    // 5 0b01101101
  0x7d,    // 6 0b01111101
  0x07,    // 7 0b00000111
  0x7f,    // 8 0b01111111
  0x6f,    // 9 0b01101111
  0x77,    // A 0b01110111
  0x7c,    // b 0b01111100
  0x39,    // C 0b00111001
  0x5e,    // d 0b01011110
  0x79,    // E 0b01111001
  0x71,    // F 0b01110001
	0x40,    // - 0b01000000
	0x00,    // nothing 0b00000000
	0x01,    //Cегмент A 
	0x02,    //Cегмент B  
	0x04,    //Cегмент C
	0x08,    //Cегмент D
	0x10,    //Cегмент E
	0x20,    //Cегмент F
	0x40     //Cегмент G
  };
//=========================================================================//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//=========================================================================//
void tik_delay(uint32_t i){
while(i)i--;
}
//=========================================================================//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//=========================================================================//
void TM1637_Generate_START(void){
 Set_CLK_Pin();
 Set_DATA_Pin();
 tik_delay(I2C_DELAY);
 Reset_DATA_Pin();
 }
//=========================================================================//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//=========================================================================//
 void TM1637_Generate_STOP(void){
	 
  Reset_CLK_Pin();
  tik_delay(I2C_DELAY);
  Reset_DATA_Pin();
  tik_delay(I2C_DELAY);
  Set_CLK_Pin();
  tik_delay(I2C_DELAY);
  Set_DATA_Pin(); 
	 
 }
//=========================================================================//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//=========================================================================//
void TM1637_WriteData(uint8_t data)//ПЕРЕДАЧА ОТМЛАДШЕГО К СТРАШЕМУ!!!НЕ СТАНДАРТ
{
  uint8_t i;
    for(i=0;i<8;i++)        
  {
    Reset_CLK_Pin();
    if(data & 0x01)Set_DATA_Pin();
    else Reset_DATA_Pin();
	  tik_delay(I2C_DELAY);
    data = data>>1;
    Set_CLK_Pin();
    tik_delay(I2C_DELAY);		
	}
	Reset_CLK_Pin();
	tik_delay(I2C_DELAY);	
  Reset_DATA_Pin();
  while(Read_DATA_Pin());
  Set_DATA_Pin(); 
  Set_CLK_Pin();
  tik_delay(I2C_DELAY);		
	Reset_CLK_Pin();
}

//============================================================================//
//=========меняем число  на его позицию  в массиве digitToSegment=============//
//============================================================================//
int8_t TM1637_coding(uint8_t DispData)// шифратор знакомест
{
	uint8_t PointData;
	if(PointFlag == POINT_ON)PointData = 0x80;
	else PointData = 0;
	if(DispData == 0x7f) DispData = 0x00 + PointData;
	else DispData = digitToSegment[DispData] + PointData;
	return DispData;
}		
//============================================================================//
//==меняем числа в массиве DispData на их позиции в массиве digitToSegment====//
//============================================================================//
void TM1637_coding_all(uint8_t DispData[])//шифратор знакомест 
{
	uint8_t PointData;
	uint8_t i;
	PointData =  PointFlag ? 0x80:0;
	for(i = 0;i < 4;i ++)
	{
		if(DispData[i] == 0x7f)DispData[i] = 0x00;
		else DispData[i] = digitToSegment[DispData[i]] + PointData; 
	DispData[i] += 0x80;
	}
	if((_DispType == D4056A)&&(DecPoint != 3))
	{
	DispData[DecPoint] += 0x80;
	DecPoint = 3;
	}
}
//=========================================================================//
//+++++++++++++++++++разбиваем число на "сегменты"+++++++++++++++++++++++++//
//=========================================================================//
void separate_Digit_to_digits(int16_t Digit,uint8_t SegArray[])//разбиваем целое число на массив чисел
{
	
	if((Digit > 9999)||(Digit < -999))return;
	if(Digit < 0)
	{
		SegArray[0] = INDEX_NEGATIVE_SIGN;
		Digit = (Digit & 0x7fff);
		SegArray[1] = Digit/100;
		Digit %= 100;
		SegArray[2] = Digit / 10;
		SegArray[3] = Digit % 10;
		if(BlankingFlag)
		{
			if(SegArray[1] == 0)
			{
				SegArray[1] = INDEX_BLANK;
				if(SegArray[2] == 0) SegArray[2] = INDEX_BLANK;
			}
		}
	}
	else
	{
		SegArray[0] = Digit/1000;
		Digit %= 1000;
		SegArray[1] = Digit/100;
		Digit %= 100;
		SegArray[2] = Digit / 10;
		SegArray[3] = Digit % 10;
		if(BlankingFlag)
		{
			if(SegArray[0] == 0)
			{
				SegArray[0] = INDEX_BLANK;
				if(SegArray[1] == 0)
				{
					SegArray[1] = INDEX_BLANK;
					if(SegArray[2] == 0) SegArray[2] = INDEX_BLANK;
				}
			}
		}
	}
	BlankingFlag = 1;
}
//=========================================================================//
//+++++++++++++++++++++++++отображает один символ из массива+++++++++++++++//
//=========================================================================//
void TM1637_display(uint8_t Seg_N,int8_t DispData)//  в определенном месте  (от 0 до 3)
{
  int8_t SegData;
  SegData = TM1637_coding(DispData);
  TM1637_Generate_START();                                
	TM1637_WriteData(ADDR_FIXED);//1:фиксированный адресс
  TM1637_Generate_STOP();
  TM1637_Generate_START();
  TM1637_WriteData(Seg_N|0xc0);// устанавливаем адресс старшие 2 бита должны быть 1(0xc0)+ номер сегмента
  TM1637_WriteData(SegData);// отправляем "кодированные" данные для одного сегмента
  TM1637_Generate_STOP();
  TM1637_Generate_START();
  TM1637_WriteData(Cmd_DispCtrl);//включаем дисплей с выставлленой яркостью;
  TM1637_Generate_STOP();
}
//=========================================================================//
//++++++++++++++++++++отображение чисел -999-9999++++++++++++++++++++++++++//
//=========================================================================//
void TM1637_display_all(uint16_t Digit) 
											
{
  uint8_t SegData[4];
  uint8_t i;
	separate_Digit_to_digits(Digit,SegData);
  TM1637_coding_all(SegData);
  TM1637_Generate_START();
  TM1637_WriteData(ADDR_AUTO);//автоматический инкремент адреса
  TM1637_Generate_STOP();
  TM1637_Generate_START();
  TM1637_WriteData(Cmd_SetAddr);//адрес первого сегмента 0xc0 
  for(i=0;i < 4;i ++)
  {
    TM1637_WriteData(SegData[i]);//передаем значения для i-го сегмента
  }
  TM1637_Generate_STOP();
  TM1637_Generate_START();
  TM1637_WriteData(Cmd_DispCtrl);//включаем дисплей с выставлленой яркостью;
  TM1637_Generate_STOP();
}
//=========================================================================//
//++++++++++++++++++++регулровка яркости дисплея+++++++++++++++++++++++++++//
//=========================================================================//
void TM1637_brightness(uint8_t brightness)
{
  Cmd_DispCtrl = 0x88 + brightness;
}
//=========================================================================//
//+++++++++++++++++++++++очистка дисплея+++++++++++++++++++++++++++++++++++//
//=========================================================================//
void TM1637_clearDisplay(void) 
{
	uint8_t i;
	for(i=0;i<4;i++)TM1637_display(i,0x7f); 
}
//=========================================================================//
//++++++++++++++++++++отображение часов и минут++++++++++++++++++++++++++++//
//=========================================================================//
void TM1637_displayTime(uint8_t hours,uint8_t minutes) 
{
  uint16_t time = (hours*100)+minutes;
	PointFlag =  PointFlag ? 0:1;  
	TM1637_display_all(time);
}	

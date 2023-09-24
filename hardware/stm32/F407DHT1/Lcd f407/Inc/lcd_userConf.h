#include "stm32f4xx_hal.h"
uint8_t i2cDeviceAddr = 0x4E; 


I2C_HandleTypeDef hi2cx;
extern I2C_HandleTypeDef hi2c1;
static void hi2cx_define(void)
{
	hi2cx = hi2c1;
}

#define LCD_16x2



static const uint8_t BFR_MAX = 100; 


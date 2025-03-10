/**
  *******************************************************************************
  * @file    BSPTest/LED/main/main.c 
  * @author  '^_^'
  * @version V0.0.1
  * @date    15-October-2015
  * @brief   This file provides main program functions
  *******************************************************************************
  */

/* Includes -------------------------------------------------------------------*/
#include "main.h" 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/**
  * @brief  LCD FB_StartAddress
  * LCD Frame buffer start address : starts at beginning of SDRAM
  */
#define LCD_FRAME_BUFFER          SDRAM_DEVICE_ADDR

#define ORG_IMG_POS_X        40
#define ORG_IMG_POS_Y        76

#define BIN_IMG_POS_X        180
#define BIN_IMG_POS_Y        76

#define EDG_IMG_POS_X        320
#define EDG_IMG_POS_Y        76
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__attribute__((__aligned__(4))) static uint8_t CameraImgBuffer[120][120][2] = {0};
__attribute__((__aligned__(4))) static uint8_t BinaryImgBuffer[120][120]    = {0};

static uint8_t ImageUpdateFlag = 0;

uint32_t _cnt_x = 0, _cnt_y = 0;
/* Global extern variables ---------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void CPU_CACHE_ENABLE(void);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  CPU_CACHE_ENABLE();
  /* STM32F7xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
     */
  HAL_Init();
  /* Configure the system clock to 200 Mhz */
  SystemClock_Config();

  BSP_LED_Init(LED1);
  /* Initialize the LCD */
  BSP_LCD_Init();
  /* Initialize the LCD Layers */
  BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FRAME_BUFFER);

  /* Set LCD Foreground Layer  */
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);

  BSP_LCD_SetFont(&LCD_DEFAULT_FONT);

  /* Clear the LCD */
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_Clear(LCD_COLOR_BLACK);

  /* Set the LCD Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	if(BSP_CAMERA_Init() == 0)
		BSP_LCD_DisplayStringAtLine(0, (uint8_t *)"Camera Init Success!");
	else {
		BSP_LCD_DisplayStringAtLine(0, (uint8_t *)"Camera Init Failed!");
		while(1) {
			BSP_LED_Toggle(LED1);
			HAL_Delay(50);
		}
	}

	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(ORG_IMG_POS_X-1, ORG_IMG_POS_Y-1, 121, 121);
	BSP_LCD_DrawRect(BIN_IMG_POS_X-1, BIN_IMG_POS_Y-1, 121, 121);
	BSP_LCD_DrawRect(EDG_IMG_POS_X-1, EDG_IMG_POS_Y-1, 121, 121);

//	BSP_CAMERA_ContinuousStart(CameraImgBuffer, 120 * 60);
	BSP_CAMERA_SnapshotStart((uint8_t *)CameraImgBuffer, 120 * 60);

  while(1)
  {
		if(ImageUpdateFlag == 1) {
			for(_cnt_y = 0; _cnt_y < 120; _cnt_y ++) {
				for(_cnt_x = 0; _cnt_x < 120; _cnt_x ++) {
					*(__IO uint32_t*)(LCD_FRAME_BUFFER + ((((BIN_IMG_POS_Y + _cnt_y) * 480) + BIN_IMG_POS_X + _cnt_x) << 2)) = (BinaryImgBuffer[_cnt_y][_cnt_x]) ? 0xFFFFFFFF : 0;
				}
			}
			for(_cnt_y = 0; _cnt_y < 119; _cnt_y ++) {
				for(_cnt_x = 0; _cnt_x < 119; _cnt_x ++) {
					BinaryImgBuffer[_cnt_y][_cnt_x] = (BinaryImgBuffer[_cnt_y][_cnt_x] != BinaryImgBuffer[_cnt_y + 1][_cnt_x] || \
					                                   BinaryImgBuffer[_cnt_y][_cnt_x] != BinaryImgBuffer[_cnt_y][_cnt_x + 1]) * 0xFF;
				}
			}
			for(_cnt_y = 0; _cnt_y < 120; _cnt_y ++) {
				for(_cnt_x = 0; _cnt_x < 120; _cnt_x ++) {
					*(__IO uint32_t*)(LCD_FRAME_BUFFER + ((((EDG_IMG_POS_Y + _cnt_y) * 480) + EDG_IMG_POS_X + _cnt_x) << 2)) = (BinaryImgBuffer[_cnt_y][_cnt_x]) ? 0xFFFFFFFF : 0;
				}
			}

			ImageUpdateFlag = 0;
			BSP_CAMERA_SnapshotStart((uint8_t *)CameraImgBuffer, 120 * 60);
			BSP_LED_Toggle(LED1);
		}
//	  BSP_LED_Toggle(LED1);
//	  HAL_Delay(200);
  }
}

void BSP_CAMERA_LineEventCallback(void) {}
void BSP_CAMERA_VsyncEventCallback(void) {}
void BSP_CAMERA_FrameEventCallback(void)
{
	uint8_t i = 0, j = 0;
	uint32_t d = 0;
	for(i = 0; i < 120; i ++) {
		for(j = 0; j < 120; j ++) {
			BinaryImgBuffer[j][i] = (CameraImgBuffer[j][i][0] >> 7) ? 0xFF : 0x00;
			d = CameraImgBuffer[j][i][0];
			*(__IO uint32_t*)(LCD_FRAME_BUFFER + ((((ORG_IMG_POS_Y + j) * 480) + ORG_IMG_POS_X + i) << 2)) = 0xFF000000 | (d << 16) | (d << 8) | (d);
		}
	}
	ImageUpdateFlag =1;
//	BSP_CAMERA_SnapshotStart((uint8_t *)CameraImgBuffer, 120 * 60);
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 200000000
  *            HCLK(Hz)                       = 200000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 400
  *            PLL_P                          = 2
  *            PLLSAI_N                       = 384
  *            PLLSAI_P                       = 8
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);
          
  ret = HAL_PWREx_EnableOverDrive();

  if(ret != HAL_OK)
  {
    while(1) { ; }
  }  
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}

/**
  * @brief  CPU L1-Cache enable.
  *         Invalidate Data cache before enabling
  *         Enable Data & Instruction Cache
  * @param  None
  * @retval None
  */
static void CPU_CACHE_ENABLE(void)
{
  (*(uint32_t *) 0xE000ED94) &= ~0x5;
  (*(uint32_t *) 0xE000ED98) = 0x0; //MPU->RNR
  (*(uint32_t *) 0xE000ED9C) = 0x20010000 |1<<4; //MPU->RBAR
  (*(uint32_t *) 0xE000EDA0) = 0<<28 | 3 <<24 | 0<<19 | 0<<18 | 1<<17 | 0<<16 | 0<<8 | 30<<1 | 1<<0 ; //MPU->RASE  WT
  (*(uint32_t *) 0xE000ED94) = 0x5;

  /* Invalidate I-Cache : ICIALLU register*/
  SCB_InvalidateICache();	
	
  /* Enable branch prediction */
  SCB->CCR |= (1 <<18); 
  __DSB();

  /* Enable I-Cache */
  SCB_EnableICache();	
	
  /* Enable D-Cache */
  SCB_InvalidateDCache();
  SCB_EnableDCache();
}

#ifdef USE_FULL_ASSERT
/**
* @brief  assert_failed
*         Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  File: pointer to the source file name
* @param  Line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line
  number,ex: printf("Wrong parameters value: file %s on line %d\r\n", 
  file, line) */
  
  /* Infinite loop */
  while (1);
}

#endif

/********************************* END OF FILE *********************************/

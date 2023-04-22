/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2020 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */
#include "tm1637.h" //Добавляем библиотеку для LED дисплея
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c2;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
	uint8_t P=0; //Вводим переменную "P" (аврийка на светодиодах)
	uint8_t Lp=0; //Вводим переменную "Lp" (левый поворотник на светодиодах)
	uint8_t Rp=0; //Вводим переменную "Rp" (правый поворотник на светодиодах)
  uint16_t R1=0; //Вводим переменную "R1" для первого переменного резистора
	uint16_t R2=0; //Вводим переменную "R2" для второго переменного резистора
	uint8_t PLCD=0; //Вводим переменную "PLCD" (аврийка на ЖК дисплее)
	uint8_t LpLCD=0; //Вводим переменную "LpLCD" (левый поворотник на ЖК дисплеее)
	uint8_t RpLCD=0; //Вводим переменную "RpLCD" (правый поворотник на ЖК дисплеее)
	uint8_t W=0;  //Вводим переменную "W" для !WARNING! на ЖКдисплее
	uint16_t RPMHl=0; //Используется для определения оборотов двигателя левого
	uint16_t RPMHr=0; //Используется для определения оборотов двигателя правого
	uint16_t RPMl=0; //Используется для определения оборотов двигателя левого
	uint16_t RPMr=0; //Используется для определения оборотов двигателя правого
	int8_t STOP1=0; //Используется для определения определения напрвления вращения левого колеса
	int8_t STOP2=0; //Используется для определения определения напрвления вращения правого колеса
	uint64_t Mileage1=0; //Пробег 1-ого двигателя (в метрах)
	uint64_t Mileage2=0; //Пробег 2-ого двигателя (в метрах)
	uint8_t ABS=0; //Отвечает за состояние ABS
	int8_t ABSh=0; //Используется для синхронизации скорости вращения двигателей
	char str[100]; //Переменная для вывода строки на ЖК дисплей
	


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);
static void MX_ADC1_Init(void);
static void MX_I2C2_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                                

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM4_Init();
  MX_ADC1_Init();
  MX_I2C2_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	LCD_ini();  //Включаем ЖК дисплей
	TM1637_brightness(BRIGHTEST); //Выставляем яркость LED дисплея на максимум
	        /*Проверка при старте*/       
////////////////////////////////////////////////////////////////
/*Все светодиоды включатся*/
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4,GPIO_PIN_SET);
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5,GPIO_PIN_SET);
////////////////////////////////////////////////////////////////
/*На ЖК дисплее загораются все элементы*/
		LCD_SetPos(15, 0);
		sprintf(str,"|");
		LCD_String(str);
		LCD_SetPos(15, 1);
		sprintf(str,"|");
		LCD_String(str);
		LCD_SetPos(15, 2);
		sprintf(str,"|");
		LCD_String(str);
		LCD_SetPos(15, 3);
		sprintf(str,"|");
		LCD_String(str);
		LCD_SetPos(0, 0);
		sprintf(str,"Power\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF");
		LCD_String(str);	
		LCD_SetPos(0, 1);
		sprintf(str,"Mileage:0000000");
		LCD_String(str);	
		LCD_SetPos(0, 2);
		sprintf(str,"RPM:0000  0000");
		LCD_String(str);
		LCD_SetPos(0, 3);
		sprintf(str,"DNR");
		LCD_String(str);
		LCD_SetPos(4, 3);
		sprintf(str,"!WARNING!");
		LCD_String(str);
		LCD_SetPos(17, 0);
		sprintf(str,"ABS");
		LCD_String(str);
		LCD_SetPos(17, 1);
		sprintf(str,"<!>");
		LCD_String(str);
		LCD_SetPos(18, 2);
		sprintf(str,"=D");
		LCD_String(str);
		LCD_SetPos(16, 3);
		sprintf(str,"STOP");
		LCD_String(str);
///////////////////////////////////////////////////////////////////////////////////////////
/*На LED дисплее дорожка делает 2 круга, символизируя загрузку*/
		TM1637_display(0,18);TM1637_display(1,18);TM1637_display(2,18);TM1637_display(3,18);
		HAL_Delay(50);
		TM1637_display(0,19);	TM1637_display(1,19);	TM1637_display(2,19);	TM1637_display(3,19);
		HAL_Delay(50);
		TM1637_display(0,20);TM1637_display(1,20);TM1637_display(2,20);TM1637_display(3,20);
		HAL_Delay(50);
		TM1637_display(0,21);TM1637_display(1,21);TM1637_display(2,21);TM1637_display(3,21);
		HAL_Delay(50);
		TM1637_display(0,22);TM1637_display(1,22);TM1637_display(2,22);TM1637_display(3,22);
		HAL_Delay(50);
		TM1637_display(0,23);TM1637_display(1,23);TM1637_display(2,23);TM1637_display(3,23);
		HAL_Delay(50);
		
		TM1637_display(0,18);TM1637_display(1,18);TM1637_display(2,18);TM1637_display(3,18);
		HAL_Delay(50);
		TM1637_display(0,19);TM1637_display(1,19);TM1637_display(2,19);TM1637_display(3,19);
		HAL_Delay(50);
		TM1637_display(0,20);TM1637_display(1,20);TM1637_display(2,20);TM1637_display(3,20);
		HAL_Delay(50);
		TM1637_display(0,21);TM1637_display(1,21);TM1637_display(2,21);TM1637_display(3,21);
		HAL_Delay(50);
		TM1637_display(0,22);TM1637_display(1,22);TM1637_display(2,22);TM1637_display(3,22);
		HAL_Delay(50);
		TM1637_display(0,24);TM1637_display(1,24);TM1637_display(2,24);TM1637_display(3,24);
		HAL_Delay(100);
		TM1637_clearDisplay();
		HAL_Delay(500);
/////////////////////////////////////////////////////////////////////////////////////////////
/*Все светодиоды потухают*/
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8,GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_9,GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4,GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
////////////////////////////////////////////////////////
/*Гаснут элементы на ЖК дисплее, имеющие переменное значение*/
	LCD_SetPos(0, 0);
	sprintf(str,"Power          "); //Дорожка POWER
	LCD_String(str);	
	LCD_SetPos(0, 3);
	sprintf(str,"   "); //Drive mode
	LCD_String(str);
	LCD_SetPos(4, 3);
	sprintf(str,"         "); //Выключаем !WARNING!
	LCD_String(str);
	LCD_SetPos(17, 0);
	sprintf(str,"   "); //Выключаем ABS
	LCD_String(str);
	LCD_SetPos(17, 1);
	sprintf(str,"   "); //Выключаем аварийку и поворотники
	LCD_String(str);
	LCD_SetPos(18, 2);
	sprintf(str,"  "); //Выключаем фары
	LCD_String(str);
	LCD_SetPos(16, 3);
	sprintf(str,"    "); //Выключаем ручник "STOP"
	LCD_String(str);
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  HAL_TIM_Base_Start_IT(&htim1); //Стартуем таймер 1 по прерыванию (для светодиодов).
	HAL_TIM_Base_Start_IT(&htim2); //Стартуем таймер 1 по прерыванию (для переменного резистора).
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); //Стартуем таймер 4 (по ШИМ каналу 1) для драйвера
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2); //Стартуем таймер 4 (по ШИМ каналу 2) для драйвера
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); //Стартуем таймер 4 (по ШИМ каналу 3) для драйвера
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); //Стартуем таймер 4 (по ШИМ каналу 4) для драйвера
	HAL_ADC_Start_IT(&hadc1);  //Стартуем прерывание по АЦП 1
 // TM1637_brightness(BRIGHTEST); //Выставляем яркость LED дисплея на максимум
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
/*Вводим переменные для вывода на дисплеи элементов в момент их вызова*/
uint16_t led=0; //Скорость на LED дисплее (м/мин)
  uint64_t Mileages=0; //Пробег
	uint16_t RPMls=0; //Обороты левого колеса
	uint16_t RPMrs=0; //Обороты правого колеса
	uint8_t lights=0; //Фары
	uint8_t lp=0; //Левый поворотник
  uint8_t rp=0;  //Правый поворотник
	uint8_t p=0;  //Аварийка
	uint8_t ff=0;  //POWER- дорожка
	uint8_t hb=0;  //Ручник (HandBreak)
	uint8_t w=0; //!WARNING!
	uint8_t abs=0; //ABS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		/*Вывод значения на LED дисплей*/
///////////////////////////////////////////////////////////////////////////		
		if(led!=(RPMl+RPMr)/175){
	    TM1637_display_all((RPMl+RPMr)/175);  //Выводим скорость в метрах в минуту
			led=(RPMl+RPMr)/175;
		}
////////////////////////////////////////////////////////////////////////////
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
		                                /*Вывод значений на ЖК дисплей*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	  /*Пробег*/
		if(Mileages!=(Mileage1+Mileage2)/3806){
			LCD_SetPos(8, 1);
			sprintf(str,"%07d",(Mileage1+Mileage2)/3806); //Выводим пробег
			LCD_String(str);
			Mileages=(Mileage1+Mileage2)/3806;
		}
////////////////////////////////////
	  /*RPM*/
		if(RPMls!=RPMl/34){
			LCD_SetPos(4, 2);
			sprintf(str,"%04d",RPMl/34); //Выводим обороты первого двигателя
			LCD_String(str);
			RPMls=RPMl/34;
		}
		if(RPMrs!=RPMr/34){
			LCD_SetPos(10, 2);
			sprintf(str,"%04d",RPMr/34); //Выводим обороты второго двигателя
			LCD_String(str);
			RPMrs=RPMr/34;
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	  /*Фары*/
		if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_9)==GPIO_PIN_RESET&&lights==0){
			LCD_SetPos(18, 2);
			sprintf(str,"  ");
			LCD_String(str);
			lights=1;
		}
		if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_9)==GPIO_PIN_SET&&lights==1){
			LCD_SetPos(18, 2);
			sprintf(str,"=D");
			LCD_String(str);
			lights=0;
		}
/////////////////////////////////////////////////////////////
		/*Drive mode*/
			if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_0)==GPIO_PIN_SET){
				LCD_SetPos(0, 3);
				sprintf(str,"D  ");
				LCD_String(str);				
			}
			if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_1)==GPIO_PIN_SET){
				LCD_SetPos(0, 3);
				sprintf(str,"  R");
				LCD_String(str);
			}
		 if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_0)==GPIO_PIN_RESET&&HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_1)==GPIO_PIN_RESET){
				LCD_SetPos(0, 3);
				sprintf(str," N ");
				LCD_String(str);
			 }
//////////////////////////////////////////////////////////////
 /*Поворотники*/
		 /*Левый*/ 
		if(LpLCD==3){ 
			LCD_SetPos(17, 1);
			sprintf(str,"<");
			LCD_String(str);
			lp=0;
			}
    if(LpLCD==2){
		 LCD_SetPos(17, 1);
			sprintf(str," ");
			LCD_String(str);	
		}
		if(LpLCD==1&&lp==0){
			LCD_SetPos(17, 1);
			sprintf(str," ");
			LCD_String(str);
			LpLCD=0;
			lp=1;
		}
		/*Правый*/
		if(RpLCD==3){ 
			LCD_SetPos(19, 1);
			sprintf(str,">");
			LCD_String(str);
			rp=0;
			}
    if(RpLCD==2){
		 LCD_SetPos(19, 1);
			sprintf(str," ");
			LCD_String(str);
		}
		if(RpLCD==1&&rp==0){
			LCD_SetPos(19, 1);
			sprintf(str," ");
			LCD_String(str);
			RpLCD=0;
			rp=1;
		}

//////////////////////////////////////////////////////////////
		/*Аварийка*/
		if(PLCD==3){
			LCD_SetPos(17, 1);
			sprintf(str,"<!>");
			LCD_String(str);
	    p=0;
		}
		if(PLCD==2){
			LCD_SetPos(17, 1);
			sprintf(str," ! ");
			LCD_String(str);
		}
		if(PLCD==1&&p==0){
			LCD_SetPos(17, 1);
			sprintf(str,"   ");
			LCD_String(str);
			PLCD=0;
			p=1;
		}
////////////////////////////////////////////////////////////////////
		/*ABS*/
		if(ABS==0&&abs==0){
			LCD_SetPos(17, 0);
			sprintf(str,"   ");
			LCD_String(str);
			abs=1;
		}
		if(ABS==1&&abs==1){
			LCD_SetPos(17, 0);
			sprintf(str,"ABS");
			LCD_String(str);
			abs=0;
		}
//////////////////////////////////////////////////////////////
		/*Ручник*/
		if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_RESET&&hb==0){
			LCD_SetPos(16, 3);
			sprintf(str,"    ");
			LCD_String(str);
			hb=1;
		}
		if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_SET){
			LCD_SetPos(16, 3);
			sprintf(str,"STOP");
			LCD_String(str);
			hb=0;
		}
///////////////////////////////////////////////////////////////
		/*!WARNING!*/
		if(W==0&&w==0){
			LCD_SetPos(4, 3);
			sprintf(str,"         ");
			LCD_String(str);
			w=1;
		}
		if(W==1&&w==1){
			LCD_SetPos(4, 3);
			sprintf(str,"!WARNING!");
			LCD_String(str);
			w=0;
		}
///////////////////////////////////////////////////////////////
    /*POWER*/
		if(R1==0&&ff!=0){ //Если R1=0%
		  LCD_SetPos(5, 0);
		  sprintf(str,"          ");
		  LCD_String(str);
			ff=0;
		}		
    if(R1>=402.8&&R1<805.6&&ff!=1){  //Если R1=10%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF         ");
		  LCD_String(str);
			ff=1;
		}
   if(R1>=805.6&&R1<1208.4&&ff!=2){  //Если R1=20%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF        ");
		  LCD_String(str);
			ff=2;
		}
   if(R1>=1208.4&&R1<1611.2&&ff!=3){  //Если R1=30%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF\xFF       ");
		  LCD_String(str);
			ff=3;
		}
   if(R1>=1611.2&&R1<2014.0&&ff!=4){  //Если R1=40%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF\xFF\xFF      ");
		  LCD_String(str);
			ff=4;
		}
   if(R1>=2014.0&&R1<2416.8&&ff!=5){  //Если R1=50%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF\xFF\xFF\xFF     ");
		  LCD_String(str);
			ff=5;
		}
   if(R1>=2416.8&&R1<2819.6&&ff!=6){  //Если R1=60%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF\xFF\xFF\xFF\xFF    ");
		  LCD_String(str);
			ff=6;
		}
   if(R1>=2819.6&&R1<3222.4&&ff!=7){  //Если R1=70%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF\xFF\xFF\xFF\xFF\xFF   ");
		  LCD_String(str);
			ff=7;
		}
   if(R1>=3222.4&&R1<3625.2&&ff!=8){  //Если R1=80%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF  ");
		  LCD_String(str);
			ff=8;
		}
   if(R1>=3625.2&&R1<3900.0&&ff!=9){  //Если R1=90%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF ");
		  LCD_String(str);
			ff=9;
		}
   if(R1>=3900.0&&ff!=10){  //Если R1=100%
		  LCD_SetPos(5, 0);
		  sprintf(str,"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF");
		  LCD_String(str);
			ff=10;
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
//	  HAL_Delay(100);
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);  //Мигаем 13-м светодиодом для проверки скорости работы while
	}				
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* ADC1 init function */
static void MX_ADC1_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;
  ADC_InjectionConfTypeDef sConfigInjected;

    /**Common config 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Injected Channel 
    */
  sConfigInjected.InjectedChannel = ADC_CHANNEL_0;
  sConfigInjected.InjectedRank = ADC_INJECTED_RANK_1;
  sConfigInjected.InjectedNbrOfConversion = 2;
  sConfigInjected.InjectedSamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfigInjected.ExternalTrigInjecConv = ADC_INJECTED_SOFTWARE_START;
  sConfigInjected.AutoInjectedConv = DISABLE;
  sConfigInjected.InjectedDiscontinuousConvMode = DISABLE;
  sConfigInjected.InjectedOffset = 0;
  if (HAL_ADCEx_InjectedConfigChannel(&hadc1, &sConfigInjected) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Injected Channel 
    */
  sConfigInjected.InjectedChannel = ADC_CHANNEL_1;
  sConfigInjected.InjectedRank = ADC_INJECTED_RANK_2;
  if (HAL_ADCEx_InjectedConfigChannel(&hadc1, &sConfigInjected) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* I2C2 init function */
static void MX_I2C2_Init(void)
{

  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM1 init function */
static void MX_TIM1_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 500;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM2 init function */
static void MX_TIM2_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 100;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM4 init function */
static void MX_TIM4_Init(void)
{

  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 4096;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim4);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11 
                          |CLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DATA_Pin|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA2 PA3 PA4 PA5 
                           PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5 
                          |GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB12 PB13 
                           PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_12|GPIO_PIN_13 
                          |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA8 PA9 PA10 PA11 
                           CLK_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11 
                          |CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : DATA_Pin PB4 PB5 */
  GPIO_InitStruct.Pin = DATA_Pin|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc1) // - прерывание по оканчанию АЦП
{
	R1=HAL_ADCEx_InjectedGetValue(hadc1,ADC_INJECTED_RANK_1);//Заносим в переменную R1 результат АЦП 1-ого канала
	R2=HAL_ADCEx_InjectedGetValue(hadc1,ADC_INJECTED_RANK_2);//Заносим в переменную R2 результат АЦП 2-ого канала

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_0)==GPIO_PIN_SET && HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_RESET&&R2<=400){ //Если рычаг переключен вперед (D) и если ручник не опущен:
		/*Моторы вращаются вперед*/
		TIM4->CCR1=R1; //Заносим в регистр значение (R1) для изменения скважнести ШИМа
		TIM4->CCR2=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR3=R1; //Заносим в регистр значение (R1) для изменения скважнести ШИМа
		TIM4->CCR4=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_1)==GPIO_PIN_SET && HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_RESET&&R2<=400){ //Иначе, если рычаг переключен назад(R) и если ручник не опущен:
		/*Моторы вращаются назад*/
		TIM4->CCR1=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR2=R1; //Заносим в регистр значение (R1) для изменения скважнести ШИМа
		TIM4->CCR3=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR4=R1; //Заносим в регистр значение (R1) для изменения скважнести ШИМа
	}
	if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_0)==GPIO_PIN_RESET && HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_1)==GPIO_PIN_RESET && HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_RESET&&R2<=400){ //�?наче рычаг нходиться в нейтральном положении(N):
		/*Моторы останавливаются*/
		TIM4->CCR1=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR2=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR3=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR4=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	/*ручник на двигателях*/
	if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_SET){ //Нажат ручник:
		R2=4000; //Активируем тормоза на полную мощность
	}
	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){	
		/*тормоза*/	
	/*Левое колесо*/
	if(R2>400 && STOP1>1){
		TIM4->CCR1=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR2=R2*STOP1/4; //Заносим в регистр значение (R2*STOP1/4) для изменения скважнести ШИМа
	}
 	if(R2>400 && STOP1<-1){
		TIM4->CCR1=R2*STOP1/-4; //Заносим в регистр значение (R2*STOP1/-4) для изменения скважнести ШИМа
		TIM4->CCR2=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	if(R2>400 && STOP1<=1 && STOP1>=-1){
		TIM4->CCR1=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR2=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	/*Правое колесо*/
	if(R2>400 && STOP2>1){
		TIM4->CCR3=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR4=R2*STOP2/4; //Заносим в регистр значение (R2*STOP2/4) для изменения скважнести ШИМа
	}
 	if(R2>400 && STOP2<-1){
		TIM4->CCR3=R2*STOP2/-4; //Заносим в регистр значение (R2*STOP2/-4) для изменения скважнести ШИМа
		TIM4->CCR4=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	if(R2>400 && STOP2<=1 && STOP2>=-1){
		TIM4->CCR3=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR4=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
		
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

					/*ABS*/
	  /*Вперёёд*/
	if(ABS==1&&ABSh<-8&&HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_0)==GPIO_PIN_SET&&R2<=400){
		TIM4->CCR1=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR2=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	if(ABS==1&&ABSh>8&&HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_0)==GPIO_PIN_SET&&R2<=400){
		TIM4->CCR3=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR4=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	
		  /*Назад*/
	if(ABS==1&&ABSh<-8&&HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_1)==GPIO_PIN_SET&&R2<=400){
		TIM4->CCR3=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR4=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	if(ABS==1&&ABSh>8&&HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_1)==GPIO_PIN_SET&&R2<=400){
		TIM4->CCR1=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		TIM4->CCR2=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
	}
	
	   /*Отключить*/
	if(ABS==1&&ABSh<8&&ABSh>-8&&R2<=400){ //Если подтормаживать не нужно возвращаем в регистры предидущие значения
		if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_0)==GPIO_PIN_SET && HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_RESET&&R2<=400){ //Если рычаг переключен вперед (D) и если ручник не опущен:
			TIM4->CCR1=R1; //Заносим в регистр значение (R1) для изменения скважнести ШИМа
			TIM4->CCR2=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
			TIM4->CCR3=R1; //Заносим в регистр значение (R1) для изменения скважнести ШИМа
			TIM4->CCR4=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
		}
		if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_1)==GPIO_PIN_SET && HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_RESET&&R2<=400){ //иначе, если рычаг переключен назад(R) и если ручник не опущен:
			TIM4->CCR1=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
			TIM4->CCR2=R1; //Заносим в регистр значение (R1) для изменения скважнести ШИМа
			TIM4->CCR3=0; //Заносим в регистр значение (0) для изменения скважнести ШИМа
			TIM4->CCR4=R1; //Заносим в регистр значение (R1) для изменения скважнести ШИМа
		}
	}
	
	
	if(GPIO_Pin== GPIO_PIN_2) { //Если произошло прерывание на пине 3, то	
		
		if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_2)==GPIO_PIN_SET){ //если на пин A2 подался сигнал(нажали кнопку), то:
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8); //значение на пине A8 сменится на противоположное.
			if(ABS==1){
				ABS=0; //ABS выключается
			}
			else{ //иначе
				ABS=1; //ABS включается
			}
		}
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		 /*Ручник*/
	if(GPIO_Pin== GPIO_PIN_7) { //Если произошло прерывание на пине 7, то	
	if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_7)==GPIO_PIN_SET){ //если на пин A7 подался сигнал(нажали кнопку), то:
	   HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5,GPIO_PIN_SET); //на пин B5 подастся сигнал(светодиод загорится),
	}
	else
		HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5,GPIO_PIN_RESET); // иначе сигнал на пине B5 будет сброшен (светодиод потухнет).
	}
		/*Аварийка*/
	if(GPIO_Pin== GPIO_PIN_6) { //Если произошло прерывание на пине 6, то		
		if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_6)==GPIO_PIN_SET){ //если на пин A6 подался сигнал(нажали кнопку), то:
			HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4,GPIO_PIN_RESET); //на пине B4 сбрасывается значение(светодиод гаснет),
			HAL_GPIO_WritePin (GPIOA, GPIO_PIN_11,GPIO_PIN_RESET); //на пине A11 сбрасывается значение(светодиод гаснет),
			HAL_GPIO_WritePin (GPIOA, GPIO_PIN_10,GPIO_PIN_RESET); //на пине A10 сбрасывается значение(светодиод гаснет),
			PLCD=3; //Переменная аврийки на ЖК дисплее приравнивается к 3, запуская процесс мигания
			LpLCD=0; //Переменная левого поворотника на ЖК дисплее становится равна 0, тем самым выключая его
			RpLCD=0; //Переменная правого поворотника на ЖК дисплее становится равна 0, тем самым выключая его
			P++; //К переменной "P" прибавится единица,
			Lp=1; //Переменной "Lp" присваивается значение 1,
			Rp=1; //Переменной "Rp" присваивается значение 1.
		}
		if(P>1){ //Если P больше единицы, то
			P=0;Lp=0;Rp=0; //значения P,Lp,Rp становятся равны нулю.
			PLCD=1;  //Значение аварийки на ЖК дисплее становится равным 1, выключая аварийку на ЖК дисплее
		}
	}
		/*Левый поворотник*/ 
	if(GPIO_Pin== GPIO_PIN_5){ //Если произошло прерывание на пине 5, то	
	if(P==0){	//если переменная "P" равна нулю то
  if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_5)==GPIO_PIN_SET){ //если на пин A5 подался сигнал(нажали кнопку), то:
		Lp++;	//к переменной "Lp" прибавится единица,
		LpLCD=3; //Переменная левого поворотника на ЖК дисплее приравнивается к 3, запуская процесс мигания
    Rp=0;	//значение Rp станет равно нулю;
    RpLCD=1; //Переменная правого поворотника на ЖК дисплее приравнивается к 1,	выключая правый поворотник	 
		}
	if(Lp>1){ //Если Lp больше единицы, то
	  Lp=0; //значение Lp станет равно нулю.
		LpLCD=1; //Переменная левого поворотника на ЖК дисплее приравнивается к 1,	выключая левый поворотник	 
		}
	}
	}
	/*Правый поворотник*/ 
	if(GPIO_Pin== GPIO_PIN_4){ //Если произошло прерывание на пине 4, то	
	if(P==0){ //если переменная "P" равна нулю то,
  if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_4)==GPIO_PIN_SET){ //если на пин A4 подался сигнал(нажали кнопку), то:
	  Rp++;	//к переменной "Rp" прибавится единица,
		RpLCD=3; //Переменная правого поворотника на ЖК дисплее приравнивается к 3, запуская процесс мигания
    Lp=0;	//значение Lp станет равно нулю;
    LpLCD=1; //Переменная левого поворотника на ЖК дисплее приравнивается к 1,	выключая левый поворотник	 		 
		}
 	if(Rp>1){ //Если Rp больше единицы, то
		Rp=0; //значение Rp станет равно нулю.
		RpLCD=1; //Переменная правого поворотника на ЖК дисплее приравнивается к 1,	выключая правый поворотник	 
		}
	 }
 }
	/*Фары*/
	if(GPIO_Pin== GPIO_PIN_3) { //Если произошло прерывание на пине 3, то	
	 if(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_3)==GPIO_PIN_SET){ //если на пин A3 подался сигнал(нажали кнопку), то:
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9); //значение на пине A9 сменится на противоположное.
		 }
	}
//////////////////////////////////////////////////////////////////////////////////////////////
	/*Прерывания для энкодеров*/	
	// 1 мотор
  if(GPIO_Pin== GPIO_PIN_12){ //Если произошло прерывание на пине 12, то
		RPMHl++; //Считываем скорость вращения
		Mileage1++; //Считываем пробег
		if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_12)==GPIO_PIN_SET && HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET ){ //Если колеса крутятся вперед
			if(STOP2<4){
				STOP2++; //Увеличиваем переменную STOP2
			}
			if(ABSh<10){
				ABSh++; //Увеличиваем переменную ABSh
			}
		}
	}
  if(GPIO_Pin== GPIO_PIN_13){ //Если произошло прерывание на пине 13, то
		if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET && HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_13)==GPIO_PIN_SET ){ //Если колеса крутятся назад
			if(STOP2>-4){
				STOP2--; //Уменьшаем переменную STOP2
			}
			if(ABSh>-10){
				ABSh--; //Уменьшаем переменную ABSh
			}
		}
	}
	// 2 мотор
	if(GPIO_Pin== GPIO_PIN_14){ //Если произошло прерывание на пине 14, то	
		RPMHr++; //Считываем скорость вращения
		Mileage2++; //Считываем пробег
		if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_14)==GPIO_PIN_SET && HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_15)==GPIO_PIN_RESET ){ //Если колеса крутятся вперед
			if(STOP1<4){
				STOP1++; //Увеличиваем переменную STOP1
			}
			if(ABSh>-10){
				ABSh--; //Уменьшаем переменную ABSh
			}
		}
	}
  if(GPIO_Pin== GPIO_PIN_15){ //Если произошло прерывание на пине 15, то
		if(HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_14)==GPIO_PIN_RESET && HAL_GPIO_ReadPin (GPIOB,GPIO_PIN_15)==GPIO_PIN_SET ){ //Если колеса крутятся назад
			if(STOP1>-4){
				STOP1--; //Уменьшаем переменную STOP1
			}
			if(ABSh<10){
				ABSh++; //Увеличиваем переменную ABSh
			}
		}
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

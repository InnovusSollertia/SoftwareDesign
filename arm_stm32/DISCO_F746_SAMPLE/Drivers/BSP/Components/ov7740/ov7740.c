/**
  ******************************************************************************
  * @file    ov7740.c
  * @author  kyChu
  * @version V1.0.0
  * @date    13-November-2017
  * @brief   This file provides the OV7740 camera driver
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ov7740.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup OV7740
  * @brief     This file provides a set of functions needed to drive the
  *            OV7740 Camera module.
  * @{
  */

/** @defgroup OV7740_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup OV7740_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup OV7740_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup OV7740_Private_FunctionPrototypes
  * @{
  */
//static uint64_t ov7740_ConvertValue(uint32_t feature, uint32_t value);
/**
  * @}
  */

/** @defgroup OV7740_Private_Variables
  * @{
  */

CAMERA_DrvTypeDef ov7740_drv =
{
  ov7740_Init,
  ov7740_VerifyID,
  ov7740_Config,
};

/* Initialization sequence for OV7740 */
const unsigned char OV7740_CFG[][2] = {
	{0x12, 0x80}, //Initiate system reset. All registers are set to factory default value after which the chip resumes normal operation.
	/* flag for soft reset delay */
	{0x55, 0xc0},  //0xc0=PLLx8=60fps  0x40=PLLx4=30fps

	/**************************************************************/
	/*  30fps  11 01 ;clock_divider ;sysclk=24MHz at XCLK=24MHz   */
	/*  20fps  11 02 ;clock_divider ;sysclk=16MHz at XCLK=24MHz   */
	/*  15fps  11 03 ;clock_divider ;sysclk=12MHz at XCLK=24MHz   */
	/*  10fps  11 05 ;sysclk=8MHz at XCLK=24MHz                   */
	/*  7p5fps 11 07 ;sysclk=6MHz at XCLK=24MHz                   */
	/**************************************************************/
	/*  7p5fps 11 0x0A ;sysclk=6MHz at XCLK=16.5MHz  (MCK=132/8)  */
	/**************************************************************/
	{0x11, 0x03}, //PLL setting && Clock divider
	/**************************************************************/

	{0x12, 0x00}, //Bit[6-0]:
	{0x0c, 0xf0}, //Bit[6-7]: mirror(bit6) and filp(bit7) function control; Bit4: YUV output, Y<->UV swap
	{0x0d, 0x34}, //Analog Setting **Changing this value is not recommended**
	{0x0e, 0xe3}, //BLC line selection, Bit3: Sleep mode, Bit[1-0]: Output driving capability.
	{0x0f, 0x10}, //Automatic Exposure Control Bit[15-8]
	{0x10, 0xf0}, //Automatic Exposure Control Bit[7-0]
	{0x1f, 0xf0}, //LSBs of tp level exposure control when exposure is less than one line.(MSBs in REG 0x30)
	{0x30, 0xf0}, //MSBs of tp Level Exposure Control when exposure is less than one line.(LSBs in REG 0x1F)
	{0x00, 0x8f}, //AGC Gain Control LSBs, analog gain = (GAIN[9]+1)*(GAIN[8]+1)*(GAIN[7]+1)*(GAIN[6]+1)*(GAIN[5]+1)*(GAIN[4]+1)*((GAIN[3:0]/16)+1)

	{0x13, 0xfa}, //Bit7: AEC speed selection, Bit6: Enable frame drop function, Bit5: Banding enable, Bit4: Banding option, Bit3: LAEC enable, 
								//Bit2: AGC auto/manual control selection, Bit1: Auto white balance control selection, Bit0: Exposure auto/manual control selection.

	{0x14, 0x20}, //Bit7: Analog setting, Bit[6-4]: AGC gain ceiling, Bit[3-1]: Analog setting, Bit0: Manual LAEC enable.
	{0x15, 0x00}, //Bit7: Enable inserting frames in night mode, ... Bit[1-0]: AGC MSBS (digital gain)
	/* output size && start point */
	{0x16, 0x00},
	{0x17, 0x32}, //Sensor Horizontal Output Start Point 8 MSBs
	{0x18, 0x78}, //Sensor Horizontal Output Size 8 MSBs          (480 * 480)
	{0x19, 0x04}, //Sensor Vertical Output Start Point 8 MSBs
	{0x1a, 0xf0}, //Sensor Vertical Output Size MSBs

	{0x1b, 0x80}, //Pixel Shift
	{0x1e, 0x11}, //Bit[7:1]: Analog setting **Changing this value is not recommended**, Bit0: AEC step control.
	{0x20, 0x00}, //Bit[7-6]: Maximum banding step for 50/60Hz, 1MSB; Bit[5-0]: Analog setting **Changing this value is not recommended**
	{0x21, 0x23}, //Bit[7-4]: Maximum banding step for 50Hz, Bit[3-0]: Maximum banding step for 60Hz; 4LSBs.
//	{0x22, 0x00}, //Analog Setting **Changing this value is not recommended**    <!!!have no default value!!!>
//	{0x23, 0x00}, //Analog Setting **Changing this value is not recommended**    <!!!have no default value!!!>
	{0x24, 0xa0}, //Luminance Signal High Range for AEC/AGC Operation
	{0x25, 0x60}, //Luminance Signal Low Range for AEC/AGC Operation
	{0x26, 0x44}, //Effective only AEC/AGC fast mode
	{0x27, 0x80}, //Bit7: Black sun cancellation enable, Analog setting **Changing this value is not recommended**
	{0x28, 0x00}, //HREF, HSYNV, VSYNC configuration.
	{0x29, 0x18}, //Horizontal tp Counter End Point LSBs
	{0x2a, 0x03}, //Horizontal tp Counter End Point MSBs
	{0x2b, 0xf8}, //Row Counter End Point LSBs
	{0x2c, 0x01}, //Row Counter End Point MSBs
	{0x2d, 0x00}, //Automatically Inserted Dummy Lines in Night Mode LSBs
	{0x2e, 0x00}, //Automatically Inserted Dummy Lines in Night Mode MSBs
	{0x31, 0x1E}, //DSP H output size 8MSB                       (120 * 120)
	{0x32, 0x3C}, //DSP V output size 8MSB
	{0x33, 0x00}, //Bit[7-4]: H size offset; Bit[3-0]: V size offset
	{0x34, 0x00}, //Bit[2-1]: DSP H output size 2 LSBs, Bit0: DSP V output size 1 LSB.
	{0x35, 0x05}, //Analog Setting **Changing this value is not recommended**    <!!!have no default value!!!>
	{0x36, 0x3f}, //Analog Setting **Changing this value is not recommended**    <!!!have no default value!!!>
//	{0x37, 0x00}, //Analog Setting **Changing this value is not recommended**    <!!!have no default value!!!>
/*
	{0x39 - 0x49} //Analog Setting **Changing this value is not recommended**    <!!!have no default value!!!>
*/
	{0x04, 0x00}, //Analog Setting **Changing this value is not recommended**
//	{0x3d, 0x0f},
//	{0x3e, 0x80},
//	{0x3f, 0x40},
//	{0x40, 0x7f},
//	{0x41, 0x6a},
//	{0x42, 0x29},
//	{0x44, 0x22}, //;was 11
//	{0x45, 0x41},
//	{0x47, 0x02},
//	{0x49, 0x64},
	{0x4a, 0x81}, //Bit[7-4]: Analog setting, Bit3: Internal regulator bypass selection, Bit[2-0]: Analog setting.    0xa1
/*
	{0x4b - 0x4f} //Analog Setting **Changing this value is not recommended**    <!!!have no default value!!!>
*/
//	{0x4b, 0x40},
//	{0x4c, 0x1a},
//	{0x4d, 0x50},
//	{0x4e, 0x13},
//	{0x4f, ----},
	{0x64, 0x00},
	{0x67, 0x88},
	{0x68, 0x1a},

	{0x50, 0x2e}, //LSBs of Banding Starting Step for 50Hz light source.(MSBs in REG 0x52)    0x97
	{0x51, 0xfc}, //LSBs of Banding Starting Step for 60Hz light source.(MSBs in REG 0x52)    0x7e
	{0x52, 0x10}, // ...    0x00
	{0x53, 0x00}, //Analog Setting **Changing this value is not recommended**
	{0x54, 0xFC}, //direction control for I/O pads
	{0xFF, 0xFF}, //disable group register write function. <page 19 in datasheet, V1.51>
	/*********************************/
	/* To enable Static Test Pattern */
	/*********************************/
//	{0x38, 0x17},
//	{0x84, 0x12},

//	{0x38, 0x18},  //MODE 3
//	{0x84, 0x22},

//	{0x38, 0x07},
//	{0x84, 0x16},

	/*********************************/
//	/* Normal Mode / No test pattern */
//	{0x38, 0x14},
	/*********************************/
	{0xe9, 0x00},

	{0x56, 0xff}, //16-zone Y Average Select.     0x55
	{0x57, 0xff}, // ...
	{0x58, 0xff}, // ...
	{0x59, 0xff}, // ...

	{0x5a, 0x01}, //k (slope of UV auto adjust curve), y = a - kx                                          0x24
	{0x5b, 0xff}, //Bit[7-6]: gth2, Bit[5-0]: a                                                            0x1f
	{0x5c, 0x1f}, //Bit[7-5]: gth2, Bit[4-0]: UV...                                                        0x88
	{0x5d, 0x00}, //Bit[7-4]: gth1, Bit[3-0]: Control bits **Changing these values is not recommended**    0x60
/*
	{0x5e - 0x62} //Analog Setting **Changing this value is not recommended**    <!!!have no default value!!!>
*/
//	{0x5f, 0x04},
	{0xec, 0x40}, // 0x40 50hz
//	{0x13, 0xff},

	{0x80, 0x7f}, //ISP Control 00
	{0x81, 0x3f}, //ISP Control 01
	{0x82, 0x3e}, //ISP Control 02, Vertical scaler enable(Bit3) && Horizontal scaler enable(Bit2)
	{0x83, 0x0d}, //ISP Control 03

	{0x38, 0x11},
	{0x84, 0x70},

	{0x85, 0x00},
	{0x86, 0x03},
	{0x87, 0x01},
	{0x88, 0x05},
	{0x89, 0x30},
	{0x8d, 0x30},
	{0x8f, 0x85},
	{0x93, 0x30},
	{0x95, 0x85},
	{0x99, 0x30},
	{0x9b, 0x85},

	{0x9c, 0x08},
	{0x9d, 0x12},
	{0x9e, 0x23},
	{0x9f, 0x45},
	{0xa0, 0x55},
	{0xa1, 0x64},
	{0xa2, 0x72},
	{0xa3, 0x7f},
	{0xa4, 0x8b},
	{0xa5, 0x95},
	{0xa6, 0xa7},
	{0xa7, 0xb5},
	{0xa8, 0xcb},
	{0xa9, 0xdd},
	{0xaa, 0xec},
	{0xab, 0x1a},

	{0xce, 0x78},
	{0xcf, 0x6e},
	{0xd0, 0x0a},
	{0xd1, 0x0c},
	{0xd2, 0x84},
	{0xd3, 0x90},
	{0xd4, 0x1e},
	{0xd5, 0x10}, //Bit5: scale_size_restart, Bit4: scale_zoom_mode, Bit[2-0]: scale_step_num

	{0xd7, 0x00},
	{0xd8, 0x84},
	{0xe5, 0x0c}, //Vertical scale control

	{0xac, 0x6e},
	{0xbe, 0xff},
	{0xbf, 0x00},
};

/**
  * @}
  */
  
/** @defgroup OV7740_Private_Functions
  * @{
  */

/**
  * @brief  Initializes the OV7740 CAMERA component.
  * @param  DeviceAddr: Device address on communication Bus.
  * @param  resolution: Camera resolution
  * @retval None
  */
void ov7740_Init(uint16_t DeviceAddr, uint32_t resolution)
{
	uint32_t index;

	/* Initialize I2C */
	CAMERA_IO_Init();

	/* Prepare the camera to be configured by resetting all its registers */
//	CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_COM7, 0x80);
	CAMERA_Delay(200);

	/* Initialize GC0329 */
	for(index=0; index<(sizeof(OV7740_CFG)/2); index++)
	{
		CAMERA_IO_Write(DeviceAddr, OV7740_CFG[index][0], OV7740_CFG[index][1]);
		CAMERA_Delay(2);
	}
}

/**
  * @brief  Configures the OV7740 camera feature.
  * @param  DeviceAddr: Device address on communication Bus.
  * @param  feature: Camera feature to be configured
  * @param  value: Value to be configured
  * @param  brightness_value: Brightness value to be configured
  * @retval None
  */
void ov7740_Config(uint16_t DeviceAddr, uint32_t feature, uint32_t value, uint32_t brightness_value)
{
//  uint8_t tslb, mtx1, mtx2, mtx3, mtx4, mtx5, mtx6;
//  uint64_t value_tmp;
//  uint32_t br_value;

//  /* Convert the input value into GC0329 parameters */
//  value_tmp = gc0329_ConvertValue(feature, value);
//  br_value = (uint32_t)gc0329_ConvertValue(CAMERA_CONTRAST_BRIGHTNESS, brightness_value);

//  switch(feature)
//  {
//  case CAMERA_CONTRAST_BRIGHTNESS:
//    {
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_BRTN, br_value);
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_CNST1, value_tmp);
//      break;
//    }
//  case CAMERA_BLACK_WHITE:
//  case CAMERA_COLOR_EFFECT:
//    {
//      tslb = (uint8_t)(value_tmp >> 48);
//      mtx1 = (uint8_t)(value_tmp >> 40);
//      mtx2 = (uint8_t)(value_tmp >> 32);
//      mtx3 = (uint8_t)(value_tmp >> 24);
//      mtx4 = (uint8_t)(value_tmp >> 16);
//      mtx5 = (uint8_t)(value_tmp >> 8);
//      mtx6 = (uint8_t)(value_tmp);
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_TSLB, tslb);
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_MTX1, mtx1);
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_MTX2, mtx2);
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_MTX3, mtx3);
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_MTX4, mtx4);
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_MTX5, mtx5);
//      CAMERA_IO_Write(DeviceAddr, OV9655_SENSOR_MTX6, mtx6);
//      break;
//    }
//  default:
//    {
//      break;
//    }
//  }
}

/**
  * @brief  Read the OV7740 Camera identity.
  * @param  DeviceAddr: Device address on communication Bus.
  * @retval the OV7740 ID
  */
uint16_t ov7740_VerifyID(uint16_t DeviceAddr)
{
	OVCamera_IDTypeDef OV7740ID;

  /* Initialize I2C */
  CAMERA_IO_Init();

  /* Get the camera ID */
	OV7740ID.Product_ID_H = CAMERA_IO_Read(DeviceAddr, OV7740_PIDH_ADDRESS);
	OV7740ID.Product_ID_L = CAMERA_IO_Read(DeviceAddr, OV7740_PIDL_ADDRESS);
	OV7740ID.Manufacturer_IDH = CAMERA_IO_Read(DeviceAddr, OV7740_MIDH_ADDRESS);
	OV7740ID.Manufacturer_IDL = CAMERA_IO_Read(DeviceAddr, OV7740_MIDL_ADDRESS);

	if(OV7740ID.Product_ID_H == OV7740_PIDH && \
		 OV7740ID.Product_ID_L == OV7740_PIDL && \
		 OV7740ID.Manufacturer_IDH == OV7740_MIDH && \
		 OV7740ID.Manufacturer_IDL == OV7740_MIDL)
		return 1;
	else
		return 0;
}

/******************************************************************************
                            Static Functions
*******************************************************************************/
/**
  * @brief  Convert input values into OV7740 parameters.
  * @param  feature: Camera feature to be configured
  * @param  value: Value to be configured
  * @retval The converted value
  */
//static uint64_t ov7740_ConvertValue(uint32_t feature, uint32_t value)
//{
//  uint64_t ret = 0;

//  switch(feature)
//  {
//  case CAMERA_BLACK_WHITE:
//    {
//      switch(value)
//      {
//      case CAMERA_BLACK_WHITE_BW:
//        {
//          ret =  OV9655_BLACK_WHITE_BW;
//          break;
//        }
//      case CAMERA_BLACK_WHITE_NEGATIVE:
//        {
//          ret =  OV9655_BLACK_WHITE_NEGATIVE;
//          break;
//        }
//      case CAMERA_BLACK_WHITE_BW_NEGATIVE:
//        {
//          ret =  OV9655_BLACK_WHITE_BW_NEGATIVE;
//          break;
//        }
//      case CAMERA_BLACK_WHITE_NORMAL:
//        {
//          ret =  OV9655_BLACK_WHITE_NORMAL;
//          break;
//        }
//      default:
//        {
//          ret =  OV9655_BLACK_WHITE_NORMAL;
//          break;
//        }
//      }
//      break;
//    }
//  case CAMERA_CONTRAST_BRIGHTNESS:
//    {
//      switch(value)
//      {
//      case CAMERA_BRIGHTNESS_LEVEL0:
//        {
//          ret =  OV9655_BRIGHTNESS_LEVEL0;
//          break;
//        }
//      case CAMERA_BRIGHTNESS_LEVEL1:
//        {
//          ret =  OV9655_BRIGHTNESS_LEVEL1;
//          break;
//        }
//      case CAMERA_BRIGHTNESS_LEVEL2:
//        {
//          ret =  OV9655_BRIGHTNESS_LEVEL2;
//          break;
//        }
//      case CAMERA_BRIGHTNESS_LEVEL3:
//        {
//          ret =  OV9655_BRIGHTNESS_LEVEL3;
//          break;
//        }
//      case CAMERA_BRIGHTNESS_LEVEL4:
//        {
//          ret =  OV9655_BRIGHTNESS_LEVEL4;
//          break;
//        }
//      case CAMERA_CONTRAST_LEVEL0:
//        {
//          ret =  OV9655_CONTRAST_LEVEL0;
//          break;
//        }
//      case CAMERA_CONTRAST_LEVEL1:
//        {
//          ret =  OV9655_CONTRAST_LEVEL1;
//          break;
//        }
//      case CAMERA_CONTRAST_LEVEL2:
//        {
//          ret =  OV9655_CONTRAST_LEVEL2;
//          break;
//        }
//      case CAMERA_CONTRAST_LEVEL3:
//        {
//          ret =  OV9655_CONTRAST_LEVEL3;
//          break;
//        }
//      case CAMERA_CONTRAST_LEVEL4:
//        {
//          ret =  OV9655_CONTRAST_LEVEL4;
//          break;
//        }
//      default:
//        {
//          ret =  OV9655_CONTRAST_LEVEL0;
//          break;
//        }
//      }
//      break;
//    }
//  case CAMERA_COLOR_EFFECT:
//    {
//      switch(value)
//      {
//      case CAMERA_COLOR_EFFECT_ANTIQUE:
//        {
//          ret =  OV9655_COLOR_EFFECT_ANTIQUE;
//          break;
//        }
//      case CAMERA_COLOR_EFFECT_BLUE:
//        {
//          ret =  OV9655_COLOR_EFFECT_BLUE;
//          break;
//        }
//      case CAMERA_COLOR_EFFECT_GREEN:
//        {
//          ret =  OV9655_COLOR_EFFECT_GREEN;
//          break;
//        }
//      case CAMERA_COLOR_EFFECT_RED:
//        {
//          ret =  OV9655_COLOR_EFFECT_RED;
//          break;
//        }
//      case CAMERA_COLOR_EFFECT_NONE:
//      default:
//        {
//          ret =  OV9655_COLOR_EFFECT_NONE;
//          break;
//        }
//      }
//      break;
//    default:
//      {
//        ret = 0;
//        break;
//      }
//    }
//  }

//  return ret;
//}

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */

/******************************** END OF FILE *********************************/

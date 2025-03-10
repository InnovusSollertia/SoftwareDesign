/**
  ******************************************************************************
  * @file    gc0329_camera.h
  * @author  kyChu
  * @version V1.0.0
  * @date    13-November-2017
  * @brief   This file contains the common defines and functions prototypes for
  *          the gc0329_camera.c driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GC0329_CAMERA_H
#define __GC0329_CAMERA_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
/* Include Camera component Driver */
#include "gc0329.h"
#include "stm32746g_discovery.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32746G_DISCOVERY
  * @{
  */
    
/** @addtogroup STM32746G_DISCOVERY_CAMERA
  * @{
  */ 
   
/** @defgroup STM32746G_DISCOVERY_CAMERA_Exported_Types STM32746G_DISCOVERY_CAMERA Exported Types
  * @{
  */
  
/** 
  * @brief  Camera State structures definition  
  */  
typedef enum 
{
  CAMERA_OK            = 0x00,
  CAMERA_ERROR         = 0x01,
  CAMERA_TIMEOUT       = 0x02,
  CAMERA_NOT_DETECTED  = 0x03,
  CAMERA_NOT_SUPPORTED = 0x04

} Camera_StatusTypeDef;

#define RESOLUTION_R160x120      CAMERA_R160x120      /* QQVGA Resolution     */
#define RESOLUTION_R320x240      CAMERA_R320x240      /* QVGA Resolution      */
#define RESOLUTION_R480x272      CAMERA_R480x272      /* 480x272 Resolution   */
#define RESOLUTION_R640x480      CAMERA_R640x480      /* VGA Resolution       */  
/**
  * @}
  */ 
 
/** @defgroup STM32746G_DISCOVERY_CAMERA_Exported_Constants STM32746G_DISCOVERY_CAMERA Exported Constants
  * @{
  */
#define BSP_CAMERA_IRQHandler      DCMI_IRQHandler
#define BSP_CAMERA_DMA_IRQHandler  DMA2_Stream1_IRQHandler  

/**
  * @}
  */

/** @addtogroup STM32746G_DISCOVERY_CAMERA_Exported_Functions
  * @{
  */    
uint8_t BSP_CAMERA_Init(void);  
uint8_t BSP_CAMERA_DeInit(void);
void    BSP_CAMERA_ContinuousStart(uint8_t *buff, uint32_t size);
void    BSP_CAMERA_SnapshotStart(uint8_t *buff, uint32_t size);
void    BSP_CAMERA_Suspend(void);
void    BSP_CAMERA_Resume(void);
uint8_t BSP_CAMERA_Stop(void); 
void    BSP_CAMERA_PwrUp(void);
void    BSP_CAMERA_PwrDown(void);
void    BSP_CAMERA_LineEventCallback(void);
void    BSP_CAMERA_VsyncEventCallback(void);
void    BSP_CAMERA_FrameEventCallback(void);
void    BSP_CAMERA_ErrorCallback(void);

void BSP_CAMERA_Config(uint32_t d3, uint32_t d1, uint32_t d2);
/* Camera features functions prototype */
void    BSP_CAMERA_ContrastBrightnessConfig(uint32_t contrast_level, uint32_t brightness_level);
void    BSP_CAMERA_BlackWhiteConfig(uint32_t Mode);
void    BSP_CAMERA_ColorEffectConfig(uint32_t Effect);
   
/* These functions can be modified in case the current settings (e.g. DMA stream)
   need to be changed for specific application needs */
void BSP_CAMERA_MspInit(DCMI_HandleTypeDef *hdcmi, void *Params);
void BSP_CAMERA_MspDeInit(DCMI_HandleTypeDef *hdcmi, void *Params);


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

#ifdef __cplusplus
}
#endif

#endif /* __STM32746G_DISCOVERY_CAMERA_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

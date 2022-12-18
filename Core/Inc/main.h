/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "global.h"
#include "button.h"
#include "task.h"
#include "scheduler.h"
#include "string.h"
#include "stdio.h"
#include "software_timer.h"
#include "pedestrian.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Perdes_Button_Pin GPIO_PIN_0
#define Perdes_Button_GPIO_Port GPIOA
#define Mode_Button_Pin GPIO_PIN_1
#define Mode_Button_GPIO_Port GPIOA
#define Add_Button_Pin GPIO_PIN_4
#define Add_Button_GPIO_Port GPIOA
#define Confirm_Button_Pin GPIO_PIN_0
#define Confirm_Button_GPIO_Port GPIOB
#define PED0_Pin GPIO_PIN_10
#define PED0_GPIO_Port GPIOB
#define PED1_Pin GPIO_PIN_8
#define PED1_GPIO_Port GPIOA
#define Led_11_Pin GPIO_PIN_10
#define Led_11_GPIO_Port GPIOA
#define Led_12_Pin GPIO_PIN_3
#define Led_12_GPIO_Port GPIOB
#define Led_22_Pin GPIO_PIN_4
#define Led_22_GPIO_Port GPIOB
#define Led_21_Pin GPIO_PIN_5
#define Led_21_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart2;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define down_key_Pin GPIO_PIN_4
#define down_key_GPIO_Port GPIOA
#define right_key_Pin GPIO_PIN_5
#define right_key_GPIO_Port GPIOA
#define f1_key_Pin GPIO_PIN_6
#define f1_key_GPIO_Port GPIOA
#define f2_key_Pin GPIO_PIN_7
#define f2_key_GPIO_Port GPIOA
#define left_key_Pin GPIO_PIN_10
#define left_key_GPIO_Port GPIOB
#define up_key_Pin GPIO_PIN_11
#define up_key_GPIO_Port GPIOB
#define scl_Pin GPIO_PIN_11
#define scl_GPIO_Port GPIOA
#define sda_Pin GPIO_PIN_12
#define sda_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

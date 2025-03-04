/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32l5xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IO1_Pin GPIO_PIN_2
#define IO1_GPIO_Port GPIOB
#define IO2_Pin GPIO_PIN_12
#define IO2_GPIO_Port GPIOF
#define IO3_Pin GPIO_PIN_13
#define IO3_GPIO_Port GPIOF
#define IO4_Pin GPIO_PIN_14
#define IO4_GPIO_Port GPIOF
#define IO5_Pin GPIO_PIN_15
#define IO5_GPIO_Port GPIOF
#define SPI1_NSS_Pin GPIO_PIN_12
#define SPI1_NSS_GPIO_Port GPIOE
#define SPI2_NSS_Pin GPIO_PIN_0
#define SPI2_NSS_GPIO_Port GPIOD
#define IO6_Pin GPIO_PIN_3
#define IO6_GPIO_Port GPIOD
#define IO7_Pin GPIO_PIN_4
#define IO7_GPIO_Port GPIOD
#define IO8_Pin GPIO_PIN_5
#define IO8_GPIO_Port GPIOD
#define IO9_Pin GPIO_PIN_6
#define IO9_GPIO_Port GPIOD
#define IO10_Pin GPIO_PIN_7
#define IO10_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern I2C_HandleTypeDef hi2c3;

extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart1;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

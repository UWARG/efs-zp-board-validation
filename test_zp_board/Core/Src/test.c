/*
 * test.c
 *
 *  Created on: Jan 27, 2025
 *      Author: arigu
 */


#include "test.h"
#include "stdio.h"

void testGPIO() {
  // all pins off
  HAL_GPIO_WritePin(IO1_GPIO_Port, IO1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOF, IO2_Pin|IO3_Pin|IO4_Pin|IO5_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, IO6_Pin|IO7_Pin|IO8_Pin|IO9_Pin
                            |IO10_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO1_GPIO_Port, IO1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO1_GPIO_Port, IO1_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO2_GPIO_Port, IO2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO2_GPIO_Port, IO2_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO3_GPIO_Port, IO3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO3_GPIO_Port, IO3_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO4_GPIO_Port, IO4_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO4_GPIO_Port, IO4_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO5_GPIO_Port, IO5_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO5_GPIO_Port, IO5_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO6_GPIO_Port, IO6_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO6_GPIO_Port, IO6_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO7_GPIO_Port, IO7_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO7_GPIO_Port, IO7_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO8_GPIO_Port, IO8_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO8_GPIO_Port, IO8_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO9_GPIO_Port, IO9_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO9_GPIO_Port, IO9_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(IO10_GPIO_Port, IO10_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(IO10_GPIO_Port, IO10_Pin, GPIO_PIN_RESET);
}

void testTIM(TIM_HandleTypeDef *htim, uint32_t channel, float compare) {
  __HAL_TIM_SET_COMPARE(htim, channel, __HAL_TIM_GET_AUTORELOAD(htim) * compare);
  HAL_TIM_PWM_Start(htim, channel);
  HAL_TIM_PWM_Stop(htim, channel);
}

void testTimers() {
  testTIM(&htim1, TIM_CHANNEL_1, 0.05);
  testTIM(&htim1, TIM_CHANNEL_2, 0.10);

  testTIM(&htim3, TIM_CHANNEL_1, 0.05);
  testTIM(&htim3, TIM_CHANNEL_2, 0.10);
  testTIM(&htim3, TIM_CHANNEL_3, 0.15);
  testTIM(&htim3, TIM_CHANNEL_4, 0.20);

  testTIM(&htim4, TIM_CHANNEL_1, 0.05);
  testTIM(&htim4, TIM_CHANNEL_2, 0.10);
  testTIM(&htim4, TIM_CHANNEL_3, 0.15);
  testTIM(&htim4, TIM_CHANNEL_4, 0.20);

  testTIM(&htim5, TIM_CHANNEL_1, 0.05);
  testTIM(&htim5, TIM_CHANNEL_2, 0.10);
  testTIM(&htim5, TIM_CHANNEL_3, 0.15);
  testTIM(&htim5, TIM_CHANNEL_4, 0.20);

  testTIM(&htim16, TIM_CHANNEL_1, 0.05);
  testTIM(&htim17, TIM_CHANNEL_1, 0.10);

}

void CS(SPI_HandleTypeDef *hspi, GPIO_PinState state) {
  if (hspi -> Instance == SPI1) {
    HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, state);
  } else if (hspi -> Instance == SPI2) {
    HAL_GPIO_WritePin(SPI2_NSS_GPIO_Port, SPI2_NSS_Pin, state);
  }
}

void testSPI(SPI_HandleTypeDef *hspi) {
  uint8_t txDataBuf[3] = {0x01, 0x02, 0x03};
  uint8_t rxDataBuf[3];
  CS(hspi, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(hspi, txDataBuf, rxDataBuf, 3, HAL_MAX_DELAY);
  CS(hspi, GPIO_PIN_SET);
}

void testI2CTx(I2C_HandleTypeDef *hi2c) {
  uint8_t txDataBuf[3] = {0x23, 0x40, 0x01};
  HAL_I2C_Master_Transmit(hi2c, 0b00000010, txDataBuf, 3, HAL_MAX_DELAY);
}

void testI2CRx(I2C_HandleTypeDef *hi2c) {
  uint8_t rxDataBuf[3];
  HAL_I2C_Master_Receive(hi2c, 0b00000010, rxDataBuf, 3, HAL_MAX_DELAY);
  printf("%x ", rxDataBuf[0]);
  printf("%x ", rxDataBuf[1]);
  printf("%x\n", rxDataBuf[2]);
}

void testUART(UART_HandleTypeDef *huart) {
  uint8_t txDataBuf[3] = {0x01, 0x02, 0x03};
  //uint8_t rxDataBuf[3];
  HAL_UART_Transmit(huart, txDataBuf, 3, HAL_MAX_DELAY);
  //HAL_UART_Recieve(huart, rxDataBuf, 3, HAL_MAX_DELAY);
}

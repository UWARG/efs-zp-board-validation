/*
 * test.c
 *
 *  Created on: Oct 7, 2025
 *      Author: lawrencewang
 */
#include "test.h"


void enableServo(SPI_HandleTypeDef *hspi, gpio *cs, gpio *servoEn, uint8_t bm) {
  HAL_GPIO_WritePin(servoEn->gpioGroup, servoEn->gpioPin, GPIO_PIN_SET);

  uint8_t rx[2], tx[2];
  tx[0] = bm;
  tx[1] = 0xAC;

  HAL_GPIO_WritePin(cs->gpioGroup, cs->gpioPin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(hspi, tx, rx, 2, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(cs->gpioGroup, cs->gpioPin, GPIO_PIN_SET);
}

void testTIM(TIM_HandleTypeDef *htim, uint32_t channel, float compare) {
  __HAL_TIM_SET_COMPARE(htim, channel, __HAL_TIM_GET_AUTORELOAD(htim) * compare);
  HAL_TIM_PWM_Start(htim, channel);
  HAL_TIM_PWM_Stop(htim, channel);
}

void testTimers(TIM_HandleTypeDef *htim1, TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim3, TIM_HandleTypeDef *htim16, TIM_HandleTypeDef *htim17) {
  testTIM(htim1, TIM_CHANNEL_1, 0.05);
  testTIM(htim1, TIM_CHANNEL_2, 0.10);
  testTIM(htim1, TIM_CHANNEL_3, 0.05);
  testTIM(htim1, TIM_CHANNEL_4, 0.10);

  testTIM(htim2, TIM_CHANNEL_1, 0.05);
  testTIM(htim2, TIM_CHANNEL_2, 0.10);
  testTIM(htim2, TIM_CHANNEL_3, 0.15);
  testTIM(htim2, TIM_CHANNEL_4, 0.20);

  testTIM(htim3, TIM_CHANNEL_3, 0.05);
  testTIM(htim3, TIM_CHANNEL_4, 0.10);

  testTIM(htim16, TIM_CHANNEL_1, 0.05);
  testTIM(htim17, TIM_CHANNEL_1, 0.10);

}
// Generic Chip Select control for any SPI + NSS pin
void CS(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState state) {
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, state);
}

// Test SPI transaction with a specific NSS pin
void testSPI(SPI_HandleTypeDef *hspi, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    uint8_t txDataBuf[3] = {0x01, 0x02, 0x03};
    uint8_t rxDataBuf[3];

    // Assert chip select
    CS(GPIOx, GPIO_Pin, GPIO_PIN_RESET);

    // Transmit and receive simultaneously
    HAL_SPI_TransmitReceive(hspi, txDataBuf, rxDataBuf, 3, HAL_MAX_DELAY);

    // Deassert chip select
    CS(GPIOx, GPIO_Pin, GPIO_PIN_SET);

    // Optional: check if rxDataBuf matches txDataBuf (loopback or echo device)
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

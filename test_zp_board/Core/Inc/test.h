/*
 * test.h
 *
 *  Created on: Jan 27, 2025
 *      Author: arigu
 */

#ifndef INC_TEST_H_
#define INC_TEST_H_

#include "main.h"

void testGPIO();

void testTIM(TIM_HandleTypeDef *htim, uint32_t channel, float compare);
void testTimers();

void CS(SPI_HandleTypeDef *hspi, GPIO_PinState state);
void testSPI(SPI_HandleTypeDef *hspi);

void testI2CTx(I2C_HandleTypeDef *hi2c);
void testI2CRx(I2C_HandleTypeDef *hi2c);

void testUART(UART_HandleTypeDef *huart);
#endif /* INC_TEST_H_ */



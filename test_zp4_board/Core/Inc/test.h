
#ifndef INC_TEST_H_
#define INC_TEST_H_

#include "main.h"
#include <stdint.h>
//#include "stm32h7xx_hal.h"

/*
Enable servo pwm channels for 1-8
Enables the ServoEN pin and enables the high side driver for specified channel 1-8
Pass in the switch hspi and the cs GPIO pin
*/
typedef struct {
    GPIO_TypeDef *gpioGroup;
    uint16_t gpioPin;
} gpio;

void enableServo(SPI_HandleTypeDef *hspi, gpio *cs, gpio *servoEn, uint8_t bm);

void testTIM(TIM_HandleTypeDef *htim, uint32_t channel, float compare);
void testTimers(TIM_HandleTypeDef *htim1, TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim3, TIM_HandleTypeDef *htim16, TIM_HandleTypeDef *htim17);

void CS(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState state);
void testSPI(SPI_HandleTypeDef *hspi, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

void testI2CTx(I2C_HandleTypeDef *hi2c);
void testI2CRx(I2C_HandleTypeDef *hi2c);

void testUART(UART_HandleTypeDef *huart);
#endif /* INC_TEST_H_ */

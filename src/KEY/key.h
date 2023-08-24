#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
// KEY1
#define KEY1_GPIO_CLK  RCC_APB2Periph_GPIOA
#define KEY1_GPIO_PORT GPIOA
#define KEY1_GPIO_PIN  GPIO_Pin_0
// KEY2
#define KEY2_GPIO_CLK  RCC_APB2Periph_GPIOC
#define KEY2_GPIO_PORT GPIOC
#define KEY2_GPIO_PIN  GPIO_Pin_13
// KEY Status
#define KEY_ON  1
#define KEY_OFF 0
// RED Led
#define RED_GPIO_PORT GPIOB
#define RED_GPIO_CLK  RCC_APB2Periph_GPIOB
#define RED_GPIO_PIN  GPIO_Pin_5
// GREEN Led
#define GREEN_GPIO_PORT GPIOB
#define GREEN_GPIO_CLK  RCC_APB2Periph_GPIOB
#define GREEN_GPIO_PIN  GPIO_Pin_0
// BLUE Led
#define BLUE_GPIO_PORT GPIOB
#define BLUE_GPIO_CLK  RCC_APB2Periph_GPIOB
#define BLUE_GPIO_PIN  GPIO_Pin_1

void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void Led_GPIO_Config(void);

#endif

#ifndef _L298N_H
#define _L298N_H

#include "stm32f10x.h"

#define High 1
#define Low  0

#define IN1(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_2); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_2)

#define IN2(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_3); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_3)

#define IN3(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_4); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_4)

#define IN4(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_5); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_5)

void Putter_Config(void);
void Putter_Stop(void);
void Putter_Up(void);
void Putter_Down(void);
void delay_ms(__IO uint32_t ms);
void delay_us(__IO uint32_t us);

#endif // !_L298N_H

#ifndef _TIM_H_
#define _TIM_H_

#include "stm32f10x.h"

/*使用TIM的通道1*/
#define GENERAL_TIM               TIM3
#define GENERAL_TIM_APBxClock_FUN RCC_APB1PeriphClockCmd
#define GENERAL_TIM_CLK           RCC_APB1Periph_TIM3
// 内部时钟为72MHz，则计数一次的时间为(7200/72000000)s=0.1ms;
#define GENERAL_TIM_Prescaler 0 
// 产生一次计数中断的周期为20ms，与驱动舵机需要的周期相符
#define GENERAL_TIM_Period (900 - 1)

// TIM 输出比较通道1
#define GENERAL_TIM_CHx_GPIO_CLK RCC_APB2Periph_GPIOA
#define GENERAL_TIM_CHx_PORT     GPIOA
#define GENERAL_TIM_CHx_PIN      GPIO_Pin_6

#define TIM_SetComparex          TIM_SetCompare1
#define TIM_SetComparey          TIM_SetCompare2
#define TIM_OCxInit              TIM_OC1Init
#define TIM_OCyInit              TIM_OC2Init

void GENERAL_TIM_Init(void);
void Duty_Cycle_Control(uint16_t Comparex);

#endif // !_TIM_H_

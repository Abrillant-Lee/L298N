#include "l298n.h"
/*
 * name  : Putter_Config
 * brief : 电动推杆驱动初始化
 * param : void
 * return: void
 */
void Putter_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);
}

/*
 * name  : Putter_Stop
 * brief : 电动推杆停止
 * param : void
 * return: void
 */
void Putter_Stop(void)
{
    IN1(Low);
    IN2(Low);
}

/*
 * name  : Putter_Up
 * brief : 电动推杆上升
 * param : void
 * return: void
 */
void Putter_Up(void)
{
    IN3(Low);
    IN4(High);
}

/*
 * name  : Putter_Down
 * brief : 电动推杆下降
 * param : void
 * return: void
 */
void Putter_Down(void)
{
    IN3(High);
    IN4(Low);
}

void delay_us(__IO uint32_t us)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock / 1000000);

    for (i = 0; i < us; i++) {
        // 当计数器的值减小到0的时候，CRTL寄存器的位16会置1
        while (!((SysTick->CTRL) & (1 << 16)))
            ;
    }
    // 关闭SysTick定时器
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void delay_ms(__IO uint32_t ms)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock / 1000);

    for (i = 0; i < ms; i++) {
        // 当计数器的值减小到0的时候，CRTL寄存器的位16会置1
        // 当置1时，读取该位会清0
        while (!((SysTick->CTRL) & (1 << 16)))
            ;
    }
    // 关闭SysTick定时器
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
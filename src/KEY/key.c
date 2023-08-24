#include "key.h"
/*
 * name  :  Key_GPIO_Config
 * brief :  按键初始化
 * param :  void
 * return:  void
 */
void Key_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK | KEY2_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin  = KEY1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = KEY2_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);
}
/*
 * name  :  Key_Scan
 * brief :  按键扫描
 * param :  GPIOx:GPIOA GPIOB GPIOC
 * return:  KEY_ON KEY_OFF
 */
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
        while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
            ;
        return KEY_ON;
    } else
        return KEY_OFF;
}

/*
 * name  :  Led_GPIO_Config
 * brief :  LED初始化
 * param :  void
 * return:  void
 */
void Led_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RED_GPIO_CLK | GREEN_GPIO_CLK | BLUE_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin   = RED_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(RED_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin   = GREEN_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GREEN_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin   = BLUE_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BLUE_GPIO_PORT, &GPIO_InitStructure);

    // 全部灭
    GPIO_SetBits(RED_GPIO_PORT, RED_GPIO_PIN | GREEN_GPIO_PIN | BLUE_GPIO_PIN);
}

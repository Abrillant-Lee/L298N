#include "stm32f10x.h"
#include "l298n.h"
#include "key.h"

int main(void)
{
    Motor_12_Config(); // 298电机驱动初始化
    Key_GPIO_Config(); // 按键初始化
    Led_GPIO_Config(); // LED初始化

    // 电机1停止，红灯亮
    GPIO_ResetBits(RED_GPIO_PORT, RED_GPIO_PIN);

    while (1) {
        // 按下KEY1，电机1正转，绿灯亮
        if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON) {
            Motor_2_PRun();
            GPIO_SetBits(RED_GPIO_PORT, RED_GPIO_PIN | GREEN_GPIO_PIN | BLUE_GPIO_PIN);
            GPIO_ResetBits(GREEN_GPIO_PORT, GREEN_GPIO_PIN);
        }
        // 按下KEY2，电机1转，蓝灯亮
        if (Key_Scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN) == KEY_ON) {
            Motor_2_NRun();
            GPIO_SetBits(RED_GPIO_PORT, RED_GPIO_PIN | GREEN_GPIO_PIN | BLUE_GPIO_PIN);
            GPIO_ResetBits(BLUE_GPIO_PORT, BLUE_GPIO_PIN);
        }
    }
}

/*---------------------------------------
- WeAct Studio Official Link
- taobao: weactstudio.taobao.com
- aliexpress: weactstudio.aliexpress.com
- github: github.com/WeActStudio
- gitee: gitee.com/WeAct-TC
- blog: www.weact-tc.cn
---------------------------------------*/

#include "debug.h"
#include "board.h"

#include "flash_test.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    Delay_Init();
    USART_Printf_Init(115200);

    board_button_init();
    board_led_init();

    printf("\r\nWeAct Studio Core Board\r\n");
    printf("weactstudio.taobao.com\r\n");
    printf("weactstudio.aliexpress.com\r\n");
    printf("wwww.weact-tc.cn\r\n\r\n");
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf("Flash TEST\r\n");

    Flash_Test();
    Flash_Test_Fast();

    uint32_t tick, toggle_tick;
    tick = 0;
    toggle_tick = 250;
    while (1)
    {
        tick++;
        if (tick % toggle_tick == 0)
        {
            board_led_toggle();
        }
        if (board_button_getstate())
        {
            while (board_button_getstate())
            {
                Delay_Ms(50);
            }
            if (toggle_tick == 250)
            {
                toggle_tick = 100;
            }
            else
            {
                toggle_tick = 250;
            }
        }
        Delay_Ms(1);
    }
}

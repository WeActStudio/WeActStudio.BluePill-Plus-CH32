/*---------------------------------------
- WeAct Studio Official Link
- taobao: weactstudio.taobao.com
- aliexpress: weactstudio.aliexpress.com
- github: github.com/WeActTC
- gitee: gitee.com/WeAct-TC
- blog: www.weact-tc.cn
---------------------------------------*/

#include "debug.h"
#include "board.h"
#include "rtc.h"

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
    printf("RTC Test\r\n");

    RTC_Init();

    uint32_t tick;
    tick = 0;
    while (1)
    {
        tick++;

        if (tick % 1000 == 0)
        {
            printf("year/month/day/week/hour/min/sec:\r\n");
            printf("%d-%d-%d  %d  %d:%d:%d\r\n", calendar.w_year, calendar.w_month, calendar.w_date,
                   calendar.week, calendar.hour, calendar.min, calendar.sec);
        }
        Delay_Ms(1);
    }
}

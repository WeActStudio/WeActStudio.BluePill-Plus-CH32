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

void usb_dc_low_level_init(void)
{
    RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_1Div5);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USB | RCC_APB2Periph_GPIOA, ENABLE);

    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    (EXTEN->EXTEN_CTR) |= EXTEN_USBD_PU_EN;

    GPIOA->CFGHR &= 0XFFF00FFF;
    GPIOA->OUTDR &= ~(3 << 11); // PA11/12=0
    GPIOA->CFGHR |= 0X00088000; // IPD
}

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
    printf("usb_cdc_acm\r\n");

    extern void cdc_acm_init(void);
    cdc_acm_init();

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

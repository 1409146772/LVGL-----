/**
 ****************************************************************************************************
 * @file        main.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-25
 * @brief       LVGL无系统移植 实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F103开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./USMART/usmart.h"
#include "./BSP/LED/led.h"
#include "./BSP/LCD/lcd.h"
#include "./BSP/KEY/key.h"
#include "./BSP/TOUCH/touch.h"

#include "./BSP/TIMER/btim.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lv_demo_stress.h"



int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
    usart_init(115200);                 /* 串口初始化为115200 */
    led_init();                         /* 初始化LED */
	key_init();                         /* 初始化按键 */
	
	//由下面LVGL函数直接初始化
	//lcd_init();                         /* 初始化LCD */
    //tp_dev.init();                      /* 触摸屏初始化 */
	
	btim_timx_int_init(72-1, 1000-1);//1ms
	lv_init(); 
	lv_port_disp_init(); /* 初始化LCD */
	lv_port_indev_init();/* 触摸屏初始化 */

//	lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
//	lv_obj_set_size(switch_obj, 120, 60);
//	lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);
	lv_demo_stress();
    while(1)
	{
		HAL_Delay(5);
		lv_timer_handler();
		
	}
}

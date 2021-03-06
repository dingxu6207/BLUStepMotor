/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   串口中断接收测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_SysTick.h"

#include <stdbool.h>
#include <stdlib.h>

#include "WifiUsart.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
extern bool bFlagRun;
extern bool bRunMotor;

int main(void)
{	
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
	
	SysTick_Init();
	
	 WifiUSART_Config();

  while(1)
	{	
		 if (bFlagRun == true)
		 {
		    if (CmdUART_RxBuffer[0] == ':')
					if (CmdUART_RxBuffer[1] == 'F')
					{
						printf("it is ok!\n");
					}
			 
			  bFlagRun = false;
				CmdUsart_FlushRxBuffer();
		 }
		 
		 
		 if (bRunMotor == true)	
     {        
				if (WIFIUART_RxBuffer[0] == ':')
				if (WIFIUART_RxBuffer[1] == 'F')
				{
						printf("it is uart3!\n");
					  WifiUsart_SendString(USART3,"it is USART3");
				}
				
					Wifiuart_FlushRxBuffer();
					bRunMotor =false;
	   }	
  }
}
/*********************************************END OF FILE**********************/

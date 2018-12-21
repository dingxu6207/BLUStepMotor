/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   �����жϽ��ղ���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
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
  * @brief  ������
  * @param  ��
  * @retval ��
  */
extern bool bFlagRun;
extern bool bRunMotor;

int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
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

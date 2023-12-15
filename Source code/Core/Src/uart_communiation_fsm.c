/*
 * uart_communiation_fsm.c
 *
 *  Created on: Dec 14, 2023
 *      Author: Hiepm
 */

#include "uart_communiation_fsm.h"
void uart_communication_fsm(ADC_HandleTypeDef* hadc1, UART_HandleTypeDef* huart2) {
	char str[50];
	switch(cmd_flag){
		case INIT:
			break;
		case RESEND:
			if(timer_flag == 1){
				ADC_value = HAL_ADC_GetValue(hadc1);
				HAL_UART_Transmit(huart2, (void *)str, sprintf(str, "!ADC=%d#\r\n",ADC_value), 500);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				setTimer(3000);
			}
		    break;
		case END:
			ADC_value = -1;
			cmd_flag = INIT;
			break;
		default:
			break;
	}
}


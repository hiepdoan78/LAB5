/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Hiepm
 */

#include <command_parser_fsm.h>


int isRSTCmd(uint8_t str[]){
	if (str[0] == 'R' && str[1] == 'S' && str[2] == 'T') {
		return 1;
	}
	return 0;
}

int isOKCmd(uint8_t str[]){
	if (str[0] == 'O' && str[1] == 'K')
		return 1;
	return 0;
}

void command_parser_fsm(ADC_HandleTypeDef* hadc1, UART_HandleTypeDef* huart2) {
	char str[50];
	switch(status) {
		case INIT:
			if(tmp == '!')
				status = READING;
			break;
		case READING:
			if(tmp != '!' && tmp != '#') {
				cmd_data[cmd_data_index] = tmp;
				cmd_data_index++;

				if(cmd_data_index > 3) {
					status = RESPONSE;
					cmd_data_index = 0;
				}
			}
			// check if end with '#' or start with more '!'
			if (tmp == '#' || tmp == '!') {
				status = RESPONSE;
				cmd_data_index = 0;
			}
			break;
		case RESPONSE:
			if (isRSTCmd(cmd_data) == 1){
				cmd_flag = RESEND;
				ADC_value = HAL_ADC_GetValue(hadc1);
				HAL_UART_Transmit(huart2, (void *)str, sprintf(str, "!ADC=%d#\r\n",ADC_value), 500);
				setTimer(3000);
			}else if (isOKCmd(cmd_data)==1){
				cmd_flag = END;
			}
			status = INIT;
			break;
		default:
			break;
	}
}


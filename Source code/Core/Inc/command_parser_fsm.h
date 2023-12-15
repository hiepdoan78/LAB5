/*
 * command_parser_fsm.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Hiepm
 */

#ifndef INC_COMMAND_PARSER_FSM_H_
#define INC_COMMAND_PARSER_FSM_H_



#endif /* INC_COMMAND_PARSER_FSM_H_ */

#include "global.h"

#include "software_timer.h"

void command_parser_fsm(ADC_HandleTypeDef* hadc1, UART_HandleTypeDef* huart2);
int isRSTCmd(uint8_t str[]);
int isOKCmd(uint8_t str[]);

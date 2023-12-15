/*
 * global.h
 *
 *  Created on: Dec 14, 2023
 *      Author: Hiepm
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_



#endif /* INC_GLOBAL_H_ */
#include "main.h"
#include "software_timer.h"
#include <stdio.h>

#define INIT 0
#define READING 1
#define RESPONSE 2
#define RESEND 4
#define END 5
#define MAX_BUFFER_SIZE 30
#define MAX_CMD_SIZE 5

extern uint32_t ADC_value;
extern int status;
extern char str[50];

extern uint8_t buffer [MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t tmp;

extern uint8_t cmd_flag;
extern uint8_t cmd_data[MAX_CMD_SIZE];
extern uint8_t cmd_data_index;

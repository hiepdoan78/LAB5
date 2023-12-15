/*
 * global.c
 *
 *  Created on: Dec 14, 2023
 *      Author: Hiepm
 */
#include "global.h"

uint32_t ADC_value = 0;
int fsm_flag = 0;
int status = INIT;
char str[50];


uint8_t buffer [MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t tmp = 0;

uint8_t cmd_flag = INIT;
uint8_t cmd_data[MAX_CMD_SIZE];
uint8_t cmd_data_index = 0;

/*
 * software_timer.c
 *
 *  Created on: Dec 14, 2023
 *      Author: Hiepm
 */

#include "software_timer.h"
int timer_counter = 0;
int timer_flag = 0;

void setTimer(int duration){
	timer_counter = duration/TICK;
	timer_flag = 0;
}
void timerRun(){
	if(timer_counter > 0){
		timer_counter--;
		if(timer_counter <= 0){
			timer_flag = 1;
		}
	}
}


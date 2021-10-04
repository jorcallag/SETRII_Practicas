/*
 * button_driver.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Jorlu
 */

#include "stm32l4xx_hal.h"
#include "button_driver.h"

extern uint8_t button;

uint8_t ReadButton(void){
	uint8_t b = HAL_GPIO_ReadPin(puerto, pin), res;

	if(b!=0){
		if(button == 2){
			button = 0;
		}
		button++;
		res = button;
	}else{
		res = 0;
	}

	return res;
}

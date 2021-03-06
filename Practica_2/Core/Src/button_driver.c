/*
 * button_driver.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Jorlu
 */
#include "main.h"
#include "stm32l4xx_hal.h"
#include "button_driver.h"

uint8_t button = 0;

uint8_t ReadButton(void){
	uint8_t b = HAL_GPIO_ReadPin(BOTON_GPIO_Port, BOTON_Pin), res;

	if(b==0){
		if(button == 3){
			button = 0;
		}
		button++;
		res = button;
	}else{
		res = 0;
	}

	return res;
}

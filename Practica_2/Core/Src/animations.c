/*
 * animations.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Jorlu
 */

#include "animations.h"

void animation1(void){
	for(int i=0; i<3; i++){
		LED_OFF(i);
		HAL_Delay(200);
		LED_ON(i);
		HAL_Delay(200);
		LED_OFF(i);
		HAL_Delay(200);
		LED_TOGGLE(i);
		HAL_Delay(200);
		LED_OFF(i);
		HAL_Delay(200);
	}
}

void animation2(void){
	LED_OFF(0);
	for(int i=0; i<3; i++){
		LED_TOGGLE(i);
		HAL_Delay(200);
	}
	LED_OFF(0);
}

void animation3(void){
	LED_OFF(0);
	for(int i=1; i<3; i++){
		LED_TOGGLE(i);
		HAL_Delay(200);
	}
	LED_ON(0);
	LED_OFF(0);
	HAL_Delay(200);
	LED_ON(0);
	LED_OFF(0);
}

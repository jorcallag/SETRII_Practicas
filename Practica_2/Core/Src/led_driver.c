/*
 * led_driver.c
 *
 *  Created on: Sep 27, 2021
 *      Author: Jorlu
 */
#include "main.h"
#include "stm32l4xx_hal.h"
#include "led_driver.h"

void LED_ON(uint8_t led) {
	switch (led){
	case 0:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
		break;
	}
}

void LED_OFF(uint8_t led) {
	switch (led){
	case 0:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		break;
	}
}

void LED_TOGGLE(uint8_t led) {
	switch (led){
		case 0:
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
			break;
		case 1:
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			break;
		case 2:
			HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
			break;
		}
}


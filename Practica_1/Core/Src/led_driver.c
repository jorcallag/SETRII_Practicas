/*
 * led_driver.c
 *
 *  Created on: Sep 27, 2021
 *      Author: Jorlu
 */
#include "stm32l4xx_hal.h"
#include "led_driver.h"

void LED_ON(uint8_t led) {
	switch (led){
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_Pin_14, SET);
		HAL_GPIO_WritePin(GPIOB, LED3, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED2, SET);
		HAL_GPIO_WritePin(GPIOB, LED3, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED2, RESET);
		HAL_GPIO_WritePin(GPIOB, LED3, SET);
		break;
	}
}

void LED_OFF(uint8_t led) {
	switch (led){
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED2, RESET);
		HAL_GPIO_WritePin(GPIOB, LED3, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED2, RESET);
		HAL_GPIO_WritePin(GPIOB, LED3, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED2, SET);
		HAL_GPIO_WritePin(GPIOB, LED3, RESET);
		break;
	}
}

void LED_TOGGLE(uint8_t led) {
	switch (led){
		case 0:
			HAL_GPIO_TogglePin(GPIOB, LED2);
			HAL_GPIO_TogglePin(GPIOB, LED3);
			break;
		case 1:
			HAL_GPIO_TogglePin(GPIOB, LED2);
			break;
		case 2:
			HAL_GPIO_TogglePin(GPIOB, LED3);
			break;
		}
}


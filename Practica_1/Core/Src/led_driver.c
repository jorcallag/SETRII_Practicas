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
		HAL_GPIO_WritePin(GPIOB, PB14, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, SET);
		break;
	}
}

void LED_OFF(uint8_t led) {
	switch (led){
	case 0:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, RESET);
		break;
	}
}

void LED_TOGGLE(uint8_t led) {
	switch (led){
		case 0:
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
			break;
		case 1:
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
			break;
		case 2:
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
			break;
		case 3:
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
			break;
		}
}


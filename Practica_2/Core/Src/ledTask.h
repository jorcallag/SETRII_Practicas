/*
 * ledTask.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Jorlu
 */

#ifndef SRC_LEDTASK_H_
#define SRC_LEDTASK_H_

#include "main.h"
#include "stm32l4xx_hal.h"
#include "led_driver.h"
#include "button_driver.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

void CreateLedTaskEj1();
void ledTaskEj1(void *pArg);

void CreateLedTaskEj2();
void ledTaskEj2(void *pArg);

void CreateLedTaskEj3();
void ledTaskEj3(void *pArg);

void CreateLedTaskEj4();
void ledAnimationTaskEj4(void *pArg);

void CreateLedTaskEj6();
void joyTaskEj6(void *pArg);

void CreateLedTaskEj7();
void joyTaskEj7(void *pArg);
void ledTaskEj7(void *pArg);

void CreateLedTaskEj8();
void joyTaskEj8(void *pArg);
void ledTask1Ej8(void *pArg);
void ledTask2Ej8(void *pArg);

void CreateLedTaskEj9();
void joyTaskEj9(void *pArg);
void ledTask1Ej9(void *pArg);
void ledTask2Ej9(void *pArg);

#endif /* SRC_LEDTASK_H_ */

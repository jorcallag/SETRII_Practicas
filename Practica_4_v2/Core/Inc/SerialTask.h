/*
 * SerialTask.h
 *
 *  Created on: Nov 15, 2021
 *      Author: Jorlu
 */

#ifndef INC_SERIALTASK_H_
#define INC_SERIALTASK_H_

#include <stdio.h>

#include "stm32l4xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

void CreateSerialObjects();

void serialSendByte(char data);
void serialReceiveByte();

void CreateSerialTask();
void serialTaskTx(void *pArg);
void serialTaskRx(void *pArg);

#endif /* INC_SERIALTASK_H_ */

#ifdef __GNUC__

#define PUTCHAR_PROTOYPE int __io_putchar(int ch)
#define GETCHAR_PROTOYPE int __io_getchar(void)

#else

#define PUTCHAR_PROTOYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOYPE int fgetc(FILE *f)

#endif /* INC_SERIALTASK_H_ */

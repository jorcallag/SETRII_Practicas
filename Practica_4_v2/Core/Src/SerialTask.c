/*
 * SerialTask.c
 *
 *  Created on: Nov 15, 2021
 *      Author: Jorlu
 */

#include "SerialTask.h"

SemaphoreHandle_t xSemaphore;
QueueHandle_t xQueue;

uint8_t *cad, *buff;
char c;

extern UART_HandleTypeDef huart1;

//Callbacks de las transmisiones y recepciones del puerto serie

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	xSemaphoreGiveFromISR(xSemaphore, pdFALSE);
	portYIELD_FROM_ISR(pdFALSE);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	xQueueSendFromISR(xQueue, &c, NULL);
	HAL_UART_Receive_IT(&huart1, &c, pdFALSE);
	portYIELD_FROM_ISR(pdFALSE);
}

//Creación de tareas

void CreateSerialTask(){
	//xTaskCreate(serialTaskTx, "serialTxTask", 123, NULL, 1, NULL);
	xTaskCreate(serialTaskRx, "serialRxTask", 256, NULL, 2, NULL);
}

//Transmisión

void serialTaskTx(void* pArg){
	char c[] = "HOLA";
	while(1){
		for(int i=0; i<4; i++){
			serialSendByte(c[i]);
		}
	}

}

void serialSendByte(char data){
	xSemaphoreTake(xSemaphore, 1);
	HAL_UART_Transmit_IT(&huart1, &data, 1);
}

//Recepción

void serialTaskRx(void* pArg){
	HAL_UART_Receive_IT(&huart1, &c, pdFALSE);
	while(1){
		xQueueReceive(xQueue, &c, portMAX_DELAY);
		printf("Nuevo dato recibido: %c\r", c);
	}
}

//Inicialización de el semáforo y la cola

void CreateSerialObjects(){
	xSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(xSemaphore);
	xQueue = xQueueCreate(16, sizeof(char *));
}

//Definiciones de putchar y getchar

PUTCHAR_PROTOYPE
{
	while(HAL_OK != HAL_UART_Transmit(&huart1, (uint8_t *) &ch, 1, 30000));
	return ch;
}

GETCHAR_PROTOYPE
{
	uint8_t ch = 0;
	while(HAL_OK != HAL_UART_Receive(&huart1, (uint8_t *) &ch, 1, 30000));
	return ch;
}


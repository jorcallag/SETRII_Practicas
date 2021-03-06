/*
 * ledTask.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Jorlu
 */

#include "ledTask.h"

TaskHandle_t taskHandler;
TaskHandle_t taskHandlerVector[2];

xSemaphoreHandle miSem;

//Ejercicio 1

void CreateLedTaskEj1(){
	xTaskCreate(ledTaskEj1, "ledTask1", 128, 1, 1, NULL);
	xTaskCreate(ledTaskEj1, "ledTask2", 128, 2, 1, NULL);
}

void ledTaskEj1(void *pArg){
	int numLed = (int) pArg;
	while(1){
		LED_TOGGLE(numLed);
		vTaskDelay(100);
	}
}

//Ejercicio 2

void CreateLedTaskEj2(){
	xTaskCreate(ledTaskEj2, "ledTask1", 128, 1, 1, NULL);
	xTaskCreate(ledTaskEj2, "ledTask2", 128, 2, 1, NULL);
}

void ledTaskEj2(void *pArg){
	int numLed = (int) pArg;
	while(1){
		LED_TOGGLE(numLed);
		vTaskDelay(200 + 100 * (numLed-1));
	}
}

//Ejercicio 3

void CreateLedTaskEj3(){
	xTaskCreate(ledTaskEj3, "ledTask1", 128, 1, 1, NULL);
}

void ledTaskEj3(void *pArg){
	int numLed = (int) pArg;
	if(numLed == 1){
		for(int i = 0; i < 5; i++){
			LED_TOGGLE(numLed);
			vTaskDelay(200 + 100 * (numLed-1));
		}
		xTaskCreate(ledTaskEj3, "LedTask2", 128, numLed+1, 1, NULL);
		vTaskDelete(NULL);
	}else if (numLed ==2){
		while(1){
			LED_TOGGLE(numLed);
			vTaskDelay(200 + 100 * (numLed-1));
		}
	}
}

//Ejercicio 4

void CreateLedTaskEj4(){
	xTaskCreate(ledAnimationTaskEj4, "LedAnimationTask", 128, NULL, 1, NULL);
}

void ledAnimationTaskEj4(void *pArg){
	while(1){
		switch(ReadButton()){
		case 1: animation1();
		case 2: animation2();
		case 3: animation3();
		}
	}
}

//Ejercicio 5

//Ejercicio 6 (Ejercicio 1 Parte 2)

void CreateLedTaskEj6(){
	xTaskCreate(joyTaskEj6, "joyTask", 128, NULL, 1, NULL);
}

void joyTaskEj6(void *pArg){
	while(1){
		if(ReadButton()){
			animation1();
		}
		vTaskDelay(10);
	}
}

//Ejercicio 7 (Ejercicio 2 Parte 2)

void CreateLedTaskEj7(){
	xTaskCreate(joyTaskEj7, "joyTask", 128, NULL, 1, NULL);
	xTaskCreate(ledTaskEj7, "ledTask", 128, NULL, 1, &taskHandler);
}

void joyTaskEj7(void *pArg){
	while(1){
		if(ReadButton()){
			xTaskNotifyGive(taskHandler);
		}
		vTaskDelay(100);
	}
}

void ledTaskEj7(void *pArg){
	while(1){
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		animation1();
		vTaskDelay(100);
	}
}

//Ejercicio 8 (Ejercicio 3 Parte 2)

void CreateLedTaskEj8(){
	xTaskCreate(joyTaskEj8, "joyTask", 128, NULL, 1, NULL);
	xTaskCreate(ledTask1Ej8, "ledTask1", 128, NULL, 1, &taskHandlerVector[0]);
	xTaskCreate(ledTask2Ej8, "ledTask2", 128, NULL, 1, &taskHandlerVector[1]);
}

void joyTaskEj8(void *pArg){
	while(1){
		int button = ReadButton();
		if(button != 0){
			xTaskNotifyGive(taskHandlerVector[button-1]);
		}
		vTaskDelay(100);
	}
}

void ledTask1Ej8(void *pArg){
	while(1){
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		animation1();
		vTaskDelay(100);
	}
}

void ledTask2Ej8(void *pArg){
	while(1){
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		animation2();
		vTaskDelay(100);
	}
}

//Ejercicio 9 (Ejercicio 4 Parte 2)

void CreateLedTaskEj9(){
	miSem=xSemaphoreCreateBinary();
	xSemaphoreGive(miSem);
	xTaskCreate(joyTaskEj9, "joyTask", 128, NULL, 1, NULL);
	xTaskCreate(ledTask1Ej9, "ledTask1", 128, NULL, 1, &taskHandlerVector[0]);
	xTaskCreate(ledTask2Ej9, "ledTask2", 128, NULL, 1, &taskHandlerVector[1]);
}

void joyTaskEj9(void *pArg){
	while(1){
		int button = ReadButton();
		if(button != 0){
			xTaskNotifyGive(taskHandlerVector[button-1]);
		}
		vTaskDelay(100);
	}
}

void ledTask1Ej9(void *pArg){
	while(1){
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		xSemaphoreTake(miSem, portMAX_DELAY);
		animation1();
		xSemaphoreGive(miSem);
	}
}

void ledTask2Ej9(void *pArg){
	while(1){
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		xSemaphoreTake(miSem, portMAX_DELAY);
		animation2();
		xSemaphoreGive(miSem);
	}
}

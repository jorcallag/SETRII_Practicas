/*
 * Practica_3.c
 *
 *  Created on: Oct 25, 2021
 *      Author: Jorlu
 */

#include "Practica_3.h"

void Pressure_Test(void){
	float press_value = 0.0;

	BSP_PSENSOR_Init();
	while(1){
		press_value = BSP_PSENSOR_ReadPressure();
		printf("PRESSURE is = %.2f mBar \n", press_value);
	}
}

void Humidity_Test(void){
	float humidity_value = 0.0;

	BSP_HSENSOR_Init();
	while(1){
		humidity_value = BSP_HSENSOR_ReadPressure();
		printf("HUMIDITY is = %.2f %%\n", humidity_value);
	}
}

void Tempereature_Test(void){
	float temp_value = 0.0;

	BSP_TSENSOR_Init();
	while(1){
		temp_value = BSP_TSENSOR_ReadPressure();
		printf("TEMPERATURE is = %.2f ºC\n", temp_value);
	}
}

void Accelero_Test(void){
	int16_t pDataXYZ[3] = {0};
	BSP_ACCELERO_Init();
	while(1){
		BSP_ACCELERO_AccGetXYZ(pDataXYZ);
		printf("ACCEL_X = %d, ACCEL_Y = %d, ACCEL_Z = %d \n\r", pDataXYZ[0], pDataXYZ[1], pDataXYZ[2]);
	}
	BSP_ACCELERO_DeInit();
	printf("\n*** End Accelerometer Test ***\n\n");
	return;
}

void Gyro_Test(void){
	float pGyroDataXYZ[3] = {0};
	BSP_GYRO_Init();
	while(1){
		BSP_GYRO_GetXYZ(pGyroDataXYZ);
		printf("GYRO_X = %.2f, GYRO_Y = %.2f, GYRO_Z = %.2f \n\r", pGyroDataXYZ[0], pGyroDataXYZ[1], pGyroDataXYZ[2]);
	}
	BSP_GYRO_DeInit();
	printf("\n*** End Gyro Test ***\n\n");
	return;
}

void Magneto_Test(void){
	int16_t pDataXYZ[3] = {0};
	BSP_MAGNETO_Init();
	while(1){
		BSP_MAGNETO_GetXYZ(pDataXYZ);
		printf("MAGNETO_X = %d, MAGNETO_Y = %d, MAGNETO_Z = %d \n\r", pDataXYZ[0], pDataXYZ[1], pDataXYZ[2]);
	}
	BSP_MAGNETO_DeInit();
	printf("\n*** End Magneto Test ***\n\n");
	return;
}


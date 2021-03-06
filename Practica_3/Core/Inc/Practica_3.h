/*
 * Practica_3.h
 *
 *  Created on: Oct 25, 2021
 *      Author: Jorlu
 */

#ifndef INC_PRACTICA_3_H_
#define INC_PRACTICA_3_H_

#include "../../BSP/stm32l475e_iot01.h"
#include "../../BSP/stm32l475e_iot01_accelero.h"
#include "../../BSP/stm32l475e_iot01_magneto.h"
#include "../../BSP/stm32l475e_iot01_gyro.h"
#include "../../BSP/stm32l475e_iot01_tsensor.h"
#include "../../BSP/stm32l475e_iot01_psensor.h"
#include "../../BSP/stm32l475e_iot01_hsensor.h"
#include "../../BSP/stm32l475e_iot01_qspi.h"
#include <stdio.h>

void Temperature_test(void);
void Humidity_test(void);
void Pressure_test(void);
void Gyro_test(void);
void Magneto_test(void);
void Accelero_test(void);

#endif /* INC_PRACTICA_3_H_ */

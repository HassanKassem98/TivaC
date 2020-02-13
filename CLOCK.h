/*
 * CLOCK.h
 *
 *  Created on: Feb 13, 2020
 *      Author: hassan
 */

#ifndef CLOCK_H_
#define CLOCK_H_
#include <Hardware_Types.h>
#include "CLOCK_REG_MAP.h"

typedef enum CLOCK_ERROR
{ CLOCK_PASS = 1 , INCORRECT_CLOCK}
CLOCK_ERROR_T;

typedef enum CLOCK_MODULE
{ GPIO_A=1 , GPIO_B, GPIO_C , GPIO_D , GPIO_E , GPIO_F }
CLOCK_MODULE_T;
#endif /* CLOCK_H_ */

/*
 * App_GPIO.h
 *
 *  Created on: Feb 13, 2020
 *      Author: hassa
 */

#ifndef APP_GPIO_H_
#define APP_GPIO_H_

#include "GPIO.h"
#include "CLOCK.h"
#include "Types.h"

typedef struct GPIO
{
    uint32 base;
    uint8 pin;
    GPIO_PAD_CONFIG_T pad_config;
}GPTO_T;


#endif /* APP_GPIO_H_ */

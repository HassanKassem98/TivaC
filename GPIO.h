/*
 * GPIO.h
 *
 *  Created on: Feb 13, 2020
 *      Author: hassan
 */

#ifndef GPIO_H_
#define GPIO_H_

#define TRUE 1
#define FALSE 0

#include "GPIO_REG_MAP.h"
#include <Hardware_Types.h>

typedef enum GPIO_ERROR
{ PASS = 1 , INCORRECT_PORT , INCORRECT_PIN , INCORRECT_VALUE}
GPIO_ERROR_T;

typedef enum RESISTOR_TYPE {
    PULL_UP = 1 , PULL_DOWN , OPEN_DRAIN
}RESISTOR_TYPE_T;

typedef enum GPIO_CURRENT   {
    CURRENT_2_MA = 1 , CURRENT_4_MA , CURRENT_8_MA
}GPIO_CURRENT_T;

 typedef struct GPIO_PAD_CONFIG
 {   RESISTOR_TYPE_T RES_TYPE_SEL;
     GPIO_CURRENT_T  CURRENT_DRIVE_SEL;
     uint8 Alternative_Fun ;
  }GPIO_PAD_CONFIG_T;

  GPIO_ERROR_T SET_PORT_DIR ( uint32 BASE , uint8 VALUE);
  GPIO_ERROR_T WRITE_PORT( uint32 BASE , uint8 VALUE);
  GPIO_ERROR_T READ_PORT( uint32 BASE , uint8* VALUE );
  GPIO_ERROR_T CONFIG_PAD( uint32 BASE , GPIO_PAD_CONFIG_T *Object , uint8 pin);
  GPIO_ERROR_T PORT_UNLOCK( uint32 BASE , uint8 VALUE);
  GPIO_ERROR_T PORT_DIGITAL_EN( uint32 BASE , uint8 VALUE);

#endif /* GPIO_H_ */

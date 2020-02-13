/*
 * App_GPIO.c
 *
 *  Created on: Feb 13, 2020
 *      Author: hassan
 */
#include "App_GPIO.h"

GPIO_ERROR_T GPIO_Init(GPTO_T *Object , uint8 DirValue)
{

    GPIO_ERROR_T STATE = PASS;
    if (Object -> base ==  GPIO_BASE_A )
    {
        ENABLE_CLOCK(GPIO_A);
    }
    else if (Object -> base ==  GPIO_BASE_B )
    {
        ENABLE_CLOCK(GPIO_B);
    }
    else if (Object -> base ==  GPIO_BASE_C )
    {
        ENABLE_CLOCK(GPIO_C);
    }
    else if (Object -> base ==  GPIO_BASE_D )
    {
        ENABLE_CLOCK(GPIO_D);
    }
    else if (Object -> base ==  GPIO_BASE_E )
    {
        ENABLE_CLOCK(GPIO_E);
    }
    else if (Object -> base ==  GPIO_BASE_F )
    {
        ENABLE_CLOCK(GPIO_F);
    }
    STATE =  SET_PORT_DIR( Object -> base , DirValue);
    return STATE;
}

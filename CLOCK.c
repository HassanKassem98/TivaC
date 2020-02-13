/*
 * CLOCK.C
 *
 *  Created on: Feb 13, 2020
 *      Author: hassan
 */
#include "CLOCK.h"

CLOCK_ERROR_T ENABLE_CLOCK(CLOCK_MODULE_T MODULE)
{
    CLOCK_ERROR_T STATE = CLOCK_PASS;
    if (MODULE == GPIO_A )
    {
        WRITE_REG_BIT(RCGCGPIO,0,0);
    }
    else if (MODULE == GPIO_B )
    {
        WRITE_REG_BIT(RCGCGPIO,0,1);
    }
    else if (MODULE == GPIO_C )
    {

        WRITE_REG_BIT(RCGCGPIO,0,2);
     }
    else if (MODULE == GPIO_D )
    {
        WRITE_REG_BIT(RCGCGPIO,0,3);
    }
    else if (MODULE == GPIO_E )
    {

        WRITE_REG_BIT(RCGCGPIO,0,4);
     }
    else if (MODULE == GPIO_F )
    {

        WRITE_REG_BIT(RCGCGPIO,0,5);
    }
    else
    {
        STATE = INCORRECT_CLOCK;
    }
    return STATE;
}

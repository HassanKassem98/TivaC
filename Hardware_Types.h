/*
 * Types.h
 *
 *  Created on: Feb 13, 2020
 *      Author: hassan
 */

#ifndef HARDWARE_TYPES_H_
#define HARDWARE_TYPES_H_

#include "Types.h"
// Hardware Types
#define WRITE_REG_32BIT(address,value)      ((*(volatile uint32*)(address)) = value )
#define READ_REG_32BIT(address)             ((*(volatile uint8*)(address)))

static inline  WRITE_REG_BIT(uint32 Reg,uint8 pin,uint8 value)
{
    if (value == 0)
    {
        (*(volatile uint32*)Reg) &= ~(1 << pin);
    }
    else if (value == 1)
    {
        (*(volatile uint32*)Reg) |= (1 << pin);

    }
    else
    {
    }
}


#endif /* HARDWARE_TYPES_H_ */

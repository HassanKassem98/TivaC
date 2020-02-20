/*
 * GPIO.C
 *
 *  Created on: Feb 13, 2020
 *      Author: hassan
 */
#include <GPIO_REG_MAP.h>
#include <Hardware_Types.h>
#include "GPIO.h"

GPIO_ERROR_T SET_PORT_DIR ( uint32 BASE , uint8 VALUE)
{
    GPIO_ERROR_T  STATE = PASS;

    if ( (BASE == GPIO_BASE_A) || (BASE == GPIO_BASE_B) || (BASE == GPIO_BASE_C) ||
            (BASE == GPIO_BASE_D) ||(BASE == GPIO_BASE_E) ||(BASE == GPIO_BASE_F) )
    {
            WRITE_REG_32BIT( (BASE + GPIO_DIRECTION_OFFSET) , VALUE);
    }
    else
    {
        STATE = INCORRECT_PORT;
    }
    return STATE;
}

GPIO_ERROR_T WRITE_PORT( uint32 BASE , uint8 VALUE)
{
    GPIO_ERROR_T  STATE = PASS;

    if ( (BASE == GPIO_BASE_A) || (BASE == GPIO_BASE_B) || (BASE == GPIO_BASE_C) ||
            (BASE == GPIO_BASE_D) ||(BASE == GPIO_BASE_E) ||(BASE == GPIO_BASE_F) )
    {
            WRITE_REG_32BIT( (BASE + GPIO_DATA_OFFSET) , VALUE);
    }
    else
    {
        STATE = INCORRECT_PORT;
    }
    return STATE;
}

GPIO_ERROR_T READ_PORT( uint32 BASE , uint8* VALUE )
{
    GPIO_ERROR_T  STATE = PASS;

    if ( (BASE == GPIO_BASE_A) || (BASE == GPIO_BASE_B) || (BASE == GPIO_BASE_C) ||
            (BASE == GPIO_BASE_D) ||(BASE == GPIO_BASE_E) ||(BASE == GPIO_BASE_F) )
    {
            *VALUE = READ_REG_32BIT((BASE + GPIO_DATA_OFFSET));
    }
    else
    {
        STATE = INCORRECT_PORT;
    }
    return STATE;
}

GPIO_ERROR_T CONFIG_PAD( uint32 BASE , GPIO_PAD_CONFIG_T *Object)
{
    GPIO_ERROR_T  STATE = PASS;

    if ( (BASE == GPIO_BASE_A) || (BASE == GPIO_BASE_B) || (BASE == GPIO_BASE_C) ||
            (BASE == GPIO_BASE_D) ||(BASE == GPIO_BASE_E) ||(BASE == GPIO_BASE_F) )
    {
        if ( Object -> Alternative_Fun == TRUE)
        {
            WRITE_REG_32BIT( (BASE + GPIO_ALTERNATIVE_FUNCTION_SELECT_OFFSET), 0xFF);
        }
        else if ( Object -> Alternative_Fun == FALSE)
        {
            WRITE_REG_32BIT( (BASE + GPIO_ALTERNATIVE_FUNCTION_SELECT_OFFSET), 0x00);
        }
        else
        {
            STATE = INCORRECT_VALUE;
        }
        if (Object-> CURRENT_DRIVE_SEL == CURRENT_2_MA )
        {
            WRITE_REG_32BIT( (BASE + GPIO_2_MA_DRIVE_SELECT_OFFSET) , 0xFF );
        }
        else if (Object-> CURRENT_DRIVE_SEL == CURRENT_4_MA )
        {
            WRITE_REG_32BIT( (BASE + GPIO_4_MA_DRIVE_SELECT_OFFSET) , 0xFF );
        }
        else if (Object-> CURRENT_DRIVE_SEL == CURRENT_8_MA )
        {
            WRITE_REG_32BIT( (BASE + GPIO_8_MA_DRIVE_SELECT_OFFSET) , 0xFF );
        }
        else if (Object-> CURRENT_DRIVE_SEL == CURRENT_2_MA )
        {
            WRITE_REG_32BIT( (BASE + GPIO_2_MA_DRIVE_SELECT_OFFSET) , 0xFF );
        }
        else
        {
            STATE = INCORRECT_VALUE;
        }

        if (Object-> RES_TYPE_SEL == PULL_UP )
        {
            WRITE_REG_32BIT( (BASE + GPIO_PULL_UP_SELECT_OFFSET ) , 0xFF );
        }
        else if (Object->  RES_TYPE_SEL == PULL_DOWN )
        {
            WRITE_REG_32BIT( (BASE + GPIO_PULL_DOWN_SELECT_OFFSET) , 0xFF );
        }
        else if (Object->  RES_TYPE_SEL == OPEN_DRAIN )
        {
            WRITE_REG_32BIT( (BASE + GPIO_OPEN_DRAIN_SELECT_OFFSET) , 0xFF );
        }
        else
        {
            STATE = INCORRECT_VALUE;
        }
    }
    else
    {
        STATE = INCORRECT_PORT;
    }
    return STATE;
}
GPIO_ERROR_T PORT_DIGITAL_EN( uint32 BASE , uint8 VALUE)
{
    GPIO_ERROR_T  STATE = PASS;

    if ( (BASE == GPIO_BASE_A) || (BASE == GPIO_BASE_B) || (BASE == GPIO_BASE_C) ||
            (BASE == GPIO_BASE_D) ||(BASE == GPIO_BASE_E) ||(BASE == GPIO_BASE_F) )
    {
            WRITE_REG_32BIT( (BASE + GPIO_DIGITAL_ENABLE_OFFSET) , VALUE);
    }
    else
    {
        STATE = INCORRECT_PORT;
    }
    return STATE;
}
GPIO_ERROR_T PORT_UNLOCK( uint32 BASE , uint8 VALUE)
{
    GPIO_ERROR_T  STATE = PASS;

    if ( (BASE == GPIO_BASE_A) || (BASE == GPIO_BASE_B) || (BASE == GPIO_BASE_C) ||
            (BASE == GPIO_BASE_D) ||(BASE == GPIO_BASE_E) ||(BASE == GPIO_BASE_F) )
    {
            WRITE_REG_32BIT( (BASE + GPIO_LOCK_OFFSET) , 0x4C4F434B);
            WRITE_REG_32BIT( (BASE + GPIO_COMMIT_OFFSET) , VALUE);
    }
    else
    {
        STATE = INCORRECT_PORT;
    }
    return STATE;
}

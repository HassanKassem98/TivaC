#define REG volatile unsigned long int *

// Clock and GPIO Register Map
REG RCC = 0x400FE060;
REG RCGCGPIO =  0x400FE608;
REG GPIODIRF =  0x4005D400;
REG GPIOHBCTL = 0x400FE06C;
REG GPIOAFSEL_F = 0x4005D420;
REG GPIODR8R_F = 0x4005D508;
REG GPIODEN_F =  0x4005D51C;
REG GPIODATA_F1 = 0x4005D008;

// Timer Register Map

REG RCGCTIMER = 0x400FE604;
REG GPTMCTL = 0x4003000C;
REG GPTMCFG = 0x40030000;
REG GPTMTAMR = 0x40030004;
REG GPTMTAILR = 0x40030028;
REG GPTMRIS = 0x4003001C;
REG GPTMICR = 0x40030024;

int main(void)

{
    // Run-Mode Clock Configuration: Internal CLK

    *RCC |= (1 << 11);
    *RCC |= (1 << 22);
    *RCC |= (1 << 11);
    *RCC |= (1 << 4);
    *RCC &= ~(1 << 5);
    *RCC |= (1 << 13);


    // GPIO Configuration

    *GPIOHBCTL |= (1 << 5); // Enable PORT F AHB
    *RCGCGPIO |= (1 << 5); // Enable CLK
    *GPIODIRF |= (1 << 1); // Enable PORT F
    *GPIOAFSEL_F &= ~(1 << 1); // GPIO Mode
    *GPIODR8R_F |= (1 << 1);
    *GPIODEN_F |= (1 << 1);
    // Initialization and configuratiion of timer

    *RCGCTIMER |= (1 << 0); // Enable and provide a clock to 16/32-bit general-purpose timer module 0 in Run mode.
    *GPTMCTL &= ~(1 << 0); // Disable Timer A
    *GPTMCFG = 0x00000000;
    *GPTMTAMR |= (0x02 << 0); // Periodic Mode
    *GPTMTAMR |= (1 << 4); // Direction Count up
    *GPTMTAILR = 0x000F4240; // Loading start value in GPTM n Intervaal Load Register 1,000,000
    *GPTMCTL |= (1 << 0); // Enable Timer A
    while (1)
    {
        if (  (*GPTMRIS & 0x00000001) == 1 ) // Checking Timer A has not timed out or not
            {
                *GPTMICR |= (1 << 0); // Interrupt clear
                *GPIODATA_F1 ^= 0xFF;
            }
    }

    return 0;
}

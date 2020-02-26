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
    *GPIODB8R_F |= (1 << 1);
    *GPIODEN_F |= (1 << 1);
    *GPIODATA_F1 = 0xFF;


    return 0;
}

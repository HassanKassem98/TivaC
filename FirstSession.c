

/**
 * main.c
 */
 
 
#define REG volatile unsigned long int *
#define F_BASE 0x4005D000
#define FB(offest) F_BASE + offest


REG RCC = 0x400FE060;
REG GPIOHBCTL = 0x400FE06C;
REG RCGCGPIO = 0x400FE608;
REG GPIODIRF = F_BASE;

REG GPIOAFSEL_F = FB(0x420);
REG GPIODB8R_F = F_BASE + 0x508;
REG GPIODEN_F = FB(0x51C);
REG GPIODATA_F1 = FB(0x00);


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

#define REG volatile unsigned long int *
#define RED 1
#define BLUE 2
#define GREEN 3
#define Red_Offset 0x008
#define Blue_Offset 0x010
#define Green_Offset 0x020

int COLOR,offset;




// Clock and GPIO Register Map
REG RCC = 0x400FE060;
REG RCGCGPIO =  0x400FE608;
REG GPIODIRF =  0x4005D400;
REG GPIOHBCTL = 0x400FE06C;
REG GPIOAFSEL_F = 0x4005D420;
REG GPIODR8R_F = 0x4005D508;
REG GPIODEN_F =  0x4005D51C;
REG GPIODATA_F1 = 0x4005D000;

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


    COLOR=RED;
    offset=Red_Offset;
    *RCC |= (1 << 11);
    *RCC |= (1 << 22);
    *RCC |= (1 << 11);
    *RCC |= (1 << 4);
    *RCC &= ~(1 << 5);
    *RCC |= (1 << 13);
     // GPIO Configuration

    *GPIOHBCTL |= (1 << 5); // Enable PORT F AHB
    *RCGCGPIO |= (1 << 5); // Enable CLK
    // Initialization and configuratiion of timer


    while (1)
    {


            GPIODATA_F1 = 0x4005D000;
            GPIODATA_F1 = (0x4005D000|offset);
            *GPIODIRF=0x00;
            *GPIODIRF |= (1 << COLOR); // Enable PORT F
            *GPIOAFSEL_F &= ~(1 << COLOR); // GPIO Mode
            *GPIODR8R_F=0x00;
            *GPIODR8R_F|=(1 << COLOR);
            *GPIODEN_F=0x00;
            *GPIODEN_F |= (1 << COLOR);
            *RCGCTIMER |= (1 << 0); // Enable and provide a clock to 16/32-bit general-purpose timer module 0 in Run mode.
            *GPTMCTL &= ~(1 << 0); // Disable Timer A
            *GPTMCFG = 0x00000000;
            *GPTMTAMR |= (0x02 << 0); // Periodic Mode
            *GPTMTAMR |= (1 << 4); // Direction Count up
            *GPTMTAILR = 0x000F424F; // Loading start value in GPTM n Intervaal Load Register 1,000,000
            *GPTMCTL |= (1 << 0); // Enable Timer A

            while((*GPTMRIS & 0x00000001) != 1 );

       if (  (*GPTMRIS & 0x00000001) == 1 ) // Checking Timer A has not timed out or not
            {
                *GPTMICR |= (1 << 0); // Interrupt clear
                *GPIODATA_F1 ^= 0xFF;
            }
       while((*GPTMRIS & 0x00000001) != 1 );

                 if((*GPIODATA_F1&0xFF)!=0x00)
                  {if(COLOR==RED)
                  {COLOR=BLUE;
                   offset=Blue_Offset;}
                  else if(COLOR==BLUE)
                  {COLOR=GREEN;
                   offset=Green_Offset;}
                  else if(COLOR==GREEN)
                  {COLOR=RED;
                  offset=Red_Offset;
                  }
                  }



}
    return 0;
}

#include <reg51.h>

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 500; i++);
}

void main(void)
{
    while(1)
    {
        P1 = 0x00;  // LOW level
        delay();

        P1 = 0xFF;  // HIGH level
        delay();
    }
}

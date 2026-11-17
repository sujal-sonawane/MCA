/* Practical 2A: Hexadecimal display 00H to FFH using 8051 Port 2.
   Based on Experiment 1C, MCA lab manual.
*/
#include <reg51.h>

void delay(void)
{
    unsigned int i, j;
    for(i = 0; i < 500; i++)
    {
        for(j = 0; j < 1275; j++);
    }
}

void main(void)
{
    unsigned int hex;

    while(1)
    {
        for(hex = 0x00; hex <= 0xFF; hex++)
        {
            P2 = (unsigned char)hex;
            delay();
        }
    }
}

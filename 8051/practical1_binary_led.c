/* Practical 1A: Binary number display using 8051 Port 2.
   Based on Experiment 1, MCA lab manual (AT89C51 / AT89S52).
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
    unsigned int count;

    while(1)
    {
        /* Display binary values from 00H to FFH on eight LEDs. */
        for(count = 0x00; count <= 0xFF; count++)
        {
            P2 = (unsigned char)count;
            delay();
        }
    }
}

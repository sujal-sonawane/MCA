/* Practical 1B: Packed BCD counter 00 to 99 using 8051 Port 2.
   Based on Experiment 1B, MCA lab manual.
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
    unsigned char bcd = 0x00;

    while(1)
    {
        P2 = bcd;          /* Display current BCD value */
        delay();

        bcd++;

        /* When units digit reaches A, correct BCD and carry to tens. */
        if((bcd & 0x0F) == 0x0A)
        {
            bcd += 0x06;
        }

        /* After 99, restart from 00. */
        if(bcd == 0xA0)
        {
            bcd = 0x00;
        }
    }
}

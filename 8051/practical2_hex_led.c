/* Program C from MCA Microcontrollers Lab Manual, Experiment 1
   Display of Hexadecimal Numbers on Port 2.
   Source: MCA Upto Expt 8 PDF, printed page 4.
*/
#include <reg51.h>

void delay(void);

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
    unsigned char hex;
    while(1)
    {
        /* Display hexadecimal values from 00H to FEH */
        for(hex = 0x00; hex < 0xFF; hex++)
        {
            P2 = hex;
            delay();
        }
        /* Display the last hexadecimal value (FFH) */
        P2 = 0xFF;
        delay();
    }
}

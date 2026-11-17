/* Program D from MCA Microcontrollers Lab Manual, Experiment 1
   Port as 8 Bit Counter. Controller: AT89S52 / AT89C51. Port: P2.
   Source: MCA Upto Expt 8 PDF, printed page 4.
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
    unsigned char count;
    while(1)
    {
        /* Count from 00H to FFH */
        for(count = 0x00; count <= 0xFF; count++)
        {
            P2 = count;
            delay();
            if(count == 0xFF)
                break;
        }
    }
}

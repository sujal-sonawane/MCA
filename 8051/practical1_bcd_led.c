/* Program B from MCA Microcontrollers Lab Manual, Experiment 1
   Display BCD Numbers (00 to 99) on Port 2.
   Source: MCA Upto Expt 8 PDF, printed page 3.
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
    unsigned char bcd = 0x00;
    while(1)
    {
        P2 = bcd;
        delay();
        bcd++;
        if((bcd & 0x0F) == 0x0A)
        {
            bcd += 0x06;
        }
        if(bcd == 0xA0)
        {
            bcd = 0x00;
        }
    }
}

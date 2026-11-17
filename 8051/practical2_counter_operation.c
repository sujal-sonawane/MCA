/* Practical 2B: 8-bit counter operation on 8051 Port 2.
   Based on the Port-as-8-bit-counter program in Experiment 1D
   of the MCA lab manual.
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
        for(count = 0x00; count <= 0xFF; count++)
        {
            P2 = (unsigned char)count;
            delay();
        }
    }
}

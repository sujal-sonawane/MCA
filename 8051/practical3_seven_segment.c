/* Practical 3: Display 0-9 and A-E on a common-cathode 7-segment display.
   Assumed wiring: P2.0=a, P2.1=b, P2.2=c, P2.3=d,
                   P2.4=e, P2.5=f, P2.6=g, P2.7=dp.
   Verify the trainer-board segment wiring before applying these codes.
*/
#include <reg51.h>

void delay(void)
{
    volatile unsigned int i, j;
    for (i = 0; i < 200; i++)
        for (j = 0; j < 1275; j++);
}

void main(void)
{
    /* Common-cathode patterns for 0,1,...,9,A,b,C,d,E. */
    unsigned char code display[15] =
    {
        0x3F, 0x06, 0x5B, 0x4F, 0x66,
        0x6D, 0x7D, 0x07, 0x7F, 0x6F,
        0x77, 0x7C, 0x39, 0x5E, 0x79
    };
    unsigned char i;

    while (1)
    {
        for (i = 0; i < 15; i++)
        {
            P2 = display[i];
            delay();
        }
    }
}

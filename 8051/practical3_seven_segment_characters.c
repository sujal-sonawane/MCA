/* Practical 3: Common-cathode 7-segment characters A-E.
   This separate program is useful when demonstrating only the letters.
*/
#include <reg51.h>
void delay(void)
{
    unsigned int i, j;
    for(i = 0; i < 200; i++)
        for(j = 0; j < 1275; j++);
}
void main(void)
{
    unsigned char code character[5] =
    {
        0x77, /* A */
        0x7C, /* b */
        0x39, /* C */
        0x5E, /* d */
        0x79  /* E */
    };
    unsigned char i;
    while(1)
    {
        for(i = 0; i < 5; i++)
        {
            P2 = character[i];
            delay();
        }
    }
}

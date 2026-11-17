/* Practical 1B: Packed BCD counter 00 to 99 using 8051 Port 2
   Target: AT89C51 / 8051
*/
#include <reg51.h>

void delay(void)
{
    volatile unsigned int i, j;
    for (i = 0; i < 500; i++)
        for (j = 0; j < 1275; j++);
}

void main(void)
{
    unsigned char bcd = 0x00;

    while (1)
    {
        P2 = bcd;
        delay();

        bcd++;

        /* Correct the units nibble from A to 0 and carry into tens. */
        if ((bcd & 0x0F) == 0x0A)
            bcd = (unsigned char)(bcd + 0x06);

        /* After 99 (0x99), restart at 00. */
        if (bcd == 0xA0)
            bcd = 0x00;
    }
}

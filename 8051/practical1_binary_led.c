/* Practical 1A: Binary counter using 8051 Port 2
   Target: AT89C51 / 8051, 11.0592 MHz
   Connect eight LEDs to P2 through suitable current-limiting resistors.
*/
#include <reg51.h>

void delay(void)
{
    unsigned int i, j;
    for (i = 0; i < 500; i++)
        for (j = 0; j < 1275; j++);
}

void main(void)
{
    unsigned int count;

    while (1)
    {
        for (count = 0; count <= 255; count++)
        {
            P2 = (unsigned char)count;
            delay();
        }
    }
}

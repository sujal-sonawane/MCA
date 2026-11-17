/* Practical 2: Hexadecimal counter 00H to FFH using 8051 Port 2
   Target: AT89C51 / 8051
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
    unsigned int value;

    while (1)
    {
        for (value = 0; value <= 0xFF; value++)
        {
            P2 = (unsigned char)value;
            delay();
        }
    }
}

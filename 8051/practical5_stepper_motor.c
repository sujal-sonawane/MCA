/* Practical 5: Clockwise and anticlockwise stepper motor sequence.
   Target: AT89C51, 11.0592 MHz crystal.
   P2.0-P2.3 connect to a suitable motor-driver input (e.g. ULN2003).
   Never connect a motor winding directly to 8051 GPIO pins.
*/
#include <reg51.h>

unsigned char code step_sequence[4] = {0x01, 0x02, 0x04, 0x08};

void delay_approximately_50ms(void)
{
    TMOD = (TMOD & 0xF0) | 0x01; /* Timer 0, 16-bit mode 1 */
    TH0 = 0x4C;
    TL0 = 0x00;                 /* 0xB400 counts ~= 50 ms */
    TF0 = 0;
    TR0 = 1;
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}

void main(void)
{
    unsigned char i;

    while (1)
    {
        /* One direction */
        for (i = 0; i < 4; i++)
        {
            P2 = step_sequence[i];
            delay_approximately_50ms();
        }

        /* Reverse sequence: opposite direction */
        for (i = 4; i > 0; i--)
        {
            P2 = step_sequence[i - 1];
            delay_approximately_50ms();
        }
    }
}

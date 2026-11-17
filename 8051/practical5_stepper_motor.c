/* Practical 5: Clockwise and anticlockwise stepper motor rotation
   using Timer 0 delay. Based on Experiment 4 of the MCA manual.
   Connect P2.0-P2.3 to a ULN2003 or suitable driver.
   Do not connect motor windings directly to MCU GPIO pins.
   Actual direction depends on the motor phase wiring.
*/
#include <reg51.h>
unsigned char step[4] = {0x01, 0x02, 0x04, 0x08};
void delay_50ms(void)
{
    TMOD = (TMOD & 0xF0) | 0x01; /* Timer 0 Mode 1 */
    TH0 = 0x4C;
    TL0 = 0x00;                  /* 46080 counts ~= 50 ms */
    TF0 = 0;
    TR0 = 1;
    while(TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}
void main(void)
{
    unsigned char i;
    while(1)
    {
        /* Clockwise sequence */
        for(i = 0; i < 4; i++)
        {
            P2 = step[i];
            delay_50ms();
        }
        /* Reverse sequence for anticlockwise rotation */
        for(i = 4; i > 0; i--)
        {
            P2 = step[i - 1];
            delay_50ms();
        }
    }
}

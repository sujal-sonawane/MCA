/* Practical 4A: Square wave using DAC and 8051 Timer 0.
   Target assumptions: AT89C51, 11.0592 MHz crystal, 12-clock timer.
   P1.0-P1.7 connect to the DAC D0-D7 inputs.
   Two nominal 500 us half-periods give a nominal 1 kHz square wave.
   Timer/call overhead affects the actual frequency; verify and calibrate
   with an oscilloscope or frequency counter.
*/
#include <reg51.h>

void timer0_half_period(void)
{
    TMOD = (TMOD & 0xF0) | 0x01; /* Timer 0, 16-bit mode 1 */
    TH0 = 0xFE;
    TL0 = 0x33;                  /* 461 counts ~= 500 us */
    TF0 = 0;
    TR0 = 1;
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}

void main(void)
{
    while (1)
    {
        P1 = 0xFF;               /* DAC maximum code */
        timer0_half_period();

        P1 = 0x00;               /* DAC minimum code */
        timer0_half_period();
    }
}

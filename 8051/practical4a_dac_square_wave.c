/* Practical 4A: Square waveform using 8051 Timer 0 and 8-bit DAC.
   AT89C51 assumptions: 11.0592 MHz crystal, 12-clock timer.
   P1.0-P1.7 connect to DAC D0-D7.
   Timer interval is nominally 500 us per half-cycle -> nominal 1 kHz.
   Measure the output on CRO/oscilloscope and calibrate for software overhead.
*/
#include <reg51.h>
void timer0_delay_500us(void)
{
    TMOD = (TMOD & 0xF0) | 0x01; /* Timer 0, Mode 1 */
    TH0 = 0xFE;
    TL0 = 0x33;                  /* 461 counts ~= 500 us */
    TF0 = 0;
    TR0 = 1;
    while(TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}
void main(void)
{
    while(1)
    {
        P1 = 0x00; /* LOW level */
        timer0_delay_500us();
        P1 = 0xFF; /* HIGH level */
        timer0_delay_500us();
    }
}

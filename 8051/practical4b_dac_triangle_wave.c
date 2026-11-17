/* Practical 4B: Triangular waveform using DAC and 8051 Timer 0.
   Target assumptions: AT89C51, 11.0592 MHz crystal, 12-clock timer.
   P1.0-P1.7 connect to the DAC D0-D7 inputs.
   16 samples form one triangle cycle. The timer interval is a starting
   calibration value; execution overhead means the exact output frequency
   must be checked and trimmed on an oscilloscope.
*/
#include <reg51.h>

#define TIMER0_SAMPLE_RELOAD_H 0xFF
#define TIMER0_SAMPLE_RELOAD_L 0xC6 /* 58 counts ~= 62.9 us */

unsigned char code triangle_table[16] =
{
      0,  36,  73, 109, 146, 182, 219, 255,
    219, 182, 146, 109,  73,  36,   0,   0
};

void timer0_sample_delay(void)
{
    TMOD = (TMOD & 0xF0) | 0x01; /* Timer 0, 16-bit mode 1 */
    TH0 = TIMER0_SAMPLE_RELOAD_H;
    TL0 = TIMER0_SAMPLE_RELOAD_L;
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
        for (i = 0; i < 16; i++)
        {
            P1 = triangle_table[i];
            timer0_sample_delay();
        }
    }
}

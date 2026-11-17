/* Optional Practical 4C: Sine waveform using 8051 Timer 0 and 8-bit DAC.
   32 samples/cycle. The timer interval is a starting value; measure and
   calibrate the final frequency using a CRO/oscilloscope.
*/
#include <reg51.h>
unsigned char code sine_table[32] =
{
    128, 153, 177, 198, 218, 233, 245, 253,
    255, 253, 245, 233, 218, 198, 177, 153,
    128, 103, 79, 58, 38, 23, 11, 3,
      0, 3, 11, 23, 38, 58, 79, 103
};
void timer0_sample_delay(void)
{
    TMOD = (TMOD & 0xF0) | 0x01;
    TH0 = 0xFF;
    TL0 = 0xE3;
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
        for(i = 0; i < 32; i++)
        {
            P1 = sine_table[i];
            timer0_sample_delay();
        }
    }
}

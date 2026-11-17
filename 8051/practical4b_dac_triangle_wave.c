/* Practical 4B: Triangular waveform using 8051 Timer 0 and 8-bit DAC.
   AT89C51 assumptions: 11.0592 MHz crystal, 12-clock timer.
   P1.0-P1.7 connect to DAC D0-D7.
   32 samples/cycle; 29 timer counts are about 31.47 us/sample,
   giving approximately 1 kHz before instruction overhead. Measure and
   calibrate the final frequency using a CRO/oscilloscope.
*/
#include <reg51.h>
unsigned char code triangle_table[32] =
{
      0,  17,  34,  51,  68,  85, 102, 119,
    136, 153, 170, 187, 204, 221, 238, 255,
    238, 221, 204, 187, 170, 153, 136, 119,
    102,  85,  68,  51,  34,  17,   0,   0
};
void timer0_sample_delay(void)
{
    TMOD = (TMOD & 0xF0) | 0x01;
    TH0 = 0xFF;
    TL0 = 0xE3; /* 29 counts ~= 31.47 us */
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
            P1 = triangle_table[i];
            timer0_sample_delay();
        }
    }
}

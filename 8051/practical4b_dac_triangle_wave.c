/* Program B from MCA Microcontrollers Lab Manual, Experiment 3
   Generate Triangular Wave using DAC. Port used: P1.
   Source: MCA Upto Expt 8 PDF, printed pages 14-15.
   Manual program uses a software delay, not a Timer-based 1 kHz delay.
*/
#include <reg51.h>
void delay(void)
{
    unsigned int i;
    for(i = 0; i < 20; i++);
}
void main(void)
{
    unsigned int i;
    while(1)
    {
        for(i = 0; i <= 255; i++)
        {
            P1 = (unsigned char)i;
            delay();
        }
        for(i = 255; i > 0; i--)
        {
            P1 = (unsigned char)i;
            delay();
        }
    }
}

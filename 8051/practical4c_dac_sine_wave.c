/* Program C from MCA Microcontrollers Lab Manual, Experiment 3
   Generate Sine Wave using DAC. Port used: P1.
   Source: MCA Upto Expt 8 PDF, printed page 15.
   This program uses the software delay printed in the manual.
*/
#include <reg51.h>
unsigned char code sine_table[32] =
{
    128, 153, 177, 198, 218, 233, 245, 253,
    255, 253, 245, 233, 218, 198, 177, 153,
    128, 103, 79, 58, 38, 23, 11, 3,
      0,   3, 11, 23, 38, 58, 79, 103
};
void delay(void)
{
    unsigned int i;
    for(i = 0; i < 20; i++);
}
void main(void)
{
    unsigned char i;
    while(1)
    {
        for(i = 0; i < 32; i++)
        {
            P1 = sine_table[i];
            delay();
        }
    }
}

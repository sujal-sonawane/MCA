/* Program E from MCA Microcontrollers Lab Manual, Experiment 2
   Display numbers 0-9 on common-cathode 7-segment display.
   Source: MCA Upto Expt 8 PDF, printed pages 9-10.
   Manual correction: array length is 10 (the PDF prints digit[9]
   despite providing ten initializers and indexing through digit[9]).
*/
#include <reg51.h>
void delay(void)
{
    unsigned int i, j;
    for(i = 0; i < 200; i++)
    {
        for(j = 0; j < 1275; j++);
    }
}
void main(void)
{
    unsigned char digit[10] =
    {
        0x3F, 0x06, 0x5B, 0x4F, 0x66,
        0x6D, 0x7D, 0x07, 0x7F, 0x6F
    };
    unsigned char i;
    while(1)
    {
        for(i = 0; i < 10; i++)
        {
            P2 = digit[i];
            delay();
        }
    }
}

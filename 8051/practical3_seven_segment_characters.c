/* Program F from MCA Microcontrollers Lab Manual, Experiment 2
   Display characters A-F on common-cathode 7-segment display.
   Source: MCA Upto Expt 8 PDF, printed page 10.
   The manual includes F although the stated task asks for A-E.
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
    unsigned char code character[6] =
    {
        0x77, /* A */
        0x7C, /* b */
        0x39, /* C */
        0x5E, /* d */
        0x79, /* E */
        0x71  /* F */
    };
    unsigned char i;
    while(1)
    {
        for(i = 0; i < 6; i++)
        {
            P2 = character[i];
            delay();
        }
    }
}

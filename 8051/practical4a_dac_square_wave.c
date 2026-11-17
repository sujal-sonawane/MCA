/* Program A from MCA Microcontrollers Lab Manual, Experiment 3
   Generate Square Wave using DAC. Port used: P1.
   Source: MCA Upto Expt 8 PDF, printed page 14.
   Manual program uses a software delay, not a Timer-based 1 kHz delay.
*/
#include <reg51.h>
void delay(void)
{
    unsigned int i;
    for(i = 0; i < 500; i++);
}
void main(void)
{
    while(1)
    {
        P1 = 0x00; /* LOW level */
        delay();
        P1 = 0xFF; /* HIGH level */
        delay();
    }
}

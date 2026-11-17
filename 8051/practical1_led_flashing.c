/* Program A from MCA Microcontrollers Lab Manual, Experiment 1
   LED Flashing using 8051. Controller: AT89S52 / AT89C51. Port: P2.
   Source: MCA Upto Expt 8 PDF, printed page 3.
*/
#include <reg51.h>
void delay(void)
{
    unsigned int i, j;
    for(i = 0; i < 500; i++)
    {
        for(j = 0; j < 1275; j++);
    }
}
void main(void)
{
    while(1)
    {
        P2 = 0xFF;
        delay();
        P2 = 0x00;
        delay();
    }
}

/* Program A from MCA Microcontrollers Lab Manual, Experiment 4
   Stepper Motor Interfacing Using Timer 0 Delay.
   Source: MCA Upto Expt 8 PDF, printed pages 20-21.
   The printed program runs one sequence only; it does not implement
   the reverse (anticlockwise) sequence described in the algorithm.
*/
#include <reg51.h>
unsigned char step[4] =
{
    0x01, /* Step 1 */
    0x02, /* Step 2 */
    0x04, /* Step 3 */
    0x08  /* Step 4 */
};
void delay_50ms()
{
    TMOD = 0x01;
    TH0 = 0x4C;
    TL0 = 0x00;
    TF0 = 0;
    TR0 = 1;
    while(TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}
void main()
{
    unsigned char i;
    while(1)
    {
        for(i = 0; i < 4; i++)
        {
            P2 = step[i];
            delay_50ms();
        }
    }
}

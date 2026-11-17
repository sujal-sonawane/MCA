/* Practical 3: Display digits 0-9 and characters A-E on a
   common-cathode 7-segment display using 8051 Port 2.
   Segment map: P2.0=a, P2.1=b, P2.2=c, P2.3=d,
   P2.4=e, P2.5=f, P2.6=g, P2.7=dp.
   Segment hex codes follow the CC table in the MCA lab manual.
*/
#include <reg51.h>
void delay(void)
{
    unsigned int i, j;
    for(i = 0; i < 200; i++)
        for(j = 0; j < 1275; j++);
}
void main(void)
{
    unsigned char code display[15] =
    {
        0x3F, 0x06, 0x5B, 0x4F, 0x66,
        0x6D, 0x7D, 0x07, 0x7F, 0x6F,
        0x77, 0x7C, 0x39, 0x5E, 0x79
    };
    unsigned char i;
    while(1)
    {
        for(i = 0; i < 15; i++)
        {
            P2 = display[i];
            delay();
        }
    }
}

/* Program from MCA Microcontrollers Lab Manual, Experiment 5
   Flash P0.8 to P0.15. Controller: LPC2148, Triton IDE.
   Source: MCA Upto Expt 8 PDF, printed pages 27-28.
   The manual program blinks all eight LEDs together only.
*/
#define IO0SET     (*(volatile unsigned long *)0xE0028004)
#define IO0DIR     (*(volatile unsigned long *)0xE0028008)
#define IO0CLR     (*(volatile unsigned long *)0xE002800C)
#define PINSEL0    (*(volatile unsigned long *)0xE002C000)
void delay(void)
{
    unsigned long i;
    for(i = 0; i < 500000; i++)
    {
    }
}
int main(void)
{
    PINSEL0 = 0x00000000;
    IO0DIR = 0x0000FF00;
    while(1)
    {
        IO0SET = 0x0000FF00;
        delay();
        IO0CLR = 0x0000FF00;
        delay();
    }
}

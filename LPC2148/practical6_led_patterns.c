/* Practical 6: Different LED patterns on LPC2148 P0.8-P0.15.
   Pin mapping/registers are based on Experiment 5 of the MCA manual.
   This adds alternate and running LED patterns required by the exam title.
   Assumes active-HIGH LEDs; invert logic if the board uses active-LOW LEDs.
*/
#define IO0SET     (*(volatile unsigned long *)0xE0028004)
#define IO0DIR     (*(volatile unsigned long *)0xE0028008)
#define IO0CLR     (*(volatile unsigned long *)0xE002800C)
#define PINSEL0    (*(volatile unsigned long *)0xE002C000)
#define LED_MASK   0x0000FF00UL

void delay(void)
{
    volatile unsigned long i;
    for(i = 0; i < 500000UL; i++);
}

void show_pattern(unsigned char pattern)
{
    IO0CLR = LED_MASK;
    IO0SET = (((unsigned long)pattern << 8) & LED_MASK);
    delay();
}

int main(void)
{
    unsigned int i;

    /* P0.8-P0.15 use PINSEL0 bits 16-31; select GPIO. */
    PINSEL0 &= 0x0000FFFFUL;
    IO0DIR |= LED_MASK;

    while(1)
    {
        show_pattern(0xFF); /* All ON */
        show_pattern(0x00); /* All OFF */
        show_pattern(0x55); /* Alternate LEDs */
        show_pattern(0xAA); /* Alternate LEDs */

        /* Running LED from P0.8 to P0.15 */
        for(i = 0; i < 8; i++)
            show_pattern((unsigned char)(1U << i));

        /* Running LED from P0.15 to P0.8 */
        for(i = 8; i > 0; i--)
            show_pattern((unsigned char)(1U << (i - 1)));
    }
}

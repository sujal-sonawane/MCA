/* Practical 6: LED patterns on LPC2148 Port 0 pins P0.8-P0.15.
   This example assumes active-high LEDs. Invert the patterns if the
   trainer board uses active-low LED connections.
*/
#define IO0SET  (*(volatile unsigned long *)0xE0028004)
#define IO0DIR  (*(volatile unsigned long *)0xE0028008)
#define IO0CLR  (*(volatile unsigned long *)0xE002800C)
#define PINSEL0 (*(volatile unsigned long *)0xE002C000)

#define LED_MASK 0x0000FF00UL

void delay(void)
{
    volatile unsigned long i;
    for (i = 0; i < 500000UL; i++);
}

void show_leds(unsigned char pattern)
{
    IO0CLR = LED_MASK;
    IO0SET = (((unsigned long)pattern << 8) & LED_MASK);
    delay();
}

int main(void)
{
    unsigned int i;

    /* P0.8-P0.15 function-select bits -> GPIO. Preserve P0.0-P0.7. */
    PINSEL0 &= 0x0000FFFFUL;
    IO0DIR |= LED_MASK;

    while (1)
    {
        show_leds(0xFF); /* All ON */
        show_leds(0x00); /* All OFF */
        show_leds(0x55); /* Alternate pattern 01010101 */
        show_leds(0xAA); /* Alternate pattern 10101010 */

        /* Running LED from P0.8 to P0.15 */
        for (i = 0; i < 8; i++)
            show_leds((unsigned char)(1U << i));

        /* Running LED from P0.15 back to P0.8 */
        for (i = 8; i > 0; i--)
            show_leds((unsigned char)(1U << (i - 1)));
    }
}

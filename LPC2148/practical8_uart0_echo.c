/* Practical 8: UART0 receive and echo a character using LPC2148.
   Based on Experiment 7 of the MCA manual.
   Assumptions: 12 MHz crystal, CCLK=60 MHz, PCLK=60 MHz.
   UART format: 9600 baud, 8 data bits, no parity, 1 stop bit (8-N-1).
*/
#define PLL0CON (*(volatile unsigned int *)0xE01FC080)
#define PLL0CFG (*(volatile unsigned int *)0xE01FC084)
#define PLL0STAT (*(volatile unsigned int *)0xE01FC088)
#define PLL0FEED (*(volatile unsigned int *)0xE01FC08C)
#define VPBDIV   (*(volatile unsigned int *)0xE01FC100)
#define PINSEL0 (*(volatile unsigned int *)0xE002C000)
#define U0RBR    (*(volatile unsigned int *)0xE000C000)
#define U0THR    (*(volatile unsigned int *)0xE000C000)
#define U0DLL    (*(volatile unsigned int *)0xE000C000)
#define U0DLM    (*(volatile unsigned int *)0xE000C004)
#define U0LCR    (*(volatile unsigned int *)0xE000C00C)
#define U0LSR    (*(volatile unsigned int *)0xE000C014)

void PLL0_Init(void);

int main(void)
{
    unsigned char a;

    PLL0_Init();

    /* P0.0 = TXD0 and P0.1 = RXD0 */
    PINSEL0 = (PINSEL0 & ~0x0FU) | 0x05U;

    U0LCR = 0x83; /* Enable divisor latch, 8-bit data */
    U0DLM = 0x01;
    U0DLL = 0x87;
    U0LCR = 0x03; /* Disable DLAB: 8-N-1 */

    while(1)
    {
        while((U0LSR & 0x01U) == 0)
        {
        }
        a = (unsigned char)U0RBR;

        while((U0LSR & 0x20U) == 0)
        {
        }
        U0THR = a;
    }
}

void PLL0_Init(void)
{
    /* 12 MHz crystal to 60 MHz CCLK */
    PLL0CON = 0x01;
    PLL0CFG = 0x24;
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;

    while((PLL0STAT & (1U << 10)) == 0)
    {
    }

    PLL0CON = 0x03; /* Connect PLL0 */
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
    VPBDIV = 0x01;  /* PCLK = CCLK */
}

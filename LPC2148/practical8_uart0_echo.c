/* Practical 8: UART0 receive-and-echo program for LPC2148.
   Assumptions: 12 MHz crystal, PLL gives CCLK=60 MHz, VPB clock=60 MHz.
   UART: 9600 baud, 8 data bits, no parity, 1 stop bit (8-N-1).
   P0.0=TXD0, P0.1=RXD0. Use a 3.3V-compatible USB-TTL adapter.
*/
#define PLL0CON  (*(volatile unsigned int *)0xE01FC080)
#define PLL0CFG  (*(volatile unsigned int *)0xE01FC084)
#define PLL0STAT (*(volatile unsigned int *)0xE01FC088)
#define PLL0FEED (*(volatile unsigned int *)0xE01FC08C)
#define VPBDIV   (*(volatile unsigned int *)0xE01FC100)

#define PINSEL0  (*(volatile unsigned int *)0xE002C000)

#define U0RBR    (*(volatile unsigned int *)0xE000C000)
#define U0THR    (*(volatile unsigned int *)0xE000C000)
#define U0DLL    (*(volatile unsigned int *)0xE000C000)
#define U0DLM    (*(volatile unsigned int *)0xE000C004)
#define U0LCR    (*(volatile unsigned int *)0xE000C00C)
#define U0LSR    (*(volatile unsigned int *)0xE000C014)

void PLL0_Init(void);
void PLL0_Feed(void);

int main(void)
{
    unsigned char received;

    PLL0_Init();

    /* P0.0 = TXD0, P0.1 = RXD0. */
    PINSEL0 = (PINSEL0 & ~0x0FUL) | 0x05UL;

    /* Enable divisor latch and select 8-bit word length. */
    U0LCR = 0x83;

    /* Divisor 391 (0x0187): approximately 9600 baud at PCLK=60 MHz. */
    U0DLM = 0x01;
    U0DLL = 0x87;

    /* DLAB=0, 8 data bits, no parity, 1 stop bit. */
    U0LCR = 0x03;

    while (1)
    {
        while ((U0LSR & 0x01UL) == 0)
        {
        }
        received = (unsigned char)U0RBR;

        while ((U0LSR & 0x20UL) == 0)
        {
        }
        U0THR = received;
    }
}

void PLL0_Feed(void)
{
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
}

void PLL0_Init(void)
{
    /* M=5, P=2: 12 MHz crystal -> 60 MHz CCLK. */
    PLL0CFG = 0x24;
    PLL0_Feed();

    PLL0CON = 0x01; /* Enable PLL */
    PLL0_Feed();

    while ((PLL0STAT & (1UL << 10)) == 0)
    {
    }

    PLL0CON = 0x03; /* Enable and connect PLL */
    PLL0_Feed();

    VPBDIV = 0x01; /* PCLK = CCLK */
}

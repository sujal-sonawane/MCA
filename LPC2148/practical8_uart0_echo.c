/* Program from MCA Microcontrollers Lab Manual, Experiment 7
   UART0 Echo Communication on LPC2148.
   Source: MCA Upto Expt 8 PDF, printed pages 39-40.
   PLL0_Init prototype is declared before main to avoid an implicit
   function declaration; register setup and program sequence follow
   the manual.
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
    char a;
    PLL0_Init();
    PINSEL0 = (PINSEL0 & ~0x0FU) | 0x05U;
    U0LCR = 0x83;
    U0DLM = 0x01;
    U0DLL = 0x87;
    U0LCR = 0x03;

    while(1)
    {
        while((U0LSR & 0x01U) == 0)
        {
        }
        a = (char)U0RBR;
        while((U0LSR & 0x20U) == 0)
        {
        }
        U0THR = (unsigned char)a;
    }
}

/* PLL Initialization */
void PLL0_Init(void)
{
    /* Configure PLL0: 12 MHz crystal to 60 MHz CCLK */
    PLL0CON = 0x01;
    PLL0CFG = 0x24;
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
    while((PLL0STAT & (1U << 10)) == 0)
    {
    }
    PLL0CON = 0x03;
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
    VPBDIV = 0x01;
}

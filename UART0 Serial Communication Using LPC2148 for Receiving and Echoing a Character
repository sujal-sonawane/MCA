
/* UART0 Echo Communication
   Controller: LPC2148 ARM7
   IDE: Triton IDE 3.0
   Baud Rate: 9600
   Frame Format: 8-N-1
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

// Function declaration
void PLL0_Init(void);

int main(void)
{
    unsigned char a;

    PLL0_Init();

    // Configure P0.0 = TXD0 and P0.1 = RXD0
    PINSEL0 = (PINSEL0 & ~0x0FU) | 0x05U;

    // Enable divisor latch, 8-bit data
    U0LCR = 0x83;

    // Configure baud rate: 9600
    U0DLM = 0x01;
    U0DLL = 0x87;

    // Disable DLAB: 8 data bits, no parity, 1 stop bit
    U0LCR = 0x03;

    while(1)
    {
        // Wait until a character is received
        while((U0LSR & 0x01U) == 0)
        {
        }

        // Read received character
        a = (unsigned char)U0RBR;

        // Wait until transmitter is ready
        while((U0LSR & 0x20U) == 0)
        {
        }

        // Echo the received character
        U0THR = a;
    }
}

// PLL Initialization
void PLL0_Init(void)
{
    // Configure PLL0: 12 MHz crystal to 60 MHz CCLK
    PLL0CON = 0x01;
    PLL0CFG = 0x24;

    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;

    // Wait for PLL lock
    while((PLL0STAT & (1U << 10)) == 0)
    {
    }

    // Connect PLL0
    PLL0CON = 0x03;

    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;

    // Peripheral clock = CCLK
    VPBDIV = 0x01;
}

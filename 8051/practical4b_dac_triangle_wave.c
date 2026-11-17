
#include <reg51.h>

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 20; i++);
}

void main(void)
{
    unsigned int i;

    while(1)
    {
        // UP Counting: 0 to 255
        for(i = 0; i <= 255; i++)
        {
            P1 = (unsigned char)i;
            delay();
        }

        // DOWN Counting: 255 to 1
        for(i = 255; i > 0; i--)
        {
            P1 = (unsigned char)i;
            delay();
        }
    }
}

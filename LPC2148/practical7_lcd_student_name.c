/* Practical 7: Display student name on a 16x2 LCD using LPC2148.
   Data: P0.8-P0.15; RS=P0.4; EN=P0.5; RW=P0.6.
   Check LCD supply and 3.3V logic compatibility with the particular module.
*/
#include <LPC214x.h>

#define LCD_DATA 0x0000FF00UL
#define RS       (1UL << 4)
#define EN       (1UL << 5)
#define RW       (1UL << 6)

void delay(unsigned int count);
void LCD_Command(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_Init(void);
void LCD_String(const char *text);

int main(void)
{
    /* Select GPIO for P0.4-P0.6 and P0.8-P0.15. */
    PINSEL0 &= 0x0000C0FFUL;
    IO0DIR |= (LCD_DATA | RS | EN | RW);
    IO0CLR = (RS | EN | RW);

    delay(20);                  /* LCD power-up settling time */
    LCD_Init();
    LCD_String("SUJAL SONAWANE"); /* 14 characters; fits on a 16-char row */

    while (1)
    {
    }
}

void delay(unsigned int count)
{
    volatile unsigned int i, j;
    for (i = 0; i < count; i++)
        for (j = 0; j < 6000; j++);
}

void LCD_Command(unsigned char command)
{
    IO0CLR = LCD_DATA;
    IO0SET = ((unsigned long)command << 8);
    IO0CLR = (RS | RW);

    IO0SET = EN;
    delay(1);
    IO0CLR = EN;

    /* Clear/home commands need a longer execution time. */
    if (command == 0x01 || command == 0x02)
        delay(5);
    else
        delay(2);
}

void LCD_Data(unsigned char data)
{
    IO0CLR = LCD_DATA;
    IO0SET = ((unsigned long)data << 8);
    IO0SET = RS;
    IO0CLR = RW;

    IO0SET = EN;
    delay(1);
    IO0CLR = EN;
    delay(2);
}

void LCD_Init(void)
{
    LCD_Command(0x38); /* 8-bit interface, 2 lines, 5x7 font */
    LCD_Command(0x0C); /* Display ON, cursor OFF */
    LCD_Command(0x06); /* Increment cursor */
    LCD_Command(0x01); /* Clear display */
    LCD_Command(0x80); /* First row, first position */
}

void LCD_String(const char *text)
{
    while (*text != '\0')
    {
        LCD_Data((unsigned char)*text);
        text++;
    }
}

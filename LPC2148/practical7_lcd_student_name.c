/* Practical 7: 16x2 LCD interfacing with LPC2148 - display student name.
   Pin mapping follows Experiment 6 of the MCA manual:
   LCD D0-D7 = P0.8-P0.15, RS=P0.4, EN=P0.5, RW=P0.6.
   Display string: SUJAL SONAWANE (14 characters).
*/
#include <LPC214x.h>

#define LCD_DATA   0x0000FF00
#define RS         (1 << 4)
#define EN         (1 << 5)
#define RW         (1 << 6)

void delay(unsigned int count);
void LCD_Command(unsigned char cmd);
void LCD_Data(unsigned char data);
void LCD_Init(void);
void LCD_String(char *str);

int main(void)
{
    PINSEL0 &= 0x0000C0FF;
    IO0DIR |= 0x0000FF70;

    LCD_Init();
    LCD_String("SUJAL SONAWANE");

    while(1);
}

void delay(unsigned int count)
{
    unsigned int i, j;
    for(i = 0; i < count; i++)
    {
        for(j = 0; j < 6000; j++);
    }
}

void LCD_Command(unsigned char cmd)
{
    IO0CLR = LCD_DATA;
    IO0SET = ((unsigned int)cmd << 8);
    IO0CLR = RS;
    IO0CLR = RW;
    IO0SET = EN;
    delay(1);
    IO0CLR = EN;
    delay(2);
}

void LCD_Data(unsigned char data)
{
    IO0CLR = LCD_DATA;
    IO0SET = ((unsigned int)data << 8);
    IO0SET = RS;
    IO0CLR = RW;
    IO0SET = EN;
    delay(1);
    IO0CLR = EN;
    delay(2);
}

void LCD_Init(void)
{
    LCD_Command(0x38); /* 8-bit mode, 2 lines, 5x7 matrix */
    LCD_Command(0x0C); /* Display ON, cursor OFF */
    LCD_Command(0x06); /* Auto increment cursor */
    LCD_Command(0x01); /* Clear display */
    LCD_Command(0x80); /* First line, first position */
}

void LCD_String(char *str)
{
    while(*str)
    {
        LCD_Data(*str);
        str++;
    }
}

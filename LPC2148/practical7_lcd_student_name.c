/* Program from MCA Microcontrollers Lab Manual, Experiment 6
   16x2 LCD interface with LPC2148; display message "NMIET PUNE".
   Source: MCA Upto Expt 8 PDF, printed pages 33-35.
   Function prototypes are added before main; the code's logic and
   pin mapping follow the manual.
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
    LCD_String("NMIET PUNE");
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
    LCD_Command(0x38);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
    LCD_Command(0x80);
}
void LCD_String(char *str)
{
    while(*str)
    {
        LCD_Data(*str);
        str++;
    }
}

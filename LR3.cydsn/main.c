#include "project.h"
#include "stdio.h"
int ms_count, seconds, minutes, hours = 0;
int miliseconds=0;
char lcd_string[16];

void update_lcd()
{
    LCD_ClearDisplay();
    //sprintf(lcd_string, "%02u:%02u:%02u",minutes, seconds,ms_count/100);
    sprintf(lcd_string, "%02u:%02u:%02u",minutes, seconds,miliseconds);
    LCD_Position(0, 0);
    LCD_PrintString(lcd_string);
}

CY_ISR(ISR)
{
     ms_count++;
    if (ms_count >= 1000)
    {
        seconds++;
        ms_count = 0;
        if (seconds >= 60)
        {
            seconds = 0;
            minutes++;
            if (minutes >= 60)
            {
                minutes = 0;
            }
        }
    }
     miliseconds=ms_count/100;
     update_lcd();
   
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Start();
    Timer_Start();
    isr_StartEx(ISR);

    for (;;)
    {
        /* Place your application code here. */
    }
}


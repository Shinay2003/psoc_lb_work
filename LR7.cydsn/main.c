/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"
int ms_count, seconds, minutes=0;

char lcd_string[16];

void update_lcd()
{
    LCD_ClearDisplay();
    sprintf(lcd_string,"%02u:%02u",minutes,seconds);
    LCD_Position(0,0);
    LCD_PrintString(lcd_string);
}

CY_ISR(ISR)
{
    ms_count++;
    
    if(ms_count == 1000)
    {
        seconds++;
        ms_count=0;
        if(seconds >=60)
        {
            seconds =0;
            minutes++;
            if(minutes >=60)
            {
                minutes=0;
            }
        }
        update_lcd();
    }
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Start();
    Timer_Start();
    isr_StartEx(ISR);
    CyGlobalIntEnable;
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */


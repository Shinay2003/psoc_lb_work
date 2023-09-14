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

#define DELAY 6000

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Pin_Red_Write(1);
    Pin_Green_Write(1);
    Pin_Blue_Write(1);
    
    int delay = 6000;
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        if(Bnt_Read())
    {
        delay-=2000;
        if(delay==0)
        {
            int delay = 6000;
            
            Pin_Blue_Write(0);
            CyDelay(1000);
            
            Pin_Green_Write(0);
            CyDelay(3000);
            
            Pin_Red_Write(0);
            CyDelay(5000);
        }
    }
}

/* [] END OF FILE */

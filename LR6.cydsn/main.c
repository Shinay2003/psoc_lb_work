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

uint8_t i=0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_Start();
    LFClk_Start();
    
    for(;;)
    {
        /* Place your application code here. */
        for(i=0;i<255;i++)
        {
            PWM_WriteCompare(i);
            CyDelay(8);
        }
        for(i=255;i>0;i--)
        {
            PWM_WriteCompare(i);
            CyDelay(23);
        }
        CyDelay(20);
    }
}

/* [] END OF FILE */

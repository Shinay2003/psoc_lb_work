#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    for(;;)
    {
        /* Place your application code here. */
       
        UART_1_UartPutString("Volodimir Petrashek TR-34\r");
        CyDelay(1000);
    }
}

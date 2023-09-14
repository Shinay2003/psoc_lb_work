#include <project.h>

#define BUFFER_SIZE 256
#define TIMER_PERIOD_US 100

volatile uint8_t waveformBuffer[BUFFER_SIZE];
volatile uint16_t bufferIndex = 0;

CY_ISR_PROTO(timer_isr_handler);

CY_ISR(timer_isr_handler)
{
    IDAC_SetValue(waveformBuffer[bufferIndex]); // Встановлення значення IDAC з буферу
    bufferIndex++;
    
    if (bufferIndex >= BUFFER_SIZE)
        bufferIndex = 0;
    
}

int main(void)
{
    CyGlobalIntEnable; // Включення глобальних переривань
    
    Timer_Start(); // Запуск таймера
    Timer_WritePeriod(TIMER_PERIOD_US); // Встановлення періоду таймера в мікросекундах
    
    isr_StartEx(timer_isr_handler); // Реєстрація функції переривання (ISR)

    IDAC_Start(); // Запуск IDAC
    
    for(;;)
    {
         Pin_Write(1);
        CyDelayUs(1);
        Pin_Write(0);
        CyDelayUs(1);
    }
}





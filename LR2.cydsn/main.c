#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define LCD_NAME_ROW     (0u) // Рядок для виведення імені
#define LCD_SURNAME_ROW  (1u) // Рядок для виведення прізвища
#define LCD_SHIFT_DELAY  (500u) // Затримка між зміщеннями

void LCD_ShiftString(char* str, uint8_t shiftDirection);

char name[]    = "Volodimir"; // Ім'я студента
char surname[] = "Petrashek"; // Прізвище студента


int main(void)
{
    CyGlobalIntEnable; /* Включення глобальних переривань. */

    setlocale(LC_CTYPE, "ukr");
    
    LCD_Char_1_Start(); // Ініціалізація дисплею LCD

    for(;;)
{
    LCD_Char_1_Position(0,0);
    LCD_Char_1_PrintString(name);
    LCD_Char_1_Position(1,0);
    LCD_Char_1_PrintString(surname);
    LCD_ShiftString(name,1);
}
}

void LCD_ShiftString(char* str, uint8_t shiftDirection)
{
    uint8_t strLength = strlen(str);
    uint8_t shiftCount = 0;

    if (strLength > 16)
    {
        // Якщо рядок занадто довгий для виведення на одному рядку, виведіть його окремо без зміщення
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_PrintString(str);
    }
    else
    {
        // Виведення рядка з зміщенням
        while (shiftCount <= strLength)
        {
            LCD_Char_1_ClearDisplay();

            if (shiftDirection == 1)
            {
                LCD_Char_1_Position(LCD_NAME_ROW, 0);
                LCD_Char_1_PrintString(&str[shiftCount]);
            }
            else
            {
                LCD_Char_1_Position(LCD_NAME_ROW, strLength - shiftCount);
                LCD_Char_1_PrintString(str);
            }

            if (shiftDirection == 1)
            {
                shiftCount++;
                if (shiftCount > strLength)
                {
                    shiftCount = 0;
                }
            }
            else
            {
                if (shiftCount > 0)
                {
                    shiftCount--;
                }
                else
                {
                    shiftCount = strLength;
                }
            }
            
            LCD_Char_1_Position(1,0);
            LCD_Char_1_PrintString(surname);
            CyDelay(LCD_SHIFT_DELAY);
        }
    }
}
/*******************************************************************************
* File Name: LFClk.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_LFClk_H)
#define CY_CLOCK_LFClk_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void LFClk_StartEx(uint32 alignClkDiv);
#define LFClk_Start() \
    LFClk_StartEx(LFClk__PA_DIV_ID)

#else

void LFClk_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void LFClk_Stop(void);

void LFClk_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 LFClk_GetDividerRegister(void);
uint8  LFClk_GetFractionalDividerRegister(void);

#define LFClk_Enable()                         LFClk_Start()
#define LFClk_Disable()                        LFClk_Stop()
#define LFClk_SetDividerRegister(clkDivider, reset)  \
    LFClk_SetFractionalDividerRegister((clkDivider), 0u)
#define LFClk_SetDivider(clkDivider)           LFClk_SetDividerRegister((clkDivider), 1u)
#define LFClk_SetDividerValue(clkDivider)      LFClk_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define LFClk_DIV_ID     LFClk__DIV_ID

#define LFClk_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define LFClk_CTRL_REG   (*(reg32 *)LFClk__CTRL_REGISTER)
#define LFClk_DIV_REG    (*(reg32 *)LFClk__DIV_REGISTER)

#define LFClk_CMD_DIV_SHIFT          (0u)
#define LFClk_CMD_PA_DIV_SHIFT       (8u)
#define LFClk_CMD_DISABLE_SHIFT      (30u)
#define LFClk_CMD_ENABLE_SHIFT       (31u)

#define LFClk_CMD_DISABLE_MASK       ((uint32)((uint32)1u << LFClk_CMD_DISABLE_SHIFT))
#define LFClk_CMD_ENABLE_MASK        ((uint32)((uint32)1u << LFClk_CMD_ENABLE_SHIFT))

#define LFClk_DIV_FRAC_MASK  (0x000000F8u)
#define LFClk_DIV_FRAC_SHIFT (3u)
#define LFClk_DIV_INT_MASK   (0xFFFFFF00u)
#define LFClk_DIV_INT_SHIFT  (8u)

#else 

#define LFClk_DIV_REG        (*(reg32 *)LFClk__REGISTER)
#define LFClk_ENABLE_REG     LFClk_DIV_REG
#define LFClk_DIV_FRAC_MASK  LFClk__FRAC_MASK
#define LFClk_DIV_FRAC_SHIFT (16u)
#define LFClk_DIV_INT_MASK   LFClk__DIVIDER_MASK
#define LFClk_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_LFClk_H) */

/* [] END OF FILE */

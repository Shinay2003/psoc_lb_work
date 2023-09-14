/*******************************************************************************
* File Name: Btn.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Btn_ALIASES_H) /* Pins Btn_ALIASES_H */
#define CY_PINS_Btn_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Btn_0			(Btn__0__PC)
#define Btn_0_PS		(Btn__0__PS)
#define Btn_0_PC		(Btn__0__PC)
#define Btn_0_DR		(Btn__0__DR)
#define Btn_0_SHIFT	(Btn__0__SHIFT)
#define Btn_0_INTR	((uint16)((uint16)0x0003u << (Btn__0__SHIFT*2u)))

#define Btn_INTR_ALL	 ((uint16)(Btn_0_INTR))


#endif /* End Pins Btn_ALIASES_H */


/* [] END OF FILE */

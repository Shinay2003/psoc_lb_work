/*******************************************************************************
* File Name: Btn.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Btn_H) /* Pins Btn_H */
#define CY_PINS_Btn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Btn_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Btn_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Btn_Read(void);
void    Btn_Write(uint8 value);
uint8   Btn_ReadDataReg(void);
#if defined(Btn__PC) || (CY_PSOC4_4200L) 
    void    Btn_SetDriveMode(uint8 mode);
#endif
void    Btn_SetInterruptMode(uint16 position, uint16 mode);
uint8   Btn_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Btn_Sleep(void); 
void Btn_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Btn__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Btn_DRIVE_MODE_BITS        (3)
    #define Btn_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Btn_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Btn_SetDriveMode() function.
         *  @{
         */
        #define Btn_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Btn_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Btn_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Btn_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Btn_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Btn_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Btn_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Btn_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Btn_MASK               Btn__MASK
#define Btn_SHIFT              Btn__SHIFT
#define Btn_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Btn_SetInterruptMode() function.
     *  @{
     */
        #define Btn_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Btn_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Btn_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Btn_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Btn__SIO)
    #define Btn_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Btn__PC) && (CY_PSOC4_4200L)
    #define Btn_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Btn_USBIO_DISABLE              ((uint32)(~Btn_USBIO_ENABLE))
    #define Btn_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Btn_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Btn_USBIO_ENTER_SLEEP          ((uint32)((1u << Btn_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Btn_USBIO_SUSPEND_DEL_SHIFT)))
    #define Btn_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Btn_USBIO_SUSPEND_SHIFT)))
    #define Btn_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Btn_USBIO_SUSPEND_DEL_SHIFT)))
    #define Btn_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Btn__PC)
    /* Port Configuration */
    #define Btn_PC                 (* (reg32 *) Btn__PC)
#endif
/* Pin State */
#define Btn_PS                     (* (reg32 *) Btn__PS)
/* Data Register */
#define Btn_DR                     (* (reg32 *) Btn__DR)
/* Input Buffer Disable Override */
#define Btn_INP_DIS                (* (reg32 *) Btn__PC2)

/* Interrupt configuration Registers */
#define Btn_INTCFG                 (* (reg32 *) Btn__INTCFG)
#define Btn_INTSTAT                (* (reg32 *) Btn__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Btn_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Btn__SIO)
    #define Btn_SIO_REG            (* (reg32 *) Btn__SIO)
#endif /* (Btn__SIO_CFG) */

/* USBIO registers */
#if !defined(Btn__PC) && (CY_PSOC4_4200L)
    #define Btn_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Btn_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Btn_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Btn_DRIVE_MODE_SHIFT       (0x00u)
#define Btn_DRIVE_MODE_MASK        (0x07u << Btn_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Btn_H */


/* [] END OF FILE */

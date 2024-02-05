/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*The ENn Registers enable interrupts*/

#define NVIC_EN0_REG   *((volatile u32 *) 0xE000E100) //Interrupt 0-31   Set Enable (EN0), offset 0x100
#define NVIC_EN1_REG   *((volatile u32 *) 0xE000E104) //Interrupt 32-63  Set Enable (EN1), offset 0x104
#define NVIC_EN2_REG   *((volatile u32 *) 0xE000E108) //Interrupt 64-95  Set Enable (EN2), offset 0x108
#define NVIC_EN3_REG   *((volatile u32 *) 0xE000E10C) //Interrupt 96-127 Set Enable (EN3), offset 0x10C
#define NVIC_EN4_REG   *((volatile u32 *) 0xE000E110) //Interrupt 128-138 Set Enable(EN4), offset 0x110

/*****************************************************************************************************************/

/*The DISn Registers Disable interrupts*/

#define NVIC_DIS0_REG   *((volatile u32 *) 0xE000E180) //Interrupt 0-31   Set DISable (DIS0), offset 0x100
#define NVIC_DIS1_REG   *((volatile u32 *) 0xE000E184) //Interrupt 32-63  Set DISable (DIS1), offset 0x104
#define NVIC_DIS2_REG   *((volatile u32 *) 0xE000E188) //Interrupt 64-95  Set DISable (DIS2), offset 0x108
#define NVIC_DIS3_REG   *((volatile u32 *) 0xE000E18C) //Interrupt 96-127 Set DISable (DIS3), offset 0x10C
#define NVIC_DIS4_REG   *((volatile u32 *) 0xE000E190) //Interrupt 128-138 Set DISable (DIS4), offset 0x190

/*****************************************************************************************************************/
/*The PENDn registers force interrupts into the pending state*/

#define NVIC_PEND0_REG   *((volatile u32 *) 0xE000E200) //Interrupt 0-31   Set PENDIG (PEN0), offset 0x100
#define NVIC_PEND1_REG   *((volatile u32 *) 0xE000E204) //Interrupt 32-63  Set PENDIG (PEN1), offset 0x104
#define NVIC_PEND2_REG   *((volatile u32 *) 0xE000E208) //Interrupt 64-95  Set PENDIG (PEN2), offset 0x108
#define NVIC_PEND3_REG   *((volatile u32 *) 0xE000E20C) //Interrupt 96-127 Set PENDIG (PEN3), offset 0x10C
#define NVIC_PEND4_REG   *((volatile u32 *) 0xE000E210) //Interrupt 128-138 Set PENDIG (PEN4), offset 0x110

/*****************************************************************************************************************/

/*The UNPENDn registers show which interrupts are pending and remove the pending state from
interrupts*/

#define NVIC_UNPEND0_REG   *((volatile u32 *) 0xE000E280) //Interrupt 0-31   Set UNPEND (UNPEND0), offset 0x100
#define NVIC_UNPEND1_REG   *((volatile u32 *) 0xE000E284) //Interrupt 32-63  Set UNPEND (UNPEND1), offset 0x104
#define NVIC_UNPEND2_REG   *((volatile u32 *) 0xE000E288) //Interrupt 64-95  Set UNPEND (UNPEND2), offset 0x108
#define NVIC_UNPEND3_REG   *((volatile u32 *) 0xE000E28C) //Interrupt 96-127 Set UNPEND (UNPEND3), offset 0x10C
#define NVIC_UNPEND4_REG   *((volatile u32 *) 0xE000E290) //Interrupt 128-138 Set UNPEND (UNPEND4), offset 0x10C
/*****************************************************************************************************************/

/*The ACTIVEn registers indicate which interrupts are active*/

#define NVIC_ACTIVE0_REG   *((volatile u32 *) 0xE000E300) //Interrupt 0-31   Get ACTIVE (ACTIVE0), offset 0x100
#define NVIC_ACTIVE1_REG   *((volatile u32 *) 0xE000E304) //Interrupt 32-63  Get ACTIVE (ACTIVE1), offset 0x104
#define NVIC_ACTIVE2_REG   *((volatile u32 *) 0xE000E308) //Interrupt 64-95  Get ACTIVE (ACTIVE2), offset 0x108
#define NVIC_ACTIVE3_REG   *((volatile u32 *) 0xE000E30C) //Interrupt 96-127 Get ACTIVE (ACTIVE3), offset 0x10C
#define NVIC_ACTIVE4_REG   *((volatile u32 *) 0xE000E310) //Interrupt 128-138 Get ACTIVE (ACTIVE3), offset 0x10C

/*****************************************************************************************************************/

/*The PRIn registers (see also page 154) provide 3-bit priority fields for each interrupt. These registers
are byte accessible. Each register holds four priority fields that are assigned to interrupts as follows*/

#define NVIC_PRI_REG        ((volatile u32 *) 0xE000E400) //Pointer To Acsess Registers PRI0:PRI34 ,Acts As Array
	
/*****************************************************************************************************************/

/**/
#define NVIC_INT_0											  0
#define NVIC_INT_31											  31
#define NVIC_INT_32											  32
#define NVIC_INT_63											  63
#define NVIC_INT_64											  64
#define NVIC_INT_95											  95
#define NVIC_INT_96											  96
#define NVIC_INT_127								  	  127
#define NVIC_INT_128									    128
#define NVIC_INT_138											138

/*****************************************************************************************************************/

/*0x05FA*/
#define SCB_APINT_REG   	*((volatile u32 *) 0xE000ED0C) //The APINT register provides priority grouping control for the exception model
#define APINT_VECTKEY											0x05FA
#define APINT_VECTKEY_MASK								0x0000
#define APINT_VECTKEY_POSITION						16
#define APINT_PRIGROUP_MASK 							0xF8FF
#define APINT_PRIGROUP_POSITION 					8
	


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

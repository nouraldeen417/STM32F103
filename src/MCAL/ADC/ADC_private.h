
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _ADC_PRIVATE_H
#define	_ADC_PRIVATE_H


#include "../../lip/STD_TYPES.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/*
0x4001 2800 - 0x4001 2BFF ADC2
Section 11.12.15 on page 252
0x40012400 - 0x400127FF ADC1
*/
#define ADC1_SR           		   (*((volatile u32*)0x40012400))
#define ADC1_CR1           		   (*((volatile u32*)0x40012404))
#define ADC1_CR2          		   (*((volatile u32*)0x40012408))
#define ADC1_SMPR1           		 (*((volatile u32*)0x4001240C))
#define ADC1_SMPR2           		 (*((volatile u32*)0x40012410))
#define ADC1_JOFR1           		 (*((volatile u32*)0x40012414))
#define ADC1_JOFR2           		 (*((volatile u32*)0x40012418))
#define ADC1_JOFR3           		 (*((volatile u32*)0x4001241C))
#define ADC1_JOFR4           		 (*((volatile u32*)0x40012420))
#define ADC1_HTR           		   (*((volatile u32*)0x40012424))
#define ADC1_LTR           		   (*((volatile u32*)0x40012428))
#define ADC1_SQR1           		 (*((volatile u32*)0x4001242C))
#define ADC1_SQR2           		 (*((volatile u32*)0x40012430))
#define ADC1_SQR3           		 (*((volatile u32*)0x40012434))
#define ADC1_JSQR           		 (*((volatile u32*)0x40012438))
#define ADC1_JDR1           		 (*((volatile u32*)0x4001243C))
#define ADC1_JDR2           		 (*((volatile u32*)0x40012440))
#define ADC1_JDR3           		 (*((volatile u32*)0x40012444))
#define ADC1_JDR4           		 (*((volatile u32*)0x40012448))
#define ADC1_DR           	  	 (*((volatile u32*)0x4001244C))

#define ADC1_SQR           		  ((volatile u32*)0x4001242C)

#define ADC_SQR1_MAX_SIZE								6
#define ADC_SQR2_MAX_SIZE								12
#define ADC_SQR3_MAX_SIZE								14


















//STRT JSTRT JEOC EOC AWD
/*SR BITS*/
#define ADC_SR_AWD_BIT  							0
#define ADC_SR_EOC_BIT  							1
#define ADC_SR_JEOC_BIT  							2
#define ADC_SR_JSTART_BIT  						3
#define ADC_SR_START_BIT  						3
/*DISCE
N
DISC 
EN JAUTO AWD 
SGL SCAN JEOC 
IE AWDIE EOCIE*/
/*CR1 BITS*/
#define ADC_CR1_EOCIE_BIT  							  5
#define ADC_CR1_AWDIE_BIT  							  6
#define ADC_CR1_JEOCIE_BIT  							7
#define ADC_CR1_SCAN_BIT  							  8
#define ADC_CR1_AWDSGL_BIT  							9
#define ADC_CR1_JAUTO_BIT  							  10
#define ADC_CR1_DISCEN_BIT  							11
#define ADC_CR1_JDISCEN_BIT  							12
#define ADC_CR1_JAWDEN_BIT  							22
#define ADC_CR1_AWDEN_BIT  							  23



/*CR2 BITS*/
#define ADC_CR2_ADON_BIT  									0
#define ADC_CR2_CONT_BIT  									1
#define ADC_CR2_CAL_BIT  							      2
#define ADC_CR2_RSTCAL_BIT  							  3
#define ADC_CR2_ALIGN_BIT  									11
#define ADC_CR2_JEXTSEL_START_BIT  					12
#define ADC_CR2_JEXTTRIG_BIT  							15
#define ADC_CR2_EXTSEL_START_BIT  					17
#define ADC_CR2_EXTTRIG_BIT  							  20
#define ADC_CR2_JSWSTART_BIT  							21
#define ADC_CR2_SWSTART_BIT  							  22
#define ADC_CR2_TSVREFE_BIT  							  23




#define ADC_TIMEOUT           							0x2000000
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
 
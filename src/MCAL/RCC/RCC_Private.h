/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
//0x40021000 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RCC_CR              		 (*((volatile u32*)0x40021000))
#define RCC_CFGR	           		 (*((volatile u32*)0x40021004))
#define RCC_CIR              		 (*((volatile u32*)0x40021008))
#define RCC_APB2RSTR	           (*((volatile u32*)0x4002100C))
#define RCC_APB1RSTR         		 (*((volatile u32*)0x40021010))
#define RCC_AHBENR         		   (*((volatile u32*)0x40021014))
#define RCC_APB2ENR          		 (*((volatile u32*)0x40021018))
#define RCC_APB1ENR          		 (*((volatile u32*)0x4002101C))
#define RCC_BDCR            		 (*((volatile u32*)0x40021020))
#define RCC_CSR	           		   (*((volatile u32*)0x40021024))
#define RCC_AHBRSTR          		 (*((volatile u32*)0x40021028))
#define RCC_CFGR2          		   (*((volatile u32*)0x4002102C))



#define CSR_LSION_BIT									   	  0		// Second interrupt enable
#define CSR_LSIRDY_BIT									   	1		// Second interrupt enable
#define BDCR_LSEON_BIT  										0   //  RTC clock source selection
#define BDCR_LSERDY_BIT  										1   //  RTC clock source selection
#define BDCR_RTCSEL_0_BIT										8   //  RTC clock source selection
#define BDCR_RTCSEL_1_BIT      							9   // RTC clock source selection
#define BDCR_RTCEN_BIT      							  15  // RTC clock enable

/*Bits */
//RCC_APB1
#define RCC_TIM_2										0
#define RCC_TIM_3										1
#define RCC_TIM_4										2
#define RCC_TIM_5										3
#define RCC_TIM_6										4
#define RCC_TIM_7										5
#define RCC_WWDG  									11
#define RCC_SPI_2										14
#define RCC_SPI_3										15
#define RCC_USART_2									17
#define RCC_USART_3									18
#define RCC_USART_4								  19
#define RCC_USART_5								  20
#define RCC_I2C_1								    21
#define RCC_I2C_2								    22
#define RCC_CAN_1								    25
#define RCC_CAN_2								    26
#define RCC_BKP 								    27
#define RCC_PWR	    						    28
#define RCC_DAC			   					    29
#define RCC_APB1_MAX_BIT			   			  32

//RCC_APB2
#define RCC_AFIO										32
#define RCC_IOPA										34
#define RCC_IOPB										35
#define RCC_IOPC										36
#define RCC_IOPD										37
#define RCC_IOPE										38
#define RCC_ADC_1										41
#define RCC_ADC_2										42
#define RCC_TIM_1										43
#define RCC_SPI_1		  							44
#define RCC_USART_1									46
#define RCC_APB2_MAX_BIT			   			  64
//RCC_AHB
#define RCC_AHB_MAX_BIT			   			  96



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

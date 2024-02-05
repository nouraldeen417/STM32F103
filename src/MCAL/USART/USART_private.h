

/*
 * File:
 * Author:
 * Comments:
 * Revision history:
 */

#ifndef _USART_PRIVATE_H
#define _USART_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lip/Macros.h"
#include "../../lip/STD_TYPES.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//0x40013800 - 0x4001 3BFF
//0x40004400 - 0x4000 47FF
#define USART_1_BASE_ADD						0x40013800
#define USART_2_BASE_ADD						0x40004400


#define USART_SR(x)    *((volatile u32 *)(x+0x00))
#define USART_DR(x)    *((volatile u32 *)(x+0x04))
#define USART_BRR(x)    *((volatile u32 *)(x+0x08))
#define USART_CR1(x)    *((volatile u32 *)(x+0x0C))
#define USART_CR2(x)    *((volatile u32 *)(x+0x10))
#define USART_CR3(x)    *((volatile u32 *)(x+0x14))
#define USART_GTPR(x)    *((volatile u32 *)(x+0x18))












#define SR_CTS_BIT    	9
#define SR_LBD_BIT 			8    /* USART LIN break detection flag*/
#define SR_TXE_BIT 			7    /* USART Data Register Empty Flag*/
#define SR_TC_BIT 			6    /* USART Transmit Complete Flag*/
#define SR_RXNE_BIT 		5    /* USART Receive Complete Flag*/
#define SR_IDLE_BIT 		4    /* USART Noise error flag*/
#define SR_ORE_BIT 			3    /* USART Data OverRun Flag*/
#define SR_NE_BIT 			2    /* USART Noise error flag*/
#define SR_FE_BIT 			1    /* USART Frame Error Flag*/
#define SR_PE_BIT 			0    /* USART Parity Error */


//UE M WAKE PCE PS PEIE TXEIE TCIE RXNEIE IDLEIE TE RE RWU SBK
//CR1
#define CR1_UE_BIT    			13
#define CR1_M_BIT    				12
#define CR1_WAKE_BIT    		11
#define CR1_PCE_BIT    			10
#define CR1_PS_BIT    			9
#define CR1_PEIE_BIT    		8
#define CR1_TXEIE_BIT    		7
#define CR1_TCIE_BIT    		6
#define CR1_RXNEIE_BIT    	5
#define CR1_IDLEIE_BIT    	4
#define CR1_TE_BIT    			3
#define CR1_RE_BIT    			2
#define CR1_RWU_BIT    			1
#define CR1_SBK_BIT    			0

#define CR3_DMAT_BIT    		7
#define CR3_DMAR_BIT    		6
#define USART_TIME_OUT 10000000

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
#endif /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

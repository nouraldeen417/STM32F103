

/*
 * File:
 * Author:
 * Comments:
 * Revision history:
 */

#ifndef _DMA_PRIVATE_H
#define _DMA_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lip/Macros.h"
#include "../../lip/STD_TYPES.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

//0x40020000 - 0x4002 03FF
#define DMA_1_BASE_ADD									0x40020000
#define DMA_1_ISR       								*((volatile u32 *)(DMA_1_BASE_ADD+0x00))
#define DMA_1_IFCR      								*((volatile u32 *)(DMA_1_BASE_ADD+0x04))
#define DMA_1_CCR(channel_number)       *((volatile u32 *)(DMA_1_BASE_ADD+(0x08 +(20*channel_number))))
#define DMA_1_CNDTR(channel_number)     *((volatile u32 *)(DMA_1_BASE_ADD+(0x0C +(20*channel_number))))
#define DMA_1_CPAR(channel_number)      *((volatile u32 *)(DMA_1_BASE_ADD+(0x10 +(20*channel_number))))
#define DMA_1_CMAR(channel_number)      *((volatile u32 *)(DMA_1_BASE_ADD+(0x14 +(20*channel_number))))
// ISR Reg
#define ISR_TEIF_BIT 			3    /* Channel transfer error flag */
#define ISR_HTIF_BIT 			2    /* Channel halh transfer error flag */
#define ISR_TCIF_BIT 			1    /* Channel transfer complete flag  */
#define ISR_GIF_BIT 			0    /* Channel global interrupt flag  */
//IFCR Reg
#define IFCR_CTEIF_BIT 			3    /* Channel transfer error flag */
#define IFCR_CHTIF_BIT 			2    /* Channel halh transfer error flag */
#define IFCR_CTCIF_BIT 			1    /* Channel transfer complete flag  */
#define IFCR_CGIF_BIT 			0    /* Channel global interrupt flag  */
//CCR Reg   
#define CCR_MEM2MEM_BIT    			14
#define CCR_PL_1_BIT    			  13
#define CCR_PL_0_BIT    				12
#define CCR_MSIZE_1_BIT    		  11
#define CCR_MSIZE_0_BIT    			10
#define CCR_PSIZE_1_BIT    			9
#define CCR_PSIZE_0_BIT    		  8
#define CCR_MINC_BIT    		    7
#define CCR_PINC_BIT    		    6
#define CCR_CIRC_BIT    	      5
#define CCR_DIR_BIT    			 		4
#define CCR_TEIE_BIT    				3
#define CCR_HTIE_BIT    				2
#define CCR_TCIE_BIT    				1
#define CCR_EN_BIT    					0
#define DMA_TIME_OUT 10000000

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

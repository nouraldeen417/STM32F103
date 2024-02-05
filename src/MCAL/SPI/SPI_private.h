/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// 0x40013000 - 0x4001 33FF
#define SPI_BASE_ADD						0x40013000
#define SPI_CR1     *((volatile u32 *)(SPI_BASE_ADD+0x00))
#define SPI_CR2     *((volatile u32 *)(SPI_BASE_ADD+0x04))
#define SPI_SR      *((volatile u32 *)(SPI_BASE_ADD+0x08))
#define SPI_DR      *((volatile u32 *)(SPI_BASE_ADD+0x0C))
#define SPI_CRCPR   *((volatile u32 *)(SPI_BASE_ADD+0x10))
#define SPI_RXCRCR  *((volatile u32 *)(SPI_BASE_ADD+0x14))
#define SPI_TXCRCR  *((volatile u32 *)(SPI_BASE_ADD+0x18))
#define SPI_I2SCFGR *((volatile u32 *)(SPI_BASE_ADD+0x1C))
#define SPI_I2SPR   *((volatile u32 *)(SPI_BASE_ADD+0x20))

/*
SPI_CR1
*/
#define SPCR1_BIDI_MODE_BIT                               15
#define SPCR1_BIDIOE_BIT                                	14
#define SPCR1_CRC_EN_BIT                               		13
#define SPCR1_CRC_NEXT_BIT                               	12
#define SPCR1_DFF_BIT                              		 		11
#define SPCR1_RX_ONLY_BIT                               	10
#define SPCR1_SSM_BIT                               			9
#define SPCR1_SSI_BIT                               			8
#define SPCR1_LSBF_BIT                              		  7
#define SPCR1_SPE_BIT			                                6
#define SPCR1_BR2_BIT                               			5	
#define SPCR1_BR1_BIT                               			4
#define SPCR1_BR_BITS                               			3
#define SPCR1_MSTR_BIT                               			2
#define SPCR1_CPOL_BIT                               			1
#define SPCR1_CPHA_BIT                               			0
/*SPI_CR2*/
#define SPCR2_TXEIE_BIT                              		  		7
#define SPCR2_RXNEIE_BIT			                                6
#define SPCR2_ERRIE_BIT                               				5		
#define SPCR2_SSOE_BIT                               					2
#define SPCR2_TXDMAEN_BIT                               			1
#define SPCR2_RXDMAEN_BIT                               			0
/*SPI_SR*/
#define SPSR_BSY_BIT                              			  		7
#define SPSR_OVR_BIT			                              		  6
#define SPSR_MODF_BIT                               					5		
#define SPSR_CRC_ERR_BIT                               				4
#define SPSR_UDR_BIT                               						3
#define SPSR_CHSIDE_BIT                               				2
#define SPSR_TXE_BIT                               						1
#define SPSR_RXNE_BIT                               					0

#define SPI_TRANSFER_TIME_OUT                       100000
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








/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef _DMA_INTERFACE_H
#define	_DMA_INTERFACE_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lip/Macros.h"
#include "../../lip/STD_TYPES.h"
#include "DMA_private.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
    DMA_Channel_1,
		DMA_Channel_2,   
		DMA_Channel_3,
	  DMA_Channel_4,
    DMA_Channel_5,
		DMA_Channel_6,   
		DMA_Channel_7,
	  MAX_DMA_1_Channel_NUM,
   	DMA_Channel_8,
    DMA_Channel_9,
		DMA_Channel_10,   
		DMA_Channel_11,
	  DMA_Channel_12,
	  MAX_DMA_Channel_NUM,
}DMA_ChannelType;

typedef enum {
    DMA_Normal_Mode,     			 // Peripheral-to-memory and memory-to-peripheral, and peripheral-to-peripheral transfers
		DMA_Circular_Mode,   			 // Circular transfer
		DMA_Memory_to_memory_Mode, //Memory-to-memory transfer
	  MAX_DMA_Mode_NUM,
}DMA_ModeType;

typedef enum {
    DMA_Low_Priority=0,     			 
		DMA_Medium_Priority,   			 
		DMA_High_Priority, 
	  DMA_Very_High_Priority,
}DMA_PriorityType;
typedef enum {
    DMA_Peripheral_8_Bits  ,//00     			 
    DMA_Peripheral_16_Bits ,//01
    DMA_Peripheral_32_Bits ,//10
	  DMA_Rserved_Peripheral ,//11
}DMA_PeripheralSizeType;
typedef enum {
    DMA_Memory_8_Bits  ,//00     			 
    DMA_Memory_16_Bits ,//01
    DMA_Memory_32_Bits ,//10
	  DMA_Rserved_Memory ,//11
}DMA_MemorySizeType;
typedef enum {
    DMA_Peripheral_Increment_Enable   ,//0     			 
    DMA_Peripheral_Increment_Disable  ,//1
}DMA_PeripheralIncrementType;
typedef enum {
    DMA_Memory_Increment_Enable   ,   // 0     			 
    DMA_Memory_Increment_Disable  ,   // 1
}DMA_MemoryIncrementType;
typedef enum {
    DMA_Read_From_Peripheral   ,   // 0     			 
    DMA_Read_From_Memory       ,   // 1
}DMA_DataTransferType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef struct {
DMA_ChannelType 									Channel_Id;
DMA_ModeType 											Copy_Mode;		
DMA_PriorityType									Copy_PL;	
DMA_PeripheralSizeType						Copy_PSIZE;
DMA_MemorySizeType								Copy_MSIZE;
DMA_PeripheralIncrementType				Copy_PINC;
DMA_MemoryIncrementType						Copy_MINC;
DMA_DataTransferType      				Copy_DIR;
u16														    Copy_u16Channel_NumReg;	                    // DMA channel number of data register
u32																Copy_u32Peripheral_AddressReg;							//DMA channel peripheral address register				
u32																Copy_u32Memory_AddressReg;									//DMA channel Memory address register				
void 													    (* DMA_pvTCNotifaction)(void)  ;						//Transfer complete interrupt enable
void 													    (* DMA_pvHTNotifaction)(void)  ;						//Half transfer interrupt enable 
void 													    (* DMA_pvTENotifaction)(void)  ;						//Transfer error interrupt enable	
}DMA_confType;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
ErrorStatus   DMA_enumInitConfig        (DMA_confType* Copy_Conf);
ErrorStatus   DMA_enumEnable        		(DMA_ChannelType Copy_channel);
ErrorStatus   DMA_enumDisable        		(DMA_ChannelType Copy_channel);
ErrorStatus   DMA_enumWait_TCIF_Flag    (u8 Copy_Id) ;

#endif /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/


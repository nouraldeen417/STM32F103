/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef _USART_INTERFACE_H
#define	_USART_INTERFACE_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lip/Macros.h"
#include "../../lip/STD_TYPES.h"
#include "USART_private.h"
#include "..\DMA\DMA_interface.h"

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
    USART_Id_1,
		USART_Id_2,   
		USART_Id_MAX,   
}USART_IdType;
typedef enum {
    USART_SYNC,
		USART_ASYNC,   
}USART_ModeType;
typedef enum {
    USART_DATA_8_BITS,
		USART_DATA_9_BITS,   
}USART_DlengthType;
typedef enum {
	  USART_STOP_1_BIT,
  	USART_STOP_0_5_BIT,
		USART_STOP_2_BITS,
		USART_STOP_1_5_BITS,
}USART_StopBitLengthType;
typedef enum {
	  USART_Even_Parity,
  	USART_Odd_Parity,
		USART_Parity_Disable,
}USART_ParitySelectType;
typedef enum {
	  Overrun_Error=0,
		Noise_Error,
		Framing_Error,
	  Parity_Error,
}USART_ErrorStateType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef struct {
		USART_IdType      	  				 USART_Id;
    USART_ModeType          			 USART_Mode;
    USART_DlengthType        			 USART_DataLength;
    USART_StopBitLengthType        USART_StopBits;
		USART_ParitySelectType				 USART_ParitySelect;
		u16 		 							 				 USART_u16DivMantissa;
    u8 		                  			 USART_u8DivFraction;
}USART_confType;

typedef struct {
USART_IdType      	  				 USART_Id;
u16       										*USART_pu16Data;	
u8														 USART_u8BufferSize;
void 													(* USART_pvNotifaction)(void)  ;
}USART_BufferType;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 void USART_voidInit();
void USART_voidDisable(u8 Copy_Id);
ErrorStatus   USART_enumInitConfig        (USART_confType* Copy_Conf);
 
ErrorStatus   USART_enumSendData          (u8 Copy_Id,u16 Copy_u8Data);
ErrorStatus   USART_enumRecevieData       (u8 Copy_Id,u16 * Copy_u8ReceviedData) ;
 
ErrorStatus   USART_enumSendBufferSync    ( USART_BufferType *Copy_BufferConf);
ErrorStatus   USART_enumSendBufferASync   ( USART_BufferType *Copy_BufferConf);
 
ErrorStatus   USART_enumRecieveBufferSync ( USART_BufferType *Copy_BufferConf);
ErrorStatus   USART_enumRecieveBufferASync( USART_BufferType *Copy_BufferConf);

ErrorStatus   USART_enumGetErrorState( u8 Copy_Id,u8* Copy_Errors);
static ErrorStatus USART_enumGetBaseAddress (u8 Copy_Id,u32* Copy_BaseAdd);

ErrorStatus   USART_enumSendData_DMA          (DMA_confType *Copy_Conf,u8 Copy_Id,u8 *Copy_u8TData,u8 Copy_u8Size);
ErrorStatus   USART_enumRecevieData_DMA       (DMA_confType *Copy_Conf,u8 Copy_Id) ;
//ErrorStatus   USART_enumSendBufferSync_DMA    ( USART_BufferType *Copy_BufferConf);
//ErrorStatus   USART_enumRecieveBufferSync_DMA ( USART_BufferType *Copy_BufferConf);

ErrorStatus   USART_enumWait_TC_Flag          (u8 Copy_Id) ;

#endif /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/


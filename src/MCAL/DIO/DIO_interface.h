/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h" 
#include "DIO_private.h" 

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
DIO_Port_A,
DIO_Port_B,
DIO_Port_C,
DIO_Port_D,
DIO_Port_E,
DIO_Port_F,
}DIO_PortType;

typedef enum {
Pin_A_0,
Pin_A_1,
Pin_A_2,
Pin_A_3,
Pin_A_4,
Pin_A_5,
Pin_A_6,
Pin_A_7,
Pin_A_8,
Pin_A_9,
Pin_A_10,
Pin_A_11,
Pin_A_12,
Pin_A_13,
Pin_A_14,
Pin_A_15,
Pin_B_0,
Pin_B_1,
Pin_B_2,
Pin_B_3,
Pin_B_4,
Pin_B_5,
Pin_B_6,
Pin_B_7,
Pin_B_8,
Pin_B_9,
Pin_B_10,
Pin_B_11,
Pin_B_12,
Pin_B_13,
Pin_B_14,
Pin_B_15,
Pin_C_13=13,
Pin_C_14,
Pin_C_15,
}DIO_PinType;
typedef enum {
		DIO_Pin_Input  ,
    DIO_Pin_Output ,    
		DIO_Port_Input=0x00  ,
    DIO_Port_Output=0xFF ,    
		
} DIO_Directiontype;

typedef enum {
		DIO_Pin_LOW=0,
    DIO_Pin_HIGH =! DIO_Pin_LOW,    
} DIO_Pin_stateType;
typedef enum {
		DIO_Port_Low  =0x00,
    DIO_Port_HIGH =0xFF,    
} DIO_Port_stateType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
ErrorStatus DIO_enumSetPinDirection  (DIO_PortType Copy_u8Port, DIO_PinType Copy_u8Pin, DIO_Directiontype Copy_u8Direction);
ErrorStatus DIO_enumSetPinValue      (DIO_PortType Copy_u8Port, DIO_PinType Copy_u8Pin, DIO_Pin_stateType Value);
ErrorStatus DIO_enumGetInputPinValue (DIO_PortType Copy_u8Port, DIO_PinType Copy_u8Pin ,u8 * Copy_PtrData);
ErrorStatus DIO_enumGetOutputPinValue(DIO_PortType Copy_u8Port, DIO_PinType Copy_u8Pin ,u8 * Copy_PtrData);

ErrorStatus DIO_enumSetPortDirection (DIO_PortType Copy_u8Port, DIO_Directiontype Copy_u8Direction);
ErrorStatus DIO_enumSetPortValue     (DIO_PortType Copy_u8Port, u32 Copy_u8Value);
ErrorStatus DIO_enumGetInputPortValue(DIO_PortType Copy_u8Port, u8 * Copy_PtrData);

ErrorStatus DIO_enumTogglePinValue   (DIO_PortType Copy_u8Port, DIO_PinType Copy_u8Pin);

ErrorStatus DIO_enumEnablePullup     (DIO_PortType Copy_u8Port, DIO_PinType Copy_u8Pin);
ErrorStatus DIO_enumEnablePullDown   (DIO_PortType Copy_u8Port, DIO_PinType Copy_u8Pin);
ErrorStatus DIO_enumEnableOpenDrain  (DIO_PortType Copy_u8Port, DIO_PinType Copy_u8Pin);



//ErrorStatus DIO_enumSetPortHighNibble(DIO_PortType Copy_u8Port, DIO_Port_stateType Copy_u8Value);
//ErrorStatus DIO_enumSetPortLowNibble (DIO_PortType Copy_u8Port, DIO_Port_stateType Copy_u8Value);
ErrorStatus DIO_enumSetPortNibble (DIO_PortType Copy_u8Port, u8 Copy_u8Value,DIO_PinType Copy_StartPin );

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

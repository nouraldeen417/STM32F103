/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
#include "EXTI_private.h"
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
EXTI_None,	
EXTI_Falling,
EXTI_Rising,
EXTI_Falling_Rising
}EXTI_EdgeType;

typedef enum {
EXTI_Interrupt,
EXTI_Event
}EXTI_RequestType;

typedef enum {
EXTI_Pin_0,
EXTI_Pin_1,
EXTI_Pin_2,
EXTI_Pin_3,
EXTI_Pin_4,
EXTI_Pin_5,
EXTI_Pin_6,
EXTI_Pin_7,
EXTI_Pin_8,
EXTI_Pin_9,
EXTI_Pin_10,
EXTI_Pin_11,
EXTI_Pin_12,
EXTI_Pin_13,
EXTI_Pin_14,
EXTI_Pin_15,
EXTI_PVD_output,
EXTI_RTC_Alarm_Event,
EXTI_USB_Wakeup_Event,
EXTI_Ethernet_Wakeup_Event,
EXTI_Max_Number	
}EXTI_PinType;

typedef struct {
EXTI_PinType 					Pin;
EXTI_EdgeType  				Edge;
EXTI_RequestType      Request;
}EXTI_ConfType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
ErrorStatus EXTI_enumSetConf		  	  (EXTI_ConfType *Copy_Conf );

ErrorStatus EXTI_enumEnableInterrupt  (EXTI_PinType   Copy_u8Pin);
ErrorStatus EXTI_enumDisableInterrupt (EXTI_PinType   Copy_u8Pin);

ErrorStatus EXTI_enumEnableEvent 		  (EXTI_PinType   Copy_u8Pin);
ErrorStatus EXTI_enumDisableEvent		  (EXTI_PinType   Copy_u8Pin);

ErrorStatus EXTI_enumSetSWTrigger 		(EXTI_PinType   Copy_u8Pin);
ErrorStatus EXTI_enumSetRisingTrigger (EXTI_PinType   Copy_u8Pin);
ErrorStatus EXTI_enumSetFallingTrigger(EXTI_PinType   Copy_u8Pin);

ErrorStatus EXTI_enumClearSWTrigger 		(EXTI_PinType   Copy_u8Pin);
ErrorStatus EXTI_enumClearRisingTrigger (EXTI_PinType   Copy_u8Pin);
ErrorStatus EXTI_enumClearFallingTrigger(EXTI_PinType   Copy_u8Pin);

ErrorStatus EXTI_enumSetBothEdgesTrigger(EXTI_PinType   Copy_u8Pin);
ErrorStatus EXTI_enumClearFlag        (EXTI_PinType   Copy_u8Pin);

u8          EXTI_u8GetFlag            (EXTI_PinType   Copy_u8Pin);

void        EXTI_voidSetCallBack     (void (* EXTI_ptrvoidCopyCallBack) (void),EXTI_PinType Copy_u8Pin);
 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/








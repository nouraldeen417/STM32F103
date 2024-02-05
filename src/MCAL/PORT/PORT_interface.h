/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _PORT_INTERFACE_H
#define _PORT_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
#include "PORT_private.h" 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PIN_INPUT_PULL_UP_DOWN      								0x8	    //0b1000
#define PIN_INPUT_FLOATING          								0x4			//0b0100
#define PIN_INPUT_ANALOG            								0x0			//0b0000
#define PIN_OUTPUT_PUSH_PULL_MAX_SPEED_10        		0x1			//0b0001
#define PIN_OUTPUT_OPEN_DRAIN_MAX_SPEED_10       		0x5			//0b0101
#define PIN_ALT_OUTPUT_PUSH_PULL_MAX_SPEED_10       0x9			//0b1001	
#define PIN_ALT_OUTPUT_OPEN_DRAIN_MAX_SPEED_10      0xD 		//0b1101
#define LCKK_PIN                                    16

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum
{
Channel_A_0,
Channel_A_1,
Channel_A_2,
Channel_A_3,
Channel_A_4,
Channel_A_5,
Channel_A_6,
Channel_A_7,
Channel_A_8,
Channel_A_9,
Channel_A_10,
Channel_A_11,
Channel_A_12,
Channel_A_13,
Channel_A_14,
Channel_A_15,
Channel_B_0,
Channel_B_1,
Channel_B_2,
Channel_B_3,
Channel_B_4,
Channel_B_5,
Channel_B_6,
Channel_B_7,
Channel_B_8,
Channel_B_9,
Channel_B_10,
Channel_B_11,
Channel_B_12,
Channel_B_13,
Channel_B_14,
Channel_B_15,
Channel_C_13=13,
Channel_C_14,
Channel_C_15,
}PORT_ChIdType;

typedef enum
{
    PORT_Id_A,
    PORT_Id_B,
    PORT_Id_C,
}PORT_IdType;

typedef enum
{
		PORT_None,  
		PORT_Unlocked,
    PORT_locked
}PORT_LockStatusType;




typedef struct
{
    PORT_ChIdType           Channel;
		PORT_IdType             Port;
    u8					            Conf;
    PORT_LockStatusType     LockStatus;
}PORT_ConfType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
ErrorStatus PORT_voidInit(const PORT_ConfType *Copy_ConfArray);

#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

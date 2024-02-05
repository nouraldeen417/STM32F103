/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EEPROM_program.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
#include "EEPROM_interface.h"
#include<util/delay.h>

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
//#define F_CPU                  8000000UL
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte) {
    u8 LOC_AddressPacket; //1010                  0                             A1 A0
    LOC_AddressPacket = (EEPROM_FIXED_ADDRESS) | (EEPROM_A2_CONNECTION << 3) | (Copy_u16LocationAddress >> 8);
    // Send Start Condition
    TWI_enumSendStartCondition();
    // Send Address Packet
    TWI_enumSendSlaveAddressWithWrite(LOC_AddressPacket);
    //Send Memory Address First 8 Bit 
    TWI_enumMasterWriteDataByte((u8) Copy_u16LocationAddress);
    //Send Data Byte
    TWI_enumMasterWriteDataByte(Copy_u8DataByte);
    //Send Stop Condition  
    TWI_voidSendStopCondition();
    //Delay   
    _delay_ms(10);

}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress) {
    u8 Copy_DataByte;
    u8 LOC_AddressPacket; //1010                  0                             A1 A0
    LOC_AddressPacket = (EEPROM_FIXED_ADDRESS) | (EEPROM_A2_CONNECTION << 3) | (Copy_u16LocationAddress >> 8);
    // Send Start Condition
    TWI_enumSendStartCondition();
    // Send Address Packet
    TWI_enumSendSlaveAddressWithWrite(LOC_AddressPacket);
    //Send Memory Address First 8 Bit 
    TWI_enumMasterWriteDataByte((u8) Copy_u16LocationAddress);
    //Send Repeated Start Condition
    
    TWI_enumSendRepeatedStartCondition();
    // Send Address Packet With Read
    TWI_enumSendSlaveAddressWithRead(LOC_AddressPacket);
    //Receive Data Byte
    TWI_enumMasterReadDataByte(& Copy_DataByte);
    //Send Stop Condition  
    TWI_voidSendStopCondition();
    //Delay   
    _delay_ms(10);
    return Copy_DataByte;

}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
 * \Description     : Describe this service                                    
 *                                                                             
 * \Sync\Async      : Synchronous                                               
 * \Reentrancy      : Non Reentrant                                             
 * \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
 * \Parameters (out): None                                                      
 * \Return value:   : None
 *                                  
 *******************************************************************************/

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
 * \Description     : Describe this service                                    
 *                                                                             
 * \Sync\Async      : Synchronous                                               
 * \Reentrancy      : Non Reentrant                                             
 * \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
 * \Parameters (out): None                                                      
 * \Return value:   : Std_ReturnType  OK
 *                                    NOK                                  
 *******************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: EEPROM_program.c
 *********************************************************************************************************************/

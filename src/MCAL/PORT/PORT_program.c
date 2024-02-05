
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO_program.c
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
#include "PORT_interface.h"
#include "PORT_conf.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :    Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                  
*******************************************************************************/ 

ErrorStatus PORT_voidInit(const PORT_ConfType *Copy_ConfArray){
ErrorStatus LOC_ErrorState =OK;
u8 LOC_u8Iterator=0;	
 volatile PORT_RegType* PORT_Addr;	
		if(Copy_ConfArray != NULL)
		{
			for(LOC_u8Iterator=0;LOC_u8Iterator< PORT_PINS_NUMS;LOC_u8Iterator++)
			{
					PORT_ChIdType Copy_Pin   =(Copy_ConfArray[LOC_u8Iterator].Channel)%16;
					PORT_IdType   Copy_PortId=Copy_ConfArray[LOC_u8Iterator].Port;   
					u8 						Copy_u8Conf=Copy_ConfArray[LOC_u8Iterator].Conf;
					//Get Port Id
					switch (Copy_PortId)
            {
            	case PORT_Id_A:
							  PORT_Addr = &PORTA_REG;
            		break;
            	case PORT_Id_B:
							  PORT_Addr = &PORTB_REG;
            		break;
            	case PORT_Id_C:
							  PORT_Addr = &PORTC_REG;							
            		break;
            	default:
								LOC_ErrorState=NOK;
            		break;
            }	
					/*Set Configration*/	
					
					switch(Copy_u8Conf){
					
            	case PIN_INPUT_PULL_UP_DOWN:
								if(Copy_Pin<8)
								{
									PORT_Addr->CRL_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRL_REG |= (Copy_u8Conf<<(Copy_Pin*4));      
								}else
								{
									Copy_Pin-=8;
									PORT_Addr->CRH_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRH_REG |= (Copy_u8Conf<<(Copy_Pin*4));									
								}
								break;
            	case PIN_INPUT_FLOATING:
								if(Copy_Pin<8)
								{
									PORT_Addr->CRL_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRL_REG |= (Copy_u8Conf<<(Copy_Pin*4));      
								}else
								{
									Copy_Pin-=8;
									PORT_Addr->CRH_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRH_REG |= (Copy_u8Conf<<(Copy_Pin*4));									
								}
            		break;
            	case PIN_INPUT_ANALOG:
								if(Copy_Pin<8)
								{
									PORT_Addr->CRL_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRL_REG |= (Copy_u8Conf<<(Copy_Pin*4));      
								}else
								{
									Copy_Pin-=8;
									PORT_Addr->CRH_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRH_REG |= (Copy_u8Conf<<(Copy_Pin*4));									
								}            		
								break;
            	case PIN_OUTPUT_PUSH_PULL_MAX_SPEED_10:
								if(Copy_Pin<8)
								{
									PORT_Addr->CRL_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRL_REG |= (Copy_u8Conf<<(Copy_Pin*4));      
								}else
								{
									Copy_Pin-=8;
									PORT_Addr->CRH_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRH_REG |= (Copy_u8Conf<<(Copy_Pin*4));									
								}   
            		break;
            	case PIN_OUTPUT_OPEN_DRAIN_MAX_SPEED_10 :
								if(Copy_Pin<8)
								{
									PORT_Addr->CRL_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRL_REG |= (Copy_u8Conf<<(Copy_Pin*4));      
								}else
								{
									Copy_Pin-=8;
									PORT_Addr->CRH_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRH_REG |= (Copy_u8Conf<<(Copy_Pin*4));									
								}   
            		break;
            	case PIN_ALT_OUTPUT_PUSH_PULL_MAX_SPEED_10 :
								if(Copy_Pin<8)
								{
									PORT_Addr->CRL_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRL_REG |= (Copy_u8Conf<<(Copy_Pin*4));      
								}else
								{
									Copy_Pin-=8;
									PORT_Addr->CRH_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRH_REG |= (Copy_u8Conf<<(Copy_Pin*4));									
								}   
            		break;
            	case PIN_ALT_OUTPUT_OPEN_DRAIN_MAX_SPEED_10 :
								if(Copy_Pin<8)
								{
									PORT_Addr->CRL_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRL_REG |= (Copy_u8Conf<<(Copy_Pin*4));      
								}else
								{
									Copy_Pin-=8;
									PORT_Addr->CRH_REG &= ~(0xF<<(Copy_Pin*4));
									PORT_Addr->CRH_REG |= (Copy_u8Conf<<(Copy_Pin*4));									
								}   
            		break;								
            	default:
								LOC_ErrorState=NOK;
            		break;
					}
					//set lock
					Copy_Pin  =(Copy_ConfArray[LOC_u8Iterator].Channel)%16;
					
					if(Copy_ConfArray[LOC_u8Iterator].LockStatus == PORT_Unlocked)
					{
						SET_BIT(PORT_Addr->LCKR_REG,LCKK_PIN);
						CLEAR_BIT(PORT_Addr->LCKR_REG,LCKK_PIN);
  					SET_BIT(PORT_Addr->LCKR_REG,LCKK_PIN);
						GET_BIT(PORT_Addr->LCKR_REG,LCKK_PIN);
						SET_BIT(PORT_Addr->LCKR_REG,Copy_Pin);
					}else if(Copy_ConfArray[LOC_u8Iterator].LockStatus == PORT_locked)
					{
						SET_BIT(PORT_Addr->LCKR_REG,LCKK_PIN);
						CLEAR_BIT(PORT_Addr->LCKR_REG,LCKK_PIN);
  					SET_BIT(PORT_Addr->LCKR_REG,LCKK_PIN);
						GET_BIT(PORT_Addr->LCKR_REG,LCKK_PIN);
						CLEAR_BIT(PORT_Addr->LCKR_REG,Copy_Pin);					
					}else
					{
						//do nothing
					}
		  }
				
		}
		else
		{

		LOC_ErrorState=NOK;

		}
return LOC_ErrorState;
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :    Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/ 

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/









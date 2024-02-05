
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
#include "DIO_interface.h"
#include "DIO_config.h"

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
ErrorStatus DIO_enumSetPinDirection  (DIO_PortType Copy_u32Port, DIO_PinType Copy_u8Pin, DIO_Directiontype Copy_u8Direction){
ErrorStatus LOC_Errorstate =OK;
u8 Copy_u8ModeBit=0;
Copy_u8Pin%=16;
	if (Copy_u8Direction == DIO_Pin_Input)
	{
		switch (Copy_u32Port)
			{
				case DIO_Port_A:
				/*Pins 0:7  modes controled GPIOA_CRL_REG,
					Pins 8:15 modes controled GPIOA_CRH_REG
					so we checked required pin first.																				*/ 
				if(Copy_u8Pin < 8)
				{
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					CLEAR_BIT(GPIOA_CRL_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOA_CRL_REG ,(Copy_u8ModeBit+1));
				}else
				{
					Copy_u8Pin-=8;
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					CLEAR_BIT(GPIOA_CRH_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOA_CRH_REG ,(Copy_u8ModeBit+1));
				}
					break;
				case DIO_Port_B:
				/*Pins 0:7  modes controled GPIOA_CRL_REG,
					Pins 8:15 modes controled GPIOA_CRH_REG
					so we checked required pin first.																				*/ 
				if(Copy_u8Pin < 8)
				{
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					CLEAR_BIT(GPIOB_CRL_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOB_CRL_REG ,(Copy_u8ModeBit+1));
				}else
				{
					Copy_u8Pin-=8;
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					CLEAR_BIT(GPIOB_CRH_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOB_CRH_REG ,(Copy_u8ModeBit+1));
				}
					break;
				case DIO_Port_C:
				/*Pins 0:7  modes controled GPIOA_CRL_REG,
					Pins 8:15 modes controled GPIOA_CRH_REG
					so we checked required pin first.																				*/ 
				if(Copy_u8Pin < 8)
				{
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					CLEAR_BIT(GPIOC_CRL_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOC_CRL_REG ,(Copy_u8ModeBit+1));
				}else
				{
					Copy_u8Pin-=8;
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					CLEAR_BIT(GPIOC_CRH_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOC_CRH_REG ,(Copy_u8ModeBit+1));
				}
					break;

						default:LOC_Errorstate =NOK;
					break;
			}
	}
	else if(Copy_u8Direction == DIO_Pin_Output)
	{
		switch (Copy_u32Port)
			{
				case DIO_Port_A:
				/*Pins 0:7  modes controled GPIOA_CRL_REG,
					Pins 8:15 modes controled GPIOA_CRH_REG
					so we checked required pin first.																				*/ 
				if(Copy_u8Pin < 8)
				{
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					SET_BIT(GPIOA_CRL_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOA_CRL_REG ,(Copy_u8ModeBit+1));
				}else
				{
				
					Copy_u8Pin-=8;				
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					SET_BIT(GPIOA_CRH_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOA_CRH_REG ,(Copy_u8ModeBit+1));
				}
					break;
				case DIO_Port_B:
				/*Pins 0:7  modes controled GPIOA_CRL_REG,
					Pins 8:15 modes controled GPIOA_CRH_REG
					so we checked required pin first.																				*/ 
				if(Copy_u8Pin < 8)
				{
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					SET_BIT(GPIOB_CRL_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOB_CRL_REG ,(Copy_u8ModeBit+1));
				}else
				{
					Copy_u8Pin-=8;
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					SET_BIT(GPIOB_CRH_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOB_CRH_REG ,(Copy_u8ModeBit+1));
				}
					break;
				case DIO_Port_C:
				/*Pins 0:7  modes controled GPIOA_CRL_REG,
					Pins 8:15 modes controled GPIOA_CRH_REG
					so we checked required pin first.																				*/ 
				if(Copy_u8Pin < 8)
				{
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					SET_BIT(GPIOC_CRL_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOC_CRL_REG ,(Copy_u8ModeBit+1));
				}else
				{
					Copy_u8Pin-=8;
					Copy_u8ModeBit=Copy_u8Pin*4;       //*4 to acsess required bit modes bit 0,4,8,12,...,28							
					SET_BIT(GPIOC_CRH_REG ,Copy_u8ModeBit);							 
					CLEAR_BIT(GPIOC_CRH_REG ,(Copy_u8ModeBit+1));
				}
					break;
						default:LOC_Errorstate =NOK;
					break;

			}
	}

return LOC_Errorstate ;
}
ErrorStatus DIO_enumSetPinValue  (DIO_PortType Copy_u32Port, DIO_PinType Copy_u8Pin, DIO_Pin_stateType Copy_u8Value){
ErrorStatus LOC_Errorstate =OK;
Copy_u8Pin%=16;

	if (Copy_u8Value == DIO_Pin_LOW)
	{
		switch (Copy_u32Port)
			{
				case DIO_Port_A:
						GPIOA_BRR_REG=(1<<Copy_u8Pin);
					break;
				case DIO_Port_B:
						GPIOB_BRR_REG=(1<<Copy_u8Pin);
					break;
				case DIO_Port_C:
						GPIOC_BRR_REG=(1<<Copy_u8Pin);
					break;
						default:LOC_Errorstate =NOK;
					break;

			}
	}
	else if(Copy_u8Value == DIO_Pin_HIGH)
	{
		switch (Copy_u32Port)
			{
				case DIO_Port_A:
						GPIOA_BSRR_REG=(1<<Copy_u8Pin);
					break;
				case DIO_Port_B:
						GPIOB_BSRR_REG=(1<<Copy_u8Pin);
					break;
				case DIO_Port_C:
						GPIOC_BSRR_REG=(1<<Copy_u8Pin);
					break;
						default:LOC_Errorstate =NOK;
					break;
			}
	}

return LOC_Errorstate ;

}


ErrorStatus DIO_enumGetInputPinValue (DIO_PortType Copy_u32Port, DIO_PinType Copy_u8Pin ,u8 * Copy_PtrData){
ErrorStatus LOC_Errorstate =OK;
		if(Copy_PtrData != NULL)
		{
		switch (Copy_u32Port)
			{
				case DIO_Port_A:
								*Copy_PtrData=			GET_BIT(GPIOA_IDR_REG ,Copy_u8Pin);
					break;
				case DIO_Port_B:
								*Copy_PtrData=			GET_BIT(GPIOB_IDR_REG ,Copy_u8Pin);
					break;
				case DIO_Port_C:
								*Copy_PtrData=			GET_BIT(GPIOC_IDR_REG ,Copy_u8Pin);
					break;
			
				default:LOC_Errorstate =NOK;
					break;

			}		
		
		}
		else
		{
		LOC_Errorstate = NOK;
		}

return LOC_Errorstate ;

}
ErrorStatus DIO_enumGetOutputPinValue (DIO_PortType Copy_u32Port, DIO_PinType Copy_u8Pin ,u8 * Copy_PtrData){
ErrorStatus LOC_Errorstate =OK;
		if(Copy_PtrData != NULL)
		{
		switch (Copy_u32Port)
			{
				case DIO_Port_A:
								*Copy_PtrData=			GET_BIT(GPIOA_ODR_REG ,Copy_u8Pin);
					break;
				case DIO_Port_B:
								*Copy_PtrData=			GET_BIT(GPIOB_ODR_REG ,Copy_u8Pin);
					break;
				case DIO_Port_C:
								*Copy_PtrData=			GET_BIT(GPIOC_ODR_REG ,Copy_u8Pin);
					break;
			
				default:LOC_Errorstate =NOK;
					break;

			}		
		
		}
		else
		{
		LOC_Errorstate = NOK;
		}

return LOC_Errorstate ;

}

ErrorStatus DIO_enumSetPortDirection (DIO_PortType Copy_u8Port, DIO_Directiontype Copy_u8Direction){
ErrorStatus LOC_Errorstate =NOK;
		switch (Copy_u8Port)
			{
				case DIO_Port_A:
					if(Copy_u8Direction == DIO_Port_Input)
					{
										GPIOA_CRL_REG = PORT_INPUT_PULL_UP_DOWN;
										GPIOA_CRH_REG = PORT_INPUT_PULL_UP_DOWN;
					}else
					{
										GPIOA_CRL_REG = PORT_OUTPUT_PUSH_PULL_DOWN;
										GPIOA_CRH_REG = PORT_OUTPUT_PUSH_PULL_DOWN;					
					}
  				break;
				case DIO_Port_B:
					if(Copy_u8Direction == DIO_Port_Input)
					{
										GPIOB_CRL_REG = PORT_INPUT_PULL_UP_DOWN;
										GPIOB_CRH_REG = PORT_INPUT_PULL_UP_DOWN;
					}else
					{
										GPIOB_CRL_REG = PORT_OUTPUT_PUSH_PULL_DOWN;
										GPIOB_CRH_REG = PORT_OUTPUT_PUSH_PULL_DOWN;					
					}
					break;
				case DIO_Port_C:
					if(Copy_u8Direction == DIO_Port_Input)
					{
										GPIOC_CRL_REG = PORT_INPUT_PULL_UP_DOWN;
										GPIOC_CRH_REG = PORT_INPUT_PULL_UP_DOWN;
					}else
					{
										GPIOC_CRL_REG = PORT_OUTPUT_PUSH_PULL_DOWN;
										GPIOC_CRH_REG = PORT_OUTPUT_PUSH_PULL_DOWN;					
					}
					break;
				default:LOC_Errorstate =NOK;
					break;

			}

return LOC_Errorstate ;

}

ErrorStatus DIO_enumSetPortValue (DIO_PortType Copy_u8Port, u32 Copy_u32Value){
ErrorStatus LOC_Errorstate =OK;
		switch (Copy_u8Port)
			{
				case DIO_Port_A:
						GPIOA_ODR_REG = Copy_u32Value;
					break;
				case DIO_Port_B:
						GPIOB_ODR_REG = Copy_u32Value;
					break;
					case DIO_Port_C:
						GPIOC_ODR_REG = Copy_u32Value;
					break;
					default:LOC_Errorstate =NOK;
					break;
			}

return LOC_Errorstate ;


}
ErrorStatus DIO_enumGetInputPortValue    (DIO_PortType Copy_u8Port, u8 * Copy_PtrData){
ErrorStatus LOC_Errorstate =OK;
		if(Copy_PtrData != NULL)
		{
		switch (Copy_u8Port)
			{
				case DIO_Port_A:
								*Copy_PtrData=	(u16) GPIOA_IDR_REG ;
					break;
				case DIO_Port_B:
								*Copy_PtrData=	(u16) GPIOB_IDR_REG ;
					break;
				case DIO_Port_C:
								*Copy_PtrData=	(u16) GPIOC_IDR_REG ;
					break;
				default:LOC_Errorstate =NOK;
					break;

			}		
		
		}
		else
		{
		LOC_Errorstate = NOK;
		
		}
return LOC_Errorstate ;

}


ErrorStatus DIO_enumTogglePinValue   (DIO_PortType Copy_u32Port, DIO_PinType Copy_u8Pin){
ErrorStatus LOC_Errorstate =OK;
		switch (Copy_u32Port)
			{
				case DIO_Port_A:
											TOGGLE_BIT(GPIOA_ODR_REG,Copy_u8Pin);
					break;
				case DIO_Port_B:
											TOGGLE_BIT(GPIOB_ODR_REG ,Copy_u8Pin);
					break;
				case DIO_Port_C:
											TOGGLE_BIT(GPIOC_ODR_REG ,Copy_u8Pin);
					break;
				default:LOC_Errorstate =NOK;
					break;
			}



		return LOC_Errorstate;

}


//ErrorStatus DIO_enumSetPortHighNibble(DIO_PortType Copy_u8Port, DIO_Port_stateType Copy_u8Value){
//ErrorStatus LOC_Errorstate =OK;

//  	switch (Copy_u8Port)
//			{
//				case DIO_Port_A:
//				if(Copy_u8Value== DIO_Port_HIGH)
//				{
//					GPIOA_BSRR_REG = 0x0F;				
//				}else
//				{
//					GPIOA_BRR_REG = 0x0F;					
//   			}
//					break;
//				case DIO_Port_B:
//				if(Copy_u8Value== DIO_Port_HIGH)
//				{
//					GPIOB_BSRR_REG = 0x0F;				
//				}else
//				{
//					GPIOB_BRR_REG = 0x0F;					
//   			}
//					break;
//				case DIO_Port_C:
//				if(Copy_u8Value== DIO_Port_HIGH)
//				{
//					GPIOC_BSRR_REG = 0x0F;				
//				}else
//				{
//					GPIOC_BRR_REG = 0x0F;					
//   			}	
//					break;
//				default:LOC_Errorstate =NOK;
//					break;
//			}

//return LOC_Errorstate ;
//}
// 0:3 4:7 8:11 12:16 //0000 0000 0000 0000
ErrorStatus DIO_enumSetPortNibble (DIO_PortType Copy_u8Port, u8 Copy_u8Value,DIO_PinType Copy_StartPin ){
ErrorStatus LOC_Errorstate =OK;
Copy_u8Value &= 0x0F;
Copy_StartPin%=16;
	switch (Copy_u8Port)
			{
				case DIO_Port_A:					
          GPIOA_ODR_REG &= ~(0x0F << Copy_StartPin);
					GPIOA_ODR_REG |=  (Copy_u8Value << Copy_StartPin);
					break;
				case DIO_Port_B:
          GPIOB_ODR_REG &= ~(0x0F << Copy_StartPin);
					GPIOB_ODR_REG |=  (Copy_u8Value << Copy_StartPin);
  				break;
				case DIO_Port_C:
          GPIOC_ODR_REG &= ~(0x0F << Copy_StartPin);
					GPIOC_ODR_REG |=  (Copy_u8Value << Copy_StartPin);
	  			break;
				default:LOC_Errorstate =NOK;
					break;
			}

return LOC_Errorstate ;

}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/









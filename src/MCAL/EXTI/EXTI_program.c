/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EXTI_program.c
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
#include "EXTI_interface.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void (* EXTI_CallBack[EXTI_Max_Number]) (void) = {NULL};
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
ErrorStatus EXTI_enumSetConf(EXTI_ConfType *Copy_Conf )
{
ErrorStatus LOC_Errorstate =OK;
EXTI_PinType 					Copy_u8Pin;
EXTI_EdgeType  				Copy_u8Edge;
EXTI_RequestType      Copy_u8Request;
	if(Copy_Conf !=NULL)
		{
			Copy_u8Pin=Copy_Conf->Pin;
			Copy_u8Request=Copy_Conf->Request;
			Copy_u8Edge =Copy_Conf->Edge;
			/*set request Option:

														EXTI_Interrupt,
														EXTI_Event
			
			*/
			switch(Copy_u8Request)
			{
				case EXTI_Event:
					SET_BIT (EXTI_EMR_REG,Copy_u8Pin);
					break;
				case EXTI_Interrupt:
					SET_BIT (EXTI_IMR_REG,Copy_u8Pin);					
				 break;
				default:
					//do nothing
					break;				
			}	
			/*set request Edge:
														EXTI_None,	 if choose it,then you may want to SW Trigger ---> with function SW Trigger
														EXTI_Falling,
														EXTI_Rising,
														EXTI_Falling_Rising
	   */
			switch(Copy_u8Edge)
			{
				case EXTI_Falling:
					SET_BIT (EXTI_FTSR_REG,Copy_u8Pin);
					CLEAR_BIT(EXTI_RTSR_REG,Copy_u8Pin);
				break;
				case EXTI_Rising:
					SET_BIT (EXTI_RTSR_REG,Copy_u8Pin);
					CLEAR_BIT(EXTI_FTSR_REG,Copy_u8Pin);
				break;
				case EXTI_Falling_Rising:
					SET_BIT (EXTI_RTSR_REG,Copy_u8Pin);
					SET_BIT(EXTI_FTSR_REG,Copy_u8Pin);
				break;
				default:
					CLEAR_BIT (EXTI_RTSR_REG,Copy_u8Pin);
					CLEAR_BIT(EXTI_FTSR_REG,Copy_u8Pin);
				break;				
			}
			
		}else
		{

		LOC_Errorstate = NOK;
		}


return LOC_Errorstate ;

}



ErrorStatus EXTI_enumEnableInterrupt (EXTI_PinType Copy_u8Pin){
ErrorStatus LOC_Errorstate =OK;

			if(Copy_u8Pin < EXTI_Max_Number)
			{
			SET_BIT (EXTI_IMR_REG,Copy_u8Pin);
			}else
			{
				LOC_Errorstate = NOK;
			}

return LOC_Errorstate ;
}

ErrorStatus EXTI_enumDisableInterrupt (EXTI_PinType Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				CLEAR_BIT (EXTI_IMR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;
}
ErrorStatus EXTI_enumEnableEvent 		  (EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				SET_BIT (EXTI_EMR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;
}
ErrorStatus EXTI_enumDisableEvent		  (EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				CLEAR_BIT (EXTI_EMR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;

}

ErrorStatus EXTI_enumSetSWTrigger 		(EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				SET_BIT (EXTI_SWIER_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;

}
ErrorStatus EXTI_enumSetRisingTrigger (EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				SET_BIT (EXTI_RTSR_REG,Copy_u8Pin);
				CLEAR_BIT	(EXTI_FTSR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;

}
ErrorStatus EXTI_enumSetFallingTrigger(EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				SET_BIT (EXTI_FTSR_REG,Copy_u8Pin);
				CLEAR_BIT	(EXTI_RTSR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;
}
ErrorStatus EXTI_enumSetBothEdgesTrigger(EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				SET_BIT (EXTI_FTSR_REG,Copy_u8Pin);
				SET_BIT	(EXTI_RTSR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;
}

ErrorStatus EXTI_enumClearSWTrigger 		(EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				CLEAR_BIT (EXTI_SWIER_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;

}
ErrorStatus EXTI_enumClearRisingTrigger (EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				CLEAR_BIT (EXTI_RTSR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;

}
ErrorStatus EXTI_enumClearFallingTrigger(EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				CLEAR_BIT (EXTI_FTSR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;
}

ErrorStatus EXTI_enumClearFlag        (EXTI_PinType   Copy_u8Pin)
{
	ErrorStatus LOC_Errorstate =OK;

				if(Copy_u8Pin < EXTI_Max_Number)
				{
				SET_BIT (EXTI_PR_REG,Copy_u8Pin);
				}else
				{
					LOC_Errorstate = NOK;
				}

	return LOC_Errorstate ;
}

u8 EXTI_u8GetFlag(EXTI_PinType Copy_u8Pin)
{
	return GET_BIT(EXTI_PR_REG,Copy_u8Pin);
}

void EXTI_voidSetCallBack (void (* EXTI_ptrvoidCopyCallBack) (void),EXTI_PinType Copy_u8Pin)
{
		if(EXTI_ptrvoidCopyCallBack != NULL)
		{
			if(Copy_u8Pin < EXTI_Max_Number)
			{
			EXTI_CallBack[Copy_u8Pin]=EXTI_ptrvoidCopyCallBack;
			}

		}
}
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

void EXTI0_IRQHandler(void)
	{
	
	if(EXTI_CallBack[EXTI_Pin_0] != NULL)
		  {
			EXTI_CallBack[0]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_0);
			}
	}
void EXTI1_IRQHandler(void)
	{
	
	if(EXTI_CallBack[EXTI_Pin_1] != NULL)
		  {
			EXTI_CallBack[1]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_1);
			}
	}
void EXTI2_IRQHandler(void)
	{
	
	if(EXTI_CallBack[EXTI_Pin_2] != NULL)
		  {
			EXTI_CallBack[2]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_2);
			}
	}

void EXTI3_IRQHandler(void)
	{
	
	if(EXTI_CallBack[EXTI_Pin_3] != NULL)
		  {
			EXTI_CallBack[3]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_3);
			}
	}	
void EXTI4_IRQHandler(void)
	{
	
	if(EXTI_CallBack[EXTI_Pin_4] != NULL)
		  {
			EXTI_CallBack[4]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_4);
			}
	}
void EXTI9_5_IRQHandler(void)
	{
	
	if (GET_BIT(EXTI_PR_REG,EXTI_Pin_5))
		  {
			EXTI_CallBack[5]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_5);
			}
	if (GET_BIT(EXTI_PR_REG,EXTI_Pin_6))
		  {
			EXTI_CallBack[6]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_6);
			}
		if (GET_BIT(EXTI_PR_REG,EXTI_Pin_7))
		  {
			EXTI_CallBack[7]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_7);
			}		
		if (GET_BIT(EXTI_PR_REG,EXTI_Pin_8))
		  {
			EXTI_CallBack[8]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_8);
			}
		if (GET_BIT(EXTI_PR_REG,EXTI_Pin_9))
		  {
			EXTI_CallBack[9]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_9);
			}
		
	}

void EXTI15_10_IRQHandler(void)
	{
	
	if (GET_BIT(EXTI_PR_REG,EXTI_Pin_10))
		  {
			EXTI_CallBack[10]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_10);
			}
	if (GET_BIT(EXTI_PR_REG,EXTI_Pin_11))
		  {
			EXTI_CallBack[11]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_11);
			}
		if (GET_BIT(EXTI_PR_REG,EXTI_Pin_12))
		  {
			EXTI_CallBack[12]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_12);
			}		
		if (GET_BIT(EXTI_PR_REG,EXTI_Pin_13))
		  {
			EXTI_CallBack[13]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_13);
			}
		if (GET_BIT(EXTI_PR_REG,EXTI_Pin_14))
		  {
			EXTI_CallBack[14]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_14);
			}
		if (GET_BIT(EXTI_PR_REG,EXTI_Pin_15))
		  {
			EXTI_CallBack[15]();
			SET_BIT(EXTI_PR_REG,EXTI_Pin_15);
			}
	}
void PVD_IRQHandler(void)
	{
	
	if(EXTI_CallBack[EXTI_PVD_output] != NULL)
		  {
			EXTI_CallBack[EXTI_PVD_output]();
			SET_BIT(EXTI_PR_REG,EXTI_PVD_output);
			}
	}
void RTCAlarm_IRQHandler(void)
	{
	
	if(EXTI_CallBack[EXTI_RTC_Alarm_Event] != NULL)
		  {
			EXTI_CallBack[EXTI_RTC_Alarm_Event]();
			SET_BIT(EXTI_PR_REG,EXTI_RTC_Alarm_Event);
			}
	}	
	
void USBWakeUp_IRQHandler(void)
	{
	
	if(EXTI_CallBack[EXTI_USB_Wakeup_Event] != NULL)
		  {
			EXTI_CallBack[EXTI_USB_Wakeup_Event]();
			SET_BIT(EXTI_PR_REG,EXTI_USB_Wakeup_Event);
			}
	}	

	

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/


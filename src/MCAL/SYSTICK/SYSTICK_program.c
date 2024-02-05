
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  NVIC_program.c
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
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void (*SYSTICK_puCallBackFunction)(void)=NULL;
/* Define Variable for state */
static u8 SYSTICK_u8State=IDLE;
/* Define Variable for interval mode */
static u8 SYSTICK_u8ModeOfInterval;
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
void SYSTICK_voidInit(){
/*SYSTICK_CLC_SRC*/

#if SYSTICK_CLK_SRC == SYSTICK_CLK_SRC_SYSTEM_CLOCK
		SET_BIT(SYSTICK_STCTRL_REG,STCTRL_CLK_SRC_BIT);
#elif SYSTICK_INTERRUPT == SYSTICK_CLK_SRC_PIOSC_DIVIDED_BY_4
		CLEAR_BIT(SYSTICK_STCTRL_REG,STCTRL_CLK_SRC_BIT);
#else
#error "Wrong SYSTICK_INTURRUPT Config"
#endif


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
void SYSTICK_voidDesable(){
		CLEAR_BIT(SYSTICK_STCTRL_REG,STCTRL_INTEN_BIT);		
		CLEAR_BIT(SYSTICK_STCTRL_REG,STCTRL_ENABLE_BIT);
		SYSTICK_STCURRENT_REG=0;
		SYSTICK_STRELOAD_REG=0;
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
void SYSTICK_voidSetPreload	 (u32  Copy_u32PreloadVal){

SYSTICK_STRELOAD_REG=Copy_u32PreloadVal;

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

ErrorStatus SYSTICK_enumGetCounterVal(u32 *Copy_u32CounterVal){
ErrorStatus LOC_ErrorState= OK;
			if(Copy_u32CounterVal != NULL)
			{
					*Copy_u32CounterVal=SYSTICK_STCURRENT_REG;
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
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/ 

ErrorStatus SYSTICK_enumSetBusyWait(u32 Copy_u32CounterVal){
ErrorStatus LOC_ErrorState= OK;
		if(SYSTICK_u8State == IDLE)
		{
				SYSTICK_u8State=BUSY;
				/*SET_PRELOAD_VAL*/
				SYSTICK_STCURRENT_REG=0;
				SYSTICK_STRELOAD_REG=Copy_u32CounterVal;
				/*SYSTICK_ENABLE*/
				SET_BIT(SYSTICK_STCTRL_REG,STCTRL_ENABLE_BIT);
				while(GET_BIT(SYSTICK_STCTRL_REG,STCTRL_COUNT_BIT)==0 ){
				//do nothing
				}

				/*SYSTICK_DISABLE*/
				CLEAR_BIT(SYSTICK_STCTRL_REG,STCTRL_ENABLE_BIT);
				SYSTICK_STCURRENT_REG=0;
				SYSTICK_STRELOAD_REG=0;
				SYSTICK_u8State=IDLE;


		}

		else
		{
			LOC_ErrorState=Busy_State;
		}
return LOC_ErrorState;

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
ErrorStatus SYSTICK_enumSetIntervalSingle(u32 Copy_u32CounterVal,void (*Copy_puCallBackFunc)(void)){
ErrorStatus LOC_ErrorState= OK;
	if(Copy_puCallBackFunc != NULL){
		if(SYSTICK_u8State == IDLE)
		{
				SYSTICK_u8State=BUSY;
				/*INTERRUPT_ENABLE*/
				SET_BIT(SYSTICK_STCTRL_REG,STCTRL_INTEN_BIT);		
				/*SET_PRELOAD_VAL*/
				SYSTICK_STCURRENT_REG=0;
				SYSTICK_STRELOAD_REG=Copy_u32CounterVal;
				/*SYSTICK_ENABLE*/
				SET_BIT(SYSTICK_STCTRL_REG,STCTRL_ENABLE_BIT);
				SYSTICK_puCallBackFunction=Copy_puCallBackFunc;
				SYSTICK_u8ModeOfInterval=SYSTICK_SINGLE_INTERVAL;
				
		}
 
		else
		{
			LOC_ErrorState=Busy_State;
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
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/ 

ErrorStatus SYSTICK_enumSetIntervalPeriodic  (u32 Copy_u32CounterVal,void (*Copy_puCallBackFunc)(void)){
ErrorStatus LOC_ErrorState= OK;
	if(Copy_puCallBackFunc != NULL){
		if(SYSTICK_u8State == IDLE)
		{
				SYSTICK_u8State=BUSY;
				/*INTERRUPT_ENABLE*/
				SET_BIT(SYSTICK_STCTRL_REG,STCTRL_INTEN_BIT);		
				/*SET_PRELOAD_VAL*/
				SYSTICK_STCURRENT_REG=0;
				SYSTICK_STRELOAD_REG=Copy_u32CounterVal;
				/*SYSTICK_ENABLE*/
				SET_BIT(SYSTICK_STCTRL_REG,STCTRL_ENABLE_BIT);
				SYSTICK_puCallBackFunction=Copy_puCallBackFunc;
				SYSTICK_u8ModeOfInterval=SYSTICK_PERIODIC_INTERVAL;
				
		}
 
		else
		{
			LOC_ErrorState=Busy_State;
		}

		}
		else
		{
			LOC_ErrorState=NOK;
		}

	return LOC_ErrorState;
}



void SysTick_Handler(void){
 if(SYSTICK_puCallBackFunction != NULL){
		if(SYSTICK_u8ModeOfInterval == SYSTICK_SINGLE_INTERVAL)
		{	
		
		SYSTICK_voidDesable();

		}

  	SYSTICK_puCallBackFunction();
		SYSTICK_u8State=IDLE;

		}
 }
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/









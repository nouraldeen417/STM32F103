
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
#include "RTC_interface.h"
#include "RTC_Conf.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define COUNTS_FOR_1_YEAR		 0xFE1ECC7F
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static void (* RTC_pvoidCallBackFunc) (void)={NULL};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

//static u32 RTC_GetCounterVal()
//{
//u32 temp= (RTC_SECOUND + (RTC_MINUTES*60) + (RTC_HOURS*60*60) );
//temp+=(((RTC_DAYS*24)+(RTC_MONTHS*30*24))*60*60);31,536,000
// FE1ECC7F	
//	return temp;
//}
void RTC_voidInit(void)
{

	while(!GET_BIT(RTC_CRL,CRL_RTOFF_BIT)); // Poll RTOFF, wait until its value goes to ‘1’
	SET_BIT(RTC_CRL,CRL_CNF_BIT);	//Set the CNF bit to enter configuration mode
	/*Write to one or more RTC registers Here*/
	RTC_PRLL=((RTC_PRESCALER & 0xFFFF)-1);
	RTC_PRLH=((RTC_PRESCALER>>16) & 0x0F);

	RTC_CNTL=0;
	RTC_CNTH=0;
	CLEAR_BIT(RTC_CRL,CRL_CNF_BIT);//Clear the CNF bit to exit configuration mode
	while(!GET_BIT(RTC_CRL,CRL_RTOFF_BIT));//Poll RTOFF, wait until its value goes to ‘1’ to check the end of the write operation.
}
void RTC_voidSetTimeandDate(RTC_ConfType *Copy_conf)
{
	u32 Copy_u32CounterVal=0;
	if(Copy_conf!=NULL)
	{

		Copy_u32CounterVal= TIME_CALC(Copy_conf->Seconds,Copy_conf->Minutes,Copy_conf->Hours,Copy_conf->Days);
		while(!GET_BIT(RTC_CRL,CRL_RTOFF_BIT)); // Poll RTOFF, wait until its value goes to ‘1’
		SET_BIT(RTC_CRL,CRL_CNF_BIT);	//Set the CNF bit to enter configuration mode
		/*Write to one or more RTC registers Here*/
		RTC_CNTL=( Copy_u32CounterVal   		 & 0xFFFF);
		RTC_CNTH=((Copy_u32CounterVal  >>16) & 0xFFFF);
		CLEAR_BIT(RTC_CRL,CRL_CNF_BIT);//Clear the CNF bit to exit configuration mode
		while(!GET_BIT(RTC_CRL,CRL_RTOFF_BIT));//Poll RTOFF, wait until its value goes to ‘1’ to check the end of the write operation.
	}

}

void RTC_voidGetTimeandDate(RTC_ConfType *Copy_conf )
{
u32 Copy_counterVal = ( (RTC_CNTH<<16) | (RTC_CNTL) );
	if(Copy_conf != NULL)
	{
		Copy_conf->Seconds  =( Copy_counterVal 	% 60);
		Copy_conf->Minutes  =( (Copy_counterVal 	/60   ) % 60);
		Copy_conf->Hours    =( (Copy_counterVal   /3600 ) % 24);	
		Copy_conf->Days     =(Copy_counterVal   /(3600*24) ) ;
	}
}
void RTC_voidSetAlarmTime  (RTC_ConfType *Copy_conf,void (* Copy_pvoidCallBackFunc) (void))
{

u32		Copy_u32CounterVal= TIME_CALC(Copy_conf->Seconds,Copy_conf->Minutes,Copy_conf->Hours,Copy_conf->Days);
	  RTC_pvoidCallBackFunc=Copy_pvoidCallBackFunc;
  	while(!GET_BIT(RTC_CRL,CRL_RTOFF_BIT)); // Poll RTOFF, wait until its value goes to ‘1’
		SET_BIT(RTC_CRL,CRL_CNF_BIT);	//Set the CNF bit to enter configuration mode
		/*Write to one or more RTC registers Here*/
		RTC_ALRL=( Copy_u32CounterVal   		 & 0xFFFF);
		RTC_ALRH=((Copy_u32CounterVal  >>16) & 0xFFFF);
		CLEAR_BIT(RTC_CRL,CRL_CNF_BIT);//Clear the CNF bit to exit configuration mode
		while(!GET_BIT(RTC_CRL,CRL_RTOFF_BIT));//Poll RTOFF, wait until its value goes to ‘1’ to check the end of the write operation.
		SET_BIT(RTC_CRH,CRH_ALRIE_BIT);
}
void RTC_IRQHandler(void)
{
	RTC_pvoidCallBackFunc();
	CLEAR_BIT(RTC_CRL,CRL_ALRF_BIT);
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
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/









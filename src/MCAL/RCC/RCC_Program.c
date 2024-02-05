
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
#include "RCC_interface.h"
#include "RCC_Conf.h"

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
ErrorStatus RCC_voidEnableClock(u8 Copy_u8Peripheral )
{
	ErrorStatus Loc_Err=OK;
	if(Copy_u8Peripheral < RCC_APB1_MAX_BIT)
	{
		SET_BIT(RCC_APB1ENR,Copy_u8Peripheral);
	}else if(Copy_u8Peripheral < RCC_APB2_MAX_BIT)
	{	
		Copy_u8Peripheral-=RCC_APB1_MAX_BIT;			// to get required Bit 0:31
		SET_BIT(RCC_APB2ENR,Copy_u8Peripheral);	
	}else if(Copy_u8Peripheral < RCC_AHB_MAX_BIT)
	{
		Copy_u8Peripheral-=RCC_APB2_MAX_BIT;			// to get required Bit 0:31
		SET_BIT(RCC_AHBENR,Copy_u8Peripheral);
	}else 
	{
	 Loc_Err =NOK;
	}
	
return Loc_Err;
}
ErrorStatus RCC_voidDisableClock(u8 Copy_u8Peripheral )
{
	ErrorStatus Loc_Err=OK;
	if(Copy_u8Peripheral < RCC_APB1_MAX_BIT)
	{
		CLEAR_BIT(RCC_APB1ENR,Copy_u8Peripheral);
	}else if(Copy_u8Peripheral < RCC_APB2_MAX_BIT)
	{	
		Copy_u8Peripheral-=RCC_APB1_MAX_BIT;			// to get required Bit 0:31
		CLEAR_BIT(RCC_APB2ENR,Copy_u8Peripheral);	
	}else if(Copy_u8Peripheral < RCC_AHB_MAX_BIT)
	{
		Copy_u8Peripheral-=RCC_APB2_MAX_BIT;			// to get required Bit 0:31
		CLEAR_BIT(RCC_AHBENR,Copy_u8Peripheral);
	}else 
	{
	 Loc_Err =NOK;
	}
	
return Loc_Err;

}
ErrorStatus RCC_voidRest(u8 Copy_u8Peripheral )
{
	ErrorStatus Loc_Err=OK;
	if(Copy_u8Peripheral < RCC_APB1_MAX_BIT)
	{
		SET_BIT(RCC_APB1RSTR,Copy_u8Peripheral);
	}else if(Copy_u8Peripheral < RCC_APB2_MAX_BIT)
	{	
		Copy_u8Peripheral-=RCC_APB1_MAX_BIT;			// to get required Bit 0:31
		SET_BIT(RCC_APB2RSTR,Copy_u8Peripheral);	
	}else if(Copy_u8Peripheral < RCC_AHB_MAX_BIT)
	{
		Copy_u8Peripheral-=RCC_APB2_MAX_BIT;			// to get required Bit 0:31
		SET_BIT(RCC_AHBRSTR,Copy_u8Peripheral);
	}else 
	{
	 Loc_Err =NOK;
	}
	
return Loc_Err;
}

void RCC_voidRTCEnableClock(void)
{
#if (RTC_CLOCK == RTC_LSIClock)
	// RTC clock source selection
	CLEAR_BIT(RCC_BDCR,BDCR_RTCSEL_0_BIT);
	SET_BIT(RCC_BDCR,BDCR_RTCSEL_1_BIT);
	//Internal RC 40 kHz oscillator ON
	SET_BIT(RCC_CSR,CSR_LSION_BIT); 	
	// wait till internal RC 40 kHz oscillator is stable
	while(!GET_BIT(RCC_CSR,CSR_LSIRDY_BIT));
#elif (RTC_CLOCK == RTC_LSEClock)
	// RTC clock source selection
	CLEAR_BIT(RCC_BDCR,BDCR_RTCSEL_1_BIT);
	SET_BIT  (RCC_BDCR,BDCR_RTCSEL_0_BIT);
	//External 32 kHz oscillator ON
	SET_BIT(RCC_CSR,BDCR_LSEON_BIT); 	
	// wait till External 32 kHz oscillator is stable
	while(!GET_BIT(RCC_CSR,BDCR_LSERDY_BIT));
#endif

	SET_BIT(RCC_BDCR,BDCR_RTCEN_BIT);
}
void RCC_voidRTCDisable(void)
{
	CLEAR_BIT(RCC_BDCR,BDCR_RTCEN_BIT);
}
ErrorStatus RCC_voidADCSetPresacaler(RTC_PrescalerType Copy_u8Psc )
{

RCC_CFGR &= ~((0x3)<<14);
RCC_CFGR |=  ((Copy_u8Psc & 0x03)<<14);

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









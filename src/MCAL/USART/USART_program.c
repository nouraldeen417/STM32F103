

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*
 * File:   USART_program.c
 * Author: nour
 *
 * Created on September 22, 2023, 2:53 PM
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/*Global pointer to function to carry the notification function called by ISR*/
static void (*USART_pvNotificationFunc)(void) = NULL;

/*Global pointer to carry the String called by ISR*/
static const u16 *USART_pu16SendData = NULL;

/*Global pointer to carry the String called by ISR*/
static u16 *USART_pu16RecieveData = NULL;

/*Global Counter for the USART Sending String*/
static u8 USART_u8Index = 0;

/*Global Counter for the USART Sending String*/
static u8 USART_u8BufferSize = 0;

/*Global flag for the USART Busy State*/
static u8 USART_u8STATE = IDLE;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
static ErrorStatus USART_enumGetBaseAddress (u8 Copy_Id,u32* Copy_BaseAdd)
{
ErrorStatus Loc_Err=OK;
	//select Usart ID
		switch (Copy_Id)
			{
				case USART_Id_1:
					*Copy_BaseAdd = (u32)USART_1_BASE_ADD;
					break;
				case USART_Id_2:
					*Copy_BaseAdd = (u32)USART_2_BASE_ADD;
					break;
				default:
					Loc_Err=NOK;
					break;
			}
return Loc_Err;
}

ErrorStatus   USART_enumInitConfig (USART_confType* Copy_Conf)
{
ErrorStatus Loc_Err=OK;
u32 Base_ADD=0;
	if(Copy_Conf != NULL)
	{	
		//select Usart ID
		
		USART_enumGetBaseAddress (Copy_Conf->USART_Id, &Base_ADD);
		/*Set mode
		
			//--Here
		*/
		//Set Data length
		if(Copy_Conf->USART_DataLength == USART_DATA_9_BITS)
		{
		 SET_BIT(USART_CR1(Base_ADD),CR1_M_BIT);
		}else
		{
		 CLEAR_BIT(USART_CR1(Base_ADD),CR1_M_BIT);		
		}
		//Set Stop Bits
		USART_CR2(Base_ADD)&=~(0xF000);
		USART_CR2(Base_ADD)|= (Copy_Conf->USART_StopBits & 0x03)<<12;		
		//set parity
		if(Copy_Conf->USART_ParitySelect == USART_Even_Parity)
		{
		 SET_BIT(USART_CR1(Base_ADD),CR1_PCE_BIT);
		 CLEAR_BIT(USART_CR1(Base_ADD),CR1_PS_BIT);		
		}else if(Copy_Conf->USART_ParitySelect == USART_Odd_Parity)
		{
		 SET_BIT(USART_CR1(Base_ADD),CR1_PCE_BIT);
		 SET_BIT(USART_CR1(Base_ADD),CR1_PS_BIT);
		}else
		{
		 CLEAR_BIT(USART_CR1(Base_ADD),CR1_PCE_BIT);		
		}
		
		//Set Boud Rate conf
		USART_BRR(Base_ADD) = ((Copy_Conf->USART_u16DivMantissa<<4) | (Copy_Conf->USART_u8DivFraction)) ;	
	  //Enable USART
		SET_BIT(USART_CR1(Base_ADD),CR1_UE_BIT);
	}else
	{
		Loc_Err = NOK; 		
	}

return Loc_Err;
}
ErrorStatus   USART_enumSendData (u8 Copy_Id,u16 Copy_u16Data)
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u32 LOC_u32TimeOutCounter =0;	
	USART_enumGetBaseAddress(Copy_Id,& Base_ADD);	
		if(GET_BIT(USART_SR(Base_ADD),SR_IDLE_BIT) == 0)
		{			
					SET_BIT(USART_CR1(Base_ADD),CR1_TE_BIT);
					/*Wait until  (UDR) is ready to receive new data*/
					while ((GET_BIT(USART_SR(Base_ADD),SR_TC_BIT) == 0) && LOC_u32TimeOutCounter < USART_TIME_OUT)
					{
							LOC_u32TimeOutCounter++;
					}
					if (LOC_u32TimeOutCounter == USART_TIME_OUT)
					{
							Loc_Err = Time_OUT_State;
					}
					else
					{
							USART_DR(Base_ADD) = Copy_u16Data;					
					}		
		}else
		{
			Loc_Err = Busy_State; 		
		}

	return Loc_Err;
}
ErrorStatus   USART_enumRecevieData (u8 Copy_Id,u16 * Copy_u16ReceviedData) 
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u32 LOC_u32TimeOutCounter =0;	
	USART_enumGetBaseAddress(Copy_Id,& Base_ADD);	
		if(GET_BIT(USART_SR(Base_ADD),SR_IDLE_BIT) == 0)
		{			
					SET_BIT(USART_CR1(Base_ADD),CR1_RE_BIT);
					/*Wait until  (UDR) is ready to receive new data*/
					while ((GET_BIT(USART_SR(Base_ADD),SR_RXNE_BIT) == 0) && LOC_u32TimeOutCounter < USART_TIME_OUT)
					{
							LOC_u32TimeOutCounter++;
					}
					if (LOC_u32TimeOutCounter == USART_TIME_OUT)
					{
							Loc_Err = Time_OUT_State;
					}
					else
					{
							*Copy_u16ReceviedData = USART_DR(Base_ADD) ;					  
					}		
		}else
		{
			Loc_Err = Busy_State; 		
		}

	return Loc_Err;

}
ErrorStatus   USART_enumSendBufferSync    ( USART_BufferType *Copy_BufferConf)
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u8 LOC_u8Iterator = 0;	
	
	if(Copy_BufferConf != NULL)
	{			
					USART_enumGetBaseAddress(Copy_BufferConf->USART_Id,& Base_ADD);
					for(LOC_u8Iterator = 0; LOC_u8Iterator < Copy_BufferConf->USART_u8BufferSize;LOC_u8Iterator ++)
					{
						
						Loc_Err=USART_enumSendData(Copy_BufferConf->USART_Id,Copy_BufferConf->USART_pu16Data[LOC_u8Iterator]);
						if(Loc_Err == OK)
						 {
						  //do nothing...
						 }else
						 {
								break;
						 }
					}
					CLEAR_BIT(USART_CR1(Base_ADD),CR1_TE_BIT);										
	}else
		{
			Loc_Err = Busy_State; 		
		}

	return Loc_Err;
}
ErrorStatus   USART_enumRecieveBufferSync ( USART_BufferType *Copy_BufferConf)
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u8 LOC_u8Iterator = 0;	
	
	if(Copy_BufferConf != NULL)
	{			
					USART_enumGetBaseAddress(Copy_BufferConf->USART_Id,& Base_ADD);
					for(LOC_u8Iterator = 0; LOC_u8Iterator < Copy_BufferConf->USART_u8BufferSize;LOC_u8Iterator ++)
					{
						
						Loc_Err=USART_enumRecevieData(Copy_BufferConf->USART_Id,&Copy_BufferConf->USART_pu16Data[LOC_u8Iterator]);
						if(Loc_Err == OK)
						 {
						  //do nothing...
						 }else
						 {
								break;
						 }
					}
					CLEAR_BIT(USART_CR1(Base_ADD),CR1_RE_BIT);					
	}else
		{
			Loc_Err = Busy_State; 		
		}

	return Loc_Err;
}

ErrorStatus   USART_enumSendBufferASync   ( USART_BufferType *Copy_BufferConf)
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u32 LOC_u32TimeOutCounter =0;	
	USART_enumGetBaseAddress(Copy_BufferConf->USART_Id,& Base_ADD);	
		if(GET_BIT(USART_SR(Base_ADD),SR_IDLE_BIT) == 0)
		{			
			    if(Copy_BufferConf											!= NULL &&
						 Copy_BufferConf->USART_pvNotifaction != NULL &&
						 Copy_BufferConf->USART_pu16Data      != NULL)
					{
						USART_u8Index = 0;
						SET_BIT(USART_CR1(Base_ADD),CR1_TE_BIT);														/*Enable transimition */	
						USART_u8BufferSize = Copy_BufferConf->USART_u8BufferSize;						/*Save Buffer size in the global variable to use in isr */	
						USART_pu16SendData = Copy_BufferConf->USART_pu16Data;								/*Save data pointer in the global pointer to use in isr */
						USART_pvNotificationFunc = Copy_BufferConf->USART_pvNotifaction;		/*Save Notification pointer in the global pointer to use in isr */
						USART_DR(Base_ADD) = Copy_BufferConf->USART_pu16Data[USART_u8Index];/*Set first item in buffer in DR Reg */					  
						SET_BIT(USART_CR1(Base_ADD),CR1_TCIE_BIT);													/*Enable TXEIE interrupt*/ 		
					}
		}else
		{
			Loc_Err = Busy_State; 		
		}

	return Loc_Err;

} 
ErrorStatus   USART_enumRecieveBufferASync( USART_BufferType *Copy_BufferConf)
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u32 LOC_u32TimeOutCounter =0;	
	USART_enumGetBaseAddress(Copy_BufferConf->USART_Id,& Base_ADD);	
		if(GET_BIT(USART_SR(Base_ADD),SR_IDLE_BIT) == 0)
		{			
			    if(Copy_BufferConf											!= NULL &&
						 Copy_BufferConf->USART_pvNotifaction != NULL &&
						 Copy_BufferConf->USART_pu16Data      != NULL)
					{
						USART_u8Index = 0;
						SET_BIT(USART_CR1(Base_ADD),CR1_RE_BIT);														/*Enable receiver */	
						USART_u8BufferSize = Copy_BufferConf->USART_u8BufferSize;						/*Save Buffer size in the global variable to use in isr */	
						USART_pu16RecieveData = Copy_BufferConf->USART_pu16Data;						/*Save data pointer in the global pointer to use in isr */
						USART_pvNotificationFunc = Copy_BufferConf->USART_pvNotifaction;		/*Save Notification pointer in the global pointer to use in isr */
						SET_BIT(USART_CR1(Base_ADD),CR1_RXNEIE_BIT);												/*Enable RXNEIE interrupt*/ 		
					 
					}
		}else
		{
			Loc_Err = Busy_State; 		
		}

	return Loc_Err;
}

ErrorStatus   USART_enumGetErrorState(u8 Copy_Id , u8* Copy_Errors)
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	USART_enumGetBaseAddress(Copy_Id,& Base_ADD);	
		if(GET_BIT(USART_SR(Base_ADD),SR_PE_BIT))
		{	
			Loc_Err=NOK;		
			Copy_Errors[Parity_Error]=1;
		}
		if(GET_BIT(USART_SR(Base_ADD),SR_ORE_BIT))
		{			
			Loc_Err=NOK;
			Copy_Errors[Overrun_Error]=1;
		}
		if(GET_BIT(USART_SR(Base_ADD),SR_FE_BIT))
		{			
			Loc_Err=NOK;
			Copy_Errors[Framing_Error]=1;
		}
		if(GET_BIT(USART_SR(Base_ADD),SR_NE_BIT))
		{			
			Loc_Err=NOK;
			Copy_Errors[Noise_Error]=1;
		}		

	return Loc_Err;
}
void USART_voidDisable(u8 Copy_Id)
{
	u32 Base_ADD=0;		
	USART_enumGetBaseAddress (Copy_Id, &Base_ADD);
	//Disable USART
	CLEAR_BIT(USART_CR1(Base_ADD),CR1_UE_BIT);
}

ErrorStatus   USART_enumSendData_DMA (DMA_confType *Copy_Conf,u8 Copy_Id,u8 *Copy_u8TData,u8 Copy_u8Size)
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u32 LOC_u32Counter =0;	
	USART_enumGetBaseAddress(Copy_Id,& Base_ADD);	
		if(GET_BIT(USART_SR(Base_ADD),SR_IDLE_BIT) == 0)
		{	
			//Set Dma Configration
			DMA_enumInitConfig(Copy_Conf);		
			//Set Data in Memory Address 
			if(Copy_u8TData != NULL)
			{
				for(LOC_u32Counter=0 ; LOC_u32Counter < Copy_u8Size;LOC_u32Counter++)
				{
					*((u8 *)(Copy_Conf->Copy_u32Memory_AddressReg+LOC_u32Counter))= Copy_u8TData[LOC_u32Counter];
				}
			}
			//Enable DMAT in UART
			SET_BIT(USART_CR3(Base_ADD),CR3_DMAT_BIT);
			CLEAR_BIT(USART_SR(Base_ADD),SR_TC_BIT);
			//Enable DMA Channel 
			DMA_enumEnable(Copy_Conf->Channel_Id);
			//Enable Transmition
			SET_BIT(USART_CR1(Base_ADD),CR1_TE_BIT);			
		}else
		{
			Loc_Err = Busy_State; 		
		}

	return Loc_Err;
}
ErrorStatus   USART_enumRecevieData_DMA (DMA_confType *Copy_Conf,u8 Copy_Id) 
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u32 LOC_u32TimeOutCounter =0;	
	USART_enumGetBaseAddress(Copy_Id,& Base_ADD);	
		if(GET_BIT(USART_SR(Base_ADD),SR_IDLE_BIT) == 0)
		{			
			//Set Dma Configration
			DMA_enumInitConfig(Copy_Conf);		
			SET_BIT(USART_CR3(USART_2_BASE_ADD),CR3_DMAR_BIT);
			SET_BIT(USART_CR1(Base_ADD),CR1_RE_BIT);
			//Enable DMA Channel 
			DMA_enumEnable(Copy_Conf->Channel_Id);					
		}else
		{
			Loc_Err = Busy_State; 		
		}
	return Loc_Err;
}




ErrorStatus   USART_enumWait_TC_Flag          (u8 Copy_Id) 
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u32 LOC_u32TimeOutCounter =0;	
	USART_enumGetBaseAddress(Copy_Id,& Base_ADD);	
	if(Copy_Id < USART_Id_MAX)
	{			
				/*Wait until  (UDR) is ready to receive new data*/
				while ((GET_BIT(USART_SR(Base_ADD),SR_TC_BIT) == 0) && LOC_u32TimeOutCounter < USART_TIME_OUT)
				{
						LOC_u32TimeOutCounter++;
				}
				if (LOC_u32TimeOutCounter == USART_TIME_OUT)
				{
						Loc_Err = Time_OUT_State;
				}
				else
				{

				}	

	}else
	{
		Loc_Err =NOK;
	}
return Loc_Err;
}
void USART1_IRQHandler(void)
{
 if(GET_BIT(USART_SR(USART_1_BASE_ADD),SR_RXNE_BIT) )
	{												
	  if(USART_pu16RecieveData != NULL)
		{
			USART_pu16RecieveData[USART_u8Index] = (USART_DR(USART_1_BASE_ADD) ) ; /*Read Data buffer From DR Reg */					  							
			USART_u8Index++;		
			if(USART_u8Index == USART_u8BufferSize)
			{
				USART_u8Index=0;
			  CLEAR_BIT(USART_CR1(USART_1_BASE_ADD),CR1_RE_BIT);									
				CLEAR_BIT(USART_CR1(USART_1_BASE_ADD),CR1_RXNEIE_BIT);						
				USART_pvNotificationFunc();
			}else 
			{
			}
		}
	}
	if(GET_BIT(USART_SR(USART_1_BASE_ADD),SR_TC_BIT))
	{						
		if(USART_pu16SendData != NULL)
		{
			USART_u8Index ++;		
			if(USART_u8Index == USART_u8BufferSize)
			{
					CLEAR_BIT(USART_CR1(USART_1_BASE_ADD),CR1_TE_BIT);									
					CLEAR_BIT(USART_CR1(USART_1_BASE_ADD),CR1_TCIE_BIT);							
  				USART_u8Index=0;
					USART_pvNotificationFunc();
			}else 
			{
					USART_DR(USART_1_BASE_ADD) = USART_pu16SendData[USART_u8Index]; /*Set the next item in buffer in DR Reg */					  			
			}
		}
	}

}
void USART2_IRQHandler(void)
{	
 if(GET_BIT(USART_SR(USART_2_BASE_ADD),SR_RXNE_BIT) )
	{												
	  if(USART_pu16RecieveData != NULL)
		{
			USART_pu16RecieveData[USART_u8Index] = (USART_DR(USART_2_BASE_ADD) ) ; /*Read Data buffer From DR Reg */					  							
			USART_u8Index++;		
			if(USART_u8Index == USART_u8BufferSize)
			{
				USART_u8Index=0;
			  CLEAR_BIT(USART_CR1(USART_2_BASE_ADD),CR1_RE_BIT);									
				CLEAR_BIT(USART_CR1(USART_2_BASE_ADD),CR1_RXNEIE_BIT);						
				USART_pvNotificationFunc();
			}else 
			{
			}
		}
	}
	if(GET_BIT(USART_SR(USART_2_BASE_ADD),SR_TC_BIT))
	{						
		if(USART_pu16SendData != NULL)
		{
			USART_u8Index ++;		
			if(USART_u8Index == USART_u8BufferSize)
			{
					CLEAR_BIT(USART_CR1(USART_2_BASE_ADD),CR1_TE_BIT);									
					CLEAR_BIT(USART_CR1(USART_2_BASE_ADD),CR1_TCIE_BIT);							
  				USART_u8Index=0;
					USART_pvNotificationFunc();
			}else 
			{
					USART_DR(USART_2_BASE_ADD) = USART_pu16SendData[USART_u8Index]; /*Set the next item in buffer in DR Reg */					  			
			}
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
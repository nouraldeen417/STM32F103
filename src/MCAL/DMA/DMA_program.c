

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*
 * File:   DMA_program.c
 * Author: nour
 *
 * Created on September 22, 2023, 2:53 PM
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

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
static void (*DMA_pvTCNotificationFunc[MAX_DMA_1_Channel_NUM])(void) = {NULL};
static void (*DMA_pvTENotificationFunc[MAX_DMA_1_Channel_NUM])(void) = {NULL};
static void (*DMA_pvHTNotificationFunc[MAX_DMA_1_Channel_NUM])(void) = {NULL};

/*Global pointer to carry the String called by ISR*/
static const u16 *DMA_pu16SendData = NULL;

/*Global pointer to carry the String called by ISR*/
static u16 *DMA_pu16RecieveData = NULL;

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
/*
DMA_ChannelType 									Channel_Id;
DMA_ModeType 											Copy_Mode;		
DMA_PriorityType									Copy_PL;	
DMA_PeripheralSizeType						Copy_PSIZE;
DMA_MemorySizeType								Copy_MSIZE;
DMA_PeripheralIncrementType				Copy_PINC;
DMA_MemoryIncrementType						Copy_MINC;
DMA_DataTransferType      				Copy_DIR;
u16														    Copy_u16Channel_NumReg;	                    // DMA channel number of data register
u32																Copy_u32Peripheral_AddressReg;							//DMA channel peripheral address register				
u32																Copy_u32Memory_AddressReg;									//DMA channel Memory address register				
void 													    (* DMA_pvTCNotifaction)(void)  ;						//Transfer complete interrupt enable
void 													    (* DMA_pvHTNotifaction)(void)  ;						//Half transfer interrupt enable 
void 													    (* DMA_pvTENotifaction)(void)  ;						//Transfer error interrupt enable	
*/
ErrorStatus   DMA_enumEnable       (DMA_ChannelType Copy_channel)
{
	ErrorStatus Loc_Err= OK;

	if(Copy_channel < MAX_DMA_1_Channel_NUM)
		{
    	SET_BIT(DMA_1_CCR(Copy_channel),CCR_EN_BIT);
		}else
		{
		  Loc_Err =NOK;
		}
 return Loc_Err;
}
ErrorStatus   DMA_enumDisable       (DMA_ChannelType Copy_channel)
{
	ErrorStatus Loc_Err= OK;

	if(Copy_channel < MAX_DMA_1_Channel_NUM)
		{
    	CLEAR_BIT(DMA_1_CCR(Copy_channel),CCR_EN_BIT);
		}else
		{
		  Loc_Err =NOK;
		}
 return Loc_Err;
}
ErrorStatus   DMA_enumInitConfig        (DMA_confType* Copy_Conf)
{
	ErrorStatus Loc_Err= OK;
	DMA_ChannelType Copy_channel = Copy_Conf->Channel_Id; 

	if(Copy_Conf != NULL)
	{
		if(Copy_channel < MAX_DMA_1_Channel_NUM)
		{
       //Set the peripheral register address			
				DMA_1_CPAR(Copy_channel)=Copy_Conf->Copy_u32Peripheral_AddressReg;
       //Set the Memory register address			
				DMA_1_CMAR(Copy_channel)=Copy_Conf->Copy_u32Memory_AddressReg;		
			 //Configure the total number of data to be transferred
				DMA_1_CNDTR(Copy_channel)=Copy_Conf->Copy_u16Channel_NumReg;
			 // Configure the channel priority	
				DMA_1_CCR(Copy_channel) |= ((Copy_Conf->Copy_PL & DMA_Very_High_Priority ) << CCR_PL_0_BIT);       //PL & 0x3
			 //Configure peripheral & memory data size
				DMA_1_CCR(Copy_channel) |= ((Copy_Conf->Copy_MSIZE & DMA_Rserved_Memory ) << CCR_MSIZE_0_BIT);     //MSIZE & 0x3		
				DMA_1_CCR(Copy_channel) |= ((Copy_Conf->Copy_PSIZE & DMA_Rserved_Peripheral ) << CCR_PSIZE_0_BIT); //PSIZE & 0x3
 			 // Configure data transfer direction		
  			if(Copy_Conf->Copy_DIR == DMA_Read_From_Memory)
				{
					SET_BIT(DMA_1_CCR(Copy_channel),CCR_DIR_BIT);
				}else if(Copy_Conf->Copy_DIR == DMA_Read_From_Memory)
				{
					CLEAR_BIT(DMA_1_CCR(Copy_channel),CCR_DIR_BIT);				
				}else
				{
					//
				}
			 //Configure circular mode,
        if(Copy_Conf->Copy_Mode == DMA_Circular_Mode)
				{
					SET_BIT(DMA_1_CCR(Copy_channel),CCR_CIRC_BIT);
				}else if(Copy_Conf->Copy_Mode == DMA_Memory_to_memory_Mode)
				{
					SET_BIT(DMA_1_CCR(Copy_channel),CCR_MEM2MEM_BIT);					
				}else
				{
					//do nothing
				}	
			 //Configure  peripheral & memory incremented mode		
        if(Copy_Conf->Copy_MINC == DMA_Memory_Increment_Enable)
				{
					SET_BIT(DMA_1_CCR(Copy_channel),CCR_MINC_BIT);
				}else if(Copy_Conf->Copy_MINC == DMA_Memory_Increment_Disable)
				{
					CLEAR_BIT(DMA_1_CCR(Copy_channel),CCR_MINC_BIT);
				}else
				{
					//do nothing
				}			
        if(Copy_Conf->Copy_PINC == DMA_Peripheral_Increment_Enable)
				{
					SET_BIT(DMA_1_CCR(Copy_channel),CCR_PINC_BIT);
				}else if(Copy_Conf->Copy_PINC == DMA_Peripheral_Increment_Disable)
				{
					CLEAR_BIT(DMA_1_CCR(Copy_channel),CCR_PINC_BIT);
				}else
				{
					//do nothing
				}		
			 //Configure Interrupts after half and/or full transfer
        if(Copy_Conf->DMA_pvTCNotifaction != NULL)
				{
					SET_BIT(DMA_1_CCR(Copy_channel),CCR_TCIE_BIT);
					DMA_pvTCNotificationFunc[Copy_channel] = Copy_Conf->DMA_pvTCNotifaction;
				}else
				{
					CLEAR_BIT(DMA_1_CCR(Copy_channel),CCR_TCIE_BIT);
				}			

        if(Copy_Conf->DMA_pvTENotifaction != NULL)
				{
					SET_BIT(DMA_1_CCR(Copy_channel),CCR_TEIE_BIT);
					DMA_pvTENotificationFunc[Copy_channel] = Copy_Conf->DMA_pvTENotifaction;
				}else
				{
					CLEAR_BIT(DMA_1_CCR(Copy_channel),CCR_TEIE_BIT);
				}

        if(Copy_Conf->DMA_pvHTNotifaction != NULL)
				{
					SET_BIT(DMA_1_CCR(Copy_channel),CCR_HTIE_BIT);
					DMA_pvHTNotificationFunc[Copy_channel] = Copy_Conf->DMA_pvHTNotifaction;
				}else
				{
					CLEAR_BIT(DMA_1_CCR(Copy_channel),CCR_HTIE_BIT);
				}		
		}else
		{
		  //
		}
	}else
	
{
		Loc_Err = NOK;
	
}
return Loc_Err;
}
ErrorStatus   DMA_enumWait_TCIF_Flag    (u8 Copy_Id) 
{
	ErrorStatus Loc_Err=OK;
	u32 Base_ADD=0;
	u32 LOC_u32TimeOutCounter =0;		
	if(Copy_Id < MAX_DMA_1_Channel_NUM)
	{			
				/*Wait until  (UDR) is ready to receive new data*/
				while ((GET_BIT(DMA_1_ISR,(ISR_TCIF_BIT + (Copy_Id*4))) == 0) && LOC_u32TimeOutCounter < DMA_TIME_OUT)
				{
						LOC_u32TimeOutCounter++;
				}
				if (LOC_u32TimeOutCounter == DMA_TIME_OUT)
				{
						Loc_Err = Time_OUT_State;
				}
				else
				{
					 SET_BIT(DMA_1_IFCR,(IFCR_CTCIF_BIT + (Copy_Id*4))) ;
				}	
	}else
	{
		Loc_Err =NOK;
	}
return Loc_Err;
}
void  DMA1_Channel1_IRQHandler   (void)
{
		if(GET_BIT(DMA_1_ISR,ISR_TCIF_BIT ) && DMA_pvTCNotificationFunc[DMA_Channel_1]!= NULL)
		{
			DMA_pvTCNotificationFunc[DMA_Channel_1]() ;
		  SET_BIT(DMA_1_IFCR,IFCR_CTCIF_BIT);
		}
		if(GET_BIT(DMA_1_ISR,ISR_HTIF_BIT)  && DMA_pvHTNotificationFunc[DMA_Channel_1]!= NULL)
		{
			DMA_pvHTNotificationFunc[DMA_Channel_1]() ;
		  SET_BIT(DMA_1_IFCR,IFCR_CHTIF_BIT);
		}
		if(GET_BIT(DMA_1_ISR,ISR_TEIF_BIT)  && DMA_pvTENotificationFunc[DMA_Channel_1]!= NULL)
		{
			DMA_pvTENotificationFunc[DMA_Channel_1]() ;
      SET_BIT(DMA_1_IFCR,IFCR_CTEIF_BIT);
		}
    SET_BIT(DMA_1_IFCR,IFCR_CGIF_BIT);
}
void  DMA1_Channel2_IRQHandler   (void)
{
	u8 Temp = DMA_Channel_2*4;
		if(GET_BIT(DMA_1_ISR,(ISR_TCIF_BIT + Temp)) && DMA_pvTCNotificationFunc[DMA_Channel_2]!= NULL)
		{
			DMA_pvTCNotificationFunc[DMA_Channel_2]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CTCIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_HTIF_BIT+ Temp))  && DMA_pvHTNotificationFunc[DMA_Channel_2]!= NULL)
		{
			DMA_pvHTNotificationFunc[DMA_Channel_2]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CHTIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_TEIF_BIT+ Temp))  && DMA_pvTENotificationFunc[DMA_Channel_2]!= NULL)
		{
			DMA_pvTENotificationFunc[DMA_Channel_2]() ;
      SET_BIT(DMA_1_IFCR,(IFCR_CTEIF_BIT+Temp));
		}
    SET_BIT(DMA_1_IFCR,(IFCR_CGIF_BIT+Temp));

}
void  DMA1_Channel3_IRQHandler   (void)
{
	u8 Temp = DMA_Channel_3*4;
		if(GET_BIT(DMA_1_ISR,(ISR_TCIF_BIT + Temp)) && DMA_pvTCNotificationFunc[DMA_Channel_3]!= NULL)
		{
			DMA_pvTCNotificationFunc[DMA_Channel_3]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CTCIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_HTIF_BIT+ Temp))  && DMA_pvHTNotificationFunc[DMA_Channel_3]!= NULL)
		{
			DMA_pvHTNotificationFunc[DMA_Channel_3]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CHTIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_TEIF_BIT+ Temp))  && DMA_pvTENotificationFunc[DMA_Channel_3]!= NULL)
		{
			DMA_pvTENotificationFunc[DMA_Channel_3]() ;
      SET_BIT(DMA_1_IFCR,(IFCR_CTEIF_BIT+Temp));
		}
    SET_BIT(DMA_1_IFCR,(IFCR_CGIF_BIT+Temp));
}	
void  DMA1_Channel4_IRQHandler   (void)
{
	u8 Temp = DMA_Channel_4*4;
		if(GET_BIT(DMA_1_ISR,(ISR_TCIF_BIT + Temp)) && DMA_pvTCNotificationFunc[DMA_Channel_4]!= NULL)
		{
			DMA_pvTCNotificationFunc[DMA_Channel_4]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CTCIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_HTIF_BIT+ Temp))  && DMA_pvHTNotificationFunc[DMA_Channel_4]!= NULL)
		{
			DMA_pvHTNotificationFunc[DMA_Channel_4]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CHTIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_TEIF_BIT+ Temp))  && DMA_pvTENotificationFunc[DMA_Channel_4]!= NULL)
		{
			DMA_pvTENotificationFunc[DMA_Channel_4]() ;
      SET_BIT(DMA_1_IFCR,(IFCR_CTEIF_BIT+Temp));
		}
    SET_BIT(DMA_1_IFCR,(IFCR_CGIF_BIT+Temp));

}	
void  DMA1_Channel5_IRQHandler   (void)
{
	u8 Temp = DMA_Channel_5*4;
		if(GET_BIT(DMA_1_ISR,(ISR_TCIF_BIT + Temp)) && DMA_pvTCNotificationFunc[DMA_Channel_5]!= NULL)
		{
			DMA_pvTCNotificationFunc[DMA_Channel_5]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CTCIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_HTIF_BIT+ Temp))  && DMA_pvHTNotificationFunc[DMA_Channel_5]!= NULL)
		{
			DMA_pvHTNotificationFunc[DMA_Channel_5]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CHTIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_TEIF_BIT+ Temp))  && DMA_pvTENotificationFunc[DMA_Channel_5]!= NULL)
		{
			DMA_pvTENotificationFunc[DMA_Channel_5]() ;
      SET_BIT(DMA_1_IFCR,(IFCR_CTEIF_BIT+Temp));
		}
    SET_BIT(DMA_1_IFCR,(IFCR_CGIF_BIT+Temp));
}	
void  DMA1_Channel6_IRQHandler   (void)
{
	u8 Temp = DMA_Channel_6*4;
		if(GET_BIT(DMA_1_ISR,(ISR_TCIF_BIT + Temp)) && DMA_pvTCNotificationFunc[DMA_Channel_6]!= NULL)
		{
			DMA_pvTCNotificationFunc[DMA_Channel_6]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CTCIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_HTIF_BIT+ Temp))  && DMA_pvHTNotificationFunc[DMA_Channel_6]!= NULL)
		{
			DMA_pvHTNotificationFunc[DMA_Channel_6]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CHTIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_TEIF_BIT+ Temp))  && DMA_pvTENotificationFunc[DMA_Channel_6]!= NULL)
		{
			DMA_pvTENotificationFunc[DMA_Channel_6]() ;
      SET_BIT(DMA_1_IFCR,(IFCR_CTEIF_BIT+Temp));
		}
    SET_BIT(DMA_1_IFCR,(IFCR_CGIF_BIT+Temp));
}	
void  DMA1_Channel7_IRQHandler   (void)
{
	u8 Temp = DMA_Channel_7*4;
		if(GET_BIT(DMA_1_ISR,(ISR_TCIF_BIT + Temp)) && DMA_pvTCNotificationFunc[DMA_Channel_7]!= NULL)
		{
			DMA_pvTCNotificationFunc[DMA_Channel_7]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CTCIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_HTIF_BIT+ Temp))  && DMA_pvHTNotificationFunc[DMA_Channel_7]!= NULL)
		{
			DMA_pvHTNotificationFunc[DMA_Channel_7]() ;
		  SET_BIT(DMA_1_IFCR,(IFCR_CHTIF_BIT+Temp));
		}
		if(GET_BIT(DMA_1_ISR,(ISR_TEIF_BIT+ Temp))  && DMA_pvTENotificationFunc[DMA_Channel_7]!= NULL)
		{
			DMA_pvTENotificationFunc[DMA_Channel_7]() ;
      SET_BIT(DMA_1_IFCR,(IFCR_CTEIF_BIT+Temp));
		}
    SET_BIT(DMA_1_IFCR,(IFCR_CGIF_BIT+Temp));
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

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
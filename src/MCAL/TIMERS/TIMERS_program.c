
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
#include "TIMERS_interface.h"
#include "TIMERS_Conf.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define GPT_TIMERS_MAX_CONF													2
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static void (* GPT_pvoidCallBackFunc[20]) (void)={NULL};
static void (* WWDG_pvoidCallBackFunc) (void)={NULL};
static u8 ICU_u8State = IDLE;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
ErrorStatus TIMER_Init(const GPT_ChannelConfigType *Copy_conf)
{
	ErrorStatus LOC_ErrorState =OK;
	if(Copy_conf !=NULL)
	{
		GPT_ChannelType Copy_TimerId=Copy_conf->ChannelID;
		switch(Copy_TimerId)
		{
			case TIMER_1:
				TIMER1_voidInit(Copy_conf);
				break;
			case TIMER_2:
				TIMER2_voidInit(Copy_conf);
				break;
			case TIMER_3:
		 	TIMER3_voidInit(Copy_conf); 
			 break;
			default:
				break;
		}
	}else
	{

}
return LOC_ErrorState;
}

void GPT_EnableNotifaction(GPT_ChannelType Copy_u8ChannelId)
{
// to make sure that interrupt will be happened
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_URS_BIT);
  	switch(Copy_u8ChannelId)
		{
			case TIMER_1:
		SET_BIT(TIMER1_DIER,TIM_DIER_UIE_BIT);	
			case TIMER_2:
		SET_BIT(TIMER2_DIER,TIM_DIER_UIE_BIT);	
				break;
			case TIMER_3:
		SET_BIT(TIMER3_DIER,TIM_DIER_UIE_BIT);	
  			break;
			default:
				break;
		}

}
void GPT_DisableNotifaction(GPT_ChannelType Copy_u8ChannelId)
{

		switch(Copy_u8ChannelId)
		{
			case TIMER_1:
		CLEAR_BIT(TIMER1_DIER,TIM_DIER_UIE_BIT);	
				break;
			case TIMER_2:
		CLEAR_BIT(TIMER2_DIER,TIM_DIER_UIE_BIT);	
				break;
			case TIMER_3:
		CLEAR_BIT(TIMER3_DIER,TIM_DIER_UIE_BIT);	
  			break;
			default:
				break;
		}

}	

void GPT_StartTimer(GPT_ChannelType Copy_u8ChannelId,u16 Value)
{
	
  	switch(Copy_u8ChannelId)
		{
			case TIMER_1:
		TIMER1_CNT=Value;		
		SET_BIT(TIMER1_CR1,TIM_CR1_CEN_BIT);	
  			break;
			case TIMER_2:
		TIMER2_CNT=Value;		
		SET_BIT(TIMER2_CR1,TIM_CR1_CEN_BIT);	
  			break;
			case TIMER_3:
		TIMER3_CNT=Value;		
		SET_BIT(TIMER3_CR1,TIM_CR1_CEN_BIT);	  	
  			break;
			default:
				break;
		}

}	
void GPT_StopTimer(GPT_ChannelType Copy_u8ChannelId)
{
	
  	switch(Copy_u8ChannelId)
		{
			case TIMER_1:
		CLEAR_BIT(TIMER1_CR1,TIM_CR1_CEN_BIT);	
  			break;
			case TIMER_2:
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_CEN_BIT);	
  			break;
			case TIMER_3:		
		CLEAR_BIT(TIMER3_CR1,TIM_CR1_CEN_BIT);	  	
  			break;
			default:
				break;
		}
	
}	
	
void GPT_CLearFlag(GPT_ChannelType Copy_u8ChannelId)
{
	
  	switch(Copy_u8ChannelId)
		{
			case TIMER_1:
		CLEAR_BIT(TIMER1_SR,TIM_SR_UIF_BIT);	
  			break;
			case TIMER_2:
		CLEAR_BIT(TIMER2_SR,TIM_SR_UIF_BIT);	
  			break;
			case TIMER_3:		
		CLEAR_BIT(TIMER3_SR,TIM_SR_UIF_BIT);	  	
  			break;
			default:
				break;
		}
}	
	
void GPT_GenerateUpdateEvent(GPT_ChannelType Copy_u8ChannelId)
{
 	switch(Copy_u8ChannelId)
		{
			case TIMER_1:
				SET_BIT(TIMER1_EGR,TIM_EGR_UG_BIT);
  			break;
    		case TIMER_2:
				SET_BIT(TIMER2_EGR,TIM_EGR_UG_BIT);
  			break;
			case TIMER_3:		
			SET_BIT(TIMER3_EGR,TIM_EGR_UG_BIT);
			break;
			default:
				break;
		}

}
u16 GPT_GetTimerCurrentVal(GPT_ChannelType Copy_u8ChannelId)
{
	u16 Copy_u16Value=0;
  	switch(Copy_u8ChannelId)
		{
			case TIMER_1:
				Copy_u16Value=TIMER1_CNT;
  			break;

			case TIMER_2:
				Copy_u16Value=TIMER2_CNT;
  			break;
			case TIMER_3:		
				Copy_u16Value=TIMER3_CNT;
			break;
			default:
				break;
		}
		return Copy_u16Value;
}	

void GPT_SetTimerPreloadVal(GPT_ChannelType Copy_u8ChannelId,u16 Copy_u16RegVal)
{

  	switch(Copy_u8ChannelId)
		{
			case TIMER_1:
					SET_BIT(TIMER1_CR1,TIM_CR1_UDIS_BIT);
					TIMER1_ARR=Copy_u16RegVal;
					CLEAR_BIT(TIMER1_CR1,TIM_CR1_UDIS_BIT);
			break;
			case TIMER_2:
					SET_BIT(TIMER2_CR1,TIM_CR1_UDIS_BIT);
					TIMER2_ARR=Copy_u16RegVal;
					CLEAR_BIT(TIMER2_CR1,TIM_CR1_UDIS_BIT);
			break;
			case TIMER_3:		
					SET_BIT(TIMER3_CR1,TIM_CR1_UDIS_BIT);
					TIMER3_ARR=Copy_u16RegVal;
					CLEAR_BIT(TIMER3_CR1,TIM_CR1_UDIS_BIT);
			break;
			default:
				break;
		}

}
ErrorStatus GPT_OutputCompareModeInit(GPT_OutputconfigType * Copy_Conf)
{

	GPT_ChannelType Copy_u8TimerId= Copy_Conf->TimerID;
	ICU_ChannelType Copy_ChannelId=Copy_Conf->ChannelID;
	ErrorStatus LOC_ErrorState =OK;
		switch(Copy_u8TimerId)
		{
			case TIMER_1:
									SET_BIT(TIMER1_BDTR, TIM_BDTR_MOE_BIT);	
									SET_BIT(TIMER1_CCER, (Copy_ChannelId*4));	//signal is output on the corresponding output pin. 				
							    TIMER1_CCR[Copy_ChannelId] = Copy_Conf->CompareMathReg;//Set CCR Value
									if(Copy_ChannelId < ICU_Channel_3) //set mode of operation
									{
									TIMER1_CCMR1 &= ~(0x73<<(8*Copy_ChannelId));//MASk 0xFF8C
									TIMER1_CCMR1 |= (Copy_Conf->Mode << (4+(8*Copy_ChannelId)));									
									}else
									{
									  Copy_ChannelId%=2;
										TIMER1_CCMR2 &= ~(0x73<<(8*Copy_ChannelId));//MASk 0xFF8C
									  TIMER1_CCMR2 |= (Copy_Conf->Mode << (4+(8*Copy_ChannelId)));
									  Copy_ChannelId=Copy_Conf->ChannelID;
									}
									if(Copy_Conf->GPT_puNotifacationFunction !=NULL)
									{//here
										GPT_pvoidCallBackFunc[(TIM_1_CC_Vect + Copy_ChannelId)]=Copy_Conf->GPT_puNotifacationFunction;
										SET_BIT(TIMER1_DIER,(Copy_ChannelId+1));										
									}else
									{
										CLEAR_BIT(TIMER1_DIER,(Copy_ChannelId+1));	
									}
			 break;



			case TIMER_2:
									SET_BIT(TIMER2_CCER, (Copy_ChannelId*4));	//signal is output on the corresponding output pin. 				
							    TIMER2_CCR[Copy_ChannelId] = Copy_Conf->CompareMathReg;//Set CCR Value
									if(Copy_ChannelId < ICU_Channel_3) //set mode of operation
									{
									TIMER2_CCMR1 &= ~(0x73<<(8*Copy_ChannelId));//MASk 0xFF8C
									TIMER2_CCMR1 |= (Copy_Conf->Mode << (4+(8*Copy_ChannelId)));									
									}else
									{
									  Copy_ChannelId%=2;
										TIMER2_CCMR2 &= ~(0x73<<(8*Copy_ChannelId));//MASk 0xFF8C
									  TIMER2_CCMR2 |= (Copy_Conf->Mode << (4+(8*Copy_ChannelId)));
									  Copy_ChannelId=Copy_Conf->ChannelID;
									}
									if(Copy_Conf->GPT_puNotifacationFunction !=NULL)
									{//here
										GPT_pvoidCallBackFunc[(TIM_2_CC_Vect + Copy_ChannelId)]=Copy_Conf->GPT_puNotifacationFunction;
										SET_BIT(TIMER2_DIER,(Copy_ChannelId+1));										
									}else
									{
										CLEAR_BIT(TIMER2_DIER,(Copy_ChannelId+1));	
									}
			 break;
			case TIMER_3:
									SET_BIT(TIMER3_CCER, (Copy_ChannelId*4));	//signal is output on the corresponding output pin. 				
							    TIMER3_CCR[Copy_ChannelId] = Copy_Conf->CompareMathReg;//Set CCR Value
									if(Copy_ChannelId < ICU_Channel_3) //set mode of operation
									{
									TIMER3_CCMR1 &= ~(0x73<<(8*Copy_ChannelId));//MASk 0xFF8C
									TIMER3_CCMR1 |= (Copy_Conf->Mode << (4+(8*Copy_ChannelId)));									
									}else
									{
									  Copy_ChannelId%=2;
										TIMER3_CCMR2 &= ~(0x73<<(8*Copy_ChannelId));//MASk 0xFF8C
									  TIMER3_CCMR2 |= (Copy_Conf->Mode << (4+(8*Copy_ChannelId)));
									  Copy_ChannelId=Copy_Conf->ChannelID;
									}
									if(Copy_Conf->GPT_puNotifacationFunction !=NULL)
									{//here
										GPT_pvoidCallBackFunc[(TIM_3_CC_Vect + Copy_ChannelId)]=Copy_Conf->GPT_puNotifacationFunction;
										SET_BIT(TIMER3_DIER,(Copy_ChannelId+1));										
									}else
									{
										CLEAR_BIT(TIMER3_DIER,(Copy_ChannelId+1));	
									}
				default:
				break;
		}
return LOC_ErrorState;
}
ErrorStatus GPT_PWMModeInit(GPT_PWMType * Copy_Conf)
{
  GPT_ChannelType Copy_u8TimerId= Copy_Conf->TimerID;
	ICU_ChannelType Copy_ChannelId=Copy_Conf->ChannelID;
	ErrorStatus LOC_ErrorState =OK;
		switch(Copy_u8TimerId)
		{
			case TIMER_1:
					SET_BIT(TIMER1_BDTR, TIM_BDTR_MOE_BIT);	
    			SET_BIT(TIMER1_CCER, (4*Copy_ChannelId));
				  SET_BIT(TIMER1_CCER, ((4*Copy_ChannelId)+1));

    			if(Copy_ChannelId < ICU_Channel_3)
					{
					TIMER1_CCMR1 &= ~(0x73<<(8*Copy_ChannelId)); //0xFF8C
				  TIMER1_CCMR1 |= (Copy_Conf->Mode << (4+(Copy_ChannelId*8)));
					}else
					{
					Copy_ChannelId%=2;
					TIMER1_CCMR2 &= ~(0x73<<(8*Copy_ChannelId)); //0xFF8C
				  TIMER1_CCMR2 |= (Copy_Conf->Mode << (4+(Copy_ChannelId*8)));
					Copy_ChannelId=Copy_Conf->ChannelID;
					}
					
  		    TIMER1_CCR[Copy_ChannelId] = Copy_Conf->CompareMathReg;

					if(Copy_Conf->GPT_puNotifacationFunction !=NULL)
					{
						GPT_pvoidCallBackFunc[(TIM_1_CC_Vect + Copy_ChannelId)]=Copy_Conf->GPT_puNotifacationFunction;
						SET_BIT(TIMER1_DIER,(Copy_ChannelId+1));										
					}else
					{
						CLEAR_BIT(TIMER1_DIER,(Copy_ChannelId+1));	
					}	
			 break;

			case TIMER_2:
					SET_BIT(TIMER2_CCER, (4*Copy_ChannelId));
				  CLEAR_BIT(TIMER2_CCER, ((4*Copy_ChannelId)+1));

    			if(Copy_ChannelId < ICU_Channel_3)
					{
					TIMER2_CCMR1 &= ~(0x73<<(8*Copy_ChannelId)); //0xFF8C
				  TIMER2_CCMR1 |= (Copy_Conf->Mode << (4+(Copy_ChannelId*8)));
					}else
					{
					Copy_ChannelId%=2;
					TIMER2_CCMR2 &= ~(0x73<<(8*Copy_ChannelId)); //0xFF8C
				  TIMER2_CCMR2 |= (Copy_Conf->Mode << (4+(Copy_ChannelId*8)));
					Copy_ChannelId=Copy_Conf->ChannelID;
					}
					
  		    TIMER2_CCR[Copy_ChannelId] = Copy_Conf->CompareMathReg;

					if(Copy_Conf->GPT_puNotifacationFunction !=NULL)
					{
						GPT_pvoidCallBackFunc[(TIM_2_CC_Vect + Copy_ChannelId)]=Copy_Conf->GPT_puNotifacationFunction;
						SET_BIT(TIMER2_DIER,(Copy_ChannelId+1));										
					}else
					{
						CLEAR_BIT(TIMER2_DIER,(Copy_ChannelId+1));	
					}	
			 break;
			case TIMER_3:
					SET_BIT(TIMER3_CCER, (4*Copy_ChannelId));
				  CLEAR_BIT(TIMER3_CCER, ((4*Copy_ChannelId)+1));

    			if(Copy_ChannelId < ICU_Channel_3)
					{
					TIMER3_CCMR1 &= ~(0x73<<(8*Copy_ChannelId)); //0xFF8C
				  TIMER3_CCMR1 |= (Copy_Conf->Mode << (4+(Copy_ChannelId*8)));
					}else
					{
					Copy_ChannelId%=2;
					TIMER3_CCMR2 &= ~(0x73<<(8*Copy_ChannelId)); //0xFF8C
				  TIMER3_CCMR2 |= (Copy_Conf->Mode << (4+(Copy_ChannelId*8)));
					Copy_ChannelId=Copy_Conf->ChannelID;
					}
					
  		    TIMER3_CCR[Copy_ChannelId] = Copy_Conf->CompareMathReg;

					if(Copy_Conf->GPT_puNotifacationFunction !=NULL)
					{
						GPT_pvoidCallBackFunc[(TIM_3_CC_Vect + Copy_ChannelId)]=Copy_Conf->GPT_puNotifacationFunction;
						SET_BIT(TIMER3_DIER,(Copy_ChannelId+1));										
					}else
					{
						CLEAR_BIT(TIMER3_DIER,(Copy_ChannelId+1));	
					}	
			 break;				 
				default:
				break;
		}
return LOC_ErrorState;
}
void GPT_DisableCapture_CompareMode(GPT_ChannelType Copy_u8TimerId,ICU_ChannelType Copy_ChannelId )
{
		switch(Copy_u8TimerId)
		{
			case TIMER_1:
					CLEAR_BIT(TIMER1_CCER, (Copy_ChannelId*4));	//Disable output on the corresponding output pin. 
			 break;
			case TIMER_2:
					CLEAR_BIT(TIMER2_CCER, (Copy_ChannelId*4));	//Disable output on the corresponding output pin. 
			 break;
			case TIMER_3:
					CLEAR_BIT(TIMER3_CCER, (Copy_ChannelId*4));	//Disable output on the corresponding output pin. 
			default:
				break;
		}
}


void GPT_SetCapture_CompareVal   (GPT_ChannelType Copy_u8TimerId,ICU_ChannelType Copy_ChannelId,u16 Copy_u16RegVal)
{
		switch(Copy_u8TimerId)
		{
			case TIMER_1:
						TIMER1_CCR[Copy_ChannelId]=	Copy_u16RegVal;
			 break;
			case TIMER_2:
						TIMER2_CCR[Copy_ChannelId]=	Copy_u16RegVal;
			 break;
			case TIMER_3:
						TIMER3_CCR[Copy_ChannelId]=	Copy_u16RegVal;
			default:
				break;
		}

}
static void TIMER2_voidInit(const GPT_ChannelConfigType *Copy_conf)
{

	#if (TIMER_2_PRELOAD_REG_BUFFERED_ENABLE==1)
		SET_BIT(TIMER2_CR1,TIM_CR1_ARPE_BIT);
	#else
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_ARPE_BIT);
	#endif	
	
	#if (TIMER_2_DOWN_COUNTING==1)
		SET_BIT(TIMER2_CR1,TIM_CR1_DIR_BIT);
	#else
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_DIR_BIT);
	#endif	
	
	#if (TIMER_2_CLOCK_DIVISION == TIMER_CLOCK_DIVISION_BY_2)
		SET_BIT(TIMER2_CR1,TIM_CR1_CKD_0_BIT);
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_CKD_1_BIT);	  
	#elif (TIMER_2_CLOCK_DIVISION == TIMER_CLOCK_DIVISION_BY_4)
		SET_BIT(TIMER2_CR1,TIM_CR1_CKD_1_BIT);
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_CKD_0_BIT);
	#else
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_CKD_0_BIT);
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_CKD_1_BIT);
	#endif	
	
	//Set Timer mode
	if(Copy_conf->Mode == GPT_Mode_OneShot)
	{
		SET_BIT(TIMER2_CR1,TIM_CR1_OPM_BIT);	
	}else
	{
		CLEAR_BIT(TIMER2_CR1,TIM_CR1_OPM_BIT);	
	}
	//set interrupt state
	if(Copy_conf->GPT_puNotifacationFunction != NULL)
	{
		SET_BIT(TIMER2_DIER,TIM_DIER_UIE_BIT);	
		GPT_pvoidCallBackFunc[TIM_2_UP_Vect]=Copy_conf->GPT_puNotifacationFunction;
	}else
	{
		CLEAR_BIT(TIMER2_DIER,TIM_DIER_UIE_BIT);	
	}
		
/*setting the UDIS bit in TIMx_CR1 register. 
	This is to avoid updating the shadow registers while writing new values in the preload .
*/
SET_BIT(TIMER2_CR1,TIM_CR1_UDIS_BIT);
TIMER2_ARR=Copy_conf->Preload;
TIMER2_PSC=Copy_conf->Prescaler;	
CLEAR_BIT(TIMER2_CR1,TIM_CR1_UDIS_BIT);
}

static void TIMER3_voidInit(const GPT_ChannelConfigType *Copy_conf)
{
	#if (TIMER_3_PRELOAD_REG_BUFFERED_ENABLE==1)
		SET_BIT(TIMER3_CR1,TIM_CR1_ARPE_BIT);
	#else
		CLEAR_BIT(TIMER3_CR1,TIM_CR1_ARPE_BIT);
	#endif	
	
	#if (TIMER_3_DOWN_COUNTING==1)
		SET_BIT(TIMER3_CR1,TIM_CR1_DIR_BIT);
	#else
		CLEAR_BIT(TIMER3_CR1,TIM_CR1_DIR_BIT);
	#endif	
	
	#if (TIMER_3_CLOCK_DIVISION == TIMER_CLOCK_DIVISION_BY_2)
		SET_BIT(TIMER3_CR1,TIM_CR1_CKD_0_BIT);
		CLEAR_BIT(TIMER3_CR1,TIM_CR1_CKD_1_BIT);	  
	#elif (TIMER_3_CLOCK_DIVISION == TIMER_CLOCK_DIVISION_BY_4)
		SET_BIT(TIMER3_CR1,TIM_CR1_CKD_1_BIT);
		CLEAR_BIT(TIMER3_CR1,TIM_CR1_CKD_0_BIT);
	#else
		CLEAR_BIT(TIMER3_CR1,TIM_CR1_CKD_0_BIT);
		CLEAR_BIT(TIMER3_CR1,TIM_CR1_CKD_1_BIT);
	#endif	
	//Set Timer mode
	if(Copy_conf->Mode == GPT_Mode_OneShot)
	{
		SET_BIT(TIMER3_CR1,TIM_CR1_OPM_BIT);	
	}else
	{
		CLEAR_BIT(TIMER3_CR1,TIM_CR1_OPM_BIT);	
	}
	//set interrupt state
	if(Copy_conf->GPT_puNotifacationFunction != NULL)
	{
		SET_BIT(TIMER3_DIER,TIM_DIER_UIE_BIT);	
		GPT_pvoidCallBackFunc[TIM_3_UP_Vect]=Copy_conf->GPT_puNotifacationFunction;
	}else
	{
		CLEAR_BIT(TIMER3_DIER,TIM_DIER_UIE_BIT);	
	}
		
/*setting the UDIS bit in TIMx_CR1 register. 
	This is to avoid updating the shadow registers while writing new values in the preload .
*/
SET_BIT(TIMER3_CR1,TIM_CR1_UDIS_BIT);
TIMER3_ARR=Copy_conf->Preload;
TIMER3_PSC=Copy_conf->Prescaler;	
CLEAR_BIT(TIMER3_CR1,TIM_CR1_UDIS_BIT);
}
static void TIMER1_voidInit(const GPT_ChannelConfigType *Copy_conf)
{
	#if (TIMER_1_PRELOAD_REG_BUFFERED_ENABLE==1)
		SET_BIT(TIMER1_CR1,TIM_CR1_ARPE_BIT);
	#else
		CLEAR_BIT(TIMER1_CR1,TIM_CR1_ARPE_BIT);
	#endif	
	
	#if (TIMER_1_DOWN_COUNTING==1)
		SET_BIT(TIMER1_CR1,TIM_CR1_DIR_BIT);
	#else
		CLEAR_BIT(TIMER1_CR1,TIM_CR1_DIR_BIT);
	#endif	
	
	#if (TIMER_1_CLOCK_DIVISION == TIMER_CLOCK_DIVISION_BY_2)
		SET_BIT(TIMER1_CR1,TIM_CR1_CKD_0_BIT);
		CLEAR_BIT(TIMER1_CR1,TIM_CR1_CKD_1_BIT);	  
	#elif (TIMER_1_CLOCK_DIVISION == TIMER_CLOCK_DIVISION_BY_4)
		SET_BIT(TIMER1_CR1,TIM_CR1_CKD_1_BIT);
		CLEAR_BIT(TIMER1_CR1,TIM_CR1_CKD_0_BIT);
	#else
		CLEAR_BIT(TIMER1_CR1,TIM_CR1_CKD_0_BIT);
		CLEAR_BIT(TIMER1_CR1,TIM_CR1_CKD_1_BIT);
	#endif	
	//Set Timer mode
	if(Copy_conf->Mode == GPT_Mode_OneShot)
	{
		SET_BIT(TIMER1_CR1,TIM_CR1_OPM_BIT);	
	}else
	{
		CLEAR_BIT(TIMER1_CR1,TIM_CR1_OPM_BIT);	
	}
	//set interrupt state
	if(Copy_conf->GPT_puNotifacationFunction != NULL)
	{
		SET_BIT(TIMER1_DIER,TIM_DIER_UIE_BIT);	
		GPT_pvoidCallBackFunc[TIM_1_UP_Vect]=Copy_conf->GPT_puNotifacationFunction;
	}else
	{
		CLEAR_BIT(TIMER1_DIER,TIM_DIER_UIE_BIT);	
	}
		
/*setting the UDIS bit in TIMx_CR1 register. 
	This is to avoid updating the shadow registers while writing new values in the preload .
*/
SET_BIT(TIMER1_CR1,TIM_CR1_UDIS_BIT);
TIMER1_ARR=Copy_conf->Preload;
TIMER1_PSC=Copy_conf->Prescaler;	
CLEAR_BIT(TIMER1_CR1,TIM_CR1_UDIS_BIT);
}

ErrorStatus TIMER_voidICUInit(const ICU_ChannelConfigType *Copy_conf)
{
	ErrorStatus LOC_ErrorState =OK;
	if(Copy_conf !=NULL)
	{
		GPT_ChannelType Copy_TimerId=Copy_conf->TimerID;
		switch(Copy_TimerId)
		{
			case TIMER_1:
				ICU_TIM1_voidInit(Copy_conf);
			 break;
			case TIMER_2:
				ICU_TIM2_voidInit(Copy_conf);
			 break;
			case TIMER_3:
				ICU_TIM3_voidInit(Copy_conf);
			 break;
			default:
				break;
		}
	}else
	{

	}
	
return LOC_ErrorState;


}
ErrorStatus TIMER_enumICUSetTrigger(GPT_ChannelType Cpoy_u8TimerId,ICU_ChannelType Cpoy_u8ChannelId,ICU_EdgeType Copy_u8Trigger)
{
	ErrorStatus LOC_ErrorState =OK;
		
		switch(Cpoy_u8TimerId)
		{
			case TIMER_1:
				ICU_TIM1_voidSetTrigger(Cpoy_u8ChannelId, Copy_u8Trigger);
			 break;
			case TIMER_2:
				ICU_TIM2_voidSetTrigger(Cpoy_u8ChannelId, Copy_u8Trigger);
			 break;
			case TIMER_3:
				ICU_TIM3_voidSetTrigger(Cpoy_u8ChannelId, Copy_u8Trigger);			
			break;
			default:
				break;
		}
	
	
return LOC_ErrorState;
}
void TIMER_voidCapture_CompareEnableInterrupt ( GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId )
{
		switch(Copy_TimerId)
		{
			case TIMER_1:
					SET_BIT(TIMER1_DIER,(Copy_ChannelId+1));
			 break;
			case TIMER_2:
					SET_BIT(TIMER2_DIER,(Copy_ChannelId+1));
			 break;
			case TIMER_3:
					SET_BIT(TIMER3_DIER,(Copy_ChannelId+1));
					break;
			default:
				break;
		}

}
void TIMER_voidCapture_CompareDisableInterrupt ( GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId )
{

		switch(Copy_TimerId)
		{
			case TIMER_1:
					CLEAR_BIT(TIMER1_DIER,(Copy_ChannelId+1));
			 break;
			case TIMER_2:
					CLEAR_BIT(TIMER2_DIER,(Copy_ChannelId+1));
			 break;
			case TIMER_3:
					CLEAR_BIT(TIMER3_DIER,(Copy_ChannelId+1));
					break;
			default:
				break;
		}

}
void GPT_CLearCapture_CompareFlag (GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId)
{
	switch(Copy_TimerId)
		{
			case TIMER_1:
	   		CLEAR_BIT(TIMER1_SR,(Copy_ChannelId+1));									
			 break;
  		case TIMER_2:
	   		CLEAR_BIT(TIMER2_SR,(Copy_ChannelId+1));									
			 break;
			case TIMER_3:
	   		CLEAR_BIT(TIMER3_SR,(Copy_ChannelId+1));
			break;
			default:
				break;
		}

}



ErrorStatus TIMER_enumICRValue ( GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId,u16 *Copy_pu16Value)
{
	ErrorStatus LOC_ErrorState =OK;
		switch(Copy_TimerId)
		{
			case TIMER_1:
								*Copy_pu16Value = TIMER1_CCR[Copy_ChannelId];
			 break;
			case TIMER_2:
								*Copy_pu16Value = TIMER2_CCR[Copy_ChannelId];
			 break;
			case TIMER_3:
								*Copy_pu16Value = TIMER3_CCR[Copy_ChannelId];	
			 break;
			default:
				break;
		}
return LOC_ErrorState;
}
ErrorStatus TIM1_enumDetectCaptureSync (ICU_ChannelType Copy_ChannelId,ICU_EdgeType Copy_Trigger, u16 *Copy_u16Ticks)
{
    ErrorStatus LOC_Err = OK;
    ICU_TIM1_voidSetTrigger(Copy_ChannelId,Copy_Trigger);
    if (ICU_u8State == IDLE) {
        if (Copy_u16Ticks != NULL) {
								ICU_u8State = BUSY;
								while (GET_BIT(TIMER1_SR, (Copy_ChannelId+1)) == 0);
								*Copy_u16Ticks = TIMER1_CCR[Copy_ChannelId];	
								ICU_u8State = IDLE;				
        } else {
            LOC_Err = NOK;
        }
    } else {
        LOC_Err = Busy_State;
    }
    return LOC_Err;
}
ErrorStatus TIM2_enumDetectCaptureSync (ICU_ChannelType Copy_ChannelId,ICU_EdgeType Copy_Trigger, u16 *Copy_u16Ticks)
{
    ErrorStatus LOC_Err = OK;
    ICU_TIM2_voidSetTrigger(Copy_ChannelId,Copy_Trigger);
    if (ICU_u8State == IDLE) {
        if (Copy_u16Ticks != NULL) {
								ICU_u8State = BUSY;
								while (GET_BIT(TIMER2_SR, (Copy_ChannelId+1)) == 0);
								*Copy_u16Ticks = TIMER2_CCR[Copy_ChannelId];	
								ICU_u8State = IDLE;				
        } else {
            LOC_Err = NOK;
        }
    } else {
        LOC_Err = Busy_State;
    }
    return LOC_Err;
}
ErrorStatus TIM3_enumDetectCaptureSync (ICU_ChannelType Copy_ChannelId,ICU_EdgeType Copy_Trigger, u16 *Copy_u16Ticks)
{
    ErrorStatus LOC_Err = OK;
    ICU_TIM3_voidSetTrigger(Copy_ChannelId,Copy_Trigger);
    if (ICU_u8State == IDLE) {
        if (Copy_u16Ticks != NULL) {
								ICU_u8State = BUSY;
								while (GET_BIT(TIMER3_SR, (Copy_ChannelId+1)) == 0);
								*Copy_u16Ticks = TIMER3_CCR[Copy_ChannelId];										
								ICU_u8State = IDLE;				
        } else {
            LOC_Err = NOK;
        }
    } else {
        LOC_Err = Busy_State;
    }
    return LOC_Err;

}

static void ICU_TIM1_voidInit(const ICU_ChannelConfigType *Copy_conf)
{
	if(Copy_conf !=NULL)
	{
		ICU_ChannelType Copy_ChannelId = Copy_conf->ChannelID;
		if(Copy_ChannelId < ICU_Channel_3)
		{
			/*01: CC1 channel is configured as input, IC1 is mapped on TI1*/
			SET_BIT  (TIMER1_CCMR1,  (Copy_ChannelId*8));
			CLEAR_BIT(TIMER1_CCMR1,((Copy_ChannelId*8)+1));
			/*Program the needed input filter duration*/
			TIMER1_CCMR1 &= ~(0xF0<<(Copy_ChannelId*8));//0xFF0F
			TIMER1_CCMR1 |=  (ICU_TIM_1_INPUT_FILTER<<((Copy_ChannelId*8)+4));	
			/*Program the input prescaler*/
			TIMER1_CCMR1 &= ~(0x0C<<(Copy_ChannelId*8));//0xFFF3
			TIMER1_CCMR1 |=  (ICU_TIM_1_INPUT_PRESCALER<<((Copy_ChannelId*8)+2));					
			
		}else
		{
			Copy_ChannelId%=2;
			/*01: CC1 channel is configured as input, IC1 is mapped on TI1*/
			SET_BIT  (TIMER1_CCMR2,  (Copy_ChannelId*8));
			CLEAR_BIT(TIMER1_CCMR2,((Copy_ChannelId*8)+1));
			/*Program the needed input filter duration*/
			TIMER1_CCMR2 &= ~(0xF0<<(Copy_ChannelId*8));//0xFF0F
			TIMER1_CCMR2 |=  (ICU_TIM_1_INPUT_FILTER<<((Copy_ChannelId*8)+4));	
			/*Program the input prescaler*/
			TIMER1_CCMR2 &= ~(0x0C<<(Copy_ChannelId*8));//0xFFF3
			TIMER1_CCMR2 |=  (ICU_TIM_1_INPUT_PRESCALER<<((Copy_ChannelId*8)+2));					
			Copy_ChannelId=Copy_conf->ChannelID;
		}		
		 if(Copy_conf->Edge == ICU_Raising)
		 {
			CLEAR_BIT(TIMER1_CCER,((Copy_ChannelId*4)+1));
		 }else
		 {
			SET_BIT(TIMER1_CCER,((Copy_ChannelId*4)+1));
		 }
		 /*enable the related interrupt request*/
		 if(Copy_conf->GPT_puNotifacationFunction != NULL)
		 {
			GPT_pvoidCallBackFunc[(Copy_ChannelId+TIM_1_CC_Vect)]= Copy_conf->GPT_puNotifacationFunction;
			SET_BIT(TIMER1_DIER,(Copy_ChannelId+1));
		 }else
		 {
			CLEAR_BIT(TIMER1_DIER,(Copy_ChannelId+1));;
		 }			
		 /*Enable capture */
		 SET_BIT(TIMER1_CCER,(Copy_ChannelId*4));				 				 
	}else
	{

	}
}

static void ICU_TIM2_voidInit(const ICU_ChannelConfigType *Copy_conf)
{
	if(Copy_conf !=NULL)
	{
		ICU_ChannelType Copy_ChannelId = Copy_conf->ChannelID;
		if(Copy_ChannelId < ICU_Channel_3)
		{
			/*01: CC1 channel is configured as input, IC1 is mapped on TI1*/
			SET_BIT  (TIMER2_CCMR1,  (Copy_ChannelId*8));
			CLEAR_BIT(TIMER2_CCMR1,((Copy_ChannelId*8)+1));
			/*Program the needed input filter duration*/
			TIMER2_CCMR1 &= ~(0xF0<<(Copy_ChannelId*8));//0xFF0F
			TIMER2_CCMR1 |=  (ICU_TIM_2_INPUT_FILTER<<((Copy_ChannelId*8)+4));	
			/*Program the input prescaler*/
			TIMER2_CCMR1 &= ~(0x0C<<(Copy_ChannelId*8));//0xFFF3
			TIMER2_CCMR1 |=  (ICU_TIM_2_INPUT_PRESCALER<<((Copy_ChannelId*8)+2));					
			
		}else
		{
			Copy_ChannelId%=2;
			/*01: CC1 channel is configured as input, IC1 is mapped on TI1*/
			SET_BIT  (TIMER2_CCMR2,  (Copy_ChannelId*8));
			CLEAR_BIT(TIMER2_CCMR2,((Copy_ChannelId*8)+1));
			/*Program the needed input filter duration*/
			TIMER2_CCMR2 &= ~(0xF0<<(Copy_ChannelId*8));//0xFF0F
			TIMER2_CCMR2 |=  (ICU_TIM_2_INPUT_FILTER<<((Copy_ChannelId*8)+4));	
			/*Program the input prescaler*/
			TIMER2_CCMR2 &= ~(0x0C<<(Copy_ChannelId*8));//0xFFF3
			TIMER2_CCMR2 |=  (ICU_TIM_2_INPUT_PRESCALER<<((Copy_ChannelId*8)+2));					
			Copy_ChannelId=Copy_conf->ChannelID;
		}		
		 if(Copy_conf->Edge == ICU_Raising)
		 {
			CLEAR_BIT(TIMER2_CCER,((Copy_ChannelId*4)+1));
		 }else
		 {
			SET_BIT(TIMER2_CCER,((Copy_ChannelId*4)+1));
		 }
		 /*enable the related interrupt request*/
		 if(Copy_conf->GPT_puNotifacationFunction != NULL)
		 {
			GPT_pvoidCallBackFunc[Copy_ChannelId+TIM_2_CC_Vect]= Copy_conf->GPT_puNotifacationFunction;
			SET_BIT(TIMER2_DIER,(Copy_ChannelId+1));
		 }else
		 {
			CLEAR_BIT(TIMER2_DIER,(Copy_ChannelId+1));;
		 }			
		 /*Enable capture */
		 SET_BIT(TIMER2_CCER,(Copy_ChannelId*4));				 				 
	}else
	{

	}
}

static void ICU_TIM3_voidInit(const ICU_ChannelConfigType *Copy_conf)
{
	if(Copy_conf !=NULL)
	{
		ICU_ChannelType Copy_ChannelId = Copy_conf->ChannelID;
		if(Copy_ChannelId < ICU_Channel_3)
		{
			/*01: CC1 channel is configured as input, IC1 is mapped on TI1*/
			SET_BIT  (TIMER3_CCMR1,  (Copy_ChannelId*8));
			CLEAR_BIT(TIMER3_CCMR1,((Copy_ChannelId*8)+1));
			/*Program the needed input filter duration*/
			TIMER3_CCMR1 &= ~(0xF0<<(Copy_ChannelId*8));//0xFF0F
			TIMER3_CCMR1 |=  (ICU_TIM_3_INPUT_FILTER<<((Copy_ChannelId*8)+4));	
			/*Program the input prescaler*/
			TIMER3_CCMR1 &= ~(0x0C<<(Copy_ChannelId*8));//0xFFF3
			TIMER3_CCMR1 |=  (ICU_TIM_3_INPUT_PRESCALER<<((Copy_ChannelId*8)+2));					
			
		}else
		{
			Copy_ChannelId%=2;
			/*01: CC1 channel is configured as input, IC1 is mapped on TI1*/
			SET_BIT  (TIMER3_CCMR2,  (Copy_ChannelId*8));
			CLEAR_BIT(TIMER3_CCMR2,((Copy_ChannelId*8)+1));
			/*Program the needed input filter duration*/
			TIMER3_CCMR2 &= ~(0xF0<<(Copy_ChannelId*8));//0xFF0F
			TIMER3_CCMR2 |=  (ICU_TIM_3_INPUT_FILTER<<((Copy_ChannelId*8)+4));	
			/*Program the input prescaler*/
			TIMER3_CCMR2 &= ~(0x0C<<(Copy_ChannelId*8));//0xFFF3
			TIMER3_CCMR2 |=  (ICU_TIM_3_INPUT_PRESCALER<<((Copy_ChannelId*8)+2));					
			Copy_ChannelId=Copy_conf->ChannelID;
		}		
		 if(Copy_conf->Edge == ICU_Raising)
		 {
			CLEAR_BIT(TIMER3_CCER,((Copy_ChannelId*4)+1));
		 }else
		 {
			SET_BIT  (TIMER3_CCER,((Copy_ChannelId*4)+1));
		 }
		 /*enable the related interrupt request*/
		 if(Copy_conf->GPT_puNotifacationFunction != NULL)
		 {
			GPT_pvoidCallBackFunc[(Copy_ChannelId+TIM_3_CC_Vect)]= Copy_conf->GPT_puNotifacationFunction;
			SET_BIT(TIMER3_DIER,(Copy_ChannelId+1));
		 }else
		 {
			CLEAR_BIT(TIMER3_DIER,(Copy_ChannelId+1));;
		 }			
		 /*Enable capture */
		 SET_BIT(TIMER3_CCER,(Copy_ChannelId*4));				 				 
	}else
	{

	}
}

static void	ICU_TIM1_voidSetTrigger(ICU_ChannelType Copy_ChannelId,ICU_EdgeType Copy_Trigger)
{
		 if(Copy_ChannelId == ICU_Raising)
		 {
			CLEAR_BIT(TIMER1_CCER,((Copy_ChannelId*4)+1));
		 }else
		 {
			SET_BIT(TIMER1_CCER,((Copy_ChannelId*4)+1));
		 }
}

static void	ICU_TIM2_voidSetTrigger(ICU_ChannelType Copy_ChannelId,ICU_EdgeType Copy_Trigger)
{
		 if(Copy_ChannelId == ICU_Raising)
		 {
			CLEAR_BIT(TIMER2_CCER,((Copy_ChannelId*4)+1));
		 }else
		 {
			SET_BIT(TIMER2_CCER,((Copy_ChannelId*4)+1));
		 }
}

static void	ICU_TIM3_voidSetTrigger(ICU_ChannelType Copy_ChannelId,ICU_EdgeType Copy_Trigger)
{
		 if(Copy_ChannelId == ICU_Raising)
		 {
			CLEAR_BIT(TIMER3_CCER,((Copy_ChannelId*4)+1));
		 }else
		 {
			SET_BIT  (TIMER3_CCER,((Copy_ChannelId*4)+1));
		 }
}




void TIM1_UP_IRQHandler(void)
{
	GPT_pvoidCallBackFunc[TIM_1_UP_Vect]();
	CLEAR_BIT(TIMER1_SR,TIM_SR_UIF_BIT);	
}
void  TIM1_CC_IRQHandler (void)
{
	if(GET_BIT(TIMER1_SR,TIM_SR_CC1IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_1_Channel_1_Vect]();
			CLEAR_BIT(TIMER1_SR,TIM_SR_CC1IF_BIT);	
		}
	if(GET_BIT(TIMER1_SR,TIM_SR_CC2IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_1_Channel_2_Vect]();
			CLEAR_BIT(TIMER1_SR,TIM_SR_CC2IF_BIT);	
		}
	if(GET_BIT(TIMER1_SR,TIM_SR_CC3IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_1_Channel_3_Vect]();
			CLEAR_BIT(TIMER1_SR,TIM_SR_CC3IF_BIT);	
		}
	if(GET_BIT(TIMER1_SR,TIM_SR_CC4IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_1_Channel_4_Vect]();
			CLEAR_BIT(TIMER1_SR,TIM_SR_CC4IF_BIT);	
		}


}
void TIM2_IRQHandler(void)
{
	if(GET_BIT(TIMER2_SR,TIM_SR_UIF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_2_UP_Vect]();
			CLEAR_BIT(TIMER2_SR,TIM_SR_UIF_BIT);	
		}
	if(GET_BIT(TIMER2_SR,TIM_SR_CC1IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_2_Channel_1_Vect]();
			CLEAR_BIT(TIMER2_SR,TIM_SR_CC1IF_BIT);	
		}
	if(GET_BIT(TIMER2_SR,TIM_SR_CC2IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_2_Channel_2_Vect]();
			CLEAR_BIT(TIMER2_SR,TIM_SR_CC2IF_BIT);	
		}
	if(GET_BIT(TIMER2_SR,TIM_SR_CC3IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_2_Channel_3_Vect]();
			CLEAR_BIT(TIMER2_SR,TIM_SR_CC3IF_BIT);	
		}
	if(GET_BIT(TIMER2_SR,TIM_SR_CC4IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_2_Channel_4_Vect]();
			CLEAR_BIT(TIMER2_SR,TIM_SR_CC4IF_BIT);	
		}
		
}
void TIM3_IRQHandler(void)
{
	if(GET_BIT(TIMER3_SR,TIM_SR_UIF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_3_UP_Vect]();
			CLEAR_BIT(TIMER3_SR,TIM_SR_UIF_BIT);	
		}
	if(GET_BIT(TIMER3_SR,TIM_SR_CC1IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_3_Channel_1_Vect]();
			CLEAR_BIT(TIMER3_SR,TIM_SR_CC1IF_BIT);	
		}
	if(GET_BIT(TIMER3_SR,TIM_SR_CC2IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_3_Channel_2_Vect]();
			CLEAR_BIT(TIMER3_SR,TIM_SR_CC2IF_BIT);	
		}
	if(GET_BIT(TIMER3_SR,TIM_SR_CC3IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_3_Channel_2_Vect]();
			CLEAR_BIT(TIMER3_SR,TIM_SR_CC3IF_BIT);	
		}
	if(GET_BIT(TIMER3_SR,TIM_SR_CC4IF_BIT))
		{
			GPT_pvoidCallBackFunc[TIM_3_Channel_4_Vect]();
			CLEAR_BIT(TIMER3_SR,TIM_SR_CC4IF_BIT);	
		}
}


void IWDG_voidInit()
{
/*set access key*/
	IWDG_KR = IWDG_ACCESS_KEY;
	IWDG_PR = (IWDG_PRESCALER_VAL & 0x07);
}
void IWDG_voidStart(u16 Copy_u16Ticks)
{
/*set access key*/
	IWDG_KR  = IWDG_ACCESS_KEY;
	IWDG_RLR = (Copy_u16Ticks & 0xFFF);
/*set start key*/
	IWDG_KR  = IWDG_START_KEY;
}
void IWDG_voidRefresh(u16 Copy_u16Ticks,u8 Copy_u8PscVal)
{
///*set access key*/
	IWDG_KR  = IWDG_STOP_KEY;
	IWDG_KR  = IWDG_ACCESS_KEY;
	IWDG_PR = (Copy_u8PscVal & 0x07);
	IWDG_RLR = (Copy_u16Ticks & 0xFFF) ;
/*set start key*/
	IWDG_KR  = IWDG_START_KEY;
}

void IWDG_voidSetPrescaler(u8 Copy_u8PscVal)
{
 /*set access key*/
	IWDG_KR = IWDG_ACCESS_KEY;
	IWDG_PR = (Copy_u8PscVal & 0x07);
}


void WWDG_voidInit()
{
	//Set prescaler
	WWDG_CFR &=~(0x180);
	WWDG_CFR |= (WWDG_PRESCALER_VAL<<7);	
	//Set counter value	
//	WWDG_CR &=~(0x7F);
	WWDG_CR  |= (WWDG_COUNTER_VAL);
	//Set Window value
	WWDG_CFR &=~(0x7F);
	WWDG_CFR |= (WWDG_WINDOW_VAL );
	//start counter
	SET_BIT(WWDG_CR,WWDG_CR_WDGA_BIT);	
}

void WWDG_voidEnableInterrupt(void (* Copy_pvoidCallBackFunc) (void))
{
	 WWDG_pvoidCallBackFunc = Copy_pvoidCallBackFunc ;
	 SET_BIT(WWDG_CFR,WWDG_CFR_EWI_BIT);	
}

void WWDG_voidRefresh()
{
	WWDG_CR |=0x7F;
}
void WWDG_voidSoftwareReset()
{
	CLEAR_BIT(WWDG_CR,WWDG_CR_T_6_BIT);
}
void WWDG_IRQHandler(void)
{
	WWDG_pvoidCallBackFunc();
	CLEAR_BIT(WWDG_SR,WWDG_SR_EWIF_BIT);	
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









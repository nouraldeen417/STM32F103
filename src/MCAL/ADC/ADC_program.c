/*
 * File:   ADC_program.c
 * Author: nour
 *
 * Created on September 8, 2023, 4:44 PM
 */


#include "ADC_interface.h"
#include "ADC_config.h"

/*Global pointer to carry the conversion result in the Asynchronous execution*/
static u16 * ADC_pu16AsynchConversionResult = NULL;


/*Global pointer to function to carry the notification function called by ISR*/
static void (* ADC_pvNotificationFunc )(void) = NULL;
static void (* AWDG_pvNotificationFunc)(void) = NULL;

static u8 ADC_u8State = IDLE;
static u8 ADC_u8Index=0;
static u8 ADC_u8ChainSize;

void ADC1_voidInit(void) 
{

	#if (ADC_1_MODE == ADC_NORMAL_MODE)

		ADC1_CR2 &= ~(0x0E << ADC_CR2_EXTSEL_START_BIT); 
		ADC1_CR2 |= (ADC_1_EXTERNAL_EVENT<< ADC_CR2_EXTSEL_START_BIT); 
	
	#elif (ADC_1_MODE ==  ADC_INJECTED_MODE)
		ADC1_CR2 &= ~(0x07 << ADC_CR2_JEXTSEL_START_BIT); 
		ADC1_CR2 |= (ADC_1_EXTERNAL_EVENT<< ADC_CR2_EXTSEL_START_BIT); 
	
	#else
	#endif	
	#if (ADC_1_ALIGHN == ADC_LEFT_ALIGHN)
		SET_BIT(ADC1_CR2,ADC_CR2_ALIGN_BIT);	
	#else
		CLEAR_BIT(ADC1_CR2,ADC_CR2_ALIGN_BIT);
	#endif	
	#if (ADC_1_CALIBRATION == ENABLE)
		SET_BIT(ADC1_CR2,ADC_CR2_CAL_BIT);	
	#else
		//CLEAR_BIT(ADC1_CR2,ADC_CR2_CAL_BIT);
	#endif
//wakes up the ADC
		SET_BIT(ADC1_CR2,ADC_CR2_ADON_BIT);
}
ErrorStatus ADC1_enumGetTemprature( u16 * Copy_u16Result)
{
	ErrorStatus  LOC_enumErrorState = OK;
	u32  Local_u32TimeoutCounter=0;	
    if (Copy_u16Result != NULL) {
        if (ADC_u8State == IDLE) {            
					  ADC_u8State = BUSY;
  					
						ADC1_SMPR1 &= ~(0x7<<(18));
						ADC1_SMPR1 |=  (ADC_SMP_7_5_CYCLE<<18);	
						ADC1_SQR3 &= ~(0x1F);
						ADC1_SQR3 |=  (16);							
						SET_BIT(ADC1_CR2,ADC_CR2_TSVREFE_BIT);						
          /* Single conversion mode */
						CLEAR_BIT(ADC1_CR2,ADC_CR2_CONT_BIT);
					
            /*ADC Start Conversion*/
            SET_BIT(ADC1_CR2, ADC_CR2_SWSTART_BIT);

            while (GET_BIT(ADC1_SR, ADC_SR_EOC_BIT) == 0 && Local_u32TimeoutCounter < ADC_TIMEOUT) {
                Local_u32TimeoutCounter++;
            }
            if (Local_u32TimeoutCounter == ADC_TIMEOUT) {
                LOC_enumErrorState = Time_OUT_State;
            } else 
						{
							//Clear Flag
               CLEAR_BIT(ADC1_SR, ADC_SR_EOC_BIT);
							#if   (ADC_1_ALIGHN == ADC_LEFT_ALIGHN)
															* Copy_u16Result = (u16)(ADC1_DR>>4);
							#elif (ADC_1_ALIGHN == ADC_RIGHT_ALIGHN)
															* Copy_u16Result = (u16)ADC1_DR;
							#else
							#error "Wrong ADC_ADJUST config"
							#endif                

            }
//						CLEAR_BIT(ADC1_CR2,ADC_CR2_ADON_BIT);
            ADC_u8State = IDLE;


        } else {
            LOC_enumErrorState = Busy_State;
        }
    } else {
        LOC_enumErrorState = NOK;
    }
    return LOC_enumErrorState;

}

ErrorStatus ADC1_enumGetResultSync(ADC_ChannelType Copy_u8Channel, u16 * Copy_u16Result)
{
    ErrorStatus LOC_enumErrorState = OK;
    u32 Local_u32TimeoutCounter = 0;
    if (Copy_u16Result != NULL) {
        if (ADC_u8State == IDLE) {            
					  ADC_u8State = BUSY;
  					
					  ADC1_SQR3 &= ~(0x1F);
						ADC1_SQR3 |= Copy_u8Channel;
						
          /* Single conversion mode */
						CLEAR_BIT(ADC1_CR2,ADC_CR2_CONT_BIT);
					
            /*ADC Start Conversion*/
            SET_BIT(ADC1_CR2, ADC_CR2_SWSTART_BIT);

            while (GET_BIT(ADC1_SR, ADC_SR_EOC_BIT) == 0 && Local_u32TimeoutCounter < ADC_TIMEOUT) {
                Local_u32TimeoutCounter++;
            }
            if (Local_u32TimeoutCounter == ADC_TIMEOUT) {
                LOC_enumErrorState = Time_OUT_State;
            } else 
						{
							//Clear Flag
               CLEAR_BIT(ADC1_SR, ADC_SR_EOC_BIT);
							#if   (ADC_1_ALIGHN == ADC_LEFT_ALIGHN)
															* Copy_u16Result = (u16)(ADC1_DR>>4);
							#elif (ADC_1_ALIGHN == ADC_RIGHT_ALIGHN)
															* Copy_u16Result = (u16)ADC1_DR;
							#else
							#error "Wrong ADC_ADJUST config"
							#endif                

            }
//						CLEAR_BIT(ADC1_CR2,ADC_CR2_ADON_BIT);
            ADC_u8State = IDLE;


        } else {
            LOC_enumErrorState = Busy_State;
        }
    } else {
        LOC_enumErrorState = NOK;
    }
    return LOC_enumErrorState;
}

ErrorStatus ADC_enumStartChainSync(Chain_Type * Copy_Chain)
{
    ErrorStatus LOC_enumErrorState = OK;
    u8 Local_u8Iteator = 0;
		u8  Copy_u8size;

    if (Copy_Chain != NULL) {
			   if (ADC_u8State == IDLE) 
					 {            
					  ADC_u8State = BUSY;
      			Copy_u8size = Copy_Chain->size;
					  /*Set Channel number in first seq*/
  					SET_BIT(ADC1_CR1, ADC_CR1_DISCEN_BIT);
					  ADC1_SQR1 &= ~((0xF)<<20);
						ADC1_SQR1 |=  ((Copy_u8size-1)<<20);  					
						/*Set Required syquence*/
					  ADC_enumSetChannelSequence( Copy_Chain->ChanelPtr ,Copy_Chain->size);

			      for(Local_u8Iteator = 0 ; Local_u8Iteator < Copy_u8size ; Local_u8Iteator++)
						{		
							SET_BIT(ADC1_CR2, ADC_CR2_SWSTART_BIT);
							while (GET_BIT(ADC1_SR, ADC_SR_EOC_BIT) == 0){}								

								#if   (ADC_1_ALIGHN == ADC_LEFT_ALIGHN)
																 Copy_Chain->Result[Local_u8Iteator]  = (u16)(ADC1_DR>>4);
								#elif (ADC_1_ALIGHN == ADC_RIGHT_ALIGHN)
																 Copy_Chain->Result[Local_u8Iteator] = (u16)ADC1_DR;
								#else
								#error "Wrong ADC_ADJUST config"
								#endif                
  						//Clear Flag
						  CLEAR_BIT(ADC1_SR, ADC_SR_EOC_BIT);
						}

						  /*Disable Discontinuous Mode*/
  					  CLEAR_BIT(ADC1_CR1, ADC_CR1_DISCEN_BIT);					 
  						/*Adc Disable*/
						  CLEAR_BIT(ADC1_CR2,ADC_CR2_ADON_BIT);
							ADC_u8State =IDLE;
				 } else
			 {
            LOC_enumErrorState = Busy_State;
       }
		 }			 
    else 
		{
        LOC_enumErrorState = NOK;
    }
    return LOC_enumErrorState;
}
ErrorStatus ADC_enumStartChainAsync(Chain_Type * Copy_Chain)
{
    ErrorStatus LOC_enumErrorState = OK;

    if (Copy_Chain != NULL) {
			   if (ADC_u8State == IDLE) {            
					  ADC_u8State = BUSY;
						ADC_u8ChainSize = Copy_Chain->size;
						ADC_pu16AsynchConversionResult = Copy_Chain->Result;
						ADC_pvNotificationFunc = Copy_Chain->NotificationFunc;
            ADC_u8Index = 0;
						/*Enable Discontinuous Mode*/
 					  SET_BIT(ADC1_CR1, ADC_CR1_DISCEN_BIT);
  		      /*Set Number of channels*/
					  ADC1_SQR1 &= ~((0xF)<<20);
						ADC1_SQR1 |=  ((ADC_u8ChainSize-1)<<20);  					
						/*Set Required syquence*/
					  ADC_enumSetChannelSequence( Copy_Chain->ChanelPtr, Copy_Chain->size);
						/*ADC Interrupt Enable*/
            SET_BIT(ADC1_CR1, ADC_CR1_EOCIE_BIT);
            /*ADC Start Conversion*/
						SET_BIT(ADC1_CR2, ADC_CR2_SWSTART_BIT);
				 } else
			 {
            LOC_enumErrorState = Busy_State;
       }
		 }			 
    else 
		{
        LOC_enumErrorState = NOK;
    }
    return LOC_enumErrorState;

}
void ADC_enumSetSamplCycle(ADC_ChannelType  Copy_u8Channel , u8  Copy_u8SampleCycle)
{
	  Copy_u8SampleCycle &= 0x7;
		if(Copy_u8Channel < ADC_Channel_10)
		{
			ADC1_SMPR2 &= ~(0x7<<(Copy_u8Channel*3));
			ADC1_SMPR2 |=  (Copy_u8SampleCycle<<(Copy_u8Channel*3));
		
		}else
		{
			Copy_u8Channel %= ADC_Channel_10;
			ADC1_SMPR1 &= ~(0x7<<(Copy_u8Channel*3));
			ADC1_SMPR1 |=  (Copy_u8SampleCycle<<(Copy_u8Channel*3));	
		}

}
 
ErrorStatus ADC_enumSetChannelSequence(ADC_ChannelType * Copy_channel , u8  Copy_u8size )
{
    ErrorStatus LOC_enumErrorState = OK;
    u8 Local_u8Iteator = 0;
		
    if (Copy_channel != NULL) 
			{
				for(Local_u8Iteator = 0 ; Local_u8Iteator < Copy_u8size ; Local_u8Iteator++)
				{		
						if(Copy_u8size < (ADC_SQR1_MAX_SIZE+1))
						{
							ADC1_SQR3 &= ~((0x1F)<<Local_u8Iteator*5);
							ADC1_SQR3 |=  ((Copy_channel[Local_u8Iteator])<<Local_u8Iteator*5);								
						
						}else if(Copy_u8size < (ADC_SQR2_MAX_SIZE+1))
						{
							ADC1_SQR2 &= ~((0x1F)<<Local_u8Iteator*5);
							ADC1_SQR2 |=  ((Copy_channel[Local_u8Iteator])<<Local_u8Iteator*5);									
						}else
						{	
							ADC1_SQR1 &= ~((0x1F)<<Local_u8Iteator*5);
							ADC1_SQR1 |=  ((Copy_channel[Local_u8Iteator])<<Local_u8Iteator*5);	
						}							
				}
		 }			 
    else 
		{
        LOC_enumErrorState = NOK;
    }
    return LOC_enumErrorState;
}

ErrorStatus ADC_enumEnableAnalogwatchdog(AWDG_Type * Copy_AWDG)
{
    ErrorStatus LOC_enumErrorState = OK;
		ADC_ChannelType  Copy_channel = Copy_AWDG->Chanel;
	  if (Copy_AWDG != NULL) 
			{
				/*Set HigherThreshold*/
				ADC1_HTR = (Copy_AWDG->HigherThreshold & 0xFFF); 	
				/*Set LowerThreshold*/
				ADC1_LTR = (Copy_AWDG->LowerThreshold  & 0xFFF);				
				if(Copy_channel == All_Regular_Channels)
				{
						SET_BIT(ADC1_CR1,ADC_CR1_AWDEN_BIT);
						CLEAR_BIT(ADC1_CR1,ADC_CR1_JAWDEN_BIT);
				}else if(Copy_channel == All_Injected_Channels)
				{
						SET_BIT(ADC1_CR1,ADC_CR1_JAWDEN_BIT);				
						CLEAR_BIT(ADC1_CR1,ADC_CR1_AWDEN_BIT);
				}else
				{ /*Regular Channel For now*/
					SET_BIT(ADC1_CR1,ADC_CR1_AWDSGL_BIT);
					SET_BIT(ADC1_CR1,ADC_CR1_AWDEN_BIT);
  				ADC1_CR1 &= ~(0x1F);
				  ADC1_CR1 |= (Copy_channel & 0x1F);
				}
				
				if(Copy_AWDG->NotificationFunc != NULL)
				{
					AWDG_pvNotificationFunc = Copy_AWDG->NotificationFunc ;
					SET_BIT(ADC1_CR1,ADC_CR1_AWDIE_BIT);
				}else
				{
					CLEAR_BIT(ADC1_CR1,ADC_CR1_AWDIE_BIT);				
				}		 
			
			}			 
    else 
		{
				LOC_enumErrorState = NOK;
		}
    return LOC_enumErrorState;
}


void ADC1_2_IRQHandler(void)
{
	if(GET_BIT(ADC1_SR,ADC_SR_AWD_BIT))
	{
		AWDG_pvNotificationFunc();
		CLEAR_BIT(ADC1_SR,ADC_SR_AWD_BIT);		
	}else if(GET_BIT(ADC1_SR,ADC_SR_EOC_BIT))
	{
		#if   (ADC_1_ALIGHN == ADC_LEFT_ALIGHN)
		ADC_pu16AsynchConversionResult[ADC_u8Index] = (u16)(ADC1_DR>>4);

		#elif (ADC_1_ALIGHN == ADC_RIGHT_ALIGHN)
				ADC_pu16AsynchConversionResult[ADC_u8Index] = (u16)(ADC1_DR);
		#else
		#error "Wrong ADC_ADJUST config"
		#endif                

		ADC_u8Index++;//1 2 3
		if(ADC_u8Index == ADC_u8ChainSize)
		{
			ADC_u8State = IDLE;
			/*Disable interrupt*/
			CLEAR_BIT(ADC1_CR1,ADC_CR1_EOCIE_BIT);
			/*Enable Discontinuous Mode*/
			CLEAR_BIT(ADC1_CR1, ADC_CR1_DISCEN_BIT);
			/*Disable ADC*/
			CLEAR_BIT(ADC1_CR2,ADC_CR2_ADON_BIT);
			ADC_pvNotificationFunc();			
		}else
		{
			SET_BIT(ADC1_CR2, ADC_CR2_SWSTART_BIT);
		}


		//Clear Flag
		 CLEAR_BIT(ADC1_SR, ADC_SR_EOC_BIT);
  }
}


#include "lip\Macros.h"
#include "lip\STD_TYPES.h"  
#include "MCAL\NVIC\NVIC_interface.h"
#include "MCAL\SYSTICK\SYSTICK_interface.h"
#include "MCAL\DIO\DIO_interface.h"
#include "MCAL\PORT\PORT_interface.h"
#include "MCAL\EXTI\EXTI_interface.h"
#include "MCAL\TIMERS\TIMERS_interface.h"
#include "MCAL\RCC\RCC_interface.h"
#include "MCAL\RTC\RTC_interface.h"
#include "MCAL\ADC\ADC_interface.h"
#include "MCAL\SPI\SPI_interface.h"
#include "MCAL\USART\USART_interface.h"
#include "MCAL\DMA\DMA_interface.h"
#include "HAL\LCD\LCD_interface.h"

//#define RCC_APB1ENR			*((volatile u32*)0x4002101C)
//#define RCC_APB2ENR			*((volatile u32*)0x40021018)
PORT_ConfType Copy_ConfArray[]={  {Channel_A_1,PORT_Id_A,PIN_OUTPUT_PUSH_PULL_MAX_SPEED_10,PORT_None},
																	{Channel_A_5,PORT_Id_A,PIN_INPUT_ANALOG,PORT_None},
																	{Channel_B_0,PORT_Id_B,PIN_OUTPUT_PUSH_PULL_MAX_SPEED_10 ,PORT_None},
																	{Channel_B_2,PORT_Id_B,PIN_ALT_OUTPUT_OPEN_DRAIN_MAX_SPEED_10,PORT_None}};

EXTI_ConfType Copy_Conf={EXTI_Pin_5,EXTI_Rising,EXTI_Interrupt};
u16 x=0;

RTC_ConfType time={3,0,0,0};
RTC_ConfType time2;


void myFunc();
void myFunc2();
ADC_ChannelType CopyChanels[5] ={ADC_Channel_2,ADC_Channel_3,ADC_Channel_4,ADC_Channel_2};
u16 Copy_u16Res[4];
AWDG_Type AWDGConf ={ADC_Channel_4,3000,2000,NULL};
Chain_Type ChainConf={CopyChanels,Copy_u16Res,4,myFunc};
GPT_ChannelConfigType Copy_conf={TIMER_1,GPT_Mode_Periodic ,2000,5000,0};
GPT_ChannelConfigType Copy_conf2={TIMER_3,GPT_Mode_Periodic ,2000,5000,myFunc};
ICU_ChannelConfigType Copy_ICUconf={TIMER_3,ICU_Channel_2,ICU_Raising,myFunc};
//GPT_OutputconfigType  Copy_Outconf={TIMER_1,ICU_Channel_1,1000,3,myFunc};
//GPT_OutputconfigType  Copy_Outconf2={TIMER_3,ICU_Channel_1,1000,3,0};
SPI_confType spi_conf={Spi_16_Bit_Date,Spi_Msb_First,Spi_Master,Spi_Freq_Divided_By_64,Spi_First_Clock_Transition,Spi_Idle_0};
USART_confType usart_conf={USART_Id_2,USART_ASYNC,USART_DATA_8_BITS,USART_STOP_1_BIT,USART_Parity_Disable,52,0};
u16 Rdata[6];
u8 Tdata[6]={'N','o','u','r','a','n'};
//SPI_BufferType spi_RTData = {Tdata,Rdata,6,0};
USART_BufferType usart_buffConf = {USART_Id_2,Rdata,4,myFunc2};
DMA_confType dma_conf={DMA_Channel_7,
											 DMA_Normal_Mode,
											 DMA_Medium_Priority,
	                     DMA_Peripheral_8_Bits,
	                     DMA_Memory_8_Bits,
	                     DMA_Peripheral_Increment_Disable,
											 DMA_Memory_Increment_Enable,
                       DMA_Read_From_Memory,
	                     6,
                       (u32)&USART_DR(USART_2_BASE_ADD),
                       (u32)0x20000170,
                       myFunc2,0,0		};

DMA_confType dma2_conf={DMA_Channel_6,
											 DMA_Normal_Mode,
											 DMA_Medium_Priority,
	                     DMA_Peripheral_8_Bits,
	                     DMA_Memory_8_Bits,
	                     DMA_Peripheral_Increment_Disable,
											 DMA_Memory_Increment_Enable,
                       DMA_Read_From_Peripheral,
	                     6,
                       (u32)&USART_DR(USART_2_BASE_ADD),
                       (u32)0x20000170,
                       0,0,0		};											 
void myFunc()
{
//GPT_CLearCapture_CompareFlag(TIMER_2,ICU_Channel_3);
//GPT_CLearFlag(TIMER_2);	

DIO_enumTogglePinValue(DIO_Port_A,Pin_A_1);

//LCD_voidSendNumber(ChainConf.Result[0]);
//LCD_voidSendNumber(ChainConf.Result[1]);
LCD_voidSendNumber(ChainConf.Result[0]);
LCD_voidSendData(' ');
LCD_voidSendNumber(ChainConf.Result[1]);
LCD_voidSendData(' ');
LCD_voidSendNumber(ChainConf.Result[2]);
LCD_voidSendData(' ');
LCD_voidSendNumber(ChainConf.Result[3]);
LCD_voidSendData(' ');
	//	DIO_enumSetPinValue(DIO_Port_A,Pin_A_1,DIO_Pin_LOW);
//	GPT_DisableCapture_CompareMode(TIMER_1,ICU_Channel_4);
}
void myFunc2()
{
USART_enumWait_TC_Flag(USART_Id_2);
  CLEAR_BIT(USART_CR1(USART_2_BASE_ADD),CR1_TE_BIT);

		
//	LCD_voidSendData(':');
//for(u8 i =0; i<6;i++)
//{
//LCD_voidSendData(Rdata[i]);
//}


//	RTC_voidGetTimeandDate(&time2);	
//  	LCD_voidDisplayClear();
//	  LCD_voidSendNumber(time2.Seconds);
//		LCD_voidSendData(':');
//		LCD_voidSendNumber(time2.Minutes);
//		LCD_voidSendData(':');
//		LCD_voidSendNumber(time2.Hours);
//		LCD_voidSendData(':');
//		LCD_voidSendNumber(time2.Days%30);
//		LCD_voidSendData(':');
//		LCD_voidSendNumber((time2.Days)/30);
//		LCD_voidSendData(':');
//		LCD_voidSendNumber((time2.Days)/365);

	
}
int main(void){
	DIO_enumSetPinDirection(DIO_Port_A,Pin_A_1,DIO_Pin_Output);
		SYSTICK_voidInit();

	

//	DIO_enumSetPinValue(DIO_Port_A,Pin_A_1,DIO_Pin_LOW);
//	IWDG_voidRefresh(0xFFFF);

//    NVIC_enumInterruptEnable(SPI_1_Interrupt);
//    NVIC_enumInterruptEnable(RTC_Interrupt);

  	LCD_voidInit();

NVIC_enumInterruptEnable(USART_2_Interrupt);	
NVIC_enumInterruptEnable(DMA_1_Channe_6_Interrupt);		
NVIC_enumInterruptEnable(DMA_1_Channe_7_Interrupt);		

//    RCC_voidEnableClock (RCC_TIM_1);
//		RCC_voidEnableClock(RCC_TIM_2);
//		RCC_voidEnableClock(RCC_TIM_3);	
//    RTC_voidInit();
//  	//RTC_voidSetTimeandDate(&time);
//	  RCC_voidRTCEnableClock();
//	  RTC_voidSetAlarmTime(&time,myFunc);
//NVIC_enumInterruptEnable(TIM_1_CC_Interrupt);	
//NVIC_enumInterruptEnable(TIM_1_UP_Interrupt);	
//NVIC_enumInterruptEnable(TIM_2_Interrupt);	
//NVIC_enumInterruptEnable(TIM_3_Interrupt);
RCC_voidADCSetPresacaler(0);
//PORT_voidInit(Copy_ConfArray);
//TIMER_voidICUInit(& Copy_ICUconf);
//TIMER_Init(&Copy_conf);
//TIMER_Init(&Copy_conf2);	
//GPT_OutputCompareModeInit(& Copy_Outconf);			
//GPT_OutputCompareModeInit(& Copy_Outconf2);			
//TIMER_voidICUInit(& Copy_ICUconf);			
//GPT_StartTimer(TIMER_1,0);
//GPT_StartTimer(TIMER_3,0);
//RCC_voidRest(RCC_TIM_3);
//TIM2_enumDetectCaptureSync (ICU_Channel_4, ICU_Failling,&x);
//	EXTI_enumSetConf		  	  (&Copy_Conf );
//EXTI_voidSetCallBack (myFunc,EXTI_Pin_5);	
//DIO_enumSetPinDirection(DIO_Port_A,Pin_A_1,DIO_Pin_Output);
//PORT_voidInit(Copy_ConfArray);
//DIO_enumSetPortValue(DIO_Port_A,DIO_Port_HIGH);
//DIO_enumSetPortValue(DIO_Port_B,DIO_Port_HIGH);
//DIO_enumSetPortValue(DIO_Port_C,DIO_Port_HIGH);

//RCC_voidEnableClock(RCC_SPI_1);
//SPI_enumInitConfig (& spi_conf) ;
//SPI_enumBufferTranceiverAsynch  (& spi_RTData) ;
//LCD_voidSendNumber(x);


RCC_voidEnableClock(RCC_USART_2);
USART_enumInitConfig (& usart_conf);




USART_enumRecevieData_DMA  (&dma2_conf,USART_Id_2);
DMA_enumWait_TCIF_Flag    (dma2_conf.Channel_Id) ;
LCD_voidSendData('b');

USART_enumSendData_DMA(&dma_conf,USART_Id_2,0,0);

while(1){

}
return 0;
}

	

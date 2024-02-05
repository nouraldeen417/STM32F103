/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _TIMERS_INTERFACE_H
#define _TIMERS_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
#include "TIMERS_private.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TIMER_6_VECTOR				6
#define TIMER_7_VECTOR				7

#define TIMER_CLOCK_DIVISION_NONE				0 
#define TIMER_CLOCK_DIVISION_BY_2				1
#define TIMER_CLOCK_DIVISION_BY_4				2

#define ICU_TIMER_FILTER_1_SAMPLES			0    //0000
#define ICU_TIMER_FILTER_2_SAMPLES			1    //0001
#define ICU_TIMER_FILTER_4_SAMPLES			2    //0010
#define ICU_TIMER_FILTER_8_SAMPLES			3    //0011
#define ICU_TIMER_FILTER_16_SAMPLES			4    //0100
#define ICU_TIMER_FILTER_32_SAMPLES			5    //0101

#define ICU_INPUT_PSC_NONE				0		//00 
#define ICU_INPUT_PSC_BY_2				1		//01
#define ICU_INPUT_PSC_BY_4				2		//10
#define ICU_INPUT_PSC_BY_8				3		//11


#define TIM_2_ICU_Channel_1				0
#define TIM_2_ICU_Channel_2				1
#define TIM_2_ICU_Channel_3				2
#define TIM_2_ICU_Channel_4				3
#define TIM_3_ICU_Channel_1				4
#define TIM_3_ICU_Channel_2				5
#define TIM_3_ICU_Channel_3				6
#define TIM_3_ICU_Channel_4				7



#define IWDG_PSC_BY_4				  0		//000 
#define IWDG_PSC_BY_8			  	1		//001
#define IWDG_PSC_BY_16				2		//010
#define IWDG_PSC_BY_32		  	3		//011
#define IWDG_PSC_BY_64	  		4		//100 
#define IWDG_PSC_BY_128 			5		//101
#define IWDG_PSC_BY_256				6		//110

#define WWDG_PSC_BY_1				  0		//00 
#define WWDG_PSC_BY_2			  	1		//01
#define WWDG_PSC_BY_4	  			2		//10
#define WWDG_PSC_BY_8 		  	3		//11






/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
    TIMER_1,
		TIMER_2,   
		TIMER_3,
	  MAX_TIMER_NUM,
}GPT_ChannelType;

typedef enum {
GPT_Mode_OneShot,
GPT_Mode_Periodic
}GPT_ModeType;
typedef enum {
GPT_Output_Mode_NONE,
GPT_Active_level_On_match,
GPT_Inactive_level_On_match,
GPT_Toggle_On_match,
GPT_Force_inactive_level,
GPT_Force_active_level,
PWM_Active_MODE_1,//- In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 
PWM_Active_MODE_2	//- In upcounting, channel 1 is inactive as long as TIMx_CNT<TIMx_CCR1 
}GPT_OutputModeType;


typedef enum {
    ICU_Channel_1,
		ICU_Channel_2,   
		ICU_Channel_3,
	  ICU_Channel_4,
	  MAX_Channel_NUM,
}ICU_ChannelType;
typedef enum {
    ICU_Raising,
		ICU_Failling,   
}ICU_EdgeType;
typedef struct 
{
  GPT_ChannelType 		ChannelID;
	GPT_ModeType				Mode		 ;
  u16 								Prescaler;
  u16 								Preload  ;
  void 								(*GPT_puNotifacationFunction)(void);
}GPT_ChannelConfigType;
typedef struct 
{
  GPT_ChannelType 		TimerID;
	ICU_ChannelType			ChannelID;
	ICU_EdgeType				Edge;	
  void 								(*GPT_puNotifacationFunction)(void);
}ICU_ChannelConfigType;
typedef struct 
{
  GPT_ChannelType 		      TimerID;
	ICU_ChannelType		      	ChannelID;
	u16												CompareMathReg;
	GPT_OutputModeType				Mode;	
  void 								      (*GPT_puNotifacationFunction)(void);
}GPT_OutputconfigType;
typedef struct 
{
  GPT_ChannelType 		      TimerID;
	ICU_ChannelType		      	ChannelID;
	u16												CompareMathReg;
	GPT_OutputModeType  				Mode;	
  void 								      (*GPT_puNotifacationFunction)(void);
}GPT_PWMType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/****************************************Counter Mode Functions*********************************************************/

ErrorStatus TIMER_Init(const GPT_ChannelConfigType *Copy_conf);
void GPT_EnableNotifaction(GPT_ChannelType Cpoy_u8ChannelId);
void GPT_DisableNotifaction(GPT_ChannelType Cpoy_u8ChannelId);
void GPT_StartTimer(GPT_ChannelType Cpoy_u8ChannelId,u16 Value);
void GPT_StopTimer(GPT_ChannelType Cpoy_u8ChannelId);
void GPT_CLearFlag(GPT_ChannelType Cpoy_u8ChannelId);
void GPT_GenerateUpdateEvent(GPT_ChannelType Cpoy_u8ChannelId);
u16  GPT_GetTimerCurrentVal(GPT_ChannelType Cpoy_u8ChannelId);
void GPT_SetTimerPreloadVal(GPT_ChannelType Cpoy_u8ChannelId,u16 Copy_u16RegVal);
/****************************************Output Compare Mode Functions******************************************************************************/
/*Note: this function didn't start timer it configur mode only..*/
ErrorStatus GPT_OutputCompareModeInit(GPT_OutputconfigType * Copy_Mode);
void GPT_DisableCapture_CompareMode(GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId );
void GPT_CLearCapture_CompareFlag(GPT_ChannelType Cpoy_u8ChannelId,ICU_ChannelType Copy_ChannelId);
void GPT_SetCapture_CompareVal   (GPT_ChannelType Copy_u8TimerId,ICU_ChannelType Copy_ChannelId,u16 Copy_u16RegVal);
/****************************************ICU Mode Functions******************************************************************************/
ErrorStatus TIMER_voidICUInit                  (const ICU_ChannelConfigType *Copy_conf);
ErrorStatus TIMER_enumICUSetTrigger            (GPT_ChannelType Cpoy_u8TimerId,ICU_ChannelType Cpoy_u8ChannelId,ICU_EdgeType Copy_u8Trigger);
void TIMER_voidCapture_CompareInterrupt        ( GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId );
void TIMER_voidCapture_CompareInterrupt        ( GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId );
ErrorStatus TIMER_enumICRValue                 ( GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId,u16 *Copy_pu16Value);
ErrorStatus TIM2_enumDetectCaptureSync         (ICU_ChannelType Copy_u8ChannelId,ICU_EdgeType Copy_u8Trigger, u16 *Copy_u16Ticks);
ErrorStatus TIM3_enumDetectCaptureSync         (ICU_ChannelType Copy_u8ChannelId,ICU_EdgeType Copy_u8Trigger, u16 *Copy_u16Ticks);
/****************************************PWM Mode Functions******************************************************************************/
/*Note: this function didn't start timer it configur mode only..*/
ErrorStatus GPT_PWMModeInit(GPT_PWMType * Copy_Mode);
void GPT_DisablePWMMode(GPT_ChannelType Copy_TimerId,ICU_ChannelType Copy_ChannelId );
/****************************************IWDG Functions******************************************************************************/
void IWDG_voidInit();
void IWDG_voidStart       (u16 Copy_u16Ticks);
void IWDG_voidSetPrescaler(u8 Copy_u16Ticks);
void IWDG_voidRefresh     (u16 Copy_u16Ticks,u8 Copy_u8PscVal);

/****************************************WWDG Functions******************************************************************************/
void WWDG_voidInit();
void WWDG_voidEnableInterrupt(void (* Copy_pvoidCallBackFunc) (void));
void WWDG_voidRefresh     ();
void WWDG_voidSoftwareReset();






static void TIMER1_voidInit  (const GPT_ChannelConfigType *Copy_conf);
static void TIMER2_voidInit  (const GPT_ChannelConfigType *Copy_conf);
static void TIMER3_voidInit  (const GPT_ChannelConfigType *Copy_conf);

static void ICU_TIM1_voidInit(const ICU_ChannelConfigType *Copy_conf);
static void ICU_TIM2_voidInit(const ICU_ChannelConfigType *Copy_conf);
static void ICU_TIM3_voidInit(const ICU_ChannelConfigType *Copy_conf);

static void	ICU_TIM1_voidSetTrigger(ICU_ChannelType Copy_u8ChannelId,ICU_EdgeType Copy_u8Trigger);
static void	ICU_TIM2_voidSetTrigger(ICU_ChannelType Copy_u8ChannelId,ICU_EdgeType Copy_u8Trigger);
static void	ICU_TIM3_voidSetTrigger(ICU_ChannelType Copy_u8ChannelId,ICU_EdgeType Copy_u8Trigger);

#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

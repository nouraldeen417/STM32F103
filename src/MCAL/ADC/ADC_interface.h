
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _ADC_INTERFACE_H
#define	_ADC_INTERFACE_H

#include "../../lip/STD_TYPES.h"
#include "ADC_private.h"
#include "../../lip/Macros.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ADC ALIGHN Result */
#define ADC_RIGHT_ALIGHN               0
#define ADC_LEFT_ALIGHN                1
/* ADC Enable*/
#define DISABLE                        0
#define ENABLE                         1
/*ADC Start Conversion Mode*/
#define ADC_SINGLE_CONVERSION          0
#define ADC_FREE_RUNNING               1

/*ADC Sample Time Select Bits*/
#define ADC_SMP_1_5_CYCLE               0
#define ADC_SMP_7_5_CYCLE               1
#define ADC_SMP_13_5_CYCLE              2
#define ADC_SMP_28_5_CYCLE              3
#define ADC_SMP_41_5_CYCLE              4
#define ADC_SMP_55_5_CYCLE              5
#define ADC_SMP_71_5_CYCLE              6
#define ADC_SMP_239_5_CYCLE             7

/* ADC Auto Trigger Source*/
#define ADC_TIMER_1_TRGO                0
#define ADC_TIMER_1_CC4                 1
#define ADC_TIMER_2_TRGO                2
#define ADC_TIMER_2_CC4                 3
#define ADC_TIMER_3_TRGO                4
#define ADC_TIMER_3_CC4                 5
#define ADC_EXTI                        6
#define ADC_START_BIT                   7
/*ADC Modes*/
#define ADC_SCAN_MODE										0
#define ADC_INJECTED_MODE								1
#define ADC_NORMAL_MODE									2
/*Channel State*/
#define ADC_SINGLE_CHANNEL             0
#define ADC_CHAIN_CHANNEL              1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	  ADC_Channel_0,
    ADC_Channel_1,
		ADC_Channel_2,   
		ADC_Channel_3,
	  ADC_Channel_4,
    ADC_Channel_5,
		ADC_Channel_6,   
		ADC_Channel_7,
	  ADC_Channel_8,
    ADC_Channel_9,
		ADC_Channel_10,   
		ADC_Channel_11,
	  ADC_Channel_12,
	  ADC_Channel_13,
		ADC_Channel_14,   
		ADC_Channel_15,
	  ADC_Channel_16,
	  MAX_ADC_Channel_NUM,
	  All_Injected_Channels,
    All_Regular_Channels
}ADC_ChannelType;

typedef struct {
    ADC_ChannelType    *ChanelPtr;
    u16 							 *Result;
    u8 									size;
    void (* NotificationFunc)(void);
} Chain_Type;

typedef struct {
    ADC_ChannelType     Chanel;
    u16 							  HigherThreshold;
    u16 								LowerThreshold;
  	void (* NotificationFunc)(void);
} AWDG_Type;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void ADC1_voidInit(void);
ErrorStatus ADC1_enumGetResultSync(ADC_ChannelType Copy_u8Channel, u16 * Copy_u16Result);
ErrorStatus ADC_enumStartChainSync(Chain_Type * Copy_Chain);
ErrorStatus ADC_enumEnableAnalogwatchdog(AWDG_Type * Copy_Chain);
ErrorStatus ADC1_enumGetTemprature( u16 * Copy_u16Result);
ErrorStatus ADC_enumStartConversionAsync(u8 Copy_u8Channel, void (* Copy_pvNotificationFunc)(void), u16 * Copy_pu16Result);
ErrorStatus ADC_enumStartChainAsync(Chain_Type * Copy_Chain);
ErrorStatus ADC_enumSetChannelSequence(ADC_ChannelType * Copy_Chain, u8  Copy_u8size);
void ADC_enumSetSamplCycle(ADC_ChannelType Copy_Chain,u8  Copy_u8SampleCycle);

#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h

*********************************************************************************************************************/

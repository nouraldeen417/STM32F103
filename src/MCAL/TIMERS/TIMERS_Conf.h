/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef _TIMER_CONFIGRATION_H
#define _TIMER_CONFIGRATION_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 /*Timer 2 Cofigration :
												as auto-reload register register is not buffered
												


*/

#define TIMER_1_PRELOAD_REG_BUFFERED_ENABLE        			       0 //to enable Buffered reg in preload Reg
#define TIMER_1_CLOCK_DIVISION 																 TIMER_CLOCK_DIVISION_NONE
#define TIMER_1_PRESCALER_VAL 																 0 //Value of prescaler (1:2^16)
#define TIMER_1_START_COUNTER_VAL 														 0 //Value of Counter (1:2^16)
#define TIMER_1_RELOAD_VAL 																		 0 //Value of Reload (1:2^16)
#define TIMER_1_DOWN_COUNTING																	 0 //to enable Down counter
#define ICU_TIM_1_INPUT_FILTER																 ICU_TIMER_FILTER_8_SAMPLES //Value of INPUT_FILTER sampling after  
#define ICU_TIM_1_INPUT_PRESCALER															 TIMER_CLOCK_DIVISION_NONE


#define TIMER_2_PRELOAD_REG_BUFFERED_ENABLE        			       0 //to enable Buffered reg in preload Reg
#define TIMER_2_CLOCK_DIVISION 																 TIMER_CLOCK_DIVISION_NONE
#define TIMER_2_PRESCALER_VAL 																 0 //Value of prescaler (1:2^16)
#define TIMER_2_START_COUNTER_VAL 														 0 //Value of Counter (1:2^16)
#define TIMER_2_RELOAD_VAL 																		 0 //Value of Reload (1:2^16)
#define TIMER_2_DOWN_COUNTING																	 0 //to enable Down counter
#define ICU_TIM_2_INPUT_FILTER																 ICU_TIMER_FILTER_8_SAMPLES //Value of INPUT_FILTER sampling after  
#define ICU_TIM_2_INPUT_PRESCALER															 TIMER_CLOCK_DIVISION_NONE




#define TIMER_3_PRELOAD_REG_BUFFERED_ENABLE        			       0 //to enable Buffered reg in preload Reg
#define TIMER_3_CLOCK_DIVISION 																 TIMER_CLOCK_DIVISION_NONE
#define TIMER_3_PRESCALER_VAL 																 0 //Value of prescaler (1:2^16)
#define TIMER_3_START_COUNTER_VAL 														 0 //Value of Counter (1:2^16)
#define TIMER_3_RELOAD_VAL 																		 0 //Value of Reload (1:2^16)
#define TIMER_3_DOWN_COUNTING																	 0 //to enable Down counter
#define ICU_TIM_3_INPUT_FILTER																 ICU_TIMER_FILTER_8_SAMPLES //Value of INPUT_FILTER sampling after  
#define ICU_TIM_3_INPUT_PRESCALER															 TIMER_CLOCK_DIVISION_NONE
/************************************************IWDG**************************/
/*
 IWDG_PSC_BY_4				 
 IWDG_PSC_BY_8			  	
 IWDG_PSC_BY_16				
 IWDG_PSC_BY_32		  	
 IWDG_PSC_BY_64	  		
 IWDG_PSC_BY_128 			
 IWDG_PSC_BY_256	

*/
#define IWDG_PRESCALER_VAL 																 IWDG_PSC_BY_64 
/* 
 WWDG_PSC_BY_1				 
 WWDG_PSC_BY_2			  	
 WWDG_PSC_BY_4				
 WWDG_PSC_BY_8	*/
#define WWDG_PRESCALER_VAL 																 WWDG_PSC_BY_8
#define WWDG_COUNTER_VAL 																   0x70								
#define WWDG_WINDOW_VAL 																   78								















/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

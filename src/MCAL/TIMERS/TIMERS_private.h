/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _TIMERS_PRIVATE_H
#define _TIMERS_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/***********************************Basic timers (TIM6 and TIM7)******************************************************/
/*
0x40001400 - 0x4000 17FF TIM7 timer

0x40001000 - 0x4000 13FF TIM6 timer
0x4001 2C00 - 0x4001 2FFF TIM1 timer
0x40000400 - 0x4000 07FF TIM3 timer
0x40000000 - 0x4000 03FF TIM2 timer
*/

#define TIMER3_CR1           		 (*((volatile u32*)0x40000400))
#define TIMER3_CR2           		 (*((volatile u32*)0x40000404))
#define TIMER3_SMCR           	 (*((volatile u32*)0x40000408))
#define TIMER3_DIER           	 (*((volatile u32*)0x4000040C))
#define TIMER3_SR           		 (*((volatile u32*)0x40000410))
#define TIMER3_EGR          		 (*((volatile u32*)0x40000414))
#define TIMER3_CCMR1           	 (*((volatile u32*)0x40000418))
#define TIMER3_CCMR2           	 (*((volatile u32*)0x4000041C))
#define TIMER3_CCER           	 (*((volatile u32*)0x40000420))
#define TIMER3_CNT           		 (*((volatile u32*)0x40000424))
#define TIMER3_PSC           		 (*((volatile u32*)0x40000428))
#define TIMER3_ARR           		 (*((volatile u32*)0x4000042C))
#define TIMER3_CCR1           	 (*((volatile u32*)0x40000434))
#define TIMER3_CCR2           	 (*((volatile u32*)0x40000438))
#define TIMER3_CCR3           	 (*((volatile u32*)0x4000043C))
#define TIMER3_CCR4           	 (*((volatile u32*)0x40000440))
#define TIMER3_DCR  	         	 (*((volatile u32*)0x40000448))
#define TIMER3_DMAR           	 (*((volatile u32*)0x4000044C))
#define TIMER3_CCR            	 ((volatile u32*)0x40000434)
	
#define TIMER2_CR1           		 (*((volatile u32*)0x40000000))
#define TIMER2_CR2           		 (*((volatile u32*)0x40000004))
#define TIMER2_SMCR           	 (*((volatile u32*)0x40000008))
#define TIMER2_DIER           	 (*((volatile u32*)0x4000000C))
#define TIMER2_SR           		 (*((volatile u32*)0x40000010))
#define TIMER2_EGR          		 (*((volatile u32*)0x40000014))
#define TIMER2_CCMR1           	 (*((volatile u32*)0x40000018))
#define TIMER2_CCMR2           	 (*((volatile u32*)0x4000001C))
#define TIMER2_CCER           	 (*((volatile u32*)0x40000020))
#define TIMER2_CNT           		 (*((volatile u32*)0x40000024))
#define TIMER2_PSC           		 (*((volatile u32*)0x40000028))
#define TIMER2_ARR           		 (*((volatile u32*)0x4000002C))
#define TIMER2_CCR1           	 (*((volatile u32*)0x40000034))
#define TIMER2_CCR2           	 (*((volatile u32*)0x40000038))
#define TIMER2_CCR3           	 (*((volatile u32*)0x4000003C))
#define TIMER2_CCR4           	 (*((volatile u32*)0x40000040))
#define TIMER2_DCR  	         	 (*((volatile u32*)0x40000048))
#define TIMER2_DMAR           	 (*((volatile u32*)0x4000004C))

#define TIMER2_CCR            	 ((volatile u32*)0x40000034)
#define TIMER2_CCMR           	 ((volatile u32*)0x40000018)
//0x4001 2C00 
	
#define TIMER1_CR1           		 (*((volatile u32*)0x40012C00))
#define TIMER1_CR2           		 (*((volatile u32*)0x40012C04))
#define TIMER1_SMCR           	 (*((volatile u32*)0x40012C08))
#define TIMER1_DIER           	 (*((volatile u32*)0x40012C0C))
#define TIMER1_SR           		 (*((volatile u32*)0x40012C10))
#define TIMER1_EGR          		 (*((volatile u32*)0x40012C14))
#define TIMER1_CCMR1           	 (*((volatile u32*)0x40012C18))
#define TIMER1_CCMR2           	 (*((volatile u32*)0x40012C1C))
#define TIMER1_CCER           	 (*((volatile u32*)0x40012C20))
#define TIMER1_CNT           		 (*((volatile u32*)0x40012C24))
#define TIMER1_PSC           		 (*((volatile u32*)0x40012C28))
#define TIMER1_ARR           		 (*((volatile u32*)0x40012C2C))
#define TIMER1_CCR1           	 (*((volatile u32*)0x40012C34))
#define TIMER1_CCR2           	 (*((volatile u32*)0x40012C38))
#define TIMER1_CCR3           	 (*((volatile u32*)0x40012C3C))
#define TIMER1_CCR4           	 (*((volatile u32*)0x40012C40))
#define TIMER1_BDTR           	 (*((volatile u32*)0x40012C44))	
#define TIMER1_DCR  	         	 (*((volatile u32*)0x40012C48))
#define TIMER1_DMAR           	 (*((volatile u32*)0x40012C4C))

#define TIMER1_CCR            	 ((volatile u32*)0x40012C34)
#define TIMER1_CCMR           	 ((volatile u32*)0x40012C18)


#define  IWDG_KR               	 (*((volatile u32*)0x40003000))
#define  IWDG_PR               	 (*((volatile u32*)0x40003004))
#define  IWDG_RLR                (*((volatile u32*)0x40003008))
#define  IWDG_SR               	 (*((volatile u32*)0x4000300C))

#define IWDG_START_KEY      (u16)0xCCCC
#define IWDG_STOP_KEY				(u16)0xAAAA
#define IWDG_ACCESS_KEY			(u16)0x5555

#define  WWDG_CR               	   (*((volatile u32*)0x40002C00))
#define  WWDG_CFR               	 (*((volatile u32*)0x40002C04))
#define  WWDG_SR                   (*((volatile u32*)0x40002C08))
#define WWDG_CR_WDGA_BIT							7
#define WWDG_CFR_EWI_BIT							9
#define WWDG_CR_T_6_BIT		  					6
#define WWDG_SR_EWIF_BIT							0

 





/*
This bit-field indicates the division ratio between the timer clock (CK_INT) frequency and 
sampling clock used by the digital filters (ETR, TIx)
*/
#define TIM_CR1_CKD_1_BIT							9
#define TIM_CR1_CKD_0_BIT							8
/*ARPE: Auto-reload preload enable
0: TIMx_ARR register is not buffered.
1: TIMx_ARR register is buffered.
*/
#define TIM_CR1_ARPE_BIT						7
/*
0: Counter used as upcounter
1: Counter used as downcounter
*/
#define TIM_CR1_DIR_BIT							4
/*
OPM: One-pulse mode
0: Counter is not stopped at update event
1: Counter stops counting at the next update event (clearing the CEN bit).

*/
#define TIM_CR1_OPM_BIT							3
/*
 Update request source
This bit is set and cleared by software to select the UEV event sources.
*/
#define TIM_CR1_URS_BIT							2
/*
1 UDIS: Update disable
This bit is set and cleared by software to enable/disable UEV event generation.
*/
#define TIM_CR1_UDIS_BIT						1
/*
CEN: Counter enable
0: Counter disabled
1: Counter enabled
*/
#define TIM_CR1_CEN_BIT							0
/*
Bit 8 UDE: Update DMA request enable
0: Update DMA request disabled.
1: Update DMA request enabled.
*/
#define TIM_DIER_UDE_BIT							8
/*
Bit 4 CC4IE: Capture/Compare 4 interrupt enable
0: Capture/Compare interrupt disabled.
1: Capture/Compare interrupt disabled.
*/
#define TIM_DIER_CC4IE_BIT							4
/*
Bit 3 CC4IE: Capture/Compare 3 interrupt enable
0: Capture/Compare interrupt disabled.
1: Capture/Compare interrupt disabled.
*/
#define TIM_DIER_CC3IE_BIT							3

/*
Bit 2 CC4IE: Capture/Compare 2 interrupt enable
0: Capture/Compare interrupt disabled.
1: Capture/Compare interrupt disabled.
*/
#define TIM_DIER_CC2IE_BIT							2

/*
Bit 1 CC4IE: Capture/Compare 1 interrupt enable
0: Capture/Compare interrupt disabled.
1: Capture/Compare interrupt disabled.
*/
#define TIM_DIER_CC1IE_BIT							1

/*
Bit 0 UIE: Update interrupt enable
0: Update interrupt disabled.
1: Update interrupt enabled.
*/
#define TIM_DIER_UIE_BIT							0

#define TIM_SR_CC4OF_BIT							12
#define TIM_SR_CC3OF_BIT							11
#define TIM_SR_CC2OF_BIT							10
#define TIM_SR_CC1OF_BIT							9

#define TIM_SR_CC4IF_BIT							4
#define TIM_SR_CC3IF_BIT							3
#define TIM_SR_CC2IF_BIT							2
#define TIM_SR_CC1IF_BIT							1
/*
UIF: Update interrupt flag
This bit is set by hardware on an update event. It is cleared by software.
0: No update occurred.
1: Update interrupt pending.
*/
#define TIM_SR_UIF_BIT							0
/*Bit 0 UG: Update generation
This bit can be set by software, it is automatically cleared by hardware.
*/
#define TIM_EGR_UG_BIT							0

#define TIM_CR2_TL1S_BIT						7

#define TIM_CCER_CC4P_BIT						13
#define TIM_CCER_CC4E_BIT						12
#define TIM_CCER_CC3P_BIT						9
#define TIM_CCER_CC3E_BIT						8
#define TIM_CCER_CC2P_BIT						5
#define TIM_CCER_CC2E_BIT						4
#define TIM_CCER_CC1P_BIT						1
#define TIM_CCER_CC1E_BIT						0


#define TIM_CCMR_CC4P_BIT						  13
#define TIM_CCMR_CC4E_BIT						  12
#define TIM_CCMR_CC3P_BIT						  9
#define TIM_CCMR_CC3E_BIT						  8
#define TIM_CCMR_OCPE_ICPSC_1_BIT						  3
#define TIM_CCMR_OCFE_ICPSC_0_BIT						  2
#define TIM_CCMR_CCS_1_BIT										1
#define TIM_CCMR_CCS_0_BIT										0
#define TIM_BDTR_MOE_BIT											15
#define TIM_BDTR_OSSR_BIT											11
#define TIM_BDTR_OSSI_BIT											10







//for callback function
#define TIM_1_BRK_Vect						      	0
#define TIM_1_UP_Vect				      				1
#define TIM_1_TRG_COM_Vect		      			2
#define TIM_1_CC_Vect											3
#define TIM_1_Channel_1_Vect							3
#define TIM_1_Channel_2_Vect							4
#define TIM_1_Channel_3_Vect							5
#define TIM_1_Channel_4_Vect							6
#define TIM_2_UP_Vect											7
#define TIM_2_CC_Vect											8
#define TIM_2_Channel_1_Vect							8
#define TIM_2_Channel_2_Vect							9
#define TIM_2_Channel_3_Vect							10
#define TIM_2_Channel_4_Vect							11
#define TIM_3_UP_Vect											12
#define TIM_3_CC_Vect											13
#define TIM_3_Channel_1_Vect							13
#define TIM_3_Channel_2_Vect							14
#define TIM_3_Channel_3_Vect							15
#define TIM_3_Channel_4_Vect							16
#define TIM_3_OFFSET											4
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
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

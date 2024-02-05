/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
#include "NVIC_private.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
0 7 settable  WWDG Window watchdog interrupt 0x0000_0040
1 8 settable  PVD PVD through EXTI Line detection 
2 9 settable  TAMPER Tamper interrupt 0x0000_0048
3 10 settable RTC RTC global interrupt 0x0000_004C
4 11 settable FLASH Flash global interrupt 0x0000_0050
5 12 settable RCC RCC global interrupt 0x0000_0054
6 13 settable EXTI0 EXTI Line0 interrupt 0x0000_0058
7 14 settable EXTI1 EXTI Line1 interrupt 0x0000_005C
8 15 settable EXTI2 EXTI Line2 interrupt 0x0000_0060
9 16 settable EXTI3 EXTI Line3 interrupt 0x0000_0064
10 17 settable EXTI4 EXTI Line4 interrupt 0x0000_0068
11 18 settable DMA1_Channel1 DMA1 Channel1 global interrupt 0x0000_006C
12 19 settable DMA1_Channel2 DMA1 Channel2 global interrupt 0x0000_0070
13 20 settable DMA1_Channel3 DMA1 Channel3 global interrupt 0x0000_0074
14 21 settable DMA1_Channel4 DMA1 Channel4 global interrupt 0x0000_0078
15 22 settable DMA1_Channel5 DMA1 Channel5 global interrupt 0x0000_007C
16 23 settable DMA1_Channel6 DMA1 Channel6 global interrupt 0x0000_0080
17 24 settable DMA1_Channel7 DMA1 Channel7 global interrupt 0x0000_0084
18 25 settable ADC1_2 ADC1 and ADC2 global interrupt 0x0000_0088
19 26 settable USB_HP_CAN_
20 27 settable USB_LP_CAN_
21 28 settable CAN_RX1 CAN RX1 interrupt 0x0000_0094
22 29 settable CAN_SCE CAN SCE interrupt 0x0000_0098
23 30 settable EXTI9_5 EXTI Line[9:5] interrupts 0x0000_009C
24 31 settable TIM1_BRK TIM1 Break interrupt 0x0000_00A0
25 32 settable TIM1_UP TIM1 Update interrupt 0x0000_00A4
26 33 settable TIM1_TRG_COM TIM1 Trigger and Commutation 
27 34 settable TIM1_CC TIM1 Capture Compare interrupt 0x0000_00AC
28 35 settable TIM2 TIM2 global interrupt 0x0000_00B0
29 36 settable TIM3 TIM3 global interrupt 0x0000_00B4
30 37 settable TIM4 TIM4 global interrupt 0x0000_00B8
31 38 settable I2C1_EV I2C1 event interrupt 0x0000_00BC
32 39 settable I2C1_ER I2C1 error interrupt 0x0000_00C0
33 40 settable I2C2_EV I2C2 event interrupt 0x0000_00C4
34 41 settable I2C2_ER I2C2 error interrupt 0x0000_00C8
35 42 settable SPI1 SPI1 global interrupt 0x0000_00CC
36 43 settable SPI2 SPI2 global interrupt 0x0000_00D0
37 44 settable USART1 USART1 global interrupt 0x0000_00D4
38 45 settable USART2 USART2 global interrupt 0x0000_00D8
39 46 settable USART3 USART3 global interrupt 0x0000_00DC
40 47 settable EXTI15_10 EXTI Line[15:10] interrupts 0x0000_00E0
41 48 settable RTCAlarm RTC alarm through EXTI line 
42 49 settable USBWakeup USB wakeup from suspend through 
EXTI line interrupt 0x0000_00E8
43 50 settable TIM8_BRK TIM8 Break interrupt 0x0000_00EC
44 51 settable TIM8_UP TIM8 Update interrupt 0x0000_00F0
45 52 settable TIM8_TRG_COM TIM8 Trigger and Commutation 
interrupts 0x0000_00F4
46 53 settable TIM8_CC TIM8 Capture Compare interrupt 0x0000_00F8
47 54 settable ADC3 ADC3 global interrupt 0x0000_00FC
48 55 settable FSMC FSMC global interrupt 0x0000_0100
49 56 settable SDIO SDIO global interrupt 0x0000_0104
50 57 settable TIM5 TIM5 global interrupt 0x0000_0108
51 58 settable SPI3 SPI3 global interrupt 0x0000_010C
52 59 settable UART4 UART4 global interrupt 0x0000_0110
53 60 settable UART5 UART5 global interrupt 0x0000_0114
54 61 settable TIM6 TIM6 global interrupt 0x0000_0118
55 62 settable TIM7 TIM7 global interrupt 0x0000_011C
56 63 settable DMA2_Channel1 DMA2 Channel1 global interrupt 0x0000_0120
57 64 settable DMA2_Channel2 DMA2 Channel2 global interrupt 0x0000_0124
58 65 settable DMA2_Channel3 DMA2 Channel3 global interrupt 0x0000_0128
59 66 settable DMA2_Channel4_5 DMA2 Channel4 and DMA2 
Channel5 global interrupts 0x0000_012C*/

#define	WWDG_Interrupt 									0
#define	PVD_Interrupt 									1
#define	TAMPER_Interrupt 								2
#define	RTC_Interrupt 									3
#define	 FLASH_Interrupt 								4
#define  RCC_Interrupt 									5
#define  EXTI_0_Interrupt								6
#define EXTI_1_Interrupt 			  				7
#define EXTI_2_Interrupt								8
#define EXTI_3_Interrupt								9
#define EXTI_4_Interrupt 				    		10
#define DMA_1_Channe_l_Interrupt 				11
#define DMA_1_Channe_2_Interrupt 				12
#define DMA_1_Channe_3_Interrupt 				13
#define DMA_1_Channe_4_Interrupt 				14
#define DMA_1_Channe_5_Interrupt  			15
#define DMA_1_Channe_6_Interrupt 	  		16
#define DMA_1_Channe_7_Interrupt 				17
#define ADC_1_2_Interrupt 							18
#define USB_HP_CAN_TX_Interrupt 	  		19
#define USB_LP_CAN_RX0_Interrupt 				20
#define CAN_RX1_Interrupt 					    21
#define CAN_SCE_Interrupt 					    22
#define EXTI_9_5_Interrupt 					    23
#define TIM_1_BRK_Interrupt 					  24
#define TIM_1_UP_Interrupt 					    25
#define TIM_1_TRG_COM_Interrupt 				26
#define TIM_1_CC_Interrupt 				    	27
#define TIM_2_Interrupt 							  28
#define TIM_3_Interrupt 		          	29
#define TIM_4_Interrupt 								30
#define I2C_1_EV_Interrupt 							31
#define I2C_1_ER_Interrupt  						32
#define I2C_2_EV_Interrupt 							33
#define I2C_2_ER_Interrupt 							34
#define SPI_1_Interrupt 		      			35
#define SPI_2_Interrupt 					      36
#define USART_1_Interrupt 							37
#define USART_2_Interrupt 							38
#define USART_3_Interrupt 							39
#define EXTI_15_10_Interrupt 						40
#define RTC_Alarm_Interrupt 						41
#define USB_Wakeup_Interrupt 						42
#define TIM_8_BRK_Interrupt 						43
#define TIM_8_UP_Interrupt 							44
#define TIM_8_TRG_COM_Interrupt 				45
#define TIM_8_CC_Interrupt 							46
#define ADC_3_Interrupt 								47
#define FSMC_Interrupt						    	48 
#define SDIO_Interrupt 							    49
#define TIM_5_Interrupt 							  50
#define SPI_3_Interrupt 							  51
#define UART_4_Interrupt 							  52
#define UART_5_Interrupt 							  53
#define TIM_6_Interrupt 							  54
#define TIM_7_Interrupt 							  55
#define DMA_2_Channel_1_Interrupt				56
#define DMA_2_Channel_2_Interrupt 			57		
#define DMA_2_Channel_3_Interrupt 			58
#define DMA_2_Channel_5_Interrupt				59

/*. Interrupt Priority Levels*/
/*3 bits for group and 0 sub to determine group number	*/
#define NVIC_GRROUP_3_SUB_0											0x4

/*2 bits for group and 1 sub to determine group number	*/
#define NVIC_GRROUP_2_SUB_1											0x5

/*1 bits for group and 2 sub to determine group number	*/
#define NVIC_GRROUP_1_SUB_2											0x6

/*0 bits for group and 3 sub to determine group number	*/
#define NVIC_GRROUP_0_SUB_3											0x7
/*. Interrupt Priority Values*/

#define NVIC_PRIORITY_0													0
#define NVIC_PRIORITY_1													1
#define NVIC_PRIORITY_2													2
#define NVIC_PRIORITY_3													3
#define NVIC_PRIORITY_4													4
#define NVIC_PRIORITY_5													5
#define NVIC_PRIORITY_6													6
#define NVIC_PRIORITY_7													7










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
ErrorStatus NVIC_enumInterruptEnable  (u8 Copy_u8IntNumber);
ErrorStatus NVIC_enumInterruptDisable (u8 Copy_u8IntNumber);
ErrorStatus NVIC_enumSetPendingState  (u8 Copy_u8IntNumber);
ErrorStatus NVIC_enumClearPendingState(u8 Copy_u8IntNumber);
ErrorStatus NVIC_enumGetActiveState   (u8 Copy_u8IntNumber,u8 *Copy_u8ActiveVal);
ErrorStatus NVIC_enumSetPriorityLevels(u8 Copy_u8PriorityLevels); 
ErrorStatus NVIC_enumSetPriorityValue (u8 Copy_u8IntNumber,u8 Copy_u8PriorityVal);
void 				NVIC_voidPriorityInit     (	void																				);

#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//0x4001 2000 - 0x4001 23FF GPIO Port G
//Section 9.5 on page 194
//0x4001 1C00 - 0x4001 1FFF GPIO Port F
//0x4001 1800 - 0x4001 1BFF GPIO Port E
//0x4001 1400 - 0x4001 17FF GPIO Port D
//0x4001 1000 - 0x4001 13FF GPIO Port C
//0x4001 0C00 - 0x4001 0FFF GPIO Port B
//0x4001 0800 - 0x4001 0BFF GPIO Port A

#define GPIO_PORTA_BASE_ADD		0x40010800
#define GPIO_PORTB_BASE_ADD		0x40010C00
#define GPIO_PORTC_BASE_ADD		0x40011000
#define GPIO_PORTD_BASE_ADD		0x40011400

/* PORTA_REG */
#define GPIOA_CRL_REG        *((volatile u32 *)   GPIO_PORTA_BASE_ADD+0x00) 		     //GPIO CRL  , offset 0x000
#define GPIOA_CRH_REG        *((volatile u32 *)  (GPIO_PORTA_BASE_ADD+0x04)) 		     //GPIO CRH  , offset 0x004
#define GPIOA_IDR_REG			   *((volatile u32 *)  (GPIO_PORTA_BASE_ADD+0x08)) 		     //GPIO IDR , offset 0x008
#define GPIOA_ODR_REG			   *((volatile u32 *)  (GPIO_PORTA_BASE_ADD+0x0C)) 		     //GPIO ODR , offset 0x00C
#define GPIOA_BSRR_REG       *((volatile u32 *)  (GPIO_PORTA_BASE_ADD+0x10)) 		     //GPIO BSRR , offset 0x010
#define GPIOA_BRR_REG        *((volatile u32 *)  (GPIO_PORTA_BASE_ADD+0x14)) 		     //GPIO BRR , offset 0x014
#define GPIOA_LCKR_REG       *((volatile u32 *)  (GPIO_PORTA_BASE_ADD+0x18)) 		     //GPIO LCKR , offset 0x018

/* PORTB_REG */
#define GPIOB_CRL_REG        *((volatile u32 *)  (GPIO_PORTB_BASE_ADD+0x00)) 		     //GPIO CRL  , offset 0x000
#define GPIOB_CRH_REG        *((volatile u32 *)  (GPIO_PORTB_BASE_ADD+0x04)) 		     //GPIO CRH  , offset 0x004
#define GPIOB_IDR_REG			   *((volatile u32 *)  (GPIO_PORTB_BASE_ADD+0x08)) 		     //GPIO IDR , offset 0x008
#define GPIOB_ODR_REG			   *((volatile u32 *)  (GPIO_PORTB_BASE_ADD+0x0C)) 		     //GPIO ODR , offset 0x00C
#define GPIOB_BSRR_REG       *((volatile u32 *)  (GPIO_PORTB_BASE_ADD+0x10)) 		     //GPIO BSRR , offset 0x010
#define GPIOB_BRR_REG        *((volatile u32 *)  (GPIO_PORTB_BASE_ADD+0x14)) 		     //GPIO BRR , offset 0x014
#define GPIOB_LCKR_REG       *((volatile u32 *)  (GPIO_PORTB_BASE_ADD+0x18)) 		     //GPIO LCKR , offset 0x018


/* PORTC_REG */
#define GPIOC_CRL_REG        *((volatile u32 *)  (GPIO_PORTC_BASE_ADD+0x00)) 		     //GPIO CRL  , offset 0x000
#define GPIOC_CRH_REG        *((volatile u32 *)  (GPIO_PORTC_BASE_ADD+0x04)) 		     //GPIO CRH  , offset 0x004
#define GPIOC_IDR_REG			   *((volatile u32 *)  (GPIO_PORTC_BASE_ADD+0x08)) 		     //GPIO IDR , offset 0x008
#define GPIOC_ODR_REG			   *((volatile u32 *)  (GPIO_PORTC_BASE_ADD+0x0C)) 		     //GPIO ODR , offset 0x00C
#define GPIOC_BSRR_REG       *((volatile u32 *)  (GPIO_PORTC_BASE_ADD+0x10)) 		     //GPIO BSRR , offset 0x010
#define GPIOC_BRR_REG        *((volatile u32 *)  (GPIO_PORTC_BASE_ADD+0x14)) 		     //GPIO BRR , offset 0x014
#define GPIOC_LCKR_REG       *((volatile u32 *)  (GPIO_PORTC_BASE_ADD+0x18)) 		     //GPIO LCKR , offset 0x018


/* PORTD_REG */
#define GPIOD_CRL_REG        *((volatile u32 *)  GPIO_PORTD_BASE_ADD+0x00) 		     //GPIO CRL  , offset 0x000
#define GPIOD_CRH_REG        *((volatile u32 *)  GPIO_PORTD_BASE_ADD+0x04) 		     //GPIO CRH  , offset 0x004
#define GPIOD_IDR_REG			   *((volatile u32 *)  GPIO_PORTD_BASE_ADD+0x08) 		     //GPIO IDR , offset 0x008
#define GPIOD_ODR_REG			   *((volatile u32 *)  GPIO_PORTD_BASE_ADD+0x0C) 		     //GPIO ODR , offset 0x00C
#define GPIOD_BSRR_REG       *((volatile u32 *)  GPIO_PORTD_BASE_ADD+0x10) 		     //GPIO BSRR , offset 0x010
#define GPIOD_BRR_REG        *((volatile u32 *)  GPIO_PORTD_BASE_ADD+0x14) 		     //GPIO BRR , offset 0x014
#define GPIOD_LCKR_REG       *((volatile u32 *)  GPIO_PORTD_BASE_ADD+0x18) 		     //GPIO LCKR , offset 0x018

#define PORT_INPUT_PULL_UP_DOWN			0x88888888
#define PORT_OUTPUT_PUSH_PULL_DOWN	0x11111111
#define PORT_HIGH										0xFFFFFFFF

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

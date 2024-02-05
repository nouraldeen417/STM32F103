/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef _USART_CONFIG_H
#define _USART_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lip/Macros.h"
#include "../../lip/STD_TYPES.h"
#include "USART_interface.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define SYSTEM_FREQUENCY 8000000
#define USART_BAUD_RATE 9600

/*Enable the USART Reciever:
  ENABLE
  DISABLE

 */
#define USART_RX_ENABLE ENABLE
/*Enable the USART Transmission:
  ENABLE
  DISABLE

 */

#define USART_TX_ENABLE ENABLE
/*Double the USART Transmission Speed:
  ENABLE
  DISABLE

 */
#define USART_DOUPLE_TRANSMISSION_SPEED DISABLE

/* Multi-processor Communication Mode:
  ENABLE
  DISABLE

 */
#define USART_Multi_PROCESSOR_COMMUNICATION_MODE DISABLE

/* RX Complete Interrupt Enable:
  ENABLE
  DISABLE

 */
#define USART_RX_COMPLETE_INTERRUPT ENABLE

/* TX Complete Interrupt Enable:
  ENABLE
  DISABLE

 */
#define USART_TX_COMPLETE_INTERRUPT ENABLE

/* USART Data Register Empty Interrupt Enable:
  ENABLE
  DISABLE

 */
#define USART_DATA_REGISTER_EMPTY_INTERRUPT DISABLE

/*  USART Mode Select:
 USART_MODE_ASYNCHRONOUS
 USART_MODESYNCHRONOUS
 */
#define USART_MODE USART_MODE_ASYNCHRONOUS

/*   Parity Mode:
 USART_PARITY_DISABLE
 USART_EVEN_PARITY
 USART_ODD_PARITY
 */
#define USART_PARITY_MODE USART_EVEN_PARITY

/* Stop Bit Select:
 USART_1_BIT_SELECT
 USART_2_BIT_SELECT
 */
#define USART_STOP_BIT_SELECT USART_1_BIT_SELECT

/*  Character Size:
 USART_CHARACTER_SIZE_5_BIT
 USART_CHARACTER_SIZE_6_BIT
 USART_CHARACTER_SIZE_7_BIT
 USART_CHARACTER_SIZE_8_BIT
 USART_CHARACTER_SIZE_9_BIT

 */
#define USART_CHARACTER_SIZE USART_CHARACTER_SIZE_8_BIT

#if USART_MODE == USART_MODE_SYNCHRONOUS
/*  Character Size:
USART_CLOCK_POLARITY_TX_RISING_RX_FALLING
USART_CLOCK_POLARITY_TX_FALLING_RX_RISING
 */
#define USART_CLOCK_POLARITY USART_CLOCK_POLARITY_TX_RISING_RX_FALLING

#endif

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

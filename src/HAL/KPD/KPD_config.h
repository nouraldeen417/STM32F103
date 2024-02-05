/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_KPD_CONFIG_H
#define	XC_KPD_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lip/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*port Number:
 DIO_PORTA 
 DIO_PORTB 
 DIO_PORTC 
 DIO_PORTD 
*/

#define KPD_PORT    DIO_PORTA

/*pins Number:
 DIO_PIN0 
 DIO_PIN1 
 DIO_PIN2 
 DIO_PIN3 
 DIO_PIN4 
 DIO_PIN5 
 DIO_PIN6 
 DIO_PIN7 
*/

#define KPD_R0      DIO_PIN0
#define KPD_R1      DIO_PIN1
#define KPD_R2      DIO_PIN2
#define KPD_R3      DIO_PIN3
/*Pins_coloums*/
#define KPD_C0      DIO_PIN4
#define KPD_C1      DIO_PIN5
#define KPD_C2      DIO_PIN6
#define KPD_C3      DIO_PIN7

/**/
#define KPD_ROW_START DIO_PIN0
#define KPD_ROW_END  DIO_PIN3

#define KPD_COL_START  DIO_PIN4
#define KPD_COL_END    DIO_PIN7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

static u8 KPD_u8Buttons[4][4]={
                        {'7','8','9','/'},
                        {'4','5','6','*'},
                        {'1','2','3','-'},
                        {'?','0','=','+'}
};
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


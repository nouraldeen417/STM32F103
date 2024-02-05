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
#ifndef XC_LCD_INTERFACE_H
#define	XC_LCD_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../lip/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_interface.h"
#include "LCD_config.h"
#include "LCD_extrachar.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FOUR_BITS                     0x28          //4 bits mode initialization (8-bit data, 2-line display, 5 x 7 font )
#define EIGHT_BITS                    0x38          //8 bits mode initialization (8-bit data, 2-line display, 5 x 7 font )
#define lcd_DisplayOn_CursorOff       0x0c          // display on, cursor off, don't blink character 
#define lcd_DisplayOn_CursorOn        0x0e          // display on, cursor on, don't blink character 
#define lcd_DisplayOff_CursorOff      0x08          // turn display off
#define lcd_Clear                     0x01          //replace all characters with ASCII 'space'  
#define lcd_EntryMode                 0x06          // shift cursor from left to right on read/write
#define lcd_Home                      0x02          // return cursor to first position on first line 
#define lcd_CGRAM                     0x40          // the first Place/Address at CGRAM
#define lcd_SetCursor                 0x80          // set cursor position
#define lcd_FunctionReset             0x30          // reset the LCD
/*LCD_Rows*/
#define LCD_ROW_1   0
#define LCD_ROW_2   1
/*LCD_Cols*/
#define LCD_COL_1   0
#define LCD_COL_2   1
#define LCD_COL_3   2
#define LCD_COL_4   3
#define LCD_COL_5   4
#define LCD_COL_6   5
#define LCD_COL_7   6
#define LCD_COL_8   7
#define LCD_COL_9   8
#define LCD_COL_10  9
#define LCD_COL_11  10
#define LCD_COL_12  11
#define LCD_COL_13  12
#define LCD_COL_14  13
#define LCD_COL_15  14
#define LCD_COL_16  15

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
void LCD_voidSendData(u8 LCD_u8Data);
void LCD_voidSendCommand(u8 LCD_u8Command);
void LCD_voidDisplayClear();
void LCD_voidInit();
void LCD_voidSendString(const u8* LCD_u8PtrString);
void LCD_voidSendNumber(u32 Copy_u64Number);
void LCD_voidSetPosition(u8 LCD_u8Row, u8 LCD_u8Colum);
void LCD_voidSendExtraChar(u8 LCD_u8Row, u8 LCD_u8Colum);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


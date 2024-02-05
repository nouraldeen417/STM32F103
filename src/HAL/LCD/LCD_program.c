/*
 * File:   LCD_interface.c
 * Author: nour
 *
 * Created on September 1, 2023, 5:29 PM
 */
#define DELAY_100_MS		(u32)800000
#define DELAY_50_MS		(u32)400000
#define DELAY_10_MS 		(u32)80000
#define DELAY_1_MS  		(u32)8000



#include "LCD_interface.h"

static void LCD_voidSendFallinEdge() {
    DIO_enumSetPinValue (LCD_Control_PORT, LCD_EN_PIN, DIO_Pin_HIGH);
    SYSTICK_enumSetBusyWait(DELAY_100_MS);
    DIO_enumSetPinValue(LCD_Control_PORT, LCD_EN_PIN, DIO_Pin_LOW);
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
}

void LCD_voidDisplayClear() {
    LCD_voidSendCommand(lcd_Clear);
    SYSTICK_enumSetBusyWait(DELAY_10_MS);
}

void LCD_voidSendData(u8 LCD_u8Data) {
#if LCD_MODE==8
    DIO_enumSetPortValue(LCD_Data_PORT  , LCD_u8Data);
    DIO_enumSetPinValue(LCD_Control_PORT, LCD_RS_PIN, DIO_Pin_HIGH);
    DIO_enumSetPinValue(LCD_Control_PORT, LCD_RW_PIN, DIO_Pin_LOW);
    LCD_voidSendFallinEdge();
#elif LCD_MODE==4
    DIO_enumSetPinValue(LCD_Control_PORT, LCD_RS_PIN, DIO_Pin_HIGH);
    DIO_enumSetPinValue(LCD_Control_PORT, LCD_RW_PIN, DIO_Pin_LOW);
    DIO_enumSetPortNibble(LCD_Data_PORT, (LCD_u8Data >> 4),LCD_DATA_PIN1);
    LCD_voidSendFallinEdge();
    DIO_enumSetPortNibble(LCD_Data_PORT, LCD_u8Data,LCD_DATA_PIN1);
    LCD_voidSendFallinEdge();
#endif


    
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
}

void LCD_voidSendCommand(u8 LCD_u8Command) {
#if LCD_MODE==8
    DIO_enumSetPortValue(LCD_Data_PORT, LCD_u8Command);
    DIO_enumSetPinValue (LCD_Control_PORT, LCD_RS_PIN, DIO_Pin_LOW);
    DIO_enumSetPinValue (LCD_Control_PORT, LCD_RW_PIN, DIO_Pin_LOW);
    LCD_voidSendFallinEdge();
#elif LCD_MODE==4
    DIO_enumSetPinValue(LCD_Control_PORT, LCD_RS_PIN, DIO_Pin_LOW);
    DIO_enumSetPinValue(LCD_Control_PORT, LCD_RW_PIN, DIO_Pin_LOW);
    DIO_enumSetPortNibble(LCD_Data_PORT, (LCD_u8Command >> 4),LCD_DATA_PIN1);
    LCD_voidSendFallinEdge();
    DIO_enumSetPortNibble(LCD_Data_PORT, LCD_u8Command,LCD_DATA_PIN1);
    LCD_voidSendFallinEdge();    
#endif    
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
}

void LCD_voidInit() {
    DIO_enumSetPinDirection(LCD_Control_PORT, LCD_RS_PIN, DIO_Pin_Output);
    DIO_enumSetPinDirection(LCD_Control_PORT, LCD_RW_PIN, DIO_Pin_Output);
    DIO_enumSetPinDirection(LCD_Control_PORT, LCD_EN_PIN, DIO_Pin_Output);
	#if LCD_MODE==8
    SYSTICK_enumSetBusyWait(DELAY_50_MS);
    DIO_enumSetPortDirection(LCD_Data_PORT, DIO_Port_Output);

    LCD_voidSendCommand(lcd_Home);
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
    LCD_voidSendCommand(EIGHT_BITS);
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
    LCD_voidSendCommand(lcd_DisplayOn_CursorOff);
    SYSTICK_enumSetBusyWait(DELAY_100_MS);
    LCD_voidDisplayClear();
    LCD_voidSendCommand(lcd_EntryMode);
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
#elif LCD_MODE==4
    SYSTICK_enumSetBusyWait(DELAY_50_MS);
    DIO_enumSetPinDirection(LCD_Data_PORT, LCD_DATA_PIN1, DIO_Pin_Output);
    DIO_enumSetPinDirection(LCD_Data_PORT, LCD_DATA_PIN2, DIO_Pin_Output);
    DIO_enumSetPinDirection(LCD_Data_PORT, LCD_DATA_PIN3, DIO_Pin_Output);
    DIO_enumSetPinDirection(LCD_Data_PORT, LCD_DATA_PIN4, DIO_Pin_Output);

    LCD_voidSendCommand(lcd_Home);
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
    LCD_voidSendCommand(FOUR_BITS);
    SYSTICK_enumSetBusyWait(DELAY_50_MS);
    LCD_voidSendCommand(lcd_DisplayOn_CursorOff);
    SYSTICK_enumSetBusyWait(DELAY_100_MS);
    LCD_voidDisplayClear();
    LCD_voidSendCommand(lcd_EntryMode);
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
#endif    

}

void LCD_voidSendString(const u8* LCD_u8PtrString) {
    u8 LOC_u8Iterator = 0;
    while (LCD_u8PtrString[LOC_u8Iterator] != '\0') {
        LCD_voidSendData(LCD_u8PtrString[LOC_u8Iterator]);
        LOC_u8Iterator++;
    }
}

void LCD_voidSetPosition(u8 LCD_u8Row, u8 LCD_u8Colum) {
    u8 LOC_u8Data; //0x80
    if (LCD_u8Row > LCD_ROW_2 && LCD_u8Colum > LCD_COL_16) {
        LOC_u8Data = lcd_SetCursor; //0x80
    } else if (LCD_u8Row == LCD_ROW_1) {

        LOC_u8Data = lcd_SetCursor + LCD_u8Colum;
    } else if (LCD_u8Row == LCD_ROW_2) {
        LOC_u8Data = lcd_SetCursor + LCD_u8Colum + (64);
    }
    LCD_voidSendCommand(LOC_u8Data);
    SYSTICK_enumSetBusyWait(DELAY_1_MS);
}

void LCD_voidSendExtraChar(u8 LCD_u8Row, u8 LCD_u8Colum) {
    u8 LOC_u8Iterator = 0;
    LCD_voidSendCommand(lcd_CGRAM);

    for (LOC_u8Iterator = 0; LOC_u8Iterator< sizeof (LCD_u8ExtraChars) / sizeof (LCD_u8ExtraChars[0]); LOC_u8Iterator++) {
        LCD_voidSendData(LCD_u8ExtraChars[LOC_u8Iterator]);
    }

    LCD_voidSetPosition(LCD_u8Row, LCD_u8Colum);

    for (LOC_u8Iterator = 0; LOC_u8Iterator < 8; LOC_u8Iterator++) {
        LCD_voidSendData(LOC_u8Iterator);
    }



}

void LCD_voidSendNumber(u32 Copy_u64Number) {
    u32 LOC_u64Temp = 1;

	if (Copy_u64Number == 0) 
	{
        LCD_voidSendData('0');
  } else
	{//17
         while (Copy_u64Number != 0) 
			   {
					LOC_u64Temp = ((LOC_u64Temp * 10) + (Copy_u64Number % 10));     
					Copy_u64Number = Copy_u64Number/10;
		     }            

        while (LOC_u64Temp != 1) 
				{
            LCD_voidSendData(((LOC_u64Temp % 10) + 48));
            LOC_u64Temp /= 10;
        }
  }
}
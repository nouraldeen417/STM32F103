/*
 * File:   KPD_program.c
 * Author: nour
 *
 * Created on September 3, 2023, 4:56 PM
 */


#include"KPD_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include<util/delay.h>

void KPD_voidInit() {
    /*Init coloums pins (output,high)*/
    DIO_voidSetPinDirection(KPD_PORT, KPD_C0, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT, KPD_C1, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT, KPD_C2, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT, KPD_C3, DIO_PIN_OUTPUT);

    DIO_voidSetPinValue(KPD_PORT, KPD_C0, DIO_PIN_HIGH);
    DIO_voidSetPinValue(KPD_PORT, KPD_C1, DIO_PIN_HIGH);
    DIO_voidSetPinValue(KPD_PORT, KPD_C2, DIO_PIN_HIGH);
    DIO_voidSetPinValue(KPD_PORT, KPD_C3, DIO_PIN_HIGH);

    DIO_voidEnablePullup(KPD_PORT, KPD_R0);
    DIO_voidEnablePullup(KPD_PORT, KPD_R1);
    DIO_voidEnablePullup(KPD_PORT, KPD_R2);
    DIO_voidEnablePullup(KPD_PORT, KPD_R3);

}

u8 KPD_u8GetPressed() {
    u8 LOC_u8Col;
    u8 LOC_u8Row;
    u8 LOC_u8GetPresesed;
    u8 LOC_u8ReturnData = KPD_NOTPRESSED;

    for (LOC_u8Col = 0 + KPD_COL_START; LOC_u8Col < KPD_COL_END + 1; LOC_u8Col++) {
        DIO_voidSetPinValue(KPD_PORT, LOC_u8Col, DIO_PIN_LOW);

        for (LOC_u8Row = 0 + KPD_ROW_START; LOC_u8Row < KPD_ROW_END + 1; LOC_u8Row++) {
            DIO_u8GetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPresesed);
            if (LOC_u8GetPresesed == 0) {
                _delay_ms(50);                                               //Delay For Bouncing
                DIO_u8GetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPresesed);  // To make sure That the Button is clicked  
                if (LOC_u8GetPresesed == 0) {
                    // Return Clicked Button From Array KPD_u8Buttons
                    LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_START][LOC_u8Col - KPD_COL_START];
                }
                   //stay here if button is pressed
                DIO_u8GetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPresesed);
                while (LOC_u8GetPresesed == 0) {
                    DIO_u8GetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPresesed);
                }

                break;

            }

        }

        DIO_voidSetPinValue(KPD_PORT, LOC_u8Col, DIO_PIN_HIGH);

    }
    return LOC_u8ReturnData;
}
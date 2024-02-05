/*
 * File:   SW_program.c
 * Author: nour
 *
 * Created on August 31, 2023, 4:21 PM
 */


#include <xc.h>
#include"SW_interface.h"

void SW_voidInit(SW_Type SW_Conf) {
    DIO_voidSetPinDirection(SW_Conf.SW_PORT, SW_Conf.SW_PIN, DIO_PIN_INPUT);
    if (SW_Conf.SW_STATE == 0) {
        DIO_voidEnablePullup(SW_Conf.SW_PORT, SW_Conf.SW_PIN);
    }
}

u8 SW_u8GetPressed(SW_Type SW_Conf) {
    u8 SW_Val=0;
    DIO_u8GetPinValue(SW_Conf.SW_PORT, SW_Conf.SW_PIN, &SW_Val);
    return SW_Val;
}

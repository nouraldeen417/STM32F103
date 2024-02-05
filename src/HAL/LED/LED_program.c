/*
 * File:   LED_program.c
 * Author: nour
 *
 * Created on August 30, 2023, 6:59 PM
 */



#include "../../lip/STD_TYPES.h"
#include "LED_interface.h"

void LED_voidInit(LED_Type LED_Configration) {
    // turn off leds as default state
    LED_voidOFF(LED_Configration);
    DIO_voidSetPinDirection(LED_Configration.Port,LED_Configration.Pin,DIO_PIN_OUTPUT);
}

void LED_voidON(LED_Type LED_Configration) {
    if (LED_Configration.Active_State == Active_HIGH) {
        DIO_voidSetPinValue(LED_Configration.Port, LED_Configration.Pin, DIO_PIN_HIGH);
    } else if (LED_Configration.Active_State == Active_LOW) {
        DIO_voidSetPinValue(LED_Configration.Port, LED_Configration.Pin, DIO_PIN_LOW);
    }
}

void LED_voidOFF(LED_Type LED_Configration) {
    if (LED_Configration.Active_State == Active_HIGH) {
        DIO_voidSetPinValue(LED_Configration.Port, LED_Configration.Pin, DIO_PIN_LOW);
    } else if (LED_Configration.Active_State == Active_LOW) {
        DIO_voidSetPinValue(LED_Configration.Port, LED_Configration.Pin, DIO_PIN_HIGH);
    }
}
void LED_voidToggle(LED_Type LED_Configration){
    DIO_voidTogglePinValue(LED_Configration.Port,LED_Configration.Pin);
}
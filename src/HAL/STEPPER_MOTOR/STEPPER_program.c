/*
 * File:   STEPPER_program.c
 * Author: nour
 *
 * Created on September 20, 2023, 3:11 PM
 */

#include <util/delay.h>
#include "STEPPER_interface.h"
#define F_CPU 8000000UL
void my_delay_ms(u16 Copy_u8Delay) {

    u16 LOC_Iterator = 0;
    for (LOC_Iterator = 0; LOC_Iterator < Copy_u8Delay; LOC_Iterator++) {
        _delay_ms(1);
    }

}

void STEEPER_voidInit() {
    DIO_voidSetPinDirection(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_OUTPUT);

    DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

}

void STEEPER_voidOff() {
    DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

}
//void STEEPER_voidInit(u8 Copy_u8PortNum, u8 Copy_u8PinNum);
// steps= angle / angle of step >>  angle / (45/256) 
//(((u32) (Copy_u16RotationAngle * 256)) / 45) / 4

void STEEPER_voidOn(u8 Copy_u8StepType, u8 Copy_u8Direction, u16 Copy_u8Speed, u16 Copy_u16RotationAngle) {
    if (Copy_u8StepType == STEPPER_FULL_STEP) {
        u32 LOC_Iterator = 0;
        if (Copy_u8Direction == STEPPER_CLOCK_WISE) {

            for (LOC_Iterator = 0; LOC_Iterator < (((u32) (Copy_u16RotationAngle * 256)) / 45) / 4; LOC_Iterator++) {
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
                my_delay_ms(Copy_u8Speed);
            }

        } else if (Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE) {

            for (LOC_Iterator = 0; LOC_Iterator < (((u32) (Copy_u16RotationAngle * 256)) / 45) / 4; LOC_Iterator++) {
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

            }
        }
    }

    if (Copy_u8StepType == STEPPER_HALF_STEP) {
        u32 LOC_Iterator = 0;
        if (Copy_u8Direction == STEPPER_CLOCK_WISE) {

            for (LOC_Iterator = 0; LOC_Iterator < (((u32) (Copy_u16RotationAngle * 512)) / 45) / 8; LOC_Iterator++) {
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
                my_delay_ms(Copy_u8Speed);

            }

        } else if (Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE) {

            for (LOC_Iterator = 0; LOC_Iterator < (((u32) (Copy_u16RotationAngle * 256)) / 45) / 4; LOC_Iterator++) {

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
                my_delay_ms(Copy_u8Speed);


                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);


                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);


                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);


                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
                DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
                my_delay_ms(Copy_u8Speed);

            }
        }
    }
}

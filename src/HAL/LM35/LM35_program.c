/*
 * File:   LM35_program.c
 * Author: nour
 *
 * Created on September 10, 2023, 10:57 PM
 */


#include <xc.h>
#include"LM35_interface.h"
#include"../../MCAL/ADC/ADC_interface.h"
//#define RES 1024
const u16 x=1024;
ErrorStatus LM35_enumGetTemperature(LM35_Config * Copy_Config, u8 * Copy_pu8TempValue) {
    u8 LOC_u8ErrorState = OK;
    u16 LOC_u16ADCResult;
    u16 LOC_u16AnalogValue;
    u16 LOC_u16ADCRefrence = (Copy_Config->LM35_u8Vreference) ;

    if (Copy_Config != NULL && Copy_pu8TempValue != NULL) {
        ADC_enumGetResultSync(Copy_Config->LM35_u8Channel, & LOC_u16ADCResult);
        if( Copy_Config->LM35_u8Resolution == ADC_RESULUTION_10_BIT){
       LOC_u16AnalogValue = (u16) (((u32) LOC_u16ADCResult * (u32) LOC_u16ADCRefrence) / (1024/1000)) ;            
//       LOC_u16AnalogValue = (u16) (((u32) LOC_u16ADCResult * 5000) / 1024) ;            
 //     //  LOC_u16AnalogValue *=1000    ;            
        
        }
        else if (( Copy_Config->LM35_u8Resolution == ADC_RESULUTION_8_BIT)){
        LOC_u16AnalogValue = (u16) (((u32) LOC_u16ADCResult * (u32) LOC_u16ADCRefrence) /(256/1000)) ;            
        }
        
        *Copy_pu8TempValue=(LOC_u16AnalogValue/10);
        //*Copy_pu8TempValue=(LOC_u16ADCResult);

    }
    
    else{
        LOC_u8ErrorState=NOK;
    }
    return LOC_u8ErrorState;

}

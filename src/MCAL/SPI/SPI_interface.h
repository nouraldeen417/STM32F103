/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MACROS>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
#include "SPI_private.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**/
#define SPI_ENABLE                              1
#define SPI_DISABLE                             0

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
    Spi_Lsb_First,
		Spi_Msb_First,   
}SPI_DataOrderType;

typedef enum {
    Spi_Master,
		Spi_Slave,   
}SPI_ModeType;

typedef enum {
    Spi_Idle_0,
		Spi_Idle_1,   
}SPI_ClockPolarityType;
typedef enum {
    Spi_8_Bit_Date,
    Spi_16_Bit_Date
}SPI_DataFrameType;

typedef enum {
    Spi_First_Clock_Transition,
    Spi_Second_Clock_Transition
}SPI_ClockPhaseType;
typedef enum {
		Spi_Freq_Divided_By_2=0,
		Spi_Freq_Divided_By_4,
		Spi_Freq_Divided_By_8,
		Spi_Freq_Divided_By_16,
		Spi_Freq_Divided_By_32,
		Spi_Freq_Divided_By_64,
		Spi_Freq_Divided_By_128,
		Spi_Freq_Divided_By_256,
}SPI_BaudRateType;

typedef struct {
		SPI_DataFrameType	  	SPI_u8DataLength;
    SPI_DataOrderType     SPI_u8DataOrder;
    SPI_ModeType          SPI_u8MasterSlaveSelect;
    SPI_BaudRateType 		  SPI_u8BaudRate;
    SPI_ClockPhaseType    SPI_u8ClockPhase;
    SPI_ClockPolarityType SPI_u8ClockPolarity;
}SPI_confType;

typedef struct {
const u16 *SPI_u16TData;
      u16 *SPI_u16RData;
      u8 SPI_u8BufferSize;
void (* SPI_pvNotifaction)(void)  ;
}SPI_BufferType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void SPI_voidInit(void) ;
ErrorStatus SPI_enumInitConfig (SPI_confType * Copy_SpiConfig) ;
ErrorStatus SPI_enumTranceive  (u16 Copy_u8TData , u16 * Copy_u8RData) ;
ErrorStatus SPI_enumBufferTranceiverSynch (SPI_BufferType * spi_buffer) ;
ErrorStatus SPI_enumBufferTranceiverAsynch (SPI_BufferType * spi_buffer) ;

#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/








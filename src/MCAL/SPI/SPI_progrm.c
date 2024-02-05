/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO_program.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
#include "SPI_interface.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static u8 SPI_u8Size = 0;
static u8 SPI_u8Index = 0;
static const u16 *SPI_pu16TData = NULL;
static u16 *SPI_pu16RData = NULL;

void (*SPI_pvCallBackFunction)(void) = NULL;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
ErrorStatus SPI_enumInitConfig(SPI_confType * Copy_SpiConfig) {
    ErrorStatus LOC_ErrorState = OK;

    if (Copy_SpiConfig != NULL) {
        if (Copy_SpiConfig->SPI_u8DataLength == Spi_16_Bit_Date) 
				{
            SET_BIT(SPI_CR1, SPCR1_DFF_BIT);
        } else if (Copy_SpiConfig->SPI_u8DataLength == Spi_8_Bit_Date) 
				{
            CLEAR_BIT(SPI_CR1, SPCR1_DFF_BIT);
        } else 
				{
            LOC_ErrorState = NOK;
        }
        if (Copy_SpiConfig->SPI_u8DataOrder == Spi_Lsb_First) 
				{
            SET_BIT(SPI_CR1, SPCR1_LSBF_BIT);
        } else if (Copy_SpiConfig->SPI_u8DataOrder == Spi_Msb_First) 
				{
            CLEAR_BIT(SPI_CR1, SPCR1_LSBF_BIT);
        } else 
				{
            LOC_ErrorState = NOK;
        }

        if (Copy_SpiConfig->SPI_u8MasterSlaveSelect == Spi_Master)
				{
            SET_BIT(SPI_CR1, SPCR1_MSTR_BIT);
        } else if (Copy_SpiConfig->SPI_u8MasterSlaveSelect == Spi_Slave) 
				{
            CLEAR_BIT(SPI_CR1, SPCR1_MSTR_BIT);
        } else 
				{
            LOC_ErrorState = NOK;
        }
        if (Copy_SpiConfig->SPI_u8ClockPolarity == Spi_Idle_1) 
				{
            SET_BIT(SPI_CR1, SPCR1_CPOL_BIT);
        } else if (Copy_SpiConfig->SPI_u8ClockPolarity == Spi_Idle_0) 
				{
            CLEAR_BIT(SPI_CR1, SPCR1_CPOL_BIT);
        } else 
				{
            LOC_ErrorState = NOK;
        }
        if (Copy_SpiConfig->SPI_u8ClockPhase == Spi_Second_Clock_Transition)
				{
            SET_BIT(SPI_CR1, SPCR1_CPHA_BIT);
        } else if (Copy_SpiConfig->SPI_u8ClockPhase == Spi_First_Clock_Transition) {
            CLEAR_BIT(SPI_CR1, SPCR1_CPHA_BIT);
        } else {
            LOC_ErrorState = NOK;
        }

				/*Set Clock rate*/
				SPI_CR1 &=~(0x38);
				SPI_CR1 |= (Copy_SpiConfig->SPI_u8BaudRate & 0x7)<<SPCR1_BR_BITS;
        /*Enable Spi*/
        SET_BIT(SPI_CR1, SPCR1_SPE_BIT);
    } else 
		{
        LOC_ErrorState = OK;
    }
    return LOC_ErrorState;
}

ErrorStatus SPI_enumTranceive(u16 Copy_u8TData, u16 * Copy_u8RData) {
    ErrorStatus LOC_ErroreState = OK;
    u32 LOC_u32TimeOutCount = 0;
	if (GET_BIT(SPI_SR, SPSR_BSY_BIT) == 0) 
	{
        SPI_DR = Copy_u8TData;
        while((GET_BIT(SPI_SR, SPSR_TXE_BIT) == 0) && LOC_u32TimeOutCount < SPI_TRANSFER_TIME_OUT) 
				{
            LOC_u32TimeOutCount++;
        }
        if (LOC_u32TimeOutCount == SPI_TRANSFER_TIME_OUT) 
				{
            LOC_ErroreState = Time_OUT_State;
        } else 
				{
					*Copy_u8RData =  SPI_DR;
        }
    } else
		{
        LOC_ErroreState = Busy_State;
    }

    return LOC_ErroreState;
}

ErrorStatus SPI_enumBufferTranceiverSynch(SPI_BufferType * Copy_SpiBuffer) {
    ErrorStatus LOC_ErroreState = OK;
    u8 LOC_Iterator = 0;
		if(Copy_SpiBuffer != NULL)
			{
					if ((Copy_SpiBuffer->SPI_u16RData != NULL) && (Copy_SpiBuffer->SPI_u16TData)) 
					{

					for (LOC_Iterator = 0; LOC_Iterator < Copy_SpiBuffer->SPI_u8BufferSize; LOC_Iterator++)
					{
            SPI_enumTranceive(Copy_SpiBuffer->SPI_u16TData[LOC_Iterator], &Copy_SpiBuffer->SPI_u16RData[LOC_Iterator]);
					}

					} else
					{
						LOC_ErroreState = NOK;
					}
			}else 
					{
						LOC_ErroreState = NOK;
					}
    return LOC_ErroreState;
}

ErrorStatus SPI_enumBufferTranceiverAsynch(SPI_BufferType * Copy_bufferConf) {
    ErrorStatus LOC_ErroreState = OK;
	if (GET_BIT(SPI_SR, SPSR_BSY_BIT) == 0) 
	{
        if (Copy_bufferConf != NULL && Copy_bufferConf->SPI_u16TData != NULL 
						&& Copy_bufferConf->SPI_u16RData != NULL
						&& Copy_bufferConf->SPI_pvNotifaction != NULL) 
				{
            SPI_pu16TData = Copy_bufferConf->SPI_u16TData;
            SPI_pu16RData = Copy_bufferConf->SPI_u16RData;
            SPI_u8Size    = Copy_bufferConf->SPI_u8BufferSize;
            SPI_pvCallBackFunction = Copy_bufferConf->SPI_pvNotifaction;
            SPI_u8Index = 0;
            /*Interrupt Enable*/
            SET_BIT(SPI_CR2, SPCR2_TXEIE_BIT);
  					/*start tranceive*/
            SPI_DR = SPI_pu16TData[SPI_u8Index];
        }
        else 
				{
            LOC_ErroreState = NOK;
        }

    } else 
	  {
        LOC_ErroreState = Busy_State;
    }

    return LOC_ErroreState;

}

void SPI1_IRQHandler (void)
{

    /*receive data*/
    SPI_pu16RData[SPI_u8Index] = SPI_DR;
    SPI_u8Index++;
    if(SPI_u8Index == SPI_u8Size)
		{    
				/*Interrupt Enable*/
				CLEAR_BIT(SPI_CR2, SPCR2_TXEIE_BIT);
				SPI_pvCallBackFunction();
    }else
		{
        SPI_DR = SPI_pu16TData[SPI_u8Index];
    }

}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
 * \Description     : Describe this service                                    
 *                                                                             
 * \Sync\Async      : Synchronous                                               
 * \Reentrancy      : Non Reentrant                                             
 * \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
 * \Parameters (out): None                                                      
 * \Return value:   : None
 *                                  
 *******************************************************************************/

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
 * \Description     : Describe this service                                    
 *                                                                             
 * \Sync\Async      : Synchronous                                               
 * \Reentrancy      : Non Reentrant                                             
 * \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
 * \Parameters (out): None                                                      
 * \Return value:   : Std_ReturnType  OK
 *                                    NOK                                  
 *******************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/


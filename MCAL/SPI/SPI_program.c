/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : SPI                                                 */
/* Version : 1.0                                                 */
/* Date    : 26 Dec 2023                                         */
/*****************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

/*Global Variables*/
pf pfSpiISRGlb = NULL_PTR;

void SPI_voidInit(void)
{
    /*Select Data Order*/
    #if SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_FIRST
    CLR_BIT(SPCR, SPCR_BIT_DORD);
    #elif SPI_DATA_ORDER == SPI_DATA_ORDER_MSB_FIRST
    SET_BIT(SPCR, SPCR_BIT_DORD);
    #endif

    /*Master / Slave Mode*/
    #if SPI_MODE == SPI_MODE_MASTER
    SET_BIT(SPCR, SPCR_BIT_MSTR);
    #elif SPI_MODE == SPI_MODE_SLAVE
    CLR_BIT(SPCR, SPCR_BIT_MSTR);
    #endif

    /*Clock Polarity*/
    #if SPI_CLK_POLARITY == SPI_CLK_POLARITY_LE_RISING
    CLR_BIT(SPCR, SPCR_BIT_CPOL);
    #elif SPI_CLK_POLARITY == SPI_CLK_POLARITY_LE_FALLING
    SET_BIT(SPCR, SPCR_BIT_CPOL);
    #endif

    /*Clock Phase*/
    #if SPI_CLK_PHASE == SPI_CLK_PHASE_LE_SAMPLE
    CLR_BIT(SPCR, SPCR_BIT_CPHA);
    #elif SPI_CLK_PHASE == SPI_CLK_PHASE_LE_SETUP
    SET_BIT(SPCR, SPCR_BIT_CPHA);
    #endif

    /*Clock Prescaler*/
    #if SPI_CLK_PRESCALER > SPI_CLK_PRESCALER_128
      /*Double Speed Enable*/
    SPCR = (SPCR & SPCR_SPR01_MASK) | (SPI_CLK_PRESCALER-4);
    SET_BIT(SPSR, SPSR_BIT_SPI2X);
    #elif SPI_CLK_PRESCALER < SPI_CLK_PRESCALER_2
      /*Double Speed Disable*/
    SPCR = (SPCR & SPCR_SPR01_MASK) | SPI_CLK_PRESCALER;
    CLR_BIT(SPSR, SPSR_BIT_SPI2X);
    #endif

    /*SPI State*/
    #if SPI_STATE == SPI_STATE_ENABLE
    SET_BIT(SPCR, SPCR_BIT_SPE);
    #elif SPI_STATE == SPI_STATE_DISABLE
    CLR_BIT(SPCR, SPCR_BIT_SPE);
    #endif

    /*Interrupt*/
    #if SPI_INTERRUPT == SPI_INTERRUPT_ENABLE
    SET_BIT(SPCR, SPCR_BIT_SPIE);
    #elif SPI_INTERRUPT == SPI_INTERRUPT_DISABLE
    CLR_BIT(SPCR, SPCR_BIT_SPIE);
    #endif
}

tenuErrorStatus SPI_enuChangeMode(const uint8 u8ModeCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;

    switch(u8ModeCpy)
    {
        case SPI_MODE_SLAVE:
        CLR_BIT(SPCR, SPCR_BIT_MSTR);
        break;
        case SPI_MODE_MASTER:
        SET_BIT(SPCR, SPCR_BIT_MSTR);
        break;
        default:
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }

    return enuErrorStatLoc;
}

tenuErrorStatus SPI_enuTransceiveSynch(const uint8 u8DataTransmitCpy, uint8* const pu8DataReceiveCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;
    uint8 u8DataReceiveLoc;

    /*Send Data*/
    SPDR = u8DataTransmitCpy;

    while(GET_BIT(SPSR, SPSR_BIT_SPIF)==0);

    /*Receive Data*/
    if(pu8DataReceiveCpy==NULL_PTR)
    {
        enuErrorStatLoc = E_NOK_NULL_POINTER;
        /*Read data to clear flag*/
        u8DataReceiveLoc = SPDR;
    }
    else
    {
        *pu8DataReceiveCpy = SPDR;
    }

    return enuErrorStatLoc;
}

void SPI_voidSendData(const uint8 u8DataCpy)
{
    SPDR = u8DataCpy;
}

tenuErrorStatus SPI_enuGetData(uint8* const pu8DataCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;
    uint8 u8TempReadLoc;

    /*Read the flag*/
    u8TempReadLoc = GET_BIT(SPSR, SPSR_BIT_SPIF);

    if(pu8DataCpy==NULL_PTR)
    {
        enuErrorStatLoc = E_NOK_NULL_POINTER;
        /*Read data to clear flag*/
        u8TempReadLoc = SPDR;
    }
    else
    {
        *pu8DataCpy = SPDR;
    }

    return enuErrorStatLoc;
}

void SPI_voidIntEnable(void)
{
    SET_BIT(SPCR, SPCR_BIT_SPIE);
}

void SPI_voidIntDisable(void)
{
    CLR_BIT(SPCR, SPCR_BIT_SPIE);
}

tenuErrorStatus SPI_enuSetCallBack(const pf pfSpiISRCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;

    if(pfSpiISRCpy==NULL_PTR)
    {
        enuErrorStatLoc = E_NOK_NULL_POINTER;
    }
    else
    {
        pfSpiISRGlb = pfSpiISRCpy;
    }

    return enuErrorStatLoc;
}


void __vector_12 (void)  __attribute__ ((signal, used));
void __vector_12 (void)
{
    if(pfSpiISRGlb!=NULL_PTR)
    {
        pfSpiISRGlb();
    }
    else
    {
        /*Nothing*/
    }
}

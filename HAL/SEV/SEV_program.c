/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : HAL                                                 */
/* SWC     : SEV                                                 */
/* Version : 1.0                                                 */
/* Date    : 10 Dec 2023                                         */
/*****************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SEV_interface.h"
#include "SEV_config.h"
#include "SEV_private.h"

/*Global Variables*/
uint8 au8DisplayPatternsGlb[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};


/*Function Definitions*/
void SEV_voidInit(void)
{
    uint8 u8CntrLoc;
    uint8 u8PortValueLoc=0;

    for(u8CntrLoc=0;u8CntrLoc<SEV_MAX_NUM;u8CntrLoc++)
    {
        /*Set Port to Output*/
        DIO_enuSetPortDirection(astrSevConfigGlb[u8CntrLoc].u8DisplayPort, 0xFF);

        if(astrSevConfigGlb[u8CntrLoc].u8CommonType==SEV_COMMON_CATHODE)
        {
            /*Disable Display from the Common Pin*/
            DIO_enuWritePinValue(astrSevConfigGlb[u8CntrLoc].u8DisplayPort, DIO_PIN7, DIO_HIGH);
            SET_BIT(u8PortValueLoc, 7);

            /*Display initial value*/
            u8PortValueLoc |= au8DisplayPatternsGlb[astrSevConfigGlb[u8CntrLoc].u8InitNum];
            DIO_enuWritePortValue(astrSevConfigGlb[u8CntrLoc].u8DisplayPort, u8PortValueLoc);
        }
        else if(astrSevConfigGlb[u8CntrLoc].u8CommonType==SEV_COMMON_ANODE)
        {
            /*Disable Display from the Common Pin*/
            DIO_enuWritePinValue(astrSevConfigGlb[u8CntrLoc].u8DisplayPort, DIO_PIN7, DIO_LOW);
            CLR_BIT(u8PortValueLoc, 7);

            /*Display initial value*/
            u8PortValueLoc |= ~(au8DisplayPatternsGlb[astrSevConfigGlb[u8CntrLoc].u8InitNum]);
            DIO_enuWritePortValue(astrSevConfigGlb[u8CntrLoc].u8DisplayPort, u8PortValueLoc);
        }
    }
}

tenuErrorStatus SEV_enuDisplayNum(uint8 u8SevIndxCpy, uint8 u8NumCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;
    uint8 u8PortValueLoc=0;

    if((u8SevIndxCpy>(SEV_MAX_NUM-1))||(u8NumCpy>9))
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        enuErrorStatLoc |= DIO_enuReadPinValue(astrSevConfigGlb[u8SevIndxCpy].u8DisplayPort, DIO_PIN7, &u8PortValueLoc);
        u8PortValueLoc = u8PortValueLoc<<7;
        if(astrSevConfigGlb[u8SevIndxCpy].u8CommonType==SEV_COMMON_CATHODE)
        {
            u8PortValueLoc |= au8DisplayPatternsGlb[u8NumCpy];
        }
        else if(astrSevConfigGlb[u8SevIndxCpy].u8CommonType==SEV_COMMON_ANODE)
        {
            u8PortValueLoc |= ~(au8DisplayPatternsGlb[u8NumCpy]);
        }
        enuErrorStatLoc |= DIO_enuWritePortValue(astrSevConfigGlb[u8SevIndxCpy].u8DisplayPort, u8PortValueLoc);
    }

    return enuErrorStatLoc;
}

tenuErrorStatus SEV_enuEnable(uint8 u8SevIndxCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;

    if(u8SevIndxCpy>(SEV_MAX_NUM-1))
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        if(astrSevConfigGlb[u8SevIndxCpy].u8CommonType==SEV_COMMON_CATHODE)
        {
            enuErrorStatLoc |= DIO_enuWritePinValue(astrSevConfigGlb[u8SevIndxCpy].u8DisplayPort, DIO_PIN7, DIO_LOW);
        }
        else if(astrSevConfigGlb[u8SevIndxCpy].u8CommonType==SEV_COMMON_ANODE)
        {
            enuErrorStatLoc |= DIO_enuWritePinValue(astrSevConfigGlb[u8SevIndxCpy].u8DisplayPort, DIO_PIN7, DIO_HIGH);
        }
    }

    return enuErrorStatLoc;
}

tenuErrorStatus SEV_enuDisable(uint8 u8SevIndxCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;

    if(u8SevIndxCpy>(SEV_MAX_NUM-1))
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        if(astrSevConfigGlb[u8SevIndxCpy].u8CommonType==SEV_COMMON_CATHODE)
        {
            enuErrorStatLoc |= DIO_enuWritePinValue(astrSevConfigGlb[u8SevIndxCpy].u8DisplayPort, DIO_PIN7, DIO_HIGH);
        }
        else if(astrSevConfigGlb[u8SevIndxCpy].u8CommonType==SEV_COMMON_ANODE)
        {
            enuErrorStatLoc |= DIO_enuWritePinValue(astrSevConfigGlb[u8SevIndxCpy].u8DisplayPort, DIO_PIN7, DIO_LOW);
        }
    }

    return enuErrorStatLoc;
}

tenuErrorStatus SEV_enuToggle(uint8 u8SevIndxCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;

    if(u8SevIndxCpy>(SEV_MAX_NUM-1))
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        enuErrorStatLoc |= DIO_enuTogglePinValue(astrSevConfigGlb[u8SevIndxCpy].u8DisplayPort, DIO_PIN7);
    }

    return enuErrorStatLoc;
}

/*****************************************************************/
/* Author  : Ahmed                                               */
/* SWC     : KEYPAD                                              */
/* Version : 1.0                                                 */
/* Date    : 12 Dec 2023                                         */
/*****************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "util/delay.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

/*Global Variables*/
static uint8 au8KPDValuesGlb[4][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
		{12, 13, 14, 15}
};

static uint8 au8KPDPatterGlb[4] = {
		0b11101111,
		0b11011111,
		0b10111111,
		0b01111111
};

/*Functions Definition*/
tenuErrorStatus KEYPAD_enuInit(void)
{
	tenuErrorStatus enuErrorStatLoc = E_OK;

	/*Config Pins Direction*/
	enuErrorStatLoc |= DIO_enuSetPortDirection(KEYPAD_PORT, 0b11110000);

	/*Write High on columns and activate pull up on rows*/
	enuErrorStatLoc |= DIO_enuWritePortValue(KEYPAD_PORT, 0xFF);

	return enuErrorStatLoc;
}

tenuErrorStatus KEYPAD_enuGetKey_0(uint8* pu8KeyNumCpy)
{
	tenuErrorStatus enuErrorStatLoc = E_OK;
	*pu8KeyNumCpy = 16;
	uint8 u8ColumnCntrLoc;
	uint8 u8PortValueLoc;
	if(pu8KeyNumCpy==NULL_PTR)
	{
		enuErrorStatLoc = E_NOK_NULL_POINTER;
	}
	else
	{
		for(u8ColumnCntrLoc=0;u8ColumnCntrLoc<4;u8ColumnCntrLoc++)
		{
			enuErrorStatLoc |= DIO_enuWritePortValue(KEYPAD_PORT, au8KPDPatterGlb[u8ColumnCntrLoc]);
			enuErrorStatLoc |= DIO_enuReadPortValue(KEYPAD_PORT,&u8PortValueLoc);

			switch(u8PortValueLoc)
			{
				case KEYPAD_SWITCH15_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[3][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH14_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[2][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH13_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[1][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH12_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[0][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH11_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[3][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH10_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[2][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH9_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[1][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH8_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[0][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH7_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[3][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH6_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[2][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH5_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[1][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH4_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[0][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH3_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[3][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH2_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[2][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH1_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[1][u8ColumnCntrLoc];
				break;
				case KEYPAD_SWITCH0_PRESSED:
				*pu8KeyNumCpy = au8KPDValuesGlb[0][u8ColumnCntrLoc];
				break;
				default:
				break;
			}

			if(*pu8KeyNumCpy!=16)
			{
				break;
			}
		}
	}

	return enuErrorStatLoc;
}

tenuErrorStatus KEYPAD_enuGetKey_1(uint8* pu8KeyNumCpy)
{
	tenuErrorStatus enuErrorStatLoc = E_OK;
	*pu8KeyNumCpy = 16;
	uint8 u8ColumnCntrLoc;
	uint8 u8RowCntrLoc;
	uint8 u8PinValueLoc;
	for(u8ColumnCntrLoc=0;u8ColumnCntrLoc<4;u8ColumnCntrLoc++)
	{
		DIO_enuWritePortValue(KEYPAD_PORT, 0xFF);
		DIO_enuWritePinValue(KEYPAD_PORT, 4+u8ColumnCntrLoc, DIO_LOW);
		for(u8RowCntrLoc=0;u8RowCntrLoc<4;u8RowCntrLoc++)
		{
			DIO_enuReadPinValue(KEYPAD_PORT, u8RowCntrLoc, &u8PinValueLoc);
			if(u8PinValueLoc==DIO_LOW)
			{
				*pu8KeyNumCpy = au8KPDValuesGlb[u8RowCntrLoc][u8ColumnCntrLoc];
				break;
			}
		}
		if(*pu8KeyNumCpy!=16)
		{
			break;
		}
	}
	return enuErrorStatLoc;
}

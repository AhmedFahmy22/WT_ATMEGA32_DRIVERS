/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : EXTINT1                                             */
/* Version : 1.0                                                 */
/* Date    : 17 Dec 2023                                         */
/*****************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "EXTINT1_interface.h"
#include "EXTINT1_private.h"
#include "EXTINT1_config.h"


pf pfExtint1ISRGlb = NULL_PTR;

void EXTINT1_voidInit(void)
{
#if EXTINT1_MODE == EXTINT1_MODE_LOW
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif EXTINT1_MODE == EXTINT1_MODE_ON_CHANGE
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif EXTINT1_MODE == EXTINT1_MODE_FALLING
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif EXTINT1_MODE == EXTINT1_MODE_RISING
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#endif

}

void EXTINT1_voidEnable(void)
{
    SET_BIT(GICR, INT1);
}

void EXTINT1_voidDisable(void)
{
    CLR_BIT(GICR, INT1);
}


tenuErrorStatus EXTINT1_enuSetCallBack(pf pfExtint1FunCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;
    if(pfExtint1FunCpy == NULL_PTR)
    {
        enuErrorStatLoc = E_NOK_NULL_POINTER;
    }
    else
    {
        pfExtint1ISRGlb = pfExtint1FunCpy;
    }
    return enuErrorStatLoc;
}



void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_2 (void){
	pfExtint1ISRGlb();
}

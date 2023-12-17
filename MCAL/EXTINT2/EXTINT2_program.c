/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : EXTINT2                                             */
/* Version : 1.0                                                 */
/* Date    : 17 Dec 2023                                         */
/*****************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "EXTINT2_interface.h"
#include "EXTINT2_private.h"
#include "EXTINT2_config.h"

pf pfExtint2ISRGlb = NULL_PTR;

void EXTINT2_voidInit(void)
{
#if EXTINT2_MODE == EXTINT2_MODE_FALLING
	CLR_BIT(MCUCSR,ISC2);
#elif EXTINT2_MODE == EXTINT2_MODE_RISING
	SET_BIT(MCUCSR,ISC2);
#endif
}

void EXTINT2_voidEnable(void)
{
    SET_BIT(GICR, INT2);
}

void EXTINT2_voidDisable(void)
{
    CLR_BIT(GICR, INT2);
}


tenuErrorStatus EXTINT2_enuSetCallBack(pf pfExtint2FunCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;
    if(pfExtint2FunCpy == NULL_PTR)
    {
        enuErrorStatLoc = E_NOK_NULL_POINTER;
    }
    else
    {
        pfExtint2ISRGlb = pfExtint2FunCpy;
    }
    return enuErrorStatLoc;
}



void __vector_3 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_3 (void){
	pfExtint2ISRGlb();
}

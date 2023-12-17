/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : GIE                                                 */
/* Version : 1.0                                                 */
/* Date    : 17 Dec 2023                                         */
/*****************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"

void GIE_voidEnable(void)
{
    SET_BIT(SREG, SREG_I_BIT);
}

void GIE_voidDisable(void)
{
    CLR_BIT(SREG, SREG_I_BIT);
}

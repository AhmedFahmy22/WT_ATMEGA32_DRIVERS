/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : HAL                                                 */
/* SWC     : SEV                                                 */
/* Version : 1.0                                                 */
/* Date    : 11 Dec 2023                                         */
/*****************************************************************/
#include "../../LIB/STD_Types.h"

#include "SEV_interface.h"
#include "SEV_config.h"
#include "SEV_private.h"

tstrSevSeg astrSevConfigGlb[SEV_MAX_NUM] = {
        {SEV_PORTC, SEV_COMMON_CATHODE, SEV_STATE_OFF, 0},
        {SEV_PORTD, SEV_COMMON_CATHODE, SEV_STATE_OFF, 0}
};

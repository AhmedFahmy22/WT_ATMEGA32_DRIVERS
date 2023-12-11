/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : HAL                                                 */
/* SWC     : SEV                                                 */
/* Version : 1.0                                                 */
/* Date    : 11 Dec 2023                                         */
/*****************************************************************/
#ifndef SEV_INTERFACE_H_
#define SEV_INTERFACE_H_

/*Includes*/
#include "../../LIB/STD_Types.h"

/*Macros*/
#define SEV_PORTA 0
#define SEV_PORTB 1
#define SEV_PORTC 2
#define SEV_PORTD 3

#define SEV_STATE_OFF 0
#define SEV_STATE_ON  1

#define SEV_COMMON_CATHODE 0
#define SEV_COMMON_ANODE   1

/*Function Prototypes*/
void SEV_voidInit(void);

tenuErrorStatus SEV_enuDisplayNum(const uint8 u8SevIndxCpy, const uint8 u8NumCpy);

tenuErrorStatus SEV_enuEnable(const uint8 u8SevIndxCpy);

tenuErrorStatus SEV_enuDisable(const uint8 u8SevIndxCpy);

tenuErrorStatus SEV_enuToggle(const uint8 u8SevIndxCpy);

#endif

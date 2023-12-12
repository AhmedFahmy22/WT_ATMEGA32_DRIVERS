/*****************************************************************/
/* Author  : Ahmed                                               */
/* SWC     : KEYPAD                                              */
/* Version : 1.0                                                 */
/* Date    : 12 Dec 2023                                         */
/*****************************************************************/
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "STD_Types.h"

tenuErrorStatus KEYPAD_enuInit(void);

tenuErrorStatus KEYPAD_enuGetKey_0(uint8* pu8KeyNumCpy);

tenuErrorStatus KEYPAD_enuGetKey_1(uint8* pu8KeyNumCpy);

#endif

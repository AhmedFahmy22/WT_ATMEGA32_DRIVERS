/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : HAL                                                 */
/* SWC     : CLCD                                                */
/* Version : 1.0                                                 */
/* Date    : 11 Dec 2023                                         */
/*****************************************************************/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "../../LIB/STD_Types.h"

/*Macros*/
#define CLCD_COMM_CLEAR           0x01          /* replace all characters with ASCII 'space'                       */
#define CLCD_COMM_HOME            0x02          /* return cursor to first position on first line                   */

/*Function Declarations*/
tenuErrorStatus CLCD_enuInit(void);
tenuErrorStatus CLCD_enuSendCommand(const uint8 u8CmdCpy);
tenuErrorStatus CLCD_enuWriteChar(const uint8 u8DataCpy);
tenuErrorStatus CLCD_enuWriteString (const uint8* const pu8StringCpy, const uint8 u8LengthCpy);
tenuErrorStatus CLCD_enuGotoxy (const uint8 u8LineNumCpy, const uint8 u8ColumnCpy);
tenuErrorStatus CLCD_enuWriteNum(const sint16 s16DataCpy);

#endif

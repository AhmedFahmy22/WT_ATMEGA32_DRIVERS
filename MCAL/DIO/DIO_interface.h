/*****************************************************************/
/* Author  : Ahmed                                               */
/* SWC     : DIO                                                 */
/* Version : 1.0                                                 */
/* Date    : 09 Dec 2023                                         */
/*****************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*Macros*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_LOW  0
#define DIO_HIGH 1

#define DIO_INPUT  0
#define DIO_OUTPUT 1

/*Function Prototypes*/
void DIO_voidInit(void);

tenuErrorStatus DIO_u8WritePinValue(const uint8 u8PortCpy, const uint8 u8PinCpy, const uint8 u8ValueCpy);

tenuErrorStatus DIO_u8ReadPinValue(const uint8 u8PortCpy, const uint8 u8PinCpy, uint8* const pu8ValueCpy);

tenuErrorStatus DIO_u8TogglePinValue(const uint8 u8PortCpy, const uint8 u8PinCpy);

tenuErrorStatus DIO_u8WritePortValue(const uint8 u8PortCpy, const uint8 u8ValueCpy);

tenuErrorStatus DIO_u8ReadPortValue(const uint8 u8PortCpy, uint8* const pu8ValueCpy);

tenuErrorStatus DIO_u8TogglePortValue(const uint8 u8PortCpy);

tenuErrorStatus DIO_u8SetPinDirection(const uint8 u8PortCpy, const uint8 u8PinCpy, const uint8 u8DirCpy);

tenuErrorStatus DIO_u8GetPinDirection(const uint8 u8PortCpy, const uint8 u8PinCpy, uint8* const pu8DirCpy);

tenuErrorStatus DIO_u8SetPortDirection(const uint8 u8PortCpy, const uint8 u8DirCpy);

tenuErrorStatus DIO_u8GetPortDirection(const uint8 u8PortCpy, uint8* const pu8DirCpy);

tenuErrorStatus DIO_u8PullUpEnable(const uint8 u8PortCpy, const uint8 u8PinCpy);

tenuErrorStatus DIO_u8PullUpDisable(const uint8 u8PortCpy, const uint8 u8PinCpy);

#endif

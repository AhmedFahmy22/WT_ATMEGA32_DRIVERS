/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : SPI                                                 */
/* Version : 1.0                                                 */
/* Date    : 26 Dec 2023                                         */
/*****************************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*Macros*/
#define SPI_MODE_SLAVE  0
#define SPI_MODE_MASTER 1


/*Function Declarations*/
void SPI_voidInit(void);

tenuErrorStatus SPI_enuChangeMode(const uint8 u8ModeCpy);

tenuErrorStatus SPI_enuTransceiveSynch(const uint8 u8DataTransmitCpy, uint8* const pu8DataReceiveCpy);

void SPI_voidSendData(const uint8 u8DataCpy);

tenuErrorStatus SPI_enuGetData(uint8* const pu8DataCpy);

void SPI_voidIntEnable(void);

void SPI_voidIntDisable(void);

tenuErrorStatus SPI_enuSetCallBack(const pf pfSpiISRCpy);

#endif

/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : ADC                                                 */
/* Version : 1.0                                                 */
/* Date    : 24 Dec 2023                                         */
/*****************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*Macros*/
#define ADC_CHANNEL_A0 0
#define ADC_CHANNEL_A1 1
#define ADC_CHANNEL_A2 2
#define ADC_CHANNEL_A3 3
#define ADC_CHANNEL_A4 4
#define ADC_CHANNEL_A5 5
#define ADC_CHANNEL_A6 6
#define ADC_CHANNEL_A7 7

/*Function Declarations*/
void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
tenuErrorStatus ADC_enuReadSynch (const uint8 u8ChannelCpy, uint16*const pu16DataCpy);
tenuErrorStatus ADC_enuReadAsynch(const uint8 u8ChannelCpy);
tenuErrorStatus ADC_enuGetData(uint16*const pu16DataCpy);
tenuErrorStatus ADC_enuChangeChannel(const uint8 u8ChannelCpy);
void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisble(void);
tenuErrorStatus ADC_enuSetCallBack(pf pfAdcISRCpy);

#endif

/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : TIMER0                                              */
/* Version : 1.0                                                 */
/* Date    : 19 Dec 2023                                         */
/*****************************************************************/
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit(void);

tenuErrorStatus TIMER0_enuEnable(uint8 u8ClkPrescalerCpy);

void TIMER0_voidSetTimerValue(uint8 u8TimerValueCpy);

tenuErrorStatus TIMER0_enuGetTimerValue(uint8* pu8TimerValueCpy);

void TIMER0_voidSetCmpMatchValue(uint8 u8CmpMatchValueCpy);

void TIMER0_voidIntOvfEnable(void);

void TIMER0_voidIntOvfDisable(void);

void TIMER0_voidIntCmpMatchEnable(void);

void TIMER0_voidIntCmpMatchDisable(void);

tenuErrorStatus TIMER0_enuSetCallBackOvf(pf pfOvfISRCpy);

tenuErrorStatus TIMER0_enuSetCallBackCmpMatch(pf pfCmpMatchISRCpy);

#endif

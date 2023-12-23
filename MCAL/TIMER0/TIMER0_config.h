/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : TIMER0                                              */
/* Version : 1.0                                                 */
/* Date    : 24 Dec 2023                                         */
/*****************************************************************/
#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


#define TIMER0_WG_MODE TIMER0_WG_MODE_NORMAL
/* Options
* TIMER0_WG_MODE_NORMAL
* TIMER0_WG_MODE_PWM_PHASE_CORRECT
* TIMER0_WG_MODE_CTC
* TIMER0_WG_MODE_PWM_FAST
*/


#define TIMER0_CMP_NONPWM_OUTPUT_MODE TIMER0_CMP_NONPWM_OUTPUT_MODE_OFF
/* Options
* TIMER0_CMP_NONPWM_OUTPUT_MODE_OFF
* TIMER0_CMP_NONPWM_OUTPUT_MODE_TOGGLE
* TIMER0_CMP_NONPWM_OUTPUT_MODE_CLEAR
* TIMER0_CMP_NONPWM_OUTPUT_MODE_SET
*/


#define TIMER0_CMP_FASTPWM_OUTPUT_MODE TIMER0_CMP_FASTPWM_OUTPUT_MODE_OFF
/* Options
* TIMER0_CMP_FASTPWM_OUTPUT_MODE_OFF
* TIMER0_CMP_FASTPWM_OUTPUT_MODE_CLEAR_CM_SET_TOP
* TIMER0_CMP_FASTPWM_OUTPUT_MODE_SET_CM_CLEAR_TOP
*/


#define TIMER0_CMP_PCPWM_OUTPUT_MODE TIMER0_CMP_PCPWM_OUTPUT_MODE_OFF
/* Options
* TIMER0_CMP_PCPWM_OUTPUT_MODE_OFF
* TIMER0_CMP_PCPWM_OUTPUT_MODE_CLEAR_UP_SET_DOWN
* TIMER0_CMP_PCPWM_OUTPUT_MODE_SET_UP_CLEAR_DOWN
*/


#define TIMER0_CLK_PRESCALER TIMER0_CLK_PRESCALER_1
/* Options
* TIMER0_CLK_PRESCALER_TIMER_OFF
* TIMER0_CLK_PRESCALER_1
* TIMER0_CLK_PRESCALER_8
* TIMER0_CLK_PRESCALER_64
* TIMER0_CLK_PRESCALER_256
* TIMER0_CLK_PRESCALER_1024
* TIMER0_CLK_PRESCALER_EXTERNAL_FALLING_EDGE
* TIMER0_CLK_PRESCALER_EXTERNAL_RISING_EDGE
*/


#define TIMER0_INTERRUPT_OVF_MODE TIMER0_INTERRUPT_OVF_MODE_DISABLE
/* Options
* TIMER0_INTERRUPT_OVF_MODE_DISABLE
* TIMER0_INTERRUPT_OVF_MODE_ENABLE
*/


#define TIMER0_INTERRUPT_CM_MODE TIMER0_INTERRUPT_OVF_MODE_DISABLE
/* Options
* TIMER0_INTERRUPT_CM_MODE_DISABLE
* TIMER0_INTERRUPT_CM_MODE_ENABLE
*/

#endif

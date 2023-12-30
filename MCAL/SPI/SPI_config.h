/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : SPI                                                 */
/* Version : 1.0                                                 */
/* Date    : 26 Dec 2023                                         */
/*****************************************************************/
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define SPI_INTERRUPT SPI_INTERRUPT_ENABLE
/**Options
* SPI_INTERRUPT_DISABLE
* SPI_INTERRUPT_ENABLE
*/


#define SPI_STATE SPI_STATE_ENABLE
/**Options
* SPI_STATE_DISABLE
* SPI_STATE_ENABLE
*/


#define SPI_DATA_ORDER SPI_DATA_ORDER_MSB_FIRST
/**Options
* SPI_DATA_ORDER_MSB_FIRST
* SPI_DATA_ORDER_LSB_FIRST
*/


#define SPI_MODE SPI_MODE_SLAVE
/**Options
* SPI_MODE_SLAVE
* SPI_MODE_MASTER
*/


#define SPI_CLK_POLARITY SPI_CLK_POLARITY_LE_RISING
/**Options
* SPI_CLK_POLARITY_LE_RISING
* SPI_CLK_POLARITY_LE_FALLING
*/


#define SPI_CLK_PHASE SPI_CLK_PHASE_LE_SAMPLE
/**Options
* SPI_CLK_PHASE_LE_SAMPLE
* SPI_CLK_PHASE_LE_SETUP
*/


#define SPI_CLK_PRESCALER SPI_CLK_PRESCALER_16
/**Options
* SPI_CLK_PRESCALER_2
* SPI_CLK_PRESCALER_4
* SPI_CLK_PRESCALER_8
* SPI_CLK_PRESCALER_16
* SPI_CLK_PRESCALER_32
* SPI_CLK_PRESCALER_64
* SPI_CLK_PRESCALER_128
*/


#endif

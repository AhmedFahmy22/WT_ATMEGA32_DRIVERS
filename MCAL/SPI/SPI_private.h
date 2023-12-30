/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : SPI                                                 */
/* Version : 1.0                                                 */
/* Date    : 26 Dec 2023                                         */
/*****************************************************************/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*Registers*/
#define SPCR (*((volatile uint8*) 0x2D))

#define SPCR_BIT_SPIE 7
#define SPCR_BIT_SPE  6
#define SPCR_BIT_DORD 5
#define SPCR_BIT_MSTR 4
#define SPCR_BIT_CPOL 3
#define SPCR_BIT_CPHA 2
#define SPCR_BIT_SPR1 1
#define SPCR_BIT_SPR0 0

#define SPCR_SPR01_MASK 0b11111100



#define SPSR (*((volatile uint8*) 0x2E))

#define SPSR_BIT_SPIF  7
#define SPSR_BIT_WCOL  6
#define SPSR_BIT_SPI2X 0

#define SPDR (*((volatile uint8*) 0x2F))


/*Configuration Macros*/
#define SPI_INTERRUPT_DISABLE 0
#define SPI_INTERRUPT_ENABLE  1

#define SPI_STATE_DISABLE 0
#define SPI_STATE_ENABLE  1

#define SPI_DATA_ORDER_MSB_FIRST 0
#define SPI_DATA_ORDER_LSB_FIRST 1

#define SPI_CLK_POLARITY_LE_RISING  0
#define SPI_CLK_POLARITY_LE_FALLING 1

#define SPI_CLK_PHASE_LE_SAMPLE 0
#define SPI_CLK_PHASE_LE_SETUP  1

#define SPI_CLK_PRESCALER_2   4
#define SPI_CLK_PRESCALER_4   0
#define SPI_CLK_PRESCALER_8   5
#define SPI_CLK_PRESCALER_16  1
#define SPI_CLK_PRESCALER_32  6
#define SPI_CLK_PRESCALER_64  2
#define SPI_CLK_PRESCALER_128 3

#endif

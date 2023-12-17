/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : MCAL                                                */
/* SWC     : EXTINT1                                             */
/* Version : 1.0                                                 */
/* Date    : 17 Dec 2023                                         */
/*****************************************************************/
#ifndef EXTINT1_PRIVATE_H_
#define EXTINT1_PRIVATE_H_

#define MCUCR  (*((volatile uint8*) 0x55))
#define GIFR   (*((volatile uint8*) 0x5A))
#define GICR   (*((volatile uint8*) 0x5B))
#define MCUCSR (*((volatile uint8*) 0x54))

#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

#define INTF1 2
#define INTF0 1
#define INTF2 0

#define INT1 7
#define INT0 6
#define INT2 5

#define ISC2 6

#endif

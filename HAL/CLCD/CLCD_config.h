/*****************************************************************/
/* Author  : Ahmed                                               */
/* SWC     : CLCD                                                 */
/* Version : 1.0                                                 */
/* Date    : 11 Dec 2023                                         */
/*****************************************************************/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*Macros*/
#define CLCD_CURSOR_MOVE_LEFT  0
#define CLCD_CURSOR_MOVE_RIGHT 1

#define CLCD_DISPLAY_SHIFT_OFF 0
#define CLCD_DISPLAY_SHIFT_ON  1

#define CLCD_CURSOR_DISPLAY_OFF 0
#define CLCD_CURSOR_DISPLAY_ON  1

#define CLCD_CURSOR_BLINK_OFF 0
#define CLCD_CURSOR_BLINK_ON  1

#define CLCD_SHIFT_PATTERN_CURSOR_LEFT   0
#define CLCD_SHIFT_PATTERN_CURSOR_RIGHT  1
#define CLCD_SHIFT_PATTERN_DISPLAY_LEFT  3
#define CLCD_SHIFT_PATTERN_DISPLAY_RIGHT 4

#define CLCD_DATA_LENGTH_8BIT 0
#define CLCD_DATA_LENGTH_4BIT 1

#define CLCD_LINES_NUM_1 0
#define CLCD_LINES_NUM_2 1

#define CLCD_CHAR_FONT_5X7  0
#define CLCD_CHAR_FONT_5X10 1

/*LCD Configurations*/
#define CLCD_CURSOR_MOVE CLCD_CURSOR_MOVE_RIGHT

#define CLCD_DISPLAY_SHIFT CLCD_DISPLAY_SHIFT_OFF

#define CLCD_CURSOR_DISPLAY CLCD_CURSOR_DISPLAY_OFF

#define CLCD_CURSOR_BLINK CLCD_CURSOR_BLINK_OFF

#define CLCD_SHIFT_PATTERN CLCD_SHIFT_PATTERN_CURSOR_RIGHT

#define CLCD_DATA_LENGTH CLCD_DATA_LENGTH_8BIT

#define CLCD_LINES_NUM CLCD_LINES_NUM_2

#define CLCD_CHAR_FONT CLCD_CHAR_FONT_5X7

/*LCD Pins Configuration*/
#define CLCD_DATAPORT       DIO_PORTC /*8 Pins for 8Bit Mode, First 4 Pins for 4Bit Mode*/
#define CLCD_CONTROLPORT    DIO_PORTA
#define CLCD_RSPIN          DIO_PIN0
#define CLCD_RWPIN          DIO_PIN1
#define CLCD_EPIN           DIO_PIN2

#endif

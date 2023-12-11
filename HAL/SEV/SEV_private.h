/*****************************************************************/
/* Author  : Ahmed                                               */
/* Layer   : HAL                                                 */
/* SWC     : SEV                                                 */
/* Version : 1.0                                                 */
/* Date    : 11 Dec 2023                                         */
/*****************************************************************/
#ifndef SEV_PRIVATE_H_
#define SEV_PRIVATE_H_

typedef struct {
    uint8 u8DisplayPort: 2;
    uint8 u8CommonType:  1;
    uint8 u8InitState:   1;
    uint8 u8InitNum:     4;
}tstrSevSeg;

extern tstrSevSeg astrSevConfigGlb[SEV_MAX_NUM];

#endif

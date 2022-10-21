#ifndef DIO_PRIV_H
#define DIO_PRIV_H

#include "STD_Types.h"
#include "BIT_Math.h"

#define DDRA *((volatile uint8 *)0x3A)
#define DDRB *((volatile uint8 *)0x37)
#define DDRC *((volatile uint8 *)0x34)
#define DDRD *((volatile uint8 *)0x31)
#define IDRA *((volatile uint8 *)0x39)
#define IDRB *((volatile uint8 *)0x36)
#define IDRC *((volatile uint8 *)0x33)
#define IDRD *((volatile uint8 *)0x30)
#define ODRA *((volatile uint8 *)0x3B)
#define ODRB *((volatile uint8 *)0x38)
#define ODRC *((volatile uint8 *)0x35)
#define ODRD *((volatile uint8 *)0x32)

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0) CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif

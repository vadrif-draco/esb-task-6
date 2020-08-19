#ifndef _REGS_H_
#define _REGS_H_

#include "../Application/typedefs.h"


// DIO Registers Addresses
#define PORTA (vuint8_t*)(0x3B)
#define DDRA  (vuint8_t*)(0x3A)
#define PINA  (vuint8_t*)(0x39)

#define PORTB (vuint8_t*)(0x38)
#define DDRB  (vuint8_t*)(0x37)
#define PINB  (vuint8_t*)(0x36)

#define PORTC (vuint8_t*)(0x35)
#define DDRC  (vuint8_t*)(0x34)
#define PINC  (vuint8_t*)(0x33)

#define PORTD (vuint8_t*)(0x32)
#define DDRD  (vuint8_t*)(0x31)
#define PIND  (vuint8_t*)(0x30)

#endif
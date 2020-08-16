#include "typedefs.h"

#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

typedef enum {input, output} EN_DIO_config_t[4][8];
typedef enum {LOW, HIGH} EN_pinState_t;

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


void DIO_init(EN_DIO_config_t configurations);

void DIO_write(vuint8_t port, uint8_t bit, EN_pinState_t ps);
EN_pinState_t DIO_read(vuint8_t port, uint8_t bit);
void DIO_toggle(vuint8_t port, uint8_t bit);

#endif /* DIO_CONTROL_H_ */
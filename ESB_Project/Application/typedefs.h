#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

// Signed typedefs
typedef signed char int8_t;
// typedef short int16_t;
typedef long int32_t;
typedef long long int64_t;

// Unsigned typedefs
typedef unsigned char uint8_t;
// typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

// Signed typedefs limits
#define INT8_MIN -0x7f - 1
#define INT8_MAX 0x7f
#define INT16_MIN -0x7fff - 1
#define INT16_MAX 0x7fff
#define INT32_MIN -0x7fffffff - 1
#define INT32_MAX 0x7fffffff
#define INT64_MIN -0x7fffffffffffffff - 1
#define INT64_MAX 0x7fffffffffffffff

// Unsigned typedefs limits
#define UINT8_MAX 0xff
#define UINT16_MAX 0xffff
#define UINT32_MAX 0xffffffff
#define UINT64_MAX 0xffffffffffffffff

// Task 6 Specific typedefs and defines
typedef enum {A0, A1, A2, A3, A4, A5, A6, A7,
              B0, B1, B2, B3, B4, B5, B6, B7,
              C0, C1, C2, C3, C4, C5, C6, C7,
              D0, D1, D2, D3, D4, D5, D6, D7,
             } EN_PINS;
typedef enum {LOW, HIGH} EN_pinState_t;
typedef volatile uint8_t vuint8_t;
#define F_CPU 1000000UL

#endif
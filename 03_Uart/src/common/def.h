/*
 * def.h
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */

#ifndef SRC_COMMON_DEF_H_
#define SRC_COMMON_DEF_H_


#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>




#define _DEF_LED1                   0
#define _DEF_LED2                   1
#define _DEF_LED3                   2
#define _DEF_LED4                   3


#define _DEF_BUTTON1                0
#define _DEF_BUTTON2                1
#define _DEF_BUTTON3                2
#define _DEF_BUTTON4                3


#define _DEF_UART1                  0
#define _DEF_UART2                  1
#define _DEF_UART3                  2
#define _DEF_UART4                  4


typedef uint32_t  err_code_t;




typedef void (*voidFuncPtr)(void);



typedef union
{
  uint8_t  u8Data[4];
  uint16_t u16Data[2];
  uint32_t u32Data;

  int8_t   s8Data[4];
  int16_t  s16Data[2];
  int32_t  s32Data;

  uint8_t  u8D;
  uint16_t u16D;
  uint32_t u32D;

  int8_t   s8D;
  int16_t  s16D;
  int32_t  s32D;
} data_t;


typedef struct
{
  data_t data;
  bool   ret;
} data_ret_t;


typedef struct
{
  uint32_t  ptr_in;
  uint32_t  ptr_out;
  uint32_t  length;
  uint8_t  *p_buf;
} ring_buf_t;


typedef struct
{
  uint32_t addr;
  uint32_t end;
  uint32_t length;
} flash_attr_t;



#define PI              3.1415926535897932384626433832795
#define HALF_PI         1.5707963267948966192313216916398
#define TWO_PI          6.283185307179586476925286766559
#define DEG_TO_RAD      0.017453292519943295769236907684886
#define RAD_TO_DEG      57.295779513082320876798154814105
#define EULER           2.718281828459045235360287471352

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef map
#define map(value, in_min, in_max, out_min, out_max) ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
#endif

#ifndef byte
#define byte uint8_t
#endif

#ifndef radians
#define radians(deg) ((deg)*DEG_TO_RAD)
#endif
#ifndef degress
#define degrees(rad) ((rad)*RAD_TO_DEG)
#endif
#ifndef sq
#define sq(x) ((x)*(x))
#endif



#endif /* SRC_COMMON_DEF_H_ */

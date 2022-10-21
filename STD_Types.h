/**************************************/
/* Description  : Standard tybes lib  */
/* Author       : A.Fahmy             */
/* Date         : 5/8/2022            */
/*Version       : 0.1V                */
/**************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;

typedef signed char sint8;
typedef signed short int sint16;
typedef signed int sint32;

typedef float float32;
typedef double float64;
typedef long double float128;

#define NULL_PTR ((void *)0)

typedef enum {
  E_OK,
  E_NOK_PARAM_OUT_OF_RANGE,
  E_NOK_PARAM_NULL_POINTER,
  E_NOK,
  E_NOK_PARAM_OUT_CONFIG_ERROR
}tenuErrorStatus;

#endif

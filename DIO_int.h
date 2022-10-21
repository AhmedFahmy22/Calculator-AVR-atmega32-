/*************************************/
/* Description :  DIO interface file */
/* Author      :  Fahmy              */
/* Date        :  20 Aug 2022         */
/* Version     :  0.1V                */
/*************************************/
#ifndef  DIO_INT_H
#define  DIO_INT_H

void DIO_voidInit(void);
tenuErrorStatus DIO_enuSetPinValue(uint8 u8PinNumCpy , uint8 u8PinValueCpy);
tenuErrorStatus DIO_enuGetPinValue(uint8 u8PinNumCpy, uint8 *pu8PinValueCpy);



#endif



#ifndef LCD_INT_H
#define LCD_INT_H

void LCD_voidInit(void);
tenuErrorStatus LCD_enuWriteCmd(uint8 u8LcdIndxCpy , uint8 u8LcdCmdCpy);
tenuErrorStatus LCD_enuWriteData(uint8 u8LcdIndxCpy , uint8 u8LcdDataCpy);
void LCD_voidWriteString(uint8 u8LcdIndxCpy, uint8 *pStringCpy);
void LCD_voidWriteFloat(uint8 u8LcdIndxCpy, float64 f64LcdDataCpy);


#endif

#include "STD_Types.h"
#include "DIO_int.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"
#include "KEYPAD_int.h"
#include <avr/delay.h>

void KEYPAD_voidInit(void)
{
  uint8 u8CntrLoc,u8PinsCntrLoc;
  for(u8CntrLoc=0;u8CntrLoc<KEYPAD_MAX_NUM;u8CntrLoc++)
  {
    for(u8PinsCntrLoc=0; u8PinsCntrLoc<KEYPAD_astrCfgSet[u8CntrLoc].u8InputPinsNum; u8PinsCntrLoc++)
    {
      DIO_enuSetPinValue(KEYPAD_astrCfgSet[u8CntrLoc].au8InputPins[u8PinsCntrLoc],1);
    }
    for(u8PinsCntrLoc=0; u8PinsCntrLoc<KEYPAD_astrCfgSet[u8CntrLoc].u8OutputPinsNum; u8PinsCntrLoc++)
    {
      DIO_enuSetPinValue(KEYPAD_astrCfgSet[u8CntrLoc].au8OutputPins[u8PinsCntrLoc],1);
    }
  }
}

uint8 KEYPAD_u8GetPressedKey(uint8 u8KeypadNumCpy)
{
  uint8 u8SeqCntrLoc,u8ReadValueLoc;
  for(u8SeqCntrLoc=0;u8SeqCntrLoc<KEYPAD_astrCfgSet[u8KeypadNumCpy].u8OutputPinsNum;u8SeqCntrLoc++)
  {
    KEYPAD_voidWriteSeq(u8KeypadNumCpy,u8SeqCntrLoc);
    _delay_ms(190);
    KEYPAD_voidReadInputs(u8KeypadNumCpy,&u8ReadValueLoc);
    _delay_ms(10);
    if(u8ReadValueLoc!=0xFF)
    {
      return KEYPAD_au8SwitchMapping[u8KeypadNumCpy][u8ReadValueLoc][u8SeqCntrLoc];
    }
  }
  return 0xFF;
}

void KEYPAD_voidWriteSeq(uint8 u8KeypadNumCpy, uint8 u8SeqNumCpy)
{
  uint8 u8PinsCntrLoc;
  for(u8PinsCntrLoc=0; u8PinsCntrLoc<KEYPAD_astrCfgSet[u8KeypadNumCpy].u8OutputPinsNum; u8PinsCntrLoc++)
  {
    if(u8PinsCntrLoc==u8SeqNumCpy)
    {
      DIO_enuSetPinValue(KEYPAD_astrCfgSet[u8KeypadNumCpy].au8OutputPins[u8PinsCntrLoc],0);
    }
    else
    {
      DIO_enuSetPinValue(KEYPAD_astrCfgSet[u8KeypadNumCpy].au8OutputPins[u8PinsCntrLoc],1);
    }
  }
}
void KEYPAD_voidReadInputs(uint8 u8KeypadNumCpy, uint8 *pu8ReadDataCpy)
{
  uint8 u8PinsCntrLoc,u8TempLoc;
  *pu8ReadDataCpy=0xFF;
  for(u8PinsCntrLoc=0; u8PinsCntrLoc<KEYPAD_astrCfgSet[u8KeypadNumCpy].u8InputPinsNum; u8PinsCntrLoc++)
  {
    DIO_enuGetPinValue(KEYPAD_astrCfgSet[u8KeypadNumCpy].au8InputPins[u8PinsCntrLoc],&u8TempLoc);
    if(u8TempLoc==0)
    {
      *pu8ReadDataCpy=u8PinsCntrLoc;
      break;
    }
  }
}

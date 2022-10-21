#ifndef KEYPAD_PRIV_H
#define KEYPAD_PRIV_H


typedef struct {
  uint8 au8InputPins[KEYPAD_MAX_INPUT_NUM];
  uint8 au8OutputPins[KEYPAD_MAX_OUTPUT_NUM];
  uint8 u8InputPinsNum;
  uint8 u8OutputPinsNum;
}tstrKeypadCfg;

extern tstrKeypadCfg KEYPAD_astrCfgSet[KEYPAD_MAX_NUM];
extern uint8 KEYPAD_au8SwitchMapping[KEYPAD_MAX_NUM][KEYPAD_MAX_INPUT_NUM][KEYPAD_MAX_OUTPUT_NUM];

void KEYPAD_voidWriteSeq(uint8 u8KeypadNumCpy, uint8 u8SeqNumCpy);
void KEYPAD_voidReadInputs(uint8 u8KeypadNumCpy, uint8 *pu8ReadDataCpy);

#endif

#include "STD_Types.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"

tstrKeypadCfg KEYPAD_astrCfgSet[KEYPAD_MAX_NUM] = {
{
    {24,25,26,27}, /*Input Pins*/
    {28,29,30,31}, /*Output Pins*/
    4, 4       /*InputPins, OutputPins*/
}
};

uint8 KEYPAD_au8SwitchMapping[KEYPAD_MAX_NUM][KEYPAD_MAX_INPUT_NUM][KEYPAD_MAX_OUTPUT_NUM]=
{
  {
    {'7','8','9','+'},{'4','5','6','-'},{'1','2','3','*'},{'0','.','/','='}
  }
};

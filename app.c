#include "STD_Types.h"
#include "BIT_Math.h"

#include <avr/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"

uint8 au8Op[4] = {'*','/','+','-'};

typedef struct {
  uint8 u8NumCntr;
  uint8 u8OperCntr;
  uint8 au8Operands[15];
  float128 af128Numbers[16];
}tstrNumsOpers;

tstrNumsOpers Calculate(tstrNumsOpers *ptrCpy, uint8 u8operandCpy);

int main(void)
{
	DIO_voidInit();
	KEYPAD_voidInit();
	uint8 au8Characters[20];
	uint8 u8CntrLoc;
	tstrNumsOpers strNumsOpers;
	float128 f128Num;
	uint8 u8InputF,u8PointF,u8SignF;
	uint8 u8Input;
	uint8 u8CntrLoc1;
while(1)
{
	  LCD_voidInit();
	  strNumsOpers.u8NumCntr=0;
	  strNumsOpers.u8OperCntr=0;
	  f128Num=0;
	  u8InputF=0;
    u8PointF=0;
    u8SignF=0;
		u8Input=0xFF;

    /*Get array of numbers and operands entered using keypad*/
		u8CntrLoc=0;
				while(u8Input==0xFF)
				{
					while(u8Input==0xFF)
					{
						u8Input=KEYPAD_u8GetPressedKey(0);
					}
					au8Characters[u8CntrLoc]=u8Input;
					u8CntrLoc++;
					if(u8Input!='=')
					{
						LCD_enuWriteData(0,u8Input);
						u8Input=0xFF;
					}
					else
					{
						LCD_voidInit();
					}
				}

    /*Make array of numbers instead of characters*/
		for(u8CntrLoc=0;au8Characters[u8CntrLoc-1]!='=';u8CntrLoc++)
	  {
	    if((au8Characters[u8CntrLoc]>='0')&&(au8Characters[u8CntrLoc]<='9'))
	    {
	      if(u8PointF>0)
        {
          u8PointF++;
        }
        f128Num=(f128Num*10)+au8Characters[u8CntrLoc]%'0';
        u8InputF=1;
	    }
	    else
	    {
        if(au8Characters[u8CntrLoc]=='.')
        {
          u8PointF=1;
          continue;
        }
        else if(au8Characters[u8CntrLoc]!='=')
	      {
          if(au8Characters[u8CntrLoc]=='-'&&u8InputF==0)
          {
            u8SignF=1;
            continue;
          }
          strNumsOpers.au8Operands[strNumsOpers.u8OperCntr]=au8Characters[u8CntrLoc];
	        strNumsOpers.u8OperCntr++;
	      }
	      if(u8InputF==1)
	      {
          for(u8CntrLoc1=1;u8CntrLoc1<u8PointF;u8CntrLoc1++)
          {
            f128Num=(f128Num/10);
          }
          if(u8SignF==1)
          {
            f128Num=-f128Num;
            u8SignF=0;
          }
          strNumsOpers.af128Numbers[strNumsOpers.u8NumCntr]=f128Num;
	        strNumsOpers.u8NumCntr++;
	        f128Num=0;
	        u8InputF=0;
          u8PointF=0;
	      }
	    }
	  }


		/*Find Result*/
		if(strNumsOpers.u8NumCntr<=strNumsOpers.u8OperCntr)
		{
			LCD_voidWriteString(0,"Syntax Error");
		}
		else
		{
			for(u8CntrLoc=0;u8CntrLoc<4;u8CntrLoc++)
		  {
		    strNumsOpers=Calculate(&strNumsOpers,u8CntrLoc);
		  }

      f128Num = strNumsOpers.af128Numbers[0];

      LCD_enuWriteData(0,'=');
			LCD_enuWriteCmd(0,0xC0);
      LCD_voidWriteFloat(0,f128Num);
		}
		_delay_ms(5000);
	}
}

tstrNumsOpers Calculate(tstrNumsOpers *ptrCpy, uint8 u8operandCpy)
{
  tstrNumsOpers temp={
    1,
    0,
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };
  uint8 u8CntrLoc,n;
  float128 f128result;
  temp.af128Numbers[0]=ptrCpy->af128Numbers[0];

  f128result=temp.af128Numbers[0];
  n=0;
  for(u8CntrLoc=0;u8CntrLoc<ptrCpy->u8OperCntr;u8CntrLoc++)
  {
    if(ptrCpy->au8Operands[u8CntrLoc]==au8Op[u8operandCpy])
    {
      switch(u8operandCpy)
      {
        case 0:
        f128result=temp.af128Numbers[u8CntrLoc-n]*ptrCpy->af128Numbers[u8CntrLoc+1];
        break;
        case 1:
        f128result=temp.af128Numbers[u8CntrLoc-n]/ptrCpy->af128Numbers[u8CntrLoc+1];
        break;
        case 2:
        f128result=temp.af128Numbers[u8CntrLoc-n]+ptrCpy->af128Numbers[u8CntrLoc+1];
        break;
        default:
        f128result=temp.af128Numbers[u8CntrLoc-n]-ptrCpy->af128Numbers[u8CntrLoc+1];
      }
      temp.af128Numbers[u8CntrLoc-n]=f128result;
      n++;
    }
    else
    {
      temp.au8Operands[temp.u8OperCntr]=ptrCpy->au8Operands[u8CntrLoc];
      temp.af128Numbers[temp.u8NumCntr]=ptrCpy->af128Numbers[u8CntrLoc+1];
      temp.u8OperCntr++;
    }
    temp.u8NumCntr=temp.u8OperCntr+1;
  }
  return temp;
}

#include "SYSTICK.h"


void SYSTICK_ENABLE(void)
{
  NVIC_ST_CTRL_R |= 5;
}

void SYSTICK_DISABLE(void)
{
  NVIC_ST_CTRL_R = 0;
}

uint32 SYSTICK_PERIOD_GET(void)
{
   
   return (NVIC_ST_CURRENT_R)/16000;
}
void SYSTICK_PERIOD_SET(uint32 PERIOD_MS)
{

   uint32 counts=0;
   counts = (PERIOD_MS * CLK_FRQ)-1;
   NVIC_ST_RELOAD_R= counts;
}

uint32 SYSTICK_VALUE_GET(void)
{
   return NVIC_ST_CURRENT_R;
}


uint8 SYSTICK_IS_TIME_OUT(void)
{
  return GET_BIT(NVIC_ST_CTRL_R , 16);
}


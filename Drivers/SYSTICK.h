#include "GPIO.h"
#include "tm4c123gh6pm.h"
#include "BIT_MATH.h"
#include "STANDARD_TYPES.h"

#define CLK_FRQ 16000
  

//2^24
void SYSTICK_ENABLE(void);
void SYSTICK_DISABLE(void);
uint32 SYSTICK_PERIOD_GET(void);
void SYSTICK_PERIOD_SET(uint32 PERIOD_MS);
uint32 SYSTICK_VALUE_GET(void);
uint8 SYSTICK_IS_TIME_OUT(void);








#ifndef  __CONFIG1_H_
#define  __CONFIG1_H_

#include "stm8s.h"

#include "type1.h"

#define  SLEEP  0


// If the pump runs for more than 20 minutes in a row, it turns off, in minutes
#define TIME_RUN_ROW            20  

// If for 1 hour the pump has worked in total for more than 30min, then it turns off, in sec
#define TIME_RUN_TOTAL        (30*60)

// If the pump has not been turned on for 10 minutes, then all counters are reset
#define TIME_RESET_COUNTERS   (10*60)

// reset cnt_turn_on every 20 min
#define TIME_RESET_CNT_TURN_ON   (20*60)



#define NUMBER_INPUTS   1
#define NUMBER_OUTPUTS  1


//#include <stdint.h>

#endif  // __CONFIG1_H_

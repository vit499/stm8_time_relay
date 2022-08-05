
#include "config1.h"
#include "lib_common.h"
#include "hw_out.h"
#include "lib_cp.h"


static U8 tc_1min_out;
static U8 tc_1s_out;
//static U8 tc_1min_out_max;
U32 t_window;
U32 t_when_on;
U32 t_when_off;
U32 t_window_fast;
U8 cnt_turn_on;
U8 must_not_turn_on;
//-----------------------------

/*

*/
void hw_out_init () { 

  OUT1_PORT->DDR |=  OUT1_PIN;
  OUT1_PORT->CR1 |=  OUT1_PIN;

  out_off();
  tc_1min_out = 0;
  
  t_when_off = 0;
  t_window = 0;
  t_when_on = 0;
  t_window_fast = 0;
  cnt_turn_on = 0; 
  must_not_turn_on = 0;
}
//------------------------------

void proc_out () { 

  if(!Is_ft_1s_out()) return;
  if(must_not_turn_on) return;
  
  if(Is_out_on()) { 
    if(++tc_1s_out >= 60) {   // 1min
      tc_1s_out = 0;
      if(++tc_1min_out >= TIME_RUN_ROW) { 
        // If the pump runs for more than 20 minutes in a row, it turns off
        LOGf("\r time run row over ", 0);
        out_off_forever();
      }
    }
  }

  proc_time_when_on();

}
//--------------------------------


void control_out (U8 on) { 
 
  if(must_not_turn_on) return;

  if(on) { 
    LOGf("\r out ON ", 0);
    tc_1s_out = 0;
    tc_1min_out = 0;
    //tc_1min_out_max = TIME_RUN_ROW;  // minutes
    out_on();
    inc_cnt_turn_on();
  }
  else { 
    LOGf("\r out OFF ", 0);
    out_off();
  }

}
//----------------------------------

void out_off_forever () { 
  LOGf("\r out off forever !!!!!!!! ", 0);
  out_off();
  must_not_turn_on = 1;
}
//---------------------

void out_on()   { 
  OUT1_PORT->ODR |=  OUT1_PIN;
}
void out_off()  { 
  OUT1_PORT->ODR &= ~OUT1_PIN; 
}
//---------------------

U8 Is_out_on ()  {
  if(OUT1_PORT->ODR & OUT1_PIN) return(1);
  return(0);
}
//------------------------------------

/*
 There is a counter of inclusions.
 If the pump turns on 10 times within 20 minutes, it turns off.
*/
void inc_cnt_turn_on () { 
  cnt_turn_on++;
  LOGk1("\r inp cnt_turn_on = ", cnt_turn_on);
  if(cnt_turn_on > 9) { 
      // If the pump turns on 10 times within 20 minutes, it turns off
    LOGf("\r cnt_turn_on over ", 0);
    out_off_forever();
  }
}
//----------------------------

/*
 the total running time of the pump per hour is calculated.
 If for 1 hour the pump has worked in total for more than 30min, then it turns off.

 If the pump has not been turned on for 10 minutes, then all counters are reset.
*/
void proc_time_when_on () { 
  
  ++t_window;
  ++t_window_fast;

  if(Is_out_on()) { 
    // the total running time of the pump per hour is calculated
    t_when_on++;
    t_when_off = 0;
  }
  else t_when_off++;

  if(t_window >= 3600) {   // 1hour
    LOGk1("\r t_window 1 hour, t_when_on = ", t_when_on);
    t_window = 0;
    if(t_when_on >= TIME_RUN_TOTAL) { 
      // If for 1 hour the pump has worked in total for more than 30min, then it turns off
      LOGf("\r t_when_on over ", 0);
      out_off_forever();
    }
    cnt_turn_on = 0;
    t_when_on = 0;
  }
  if(t_when_off >= TIME_RESET_COUNTERS) {  // 10min
    // If the pump has not been turned on for 10 minutes, then all counters are reset
    t_when_off = 0;
    t_window = 0;
    t_when_on = 0;
    cnt_turn_on = 0;
    t_window_fast = 0;
    LOGf("\r t_when_off over, reset counters ", 0);
  }
  if(t_window_fast >= TIME_RESET_CNT_TURN_ON) {   // 20min
    // reset cnt_turn_on every 20 min
    t_window_fast = 0;
    cnt_turn_on = 0;
    LOGf("\r t_window_fast, reset cnt_turn_on ", 0);
  } 
}
//----------------------------------





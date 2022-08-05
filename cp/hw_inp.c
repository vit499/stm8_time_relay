
#include "config1.h"
#include "lib_common.h"
#include "hw_inp.h"

U8 tc_inp[NUMBER_INPUTS];
U8 stat[NUMBER_INPUTS];
U8 lock_inp;
U8 tc_lock_inp;

/*

*/
void inp_init () { 
  U8 inp;

  for(inp = 0; inp < NUMBER_INPUTS; inp++) { 
    stat[inp] = 0;
    tc_inp[inp] = 0;
  }

  lock_inp = 1;
  tc_lock_inp = 0;
 // control_out(0, 1, 1);
 // alarm_led();
}
//-------------------------------------

#define pin_jp1    (JP1_PORT->IDR & JP1_PIN)

U8 Is_jp1 () { 
  //if(pin_jp1) return(1);
  //else return(0); 
  return(1);
}
//---------------------------------

#define pin_inp1    (IN1_PORT->IDR & IN1_PIN)

U8 Is_inp1 () { 
  if(pin_inp1) return(1);
  else return(0); 
}
//---------------------------------

/*

*/
void check_inp (U8 inp) { 
  U8 s;

  if(inp > 0) return;

  s = Is_inp1();
  if(stat[inp]) { 
    if(!s) { 
      if(++tc_inp[inp] > 5) { 
        stat[inp] = 0;
        proc_input(inp, 0);
        tc_inp[inp] = 0;
      }
    }
    else tc_inp[inp] = 0;
  }
  else { 
    if(s) { 
      if(++tc_inp[inp] > 5) { 
        stat[inp] = 1;
        proc_input(inp, 1);
        tc_inp[inp] = 0;
      }
    }
    else tc_inp[inp] = 0;
  }
}
//-----------------------------

/*

*/
void check_hw_input () { 
  U8 inp;

  if(!Is_ft_100ms_inp()) return;

//  if(lock_inp) { 
//    if(++tc_lock_inp > 100) { 
//      tc_lock_inp = 0;
//      lock_inp = 0;
//    }
//    return;
//  }

  for(inp = 0; inp < NUMBER_INPUTS; inp++) { 
    check_inp(inp);
  }
}
//-----------------------------------

void proc_input (U8 inp, U8 alarm) { 
  if(alarm) { 
    LOGf("\r inp stat = 1 ", 0);
    control_out(1);
    //alarm_led();
  }
  else { 
    LOGf("\r inp stat = 0 ", 0);
    control_out(0);
  }
}
//----------------------------------







#include "config1.h"
#include "lib_common.h"
#include "lib_cp.h"

/*

*/
void start_init () { 

  /* Fmaster = 16MHz */
 // CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV8);
  clk_init();

  wdt_init();
  hw_init();
  uart_init();

  timer_init();
  inp_init();
  
  enableInterrupts();
  //delay_100ms(10);
  LOGf("\r Start stm8 ", 0);
}
//---------------------------------

void main () { 
  //int a;

  start_init();

#if (SLEEP == 1)
  awu_init();
#endif

  while(1) { 
    wdr();
#if (SLEEP == 1)
    halt();
#endif
    processing_100ms();
    if(Is_ft_1s()) { 
      //led_tog();
    }
    check_hw_input();
    proc_out();
  }

}

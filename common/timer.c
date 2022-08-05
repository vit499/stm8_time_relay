
#include "config1.h"
#include "lib_common.h"

volatile uint8_t  ft_100ms;
volatile uint8_t  tc1;
volatile uint8_t ft_100ms1;
uint8_t ft_1s;
uint8_t ft_1min;
uint8_t tc_1s;
volatile uint8_t tc_100ms1;
volatile uint8_t tc_100msc;
uint8_t tc_1min;
uint8_t tc_led;
uint8_t ft_1s_out;
uint8_t ft_100ms_inp;
uint8_t awu_en;
uint8_t alarm_en;

/*

*/
void timer_init () { 

 // TIM4_TimeBaseInit(TIM4_PRESCALER_128, 124);
 // TIM4_TimeBaseInit(TIM4_PRESCALER_128, 15);
  TIM4_TimeBaseInit(TIM4_PRESCALER_8, 124);

  TIM4_ClearFlag(TIM4_FLAG_UPDATE);

  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  
  ft_100ms = 0;
  ft_1s = 0;
  ft_1min = 0;
  alarm_en = 0;
  alarm_led();

  TIM4_Cmd(ENABLE);
  //awu_en = 1;
}
//--------------------------------

uint8_t Is_ft_100ms () { 
  if(ft_100ms) { ft_100ms = 0; return(1); }
  else return(0);
}
//-----------------------

uint8_t Is_ft_100ms1 () { 
  if(ft_100ms1) { ft_100ms1 = 0; return(1); }
  else return(0);
}
//-----------------------

uint8_t Is_ft_1s () { 
  if(ft_1s) { ft_1s = 0; return(1); }
  else return(0);
}
//-----------------------

void sc_100ms (U8 t) { 
  ft_100ms1 = 0; 
  tc_100ms1 = 0;
  tc_100msc = t;
}

//uint8_t Is_ft_1min () { 
//  if(ft_1min) { ft_1min = 0; return(1); }
//  else return(0);
//}
//-----------------------

uint8_t Is_ft_1s_out () { 
  if(ft_1s_out) { ft_1s_out = 0; return(1); }
  else return(0);
}
//-----------------------

uint8_t Is_ft_100ms_inp () { 
  if(ft_100ms_inp) { ft_100ms_inp = 0; return(1); }
  else return(0);
}
//-----------------------

void delay_100ms (U8 t) { 
  sc_100ms(t);
  while(!Is_ft_100ms1()) wdr(); 
}

void alarm_led () { 
  tc_led = 0;
  led_on();
  alarm_en = 1;
}

/*

*/
void processing_100ms () { 
  if(!Is_ft_100ms()) return;
  
  if(++tc_1s > 7) { 
    tc_1s = 0;
//    if(++tc_1min > 59) { 
//      tc_1min = 0;
//      ft_1min = 1;
//    }
    ft_1s = 1;
    ft_1s_out = 1;
  }
  ft_100ms_inp = 1;


  if(Is_sled()) { 
    tc_led = 0;
    led_off();
  }
  else { 
    if(++tc_led > 28) { 
      led_on();
    }
  }  
}
//--------------------------

/*

*/
void timer_irq () { 
  uint8_t temp;

  if(++tc1 > 12) { 
    tc1 = 0;
    ft_100ms = 1;
  }
  temp = tc_100msc;
  if(++tc_100ms1 > temp) { 
    tc_100ms1 = 0;
    ft_100ms1 = 1;
  }
  TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
}
//-----------------------------------


void awu_init () { 
  
  //AWU->CSR |= AWU_CSR_AWUEN;
  AWU_Init(AWU_TIMEBASE_128MS);
 // AWU_Init(AWU_TIMEBASE_1S);

  TIM4_ITConfig(TIM4_IT_UPDATE, DISABLE);
  TIM4_Cmd(DISABLE);
  //halt();
}
//------------------------------

/*

*/
void awu_irq () { 
  U8 a = AWU->CSR;
  ft_100ms = 1;
}
//-----------------------------



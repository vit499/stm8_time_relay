
#include "config1.h"
#include "hw.h"

uint8_t sled;

/*

*/
void hw_init () { 

  hw_unused_init();
  led_init();
  hw_out_init();
}
//----------------------

/*

*/
void led_init () { 
  led_on();

}
//------------------------

void led_on () { 
  LED_PORT->DDR |=  LED_PIN;
  LED_PORT->ODR &= ~LED_PIN;
  sled = 1; 
}

void led_off () { 
  LED_PORT->DDR &= ~LED_PIN;
  LED_PORT->ODR &= ~LED_PIN; 
  sled = 0;
}

void led_tog () { 
  if(sled) led_off();
  else led_on();
}
//------------------------------

uint8_t Is_sled () { 
  if(sled) return(1); 
  else return(0);
}
//--------------------------------

#define  PA_MASK  0xff
#define  PB_MASK  0xff
#define  PC_MASK  0xff
#define  PD_MASK  0xff

/*
 a1 - a3
 b4, b5 (led)
 c3 - c7
 d2 - d6

*/
void hw_unused_init () { 

  GPIOA->DDR &= ~PA_MASK;
  GPIOA->CR1 |=  PA_MASK;
  GPIOB->DDR &= ~PB_MASK;
  GPIOB->CR1 |=  PB_MASK;
  GPIOC->DDR &= ~PC_MASK;
  GPIOC->CR1 |=  PC_MASK;
  GPIOD->DDR &= ~PD_MASK;
  GPIOD->CR1 |=  PD_MASK;
}
//---------------------------------


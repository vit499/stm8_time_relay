
#ifndef  __HW_H_
#define  __HW_H_

#include "hw_out.h"

#define LED_PORT    GPIOB
#define LED_PIN     GPIO_PIN_5


void hw_init ();
void led_init ();
void led_on ();
void led_off ();
void led_tog () ;
uint8_t Is_sled ();
void hw_unused_init ();

#endif  // __HW_H_

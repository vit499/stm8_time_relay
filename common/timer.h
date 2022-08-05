
#ifndef  __TIMER_H_
#define  __TIMER_H_

void timer_init ();
uint8_t Is_ft_100ms ();
uint8_t Is_ft_1s ();
uint8_t Is_ft_1min ();
void processing_100ms ();
uint8_t Is_ft_1s_out ();
uint8_t Is_ft_100ms_inp ();
void delay_100ms (U8 t);
uint8_t Is_ft_100ms1 ();
void alarm_led ();

void timer_irq ();
void awu_irq ();
void awu_init ();

#endif  // __TIMER_H_


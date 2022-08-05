
#ifndef  __HW_OUT_H_
#define  __HW_OUT_H_


#define OUT1_PORT    GPIOD
#define OUT1_PIN     GPIO_PIN_4

void hw_out_init ();
void control_out (U8 on);
void out_on ();
void out_off ();
void proc_out ();
U8 Is_out_on ();
void inc_cnt_turn_on ();
void out_off_forever ();

#endif  // __HW_OUT_H_

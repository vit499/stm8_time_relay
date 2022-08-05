
#ifndef  __HW_INP_H_
#define  __HW_INP_H_


#define IN1_PORT    GPIOD
#define IN1_PIN     GPIO_PIN_3

#define JP1_PORT    GPIOA
#define JP1_PIN     GPIO_PIN_2

void inp_init ();
void proc_input (U8 inp, U8 alarm);
void check_hw_input ();
U8 Is_jp1 ();

void proc_time_when_on ();

#endif  // __HW_INP_H_

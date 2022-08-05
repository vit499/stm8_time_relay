
#include "config1.h"
#include "hw_uart.h"

#define BUFF_SIZE_0  0x100

typedef struct {
	uint16_t	ri, wi, ct, act;
	uint8_t		buff[BUFF_SIZE_0];
} S_uart0;

volatile S_uart0  s_u0tx;

/*

*/
void uart_init () {

  UART1_Init((uint32_t)57600, UART1_WORDLENGTH_8D,UART1_STOPBITS_1, UART1_PARITY_ODD,
                   UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);


  UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
  

  UART1_ITConfig(UART1_IT_TXE, ENABLE);

 
  UART1_Cmd(ENABLE);
  
 
  enableInterrupts();
}
//------------------------------------

void uart_rx_irq () {
  uint8_t c;

  c = get_rx0();
  (void) c;
}
//------------------------------------

void uart_tx_irq () {
  uint16_t cnt;
  uint16_t i;

    cnt = s_u0tx.ct;
    if(cnt) {		
      i = s_u0tx.ri;
      hw_send_uart0(s_u0tx.buff[i]); // LPC_UART0->THR = s_u0tx.buff[i];
      cnt--;
      if(s_u0tx.wi >= cnt) 
        i = s_u0tx.wi - cnt;
      else 
        i = BUFF_SIZE_0 + s_u0tx.wi - cnt; 
      s_u0tx.ri = i % BUFF_SIZE_0;
      s_u0tx.ct = cnt;
    } 
    else {
      s_u0tx.act = 0; 
     // USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
      UART1_ITConfig(UART1_IT_TXE, DISABLE);
    }

}
//---------------------------------------------

#define WAIT_UART  1

/*
 uart only
*/
void put0 (uint8_t c) {
  uint16_t i;
#if (WAIT_UART == 0)
  uint16_t cnt;
#endif

  if(s_u0tx.ct >= (BUFF_SIZE_0-1)) { 
#if WAIT_UART
   // if(Is_enable_interrupt(USART1_IRQn) && Is_en_interrupt_global()) {    
      while (s_u0tx.ct >= (BUFF_SIZE_0-5)) ; //wdr();  ///  !!!
   // }
   // else { 
#else
      NVIC_DisableIRQ(USART1_IRQn);
      cnt = s_u0tx.ct;
      cnt--;
      if(s_u0tx.wi >= cnt) 
        i = s_u0tx.wi - cnt;
      else 
        i = BUFF_SIZE_0 + s_u0tx.wi - cnt;
      s_u0tx.ri = i % BUFF_SIZE_0;
      s_u0tx.ct = cnt;    
   // } 
#endif
  } 
  //NVIC_DisableIRQ(USART1_IRQn);
  if (s_u0tx.act) {
    i = s_u0tx.wi;		
    s_u0tx.buff[i++] = c;
    s_u0tx.wi = i % BUFF_SIZE_0;
    s_u0tx.ct++;
  } 
  else {
    s_u0tx.act = 1;		
    hw_send_uart0(c);  // LPC_UART0->THR = c;
    //USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
  }
  //NVIC_EnableIRQ(USART1_IRQn);
}
//--------------------------------


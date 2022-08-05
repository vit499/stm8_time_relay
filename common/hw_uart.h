
#ifndef  __HW_UART_H_
#define  __HW_UART_H_

void uart_init ();
void uart_tx_irq ();
void uart_rx_irq ();

#define hw_send_uart0(Data)      (UART1->DR = Data)
#define get_rx0()           (UART1->DR)

#endif  // __HW_UART_H_

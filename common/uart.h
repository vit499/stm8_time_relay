
#ifndef  __UART_H_
#define  __UART_H_

#include "hw_uart.h"

void uart_pc_init (uint32_t b);
void put0 (uint8_t c);
void LOGf (void const *buf, uint16_t i);
void put0k (uint8_t k, uint32_t c);
uint16_t get_u0_act();
void LOGh8 (uint8_t *b, uint32_t n);
void put0h (uint8_t k, uint32_t c);
void u0_puthex32(uint32_t i);
void u0_puthex16(uint16_t i);
void LOGk ( uint8_t const *cp, uint8_t f, uint32_t k1, uint32_t k2, uint32_t k3 );
void u0_puthex(uint8_t i);
void LOGh16 (uint16_t *b, uint32_t n);
void u0_putItoS (uint32_t c);
void phex8(uint8_t i);
void putd (uint8_t c);
void puttime (uint16_t t);
void LOGfa (void const *buf, uint16_t i, uint8_t a);
U8 Is_debug_pc ();
void phex16 (uint16_t i);
void put0h8 (uint8_t k, uint8_t c);
void put00 (uint32_t c);
void LOGh8a (uint8_t *b, uint32_t n, uint8_t a);
void put0h8_4 (uint8_t k, uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4);
void put0h16 (uint8_t k, uint16_t c);
void put0h8_2 (uint8_t k, uint8_t c, uint8_t c1);
void put0h16_2 (uint8_t k, uint16_t c, uint8_t c2);
void put0_uu (uint8_t c);
void put0_u (uint8_t c);
void LOG_uu (void const *buf, uint16_t i);
void put0k_uu (uint8_t k, uint32_t c);
void put_buf (U8 *buf, U8 c);
void put0k2 (uint8_t k, uint32_t c, uint32_t c2);
void put0k12 (uint8_t k, uint32_t c, uint8_t k2, uint32_t c2);
void put0kw (U8 a, U32 b);
void LOGh16k (uint8_t const *str, uint16_t *b, uint32_t n);
void LOGk1 (U8 const *buf, U32 k);
void LOGh81 (U8 *b, U32 n);
void LOG_tick (U8 const *cp, U32 k);
void put0s (uint32_t c);
void LOGh8a_uu (uint8_t *b, uint32_t n, uint8_t a);
void put0d (uint32_t c);
void LOGt (U8 const *cp, U32 k);

//#define hw_send_uart0(c)      ( USART1->DR = c )
//#define hw_tx0_complete()     (USART_GetFlagStatus(USART1, USART_FLAG_TXE) != RESET)
//#define hw_rx0_complete()     (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
//#define get_rx0()             (USART1->DR)

void purge_com ();

void wdr();

#define  PRDN      1
#define  PRK1      2
#define  PRK2      3
#define  PRK3      4
#define  PRDNHEX   6



#endif  // __UART_H_

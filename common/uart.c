
#include "config1.h"
#include "lib_common.h"



void read_uart_pc (uint8_t c);
void uart_rec_pc_init ();
void put_sd(U8 c);
U8 Is_dbg ();
void led_trbl_tog();
//-----------------------------------

/*

*/
void uart1_init () { 
  purge_com();
  uart_rec_pc_init();
  uart_pc_init(57600);
}
//--------------------------------------

/*

*/
void LOGf (void const *buf, uint16_t i) { 
  uint8_t const * cp = (uint8_t const *) buf;
  if(!i) { while(*cp) put0(*cp++); }
  else { while(i--) put0(*cp++); }
}
//---------------------------------------------------

/*
 only uart
*/
void LOGf_u (void const *buf, uint16_t i) { 
  uint8_t const * cp = (uint8_t const *) buf;
  if(!i) { while(*cp) put0_u(*cp++); }
  else { while(i--) put0_u(*cp++); }
}

//---------------------------------------------------

/*
 only uart and usb
*/
void LOG_uu (void const *buf, uint16_t i) { 
  uint8_t const * cp = (uint8_t const *) buf;
  if(!i) { while(*cp) put0_uu(*cp++); }
  else { while(i--) put0_uu(*cp++); }
}
//----------------------------------------------------

void u0_putItoS (uint32_t c)
{
  uint8_t buf[0x10];
  uint8_t len;
  len = IntToStr(buf, c);
  if(len) LOGf (buf, len);
}

void put0s (uint32_t c) {
  uint8_t buf[0x10];
  uint8_t len;
  len = IntToStr(buf, c);
  if(len) { put0(' '); LOGf (buf, len); }
}

void LOGk (uint8_t const *cp, uint8_t f, uint32_t k1, uint32_t k2, uint32_t k3) { 

  if(f == PRDN) { 
    put0(0xd);
    while(k1--) put0(*cp++);
  }
  if(f == PRK1) { 
    LOGf(cp, 0);
    u0_putItoS(k1);
  }  
  if(f == PRK2) { 
    LOGf(cp, 0);
    u0_putItoS(k1); put0(','); u0_putItoS(k2);
  } 
  if(f == PRK3) { 
    LOGf(cp, 0);
    u0_putItoS(k1); put0(','); u0_putItoS(k2); put0(','); u0_putItoS(k3);
  }
  if(f == 5) { 
    u0_puthex(k1);
  } 
  if(f == PRDNHEX) { 
    put0(0xd);
    while(k1--) u0_puthex(*cp++); 
  }   
 
}
//---------------------------------------------

void put0d (uint32_t c) { 
  uint8_t buf[0x10];
  uint8_t len;
  len = IntToStr(buf, c);
  if(len) LOGf (buf, len);
  // u0_puthex32(c);
}
//-------

void put0d_u (uint32_t c) { 
  uint8_t buf[0x10];
  uint8_t len;
  len = IntToStr(buf, c);
  if(len) LOGf_u (buf, len);
  // u0_puthex32(c);
}
//-------

void LOGk1 (U8 const *buf, U32 k) { 
  LOGf(buf, 0);
  put0d(k);
}
//------------------------------------------

void LOGk1_u (U8 const *buf, U32 k) { 
  LOGf_u(buf, 0);
  put0d_u(k);
}
//------------------------------------------

/*-------------------------------------------------------------------
 view: _0xFF
------------------------------------------------------------------*/
void u0_puthex(uint8_t i) {
  uint8_t c;
  put0(' '); put0('0'); put0('x');
  c = i >> 4;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
}
//-------------------------------------------------------------------

/*-------------------------------------------------------------------
 view: _FF
------------------------------------------------------------------*/
void phex8 (uint8_t i) {
  uint8_t c;
  put0(' '); 
  c = i >> 4;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
}

void phex8_u (uint8_t i) {
  uint8_t c;
  put0_u(' '); 
  c = i >> 4;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
}

void phex8_uu (uint8_t i) {
  uint8_t c;
  put0_uu(' '); 
  c = i >> 4;
  if(c > 9) put0_uu(c + 0x37);
  else put0_uu(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0_uu(c + 0x37);
  else put0_uu(c + 0x30);
}

/*
 _FFFF
*/
void phex16 (uint16_t i) {
  uint8_t c;
  put0(' '); 
  c = (i >> 12) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 8) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 4) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
}

//----------


void u0_puthex32(uint32_t i) {
  uint8_t c;
  put0(' '); put0('0'); put0('x');
  c = (i >> 28) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 24) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 20) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 16) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 12) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 8) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 4) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30); 
}
//----------

void u0_puthex32_u (uint32_t i) {
  uint8_t c;
  put0_u(' '); put0_u('0'); put0_u('x');
  c = (i >> 28) & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
  c = (i >> 24) & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
  c = (i >> 20) & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
  c = (i >> 16) & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
  c = (i >> 12) & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
  c = (i >> 8) & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
  c = (i >> 4) & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0_u(c + 0x37);
  else put0_u(c + 0x30); 
}
//----------

/*-------------------------------------------------------------------
 view: _0xFFFF
------------------------------------------------------------------*/
void u0_puthex16(uint16_t i) {
  uint8_t c;
  put0(' '); put0('0'); put0('x');
  c = (i >> 12) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 8) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 4) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30); 
}
//----------------------------------------------------------------------

/*-------------------------------------------------------------------
 view: _FFFF
------------------------------------------------------------------*/
void u0_puthex16_small(uint16_t i) {
  uint8_t c;
  put0(' '); 
  c = (i >> 12) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 8) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = (i >> 4) & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30);
  c = i & 0xf;
  if(c > 9) put0(c + 0x37);
  else put0(c + 0x30); 
}
//---------------------------------------------------------------------
void u0_print_32(uint32_t *cp, uint16_t i) {
  put0(0xd); 
  while(i--) u0_puthex32(*cp++);
}
//-------------------------------------
void u0_print_16(uint16_t *cp, uint16_t i) { 
  put0(0xd); 
  while(i--) { wdr(); u0_puthex16(*cp++); }
}
void u0_print_s (uint16_t *cp, uint16_t i) { 
  put0(0xd);
  while(i--) { wdr(); put0(' '); u0_putItoS(*cp++); }
}
//-----------------------------------------
uint32_t r_err;
//------------------------------------------

//uint8_t getk0() { 
//  uint8_t c = 0; 
//
//  r_err = 0;
//  while(!hw_rx0_complete()); 
//  c = get_rx0();
//  return(c);
//} 
//------------------------------------------------
/*uint32_t read_uart0(uint8_t *cp, uint32_t i) { 
  set_wait_boot();
  while(i) { 
    wdr(); 
    if(Is_rec_byte()) { 
      *cp++ = get_rec_byte();
      i--;
    } 
  }
 // while(i--) { wdr(); *cp++ = getk0(); if(r_err) return(0); } 
  return(1); 
}   */
//-----------------------------
void uart0_print_2s (uint8_t *cp1, uint8_t *cp2) { 
  put0(0xd); 
  while(*cp1) put0(*cp1++);
  put0('='); 
  while(*cp2) put0(*cp2++);
}
//-------------------------------------------------------------------
//=============================================================================

/*
void uart0_putchar_i(uint8_t i) {
  uint8_t temp1, temp2;  
  buffer_uart0_tx[iwu++] = i;
  nu++;
  if(nu == 0) nu = 0xff; 
  temp1 = nu;
  temp2 = iwu-temp1;
  iru = temp2;
  if(uart0_empty) {  
    uart0_empty = 0; 
    LPC_UART0->THR = buffer_uart0_tx[iru];
    nu--; temp1 = nu;
    temp2 = iwu-temp1; 
    iru = temp2;
  }   
}  */
//-------------------------------------------------------------------------


//-------------------------------------------------------------------------


void put00 (uint32_t c) { 
  put0(0xd); u0_putItoS(c);
}
//-----------------------------------------

void put0k (uint8_t k, uint32_t c) { 
  uint8_t buf[0x10];
  uint8_t len;
  put0(0xd); put0(k); put0('=');
  len = IntToStr(buf, c);
  if(len) LOGf (buf, len);
  // u0_puthex32(c);
}
//-------

void put0k_u (uint8_t k, uint32_t c) { 
  uint8_t buf[0x10];
  uint8_t len;
  put0_u(0xd); put0_u(k); put0_u('=');
  len = IntToStr(buf, c);
  if(len) LOGf_u (buf, len);
  // u0_puthex32(c);
}

void put0k_uu (uint8_t k, uint32_t c) { 
  uint8_t buf[0x10];
  uint8_t len;
  put0_uu(0xd); put0_uu(k); put0_uu('=');
  len = IntToStr(buf, c);
  if(len) LOG_uu (buf, len);
  // u0_puthex32(c);
}

void put0k2 (uint8_t k, uint32_t c, uint32_t c2) { 
  uint8_t buf[0x10];
  uint8_t len;
  put0(0xd); put0(k); put0('=');
  len = IntToStr(buf, c);
  if(len) LOGf (buf, len);
  put0(',');
  len = IntToStr(buf, c2);
  if(len) LOGf (buf, len);
  // u0_puthex32(c);
}
//-------

void put0h (uint8_t k, uint32_t c) { 
  put0(0xd); put0(k); put0('=');
  u0_puthex32(c);
}
//-----------------------------------------

void put0h_u (uint32_t c) { 
  put0_u(0xd); //put0_u(k); put0_u('=');
  u0_puthex32_u(c);
}
//-----------------------------------------

void put0h8 (uint8_t k, uint8_t c) { 
  put0(0xd); put0(k); put0('=');
  u0_puthex(c);
}

void put0h8_u (uint8_t k, uint8_t c) { 
  put0_u(0xd); put0_u(k); put0_u('=');
  phex8_u(c);
}

void put0h8_2 (uint8_t k, uint8_t c1, uint8_t c2) { 
  put0(0xd); put0(k); put0('=');
  phex8(c1);
  phex8(c2);
}

void put0h16 (uint8_t k, uint16_t c) { 
  put0(0xd); put0(k); put0('=');
  u0_puthex16(c);
}

void put0h16_2 (uint8_t k, uint16_t c, uint8_t c2) { 
  put0(0xd); put0(k); put0('=');
  u0_puthex16(c);
  phex8(c2);
}
//-----------------------------------------

/*

*/
void puttime (uint16_t t) { 
  put0(0xd);
  put0('t'); put0('='); put0d(t >> 8); put0(':'); put0d(t & 0xff);
}
//-----------------------------------------

void put0h8_4 (uint8_t k, uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4) { 
  put0(0xd); put0(k); put0('=');
  phex8(c1); phex8(c2); phex8(c3); phex8(c4);
}
//-----------------------------------------

/*-------------------------------------------------------------------
 view: <CR> 0xFF 0xFF 0xFF ....
------------------------------------------------------------------*/
void LOGh (uint8_t *b, uint32_t n) { 
  put0(0xd);
  while(n--) u0_puthex(*b++);
}
//-------------------------------------------

/*
 view: <CR> FF FF FF ....
*/
void LOGh8 (U8 *b, U32 n) { 
  put0(0xd); 
  while(n--) phex8(*b++);
}
//-------------------------------------------

void LOGh8_uu (U8 *b, U32 n) { 
  put0_uu(0xd); 
  while(n--) phex8_uu(*b++);
}
//-------------------------------------------

void LOGh81 (U8 *b, U32 n) { 
  while(n--) phex8(*b++);
}
//-------------------------------------------

void LOGh8a (uint8_t *b, uint32_t n, uint8_t a) { 
  put0(0xd);  put0(a); put0(':');
  while(n--) phex8(*b++);
}
//-------------------------------------------

void LOGh8a_uu (uint8_t *b, uint32_t n, uint8_t a) { 
  put0_uu(0xd);  put0_uu(a); put0_uu(':');
  while(n--) phex8_uu(*b++);
}
//-------------------------------------------

/*

*/
void LOGfa (void const *buf, uint16_t i, uint8_t a) { 
  uint8_t const * cp = (uint8_t const *) buf;
  put0_uu(0xd);  put0_uu(a); put0_uu(':');
  if(!i) { while(*cp) put0_uu(*cp++); }
  else { while(i--) put0_uu(*cp++); }
}

/*-------------------------------------------------------------------
 view: <CR> FFFF FFFF FFFF ....
------------------------------------------------------------------*/
void LOGh16 (uint16_t *b, uint32_t n) { 
  put0(0xd);
  while(n--) u0_puthex16_small(*b++);
}
//------------------------------------------------------------------

/*-------------------------------------------------------------------
 view: str FFFF FFFF FFFF ....
------------------------------------------------------------------*/
void LOGh16k (uint8_t const *str, uint16_t *b, uint32_t n) { 
  put0(0xd);
  LOGf (str, 0);
  while(n--) u0_puthex16_small(*b++);
}

/*-------------------------------------------------------------------
 view: str FFFF FFFF FFFF ....
------------------------------------------------------------------*/
void LOGh8k (uint8_t const *str, uint8_t *b, uint32_t n) { 
  put0(0xd);
  LOGf (str, 0);
  while(n--) phex8(*b++);
}
//------------------------------------------------------------------
void put_usb (U8 c);


#if (F_USB == 1)
/*
#define DUAL_DIAG  0

void putd (uint8_t c)
{
  put_usb(c);
}


void LOGd (uint8_t const *buf, uint32_t i)
{
  if(!i) { while(*buf) putd(*buf++); }
  else { while(i--) putd(*buf++); }  
}


void LOGdm (uint8_t m, uint8_t const *buf, uint32_t i)
{
  putd(0xd); putd('m'); putd(m+'1'); putd(':'); putd(' ');
  if(!i) { while(*buf) putd(*buf++); }
  else { while(i--) putd(*buf++); }  
}


void putd_hex_small(uint8_t i) 
{
  uint8_t c;
  putd(' '); 
  c = i >> 4;
  if(c > 9) putd(c + 0x37);
  else putd(c + 0x30);
  c = i & 0xf;
  if(c > 9) putd(c + 0x37);
  else putd(c + 0x30);
}


void LOGdh8 (uint8_t const *b, uint32_t n) 
{ 
  putd(0xd);
  while(n--) putd_hex_small(*b++);
}


void putId(uint32_t i) {
  uint8_t buf[0x10];
  uint8_t len;
  len = IntToStr(buf, i);
  if(len) LOGd (buf, len);
}


void LOGdmk ( uint8_t m, uint8_t const *cp, uint8_t f, uint32_t k1, uint32_t k2, uint32_t k3 )
{ 
  if(m < 2) { 
    putd(0xd); putd('m'); putd(m+'1'); putd(':'); putd(' ');
  }
  if(f == PRDN) { 
    putd(0xd);
    while(k1--) putd(*cp++);
  }
  if(f == PRK1) { 
    LOGd(cp, 0);
    putId(k1);
  }  
  if(f == PRK2) { 
    LOGd(cp, 0);
    putId(k1); putd(','); putId(k2);
  } 
  if(f == PRK3) { 
    LOGd(cp, 0);
    putId(k1); putd(','); putId(k2); putd(','); putId(k3);
  }
  if(f == 5) { 
    u0_puthex(k1);
  } 
  if(f == PRDNHEX) { 
    putd(0xd);
    while(k1--) u0_puthex(*cp++); 
  } 
 
}

void putdk (uint8_t k, uint8_t c) { 
  putd(0xd);
  putd(k);
  putd(':');
  putd(' ');
  putId(c);
}

*/
#endif  // (F_USB == 1)


void put_buf (U8 *buf, U8 c) { 
  U8 i;
  put0(0xd); put0(c); put0(' ');
  for(i = 0; i < 8; i++) { 
    if(buf[i] == 0) break;
    phex8(buf[i]);
  }
}
//-----------------------------

void put0k12 (uint8_t k, uint32_t c, uint8_t k2, uint32_t c2) { 
  uint8_t buf[0x10];
  uint8_t len;
  put0(0xd); put0(k); put0('=');
  len = IntToStr(buf, c);
  if(len) LOGf (buf, len); 
  put0(' '); put0(k2); put0('=');
  len = IntToStr(buf, c2);
  if(len) LOGf (buf, len); 
}
void put0k22 (uint8_t k, uint32_t c, uint32_t c1, uint8_t k2, uint32_t c2, uint32_t c3) { 
  uint8_t buf[0x10];
  uint8_t len;
  put0(0xd); put0(k); put0('=');
  len = IntToStr(buf, c);
  if(len) LOGf (buf, len); put0(',');
  len = IntToStr(buf, c1);
  if(len) LOGf (buf, len);
  put0(' '); put0(k2); put0('=');
  len = IntToStr(buf, c2);
  if(len) LOGf (buf, len); put0(',');
  len = IntToStr(buf, c3);
  if(len) LOGf (buf, len);
}
//-------------------------------------

void put0kw (U8 a, U32 b) { 
  put0k_u(a, b); 
  while(get_u0_act());
  //delay_us(1000);
}
//-------------------------------------

void LOGt (U8 const *cp, U32 k) { 
  put0(0xd);
  LOGf(cp, 0);
  put0(':');
  put0(' ');
  put0d(k);
}
//-------------------------------------









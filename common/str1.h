
#ifndef __STR1_H_
#define __STR1_H_

#include "str2.h"

U8 strncmp1(U8  *cp1, U8   const *cp2, U16 i);
U8 strncmp2(U8  *cp1, U8  const *cp2, U8 i);
//U8 strncmp3(U8  *cp1, U8  *cp2, U8 i);
void strcpy1(U8  *cp1, U8 const  *cp2);
void strcpy2(U8  *cp1, U8  *cp2);
//void strcpy1(U8 *cp1,U8 *cp2,U8 *a1,U8 i);
U8 srhch(U8  *cp,U8 *a1,U8 a2,U8 i);
void clearbuf(U8  *cp,U8 i);
void strgps(U8  *cp1, U8   *cp2);
U8 length1(U8 const *cp);
void strncpy1(U8  *cp1, U8 const *cp2, U16 i);
U8 strcmp1(U8  *cp1, U8  *cp2);
void strncpyc(U8  *cp1, U8 const  *cp2, U8 i);
//void clr_buffer(U8 *cp, U16 i) ;
void hex2char2(U8 *cp, U8 c);
void strncpy2(U8  *cp1, U8  *cp2, U8 i);
U8 length2(U8  *cp);
//U16 strcpy3( U8 *dst, U8 const *src );
void strncpy16(U16  *cp1, U16  *cp2, U8 i);
U16 strcpy_( U8 *dst, const U8 *src );
void strncpy_ram (U8 *dst, U8 const *src, U16 len);
U8 strcpyc7(char *cp1, char const *cp2);
U8 bcd2char_rr(U8 i);
U32 HexStr (U8 *dst, U8 const *src, U16 len_src);
U8 length_text_0d0a20 (U8 *cp);
//U16 strncpy3( U8 *dst, const U8 *src, U16 n );
uint16_t length_max(uint8_t const *cp, uint16_t max);
uint8_t search_byte(uint8_t  *buf, uint16_t *ind, uint8_t byte, uint8_t num, uint16_t max);

U8 char2bcd(U8 c); 
U8 int2abcd(U8 i);


U8 bcd2char1(U8 i);

U8 bcd2char0(U8 i);
U8 ch2bcd(U8 *cp);
void bcd2ch(U8 *cp, U8 i);
//U8 strncmp3(U8  *cp1, U8  *cp2, U8 i);
U8 hex2bcd(U8 i);
void hex2char3(U8 *cp, U8 c);
void hex2dec2(U8 *cp, U8 c) ;

U8 chartobcd(U8 c);

U8 length_text_k(U8  *cp);
U8 length_text_0d(U8  *cp);
uint16_t length_text_k_ussd (uint8_t *cp, uint16_t max);
U8 length_text_0d0a(U8 *cp); 

U8 Int2Str (U8 *cp, U32 i);
U16 Str2Int_len (U8 *cp, U8 len);
U8 Str22Int (U8 *cp);
U32 Str2Int (U8 *cp);
U8 Is_dec_symbol (U8 c);

#define MAX_LENGTH_TEXT   100
#define MAX_LENGTH_STR    200

U8 get_length_cr(U8 *cp) ;
U8 strncmp5(U8 *cp1, U8 *cp2);

U8 length_text_symbol(U8 *cp, U8 symbol, U8 number);
U16 char2int(U8 *cp);

U8 strcpyc6(U8 *cp1, U8  const  *cp2);

U8 packet_tel(U8 *cp1, U8 *cp2);
U8 search_symbol(U8  *cp, U8 *ind, U8 symbol, U8 num);
U8 IntToStr(U8 *cp, U32 i) ;
uint8_t Is_digit_symbol (uint8_t c);
uint8_t uint8val (uint8_t c);

uint16_t strcpy3 (void *dst, void const *src);
uint16_t strncpy3 (void *dst, void const *src, uint16_t len);
void clr_buffer (void *buf, uint16_t n);

void fill_buffer_strelec (U8 *dst, U8 hundred_strelec);
uint8_t dec01_to_str (uint8_t *dst, uint16_t src);
uint8_t dec02_to_str (uint8_t *dst, uint16_t src);

#endif  // __STR1_H_









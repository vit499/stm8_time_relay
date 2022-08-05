
#include "config1.h"
#include "str1.h"

U8 strncmp1(U8  *cp1, U8 const  *cp2, U16 i){
  while(i--) if(*cp1++ != *cp2++) return(1);
  return(0);
}

U8 strcmp1(U8  *cp1, U8  *cp2){
  while(*cp1){
    if( *cp1++ != *cp2++ ) return(1);
  }
  if(*cp2 != 0xd) return(1);
  return(0);	
}

/**

*/
void strncpy_ram (U8 *dst, U8 const *src, U16 len)
{
  while(len--) *dst++ = *src++;
}

/*
 compare without different case
*/
U8 strncmp2(U8  *cp1, U8 const  *cp2, U8 i){
  U8 c1, c2;
  while(i--) { 
    c1 = *cp1++; c2 = *cp2++;
    if( (c1 != c2) && (c1+0x20 != c2) && (c1 != c2+0x20) ) return(1);
  }
  return(0);	
}    
/*void clr_buffer(U8 *cp, U16 i) { 
  while(i--) *cp++ = 0;
} */

/*
return number of bytes without null of the end
*/ 
/*U16 strcpy3( U8 *dst, const U8 *src ) { 
  U16 len = 0;
  while(*src) { *dst++ = *src++; len++; }
  return(len); 
}

U16 strncpy3( U8 *dst, const U8 *src, U16 n ) { 
  U16 len = 0;
  while(n--) { *dst++ = *src++; len++; }
  return(len); 
} */



/*
replace symbol '(' -> '_'
*/
U16 strcpy_( U8 *dst, const U8 *src ) { 
  U16 len = 0;
  U8 c;
  while(*src) { 
    c = *src++; 
    if(c == '(') c = '_';
    *dst++ = c; 
    len++; 
  }
  return(len); 
}
//-------------------------------------------------------------------------
void strcpy1(U8  *cp1, U8 const  *cp2){
  U8 c;
  do{
    c = *cp2++;
    *cp1++ = c;
  } while (c != 0);  
}  
//------------------------------------------------------------------------
void strcpy2(U8  *cp1, U8  *cp2){
  U8 c;
  do{
    c = *cp2++;
    *cp1++ = c;
  } while (c != 0);
}  
//--------------------------------------------
void strncpyc(U8  *cp1, U8 const  *cp2, U8 i) {
  while(i--) { *cp1++ = *cp2++; }
}
//---------------------------------------------
void strncpy1(U8  *cp1, U8 const *cp2, U16 i) {
  while(i--) *cp1++ = *cp2++;
}  
void strncpy2(U8  *cp1, U8  *cp2, U8 i){
  while(i--) *cp1++ = *cp2++;
}
void strncpy16(U16  *cp1, U16  *cp2, U8 i){
  while(i--) *cp1++ = *cp2++;
}

/*
void strcpy1(U8 *cp1,U8 *cp2,U8 *a1,U8 i){
	*a1 = 0;
	while (*cp2 != i){
		*cp1++ = *cp2++;
		*a1 += 1;
	}
}  */ 

U8 srhch(U8  *cp, U8 *a1, U8 a2, U8 i){
	*a1 = 1;
z01:
	if(*cp == a2) if(!(--i)) return(1);
	*a1 += 1;
	if(*a1 > 120) return(0);
	cp++;
	goto z01;
}
//------------------------------------------------------------------------
void clearbuf(U8  *cp, U8 i){
	 while(i--) *cp++ = 0;
}

void strgps(U8  *cp1, U8   *cp2){
  U8 c, a1=0;
	 do {
m1:
    c = *cp2++;
		  if(c == ','){
			   *cp1++ = '%';*cp1++ = '2';*cp1++ = 'C'; a1 += 3; goto m1;
		  }
   	if(c == '='){
			   *cp1++ = '%';*cp1++ = '3';*cp1++ = 'D'; a1 += 3; goto m1;
		  }
		  if(c == ' '){
			   *cp1++ = '+'; a1 += 1; goto m1;
		  }
		  if(c == '$'){
			   *cp1++ = '%';*cp1++ = '2';*cp1++ = '4'; a1 += 3; goto m1;
		  }
    if(c == 0x0d){
			   *cp1++ = '%';*cp1++ = '0';*cp1++ = 'D'; a1 += 3; goto m1;
		  }
		  if(c == 0x0a){
			   *cp1++ = '%';*cp1++ = '0';*cp1++ = 'A'; a1 += 3; goto m1;
		  }
		  *cp1++ = c; a1++;
	 } while ( c && (a1 < 100) );	
}

U8 length1(U8 const *cp) {
  U8 len = 0;
  while (*cp++) { 
    len++;
    if(len > MAX_LENGTH_STR) return(MAX_LENGTH_STR); 
  }
  return(len); 
}
//-----------------------------------------------------------
U8 length2(U8  *cp) {
  U8 len = 0;
  while (*cp++) { 
    len++;
    if(len > MAX_LENGTH_STR) return(MAX_LENGTH_STR); 
  }
  return(len); 
}
//------------------------------------------------------------
uint16_t length3 (uint8_t const *cp) {
  uint16_t len = 0;

  while(*cp++) { 
    len++;
    if(len > 0x500) return(0x500); 
  }
  return(len); 
}
//------------------------------------------
U8 length_text_0d0a(U8 *cp) {
  U8 len = 0; U8 c;
  while (1) { 
    c = *cp++;
    if((c == 0) || (c == 0xd) || (c == 0xa)) break;
    len++;
    if(len > MAX_LENGTH_STR) return(MAX_LENGTH_STR); 
  }
  return(len); 
}

U8 length_text_0d0a20 (U8 *cp) {
  U8 len = 0; U8 c;
  while (1) { 
    c = *cp++;
    if((c == 0) || (c == 0xd) || (c == 0xa) || (c == ' ')) break;
    len++;
    if(len > MAX_LENGTH_STR) return(MAX_LENGTH_STR); 
  }
  return(len); 
}
//--------------------------------------------------
U8 length_f(U8  const  *cp) {
  U8 len = 0;
  while (*cp++) { 
    len++;
    if(len > MAX_LENGTH_STR) return(MAX_LENGTH_STR); 
  }
  return(len); 
}
//------------------------------------------------
U8 length_text_k(U8  *cp){
  U8 len = 0;
  while (*cp != '"') { 
    len++; cp++;
    if(len > MAX_LENGTH_TEXT) return(MAX_LENGTH_TEXT); 
  }
  *cp = 0;
  return(len); 
}
//----------------------
U8 length_text_symbol(U8 *cp, U8 symbol, U8 number) {
  U8 len = 0;
A:
  while (*cp != symbol) { 
    len++; cp++;
    if(len > MAX_LENGTH_TEXT) return(0); 
  }
  if(--number) { len++; cp++; goto A; }
  return(len); 
}
//------------------------------------------

uint16_t length_text_k_ussd (uint8_t *cp, uint16_t max) {
  uint8_t c;
  uint16_t len = 0;

  c = *cp;
  if(*cp == '"') goto RET;
  cp++;
  while(1) { 
    if( (*cp == '"') && (c != 0x04) ) { cp++; len++; goto RET; } 
    c = *cp;
    cp++; len++; 
    if(len >= max) { goto RET; }
  }
RET:
  *cp = 0;
  return(len); 
}
//------------------------------------------

U8 length_text_0d(U8  *cp){
  U8 len = 0;
  while (*cp != 0xd) { 
    len++; cp++;
    if(len > MAX_LENGTH_TEXT) return(MAX_LENGTH_TEXT); 
  }
  *cp = 0;
  return(len); 
}
//----------------------------------------
U8 int2abcd(U8 i) { 
  U8 c;
  if(i > 9) c = i + 0x37;
  else c = i + 0x30;
  return(c);
}
//-----------------------------------------
U8 char2bcd(U8 c){
  U8 i;
  if( (c < '0') || (c > 'F') ) return(0);
  if( (c > '9') && (c < 'A') ) return(0);
  if(c < 0x3a) i = c - 0x30;
  else i = c - 0x37;
  return(i);
}
U8 bcd2char1(U8 i){
  U8 c;
  i >>= 4;
  if(i > 9) c = i + 0x37;
  else c = i + 0x30;
  return(c);
}
U8 bcd2char0(U8 i){
  U8 c;
  i &= 0xf;
  if(i > 9) c = i + 0x37;
  else c = i + 0x30;
  return(c);
}
//-------------------------------------------
U8 char2hex(U8 *cp){
  U8 i;
  if(*cp == ',') { i = 0xa; goto z01; } 
  if(*cp == '.') { i = 0xb; goto z01; }
  if(*cp < 0x3a) i = *cp - 0x30;
  else i = *cp - 0x37;
z01:
  cp++; i <<= 4;
  if(*cp == ',') { i += 0xa; goto z02; }
  if(*cp == '.') { i += 0xb; goto z02; }
  if(*cp < 0x3a) i += *cp - 0x30;
  else i += *cp - 0x37;
z02:
  return(i);
}
//-----------------------------------------------

/**
 @brief convert str of 2 symbols to unsigned char
*/
U8 Str22Int(U8 *cp){
  U8 i;
  i = (cp[0] - 0x30) * 10 + (cp[1] - 0x30);
  return(i);
}
//-------------------------------------------

/*
 src: 0x1, 0x2, 0x3, 0x4
 dst: 01 02 03 04
*/
U32 HexStr (U8 *dst, U8 const *src, U16 len_src) {
  U8 b, c;
  U32 len = 0;
  U16 i;

  for(i = 0; i < len_src; i++) { 
    b = src[i];
    c = b >> 4;
    if(c > 9) dst[len++] = c + 0x37;
    else dst[len++] = c + 0x30;
    c = b & 0x0f;
    if(c > 9) dst[len++] = c + 0x37;
    else dst[len++] = c + 0x30;
    dst[len++] = ' ';
  }
  return(len);
}
//-----------------------------------------
U8 hex2bcd(U8 i){
  U8 r = 0;
  while (i > 9) {
    i -= 10;
    r++;
  }
  r = (r << 4) + i;
  return(r);  
}
//-------------------------------------

/*

*/
void hex2char3(U8 *cp, U8 c) {
  U8 dec = 0, hundred = 0;
  while(c > 9) {
    if(++dec > 9) { dec = 0; hundred++; } 
    c -= 10;
  }
  if(hundred > 9) hundred = 0;
  if(dec > 9) dec = 0;
  *cp++ = 0x30 + hundred;
  *cp++ = 0x30 + dec;
  *cp   = 0x30 + c; 
}
//--------------------------------------
void hex2char2(U8 *cp, U8 c) {
  U8 dec = 0;
  while(c > 9) {
    dec++; // if(++dec > 9) { dec = 0; hundred++; } 
    c -= 10;
  }
  if(dec > 9) dec = 0;
  *cp++ = 0x30 + dec;
  *cp   = 0x30 + c; 
}
//-------------------------------------
void hex2dec2(U8 *cp, U8 c) {
  U8 dec = 0, hundred = 0;
  while(c > 9) {
    if(++dec > 9) { dec = 0; hundred++; } 
    c -= 10;
  }
  *cp = hundred;
  *(cp+1) = (dec << 4) + c;
}
//-------------------------------------
/*------------------------------
извлечение только цифры
------------------------------*/
U8 chartobcd(U8 c){
  if((c < '0') || (c > '9')) c = 0xff;
  else c = c - 0x30;
  return(c);
}
//-------------------------

//-----------------------------------------------------
U8 get_length_cr(U8 *cp) { 
  U8 len = 0, c; c = *cp++;
  while( (c != 0xd) && (c != 0) ) 
  { 
    len++; c = *cp++;
    if(len > 7) return(0);
  }
  return(len);
}
//-----------------------------------------------
U8 strncmp5(U8 *cp1, U8 *cp2) {
  U8 len1, len2;
  len1 = get_length_cr(cp1); 
  len2 = get_length_cr(cp2);
  if(!len1 || !len2) return(0xff); 
  while(len1--) if(*cp1++ != *cp2++) return(0xff);
  return(0);
}
//-----------------------------------------------------------
U16 char2int(U8 *cp) { 
  U16 n;
  n = char2bcd(cp[0]); n <<= 4;
  n = n + char2bcd(cp[1]); n <<= 4;
  n = n + char2bcd(cp[2]); n <<= 4;
  n = n + char2bcd(cp[3]);
  return(n);
}
//-----------------------------------------------------------
U8 strcpyc6(U8 *cp1, U8  const  *cp2) { 
  U8 len = length_f(cp2);
  strncpyc(cp1, cp2, len);
  return(len);
}

/*

*/
U8 strcpyc7(char *cp1, char const *cp2) { 
  U8 i;
  U8 len = length_f((U8*)cp2);
  for(i = 0; i < len; i++) { 
    cp1[i] = cp2[i];
  } 
  cp1[len] = 0;
  return(len);
}
//--------------------------------------------------

//---------------------------------
U8 packet_tel(U8 *dst, U8 *src){
  U8 c;
  U8 i, j;
  U8 tempbuf[0x10];

  for(i = 0; i < 8; i++) dst[i] = 0;   
  
  c = src[0];
  if( (c < 0x10) || (c > 0x39) || (c== '"') ) return(0);
  c = src[1];
  if( (c < 0x10) || (c > 0x39) || (c== '"') ) return(0);
  
  if(src[0] == '7') {                  //   "790..." -> "+790..."
    tempbuf[0] = '+'; 
    for(i = 0; i < 15; i++) tempbuf[i+1] = src[i]; 
  }
  else if(src[0] == '8') {                  //  "890..." -> "+790..."
    tempbuf[0] = '+'; 
    tempbuf[1] = '7'; 
    for(i = 1; i < 15; i++) tempbuf[i+1] = src[i]; 
  }
  else { 
    for(i = 0; i < 16; i++) tempbuf[i] = src[i];
  }
//C:
  i = 0; j = 0;
  while(1) { 
    c = tempbuf[j];
    if( (c < 0x10) || (c > 0x39) || (c== '"'))   {  c = 0xb; goto A; }
    if(c == '+') { c = 0xa; goto A;  } 
    if(c == '*') { c = 0xe; goto A;  }
    if(c == '#') { c = 0xd; goto A;  } 
    c -= 0x30;  
A:    
    dst[i] = c << 4; if(c == 0xb) break; 
    j++;
    c = tempbuf[j];
    if( (c < 0x10) || (c > 0x39) || (c== '"'))   {  c = 0xb; goto B; }
    if(c == '+') { c = 0xa; goto B;  } 
    if(c == '*') { c = 0xe; goto B;  }
    if(c == '#') { c = 0xd; goto B;  } 
    c -= 0x30;
B:
    dst[i] = dst[i] + c; if(c == 0xb) break;
    j++; i++;
    if(i > 8) return(0);          
  }
  return(1);
}
//-----------------------------------------------
U8 search_symbol(U8  *cp, U8 *ind, U8 symbol, U8 num){
	 *ind = 1;
  while(1) {
    if(*cp == 0) return(0); 
	   if(*cp == symbol) if(!(--num)) return(1);
	   *ind += 1;
	   if(*ind > 240) return(0);
 	  cp++;
  } 
}

/*-----------------------------------------------------------------------
  U8 IntToStr(U8 *cp, U32 i)
  i -  integer value
  cp - return string
  return - number symbols (length string)
------------------------------------------------------------------------*/
U8 IntToStr(U8 *cp, U32 i) {  
  uint8_t c = 0, b = 0, len = 0;
  while (i > 999999999) {
    i -= 1000000000;
    c++; b = 1;
  }
  if(b) cp[len++] = 0x30+c; // putch(0x30 + c);
  c = 0;
  while (i > 99999999) {
    i -= 100000000;
    c++; b = 1;
  }
  if(b) cp[len++] = 0x30+c; // putch(0x30 + c);
  c = 0;
  while (i > 9999999) {
    i -= 10000000;
    c++; b = 1;
  }
  if(b) cp[len++] = 0x30+c; // putch(0x30 + c);
  c = 0;
  while (i > 999999) {
    i -= 1000000;
    c++; b = 1;
  }
  if(b) cp[len++] = 0x30+c; // putch(0x30 + c);
  c = 0;  
  while (i > 99999) {
    i -= 100000;
    c++; b = 1;
  }
  if(b) { cp[len++] = 0x30+c; }   // putch(0x30 + c);
  c = 0;  
  while (i > 9999) {
    i -= 10000;
    c++; b = 1;
  }
  if(b) { cp[len++] = 0x30+c; }   // putch1(0x30 + c);
  c = 0;
  while (i > 999) {
    i -= 1000;
    c++; b = 1;
  }
  if(b) { cp[len++] = 0x30+c; }   // putch1 (0x30 + c);
  c = 0;
  while (i > 99) {
    i -= 100;
    c++; b = 1;
  }
  if(b) { cp[len++] = 0x30+c; }   // putch1 (0x30 + c);
  c = 0;
  while (i > 9) {
    i -= 10;
    c++; b = 1;
  }
  if(b) { cp[len++] = 0x30+c; }   // putch1 (0x30 + c);
  cp[len++] = 0x30+i;    // putch1 (0x30 + i);
  return(len);
}
//-----------------------------------------------
/*U8 char2bcd1(U8  *cp){
  U8 i; //ferr = 0;
  if((*cp < 0x30) || (*cp > 0x46) || ((*cp > 0x39) && (*cp < 0x41))) ferr = 1;
  if(*cp < 0x3a) i = (*cp - 0x30) << 4;
  else i = (*cp - 0x37) << 4;
  cp++;
  if((*cp < 0x30) || (*cp > 0x46) || ((*cp > 0x39) && (*cp < 0x41))) ferr = 1;
  if(*cp < 0x3a) i += (*cp - 0x30);
  else i += (*cp - 0x37);
  return(i);
}  */

/*

*/
U8 Is_dec_symbol (U8 c) {
  if((c < '0') || (c > '9')) return(0xff);
  else return(c - 0x30);
}

uint8_t Is_digit_symbol (uint8_t c) {
  if((c < '0') || (c > '9')) return(0);
  else return(1);
}

uint8_t uint8val (uint8_t c) { 
  return(c - 0x30);
}
//-------------------------------------

/*

*/
U16 Str2Int_len (U8 *buf, U8 len){
  U16 n = 0; 
  U8 c;
  U8 i;

  for(i = 0; i < len; i++) { 
    c = Is_dec_symbol(buf[i]);
    if(c == 0xff) goto ER1;
    n += c;
    if((i + 1) < len) n = n * 10;
  } 
  return(n);
ER1:
  return(0); 
}


/*
 num - number of repeats byte
*/
uint8_t search_byte(uint8_t  *buf, uint16_t *ind, uint8_t byte, uint8_t num, uint16_t max) {
  uint16_t pos;
  uint8_t n = 0;
  uint8_t res = 0;

  for(pos = 0; pos < max; pos++) { 
    if(buf[pos] == 0) break;
    if(buf[pos] == byte) n++;
    if(n == num) { 
      *ind = pos+1; 
      res = 1; 
      break; 
    }
  }
  return(res);
}
//------------------------

/*

*/
uint16_t length_max(uint8_t const *cp, uint16_t max) {
  uint16_t len = 0;
  while (*cp++) { 
    len++;
    if(len > max) return(max); 
  }
  return(len); 
}
//--------------------------------------------------

void clr_buffer (void *buf, uint16_t n) { 
  uint8_t *b = (uint8_t*) buf;
  while(n--) *b++ = 0;
}
//--------------------------------------------------

/*
 src uint16_t:  0x0100 (256)
 dst string:    "+25.6"
 -3   -> -0.3
 2    -> +0.2
 22   -> +2.2
 0    -> 0.0
*/
//uint8_t dec01_to_str (uint8_t *dst, uint16_t src) { 
//  uint8_t buf[0x10];
//  uint8_t len_src = 0;
//  uint8_t len = 0;
//  uint8_t sign = 0;
//  
//  if(src & (1<<15)) { 
//    src ^= 0xffff;
//    src += 1;
//    sign = '-';
//  }
//  else { 
//    //sign = '+';
//  }
//    
//  len_src = IntToStr(buf, src);
//  if(len_src == 1) {                   // if buf= 3 -> buf= 03
//    buf[1] = buf[0];
//    buf[0] = '0';
//    len_src = 2;
//  }
//  if(sign) { 
//    dst[len++] = sign;
//  }
//  len += strncpy4(dst + len, buf, len_src-1);
//  dst[len++] = '.';
//  dst[len++] = buf[len_src-1];
//
//  return(len);
//}
//-------------------------------------------------

const U16 t1[] = { 256, 0, 0xffff, 0xfff0 };
 
//void debug_temp () { 
//  U8 i;
//  U8 buf[0x20];
//  U8 len;
//
//  for(i = 0; i < 4; i++) { 
//    len = dec01_to_str(buf, t1[i]); 
//    put0k('t', t1[i]); put0(' ');
//    LOGf(buf, len);
//  }
//}
//-----------------------------------------------

/*
 src uint16_t:  0x0100 (256)
 dst string:    "2.56"
*/
uint8_t dec02_to_str (uint8_t *dst, uint16_t src) { 
  uint8_t buf[0x10];
  uint8_t len=0;
  uint8_t i=0;

  len = IntToStr(buf, src);
  if(len == 1) { 
    dst[i++] = '0';
    if(buf[0] != '0') { 
      dst[i++] = '.';
      dst[i++] = '0';
      dst[i++] = buf[0];
    }
    return(i);
  }
  if(len < 3) dst[i++] = '0';
  else { 
    for(i = 0; i < (len-2); i++) { 
      dst[i] = buf[i];
    }
  }
  dst[i++] = '.';
  dst[i++] = buf[len-2];
  dst[i++] = buf[len-1];
  return(i);
}
//-------------------------------------------------

/*--------------------------------------------
для РРОП Стрелец 0-9 = 0-9, 10-14 = 11-15
----------------------------------------------*/
U8 bcd2char_rr(U8 i) {
  U8 c;
  i &= 0xf;
  if(i > 0xe) return(0);
  if(i > 9) c = i + 0x38;
  else c = i + 0x30;
  return(c);
}
//-------------------------------------------

void fill_buffer_strelec (U8 *dst, U8 hundred_strelec) { 
  U8 i;
  U8 sum = 0;

  dst[0x0a] = bcd2char_rr(hundred_strelec);
  for(i = 0; i < 13; i++ ) sum += dst[i];
  dst[13] = sum;
}
//-------------------------------------------------









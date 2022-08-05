
#include "config1.h"
#include "str1.h"
#include "str2.h"


/*
 
*/
U16 indexof1 (U8 *buf, U8 byte, U8 num, U16 max) { 
  uint16_t pos;
  uint8_t n = 0;
  uint8_t ind = 0;

  for(pos = 0; pos < max; pos++) { 
    if(buf[pos] == 0) break;
    if(buf[pos] == byte) n++;
    if(n == num) { 
      ind = pos+1; 
      break; 
    }
  }
  return(ind);
}
//-----------------------------------------------

/*

*/
U32 Str2Int (U8 *buf) {
  U32 value = 0; 
  U8 c;
  U8 i;
  U8 len = 20;

  if(buf[0] == ' ') { 
    buf++;   // ignore space in begin, ex: _25 -> 25
    if(buf[0] == ' ') buf++;
  }
  for(i = 0; i < len; i++) { 
    c = Is_dec_symbol(buf[i]);
    if(c == 0xff) break;
    value = value * 10 + c;
  } 
  return(value);
}
//----------------------------

/*
 src: "abcdefghijkl", st=2,  len=3
 dst: "cde"
*/
U16 substr1 (U8 *dst, U8 *src, U16 st, U16 len_src) { 
  U16 i;
  U16 len = 0;

  for(i = 0; i < len_src; i++) { 
    if(src[i+st] == 0) break;
    dst[len++] = src[i+st];
  }
  dst[len] = 0;
  return(len);
}
//------------------------------


/*

*/
uint16_t strncmp3 (void const *str1, void const *str2, uint16_t len) {
  uint16_t i;
  uint8_t const *s1;
  uint8_t const *s2;
                                            
  s1 = (uint8_t const *) str1;
  s2 = (uint8_t const *) str2;
                                            
                                            
  for(i = 0; i < len; i++) {                    
    if(s1[i] != s2[i]) return(i+1);
  }                                        
  return(0);	
}
//-------------------------------

/*

*/
uint16_t strcpy3 (void *dst, void const *src) { 
  uint16_t len = 0;
  uint8_t *d;
  uint8_t const *s;
 
  d = (uint8_t*) dst;
  s = (uint8_t const *) src;
  while(*s) { d[len++] = *s++; }
  return(len); 
} 
//----------------------------------------------------------

/*

*/
uint16_t strncpy3 (void *dst, void const *src, uint16_t len) { 
  uint16_t i;
  uint8_t *d;
  uint8_t const *s;

  d = (uint8_t*) dst;
  s = (uint8_t const*) src;
  for(i = 0; i < len; i++) { 
    if(s[i] == 0) break; 
    d[i] = s[i];
  }
  return(i);
}  
//--------------------------------

/*

*/
uint16_t strncpy4 (void *dst, void const *src, uint16_t len) { 
  uint16_t i;
  uint8_t *d;
  uint8_t const *s;

  d = (uint8_t*) dst;
  s = (uint8_t const*) src;
  for(i = 0; i < len; i++) { 
   // if(s[i] == 0) break; 
    d[i] = s[i];
  }
  return(i);
}  
//--------------------------------

/*

*/
uint16_t strncpy5 (void *dst, void const *src, uint16_t len) { 
  uint16_t i;
  uint8_t *d;
  uint8_t const *s;

  d = (uint8_t*) dst;
  s = (uint8_t const*) src;
  for(i = 0; i < len; i++) d[i] = 0;
  for(i = 0; i < len; i++) { 
    if(s[i] == 0) break; 
    d[i] = s[i];
  }
  return(i);
}  
//--------------------------------

/*
 src: &cmd1=val1&cmd2=val2 
 dst: cmd1=val1 
*/
uint16_t substr_cmd (void *dst, void const *src, uint16_t len_src) { 
  uint16_t i = 0;
  uint16_t len = 0;
  uint8_t *d;
  uint8_t const *s;
  uint8_t c;

  d = (uint8_t*) dst;
  s = (uint8_t const*) src;
  if(s[0] == '&') i = 1;
  for(; i < len_src; i++) { 
    c = s[i];
    if((c == '&') || (c == 0xd) || (c == 0xa) || (c == 0)) break;
    d[len++] = c;
  }
  d[len] = 0;
  return(len);
}
//--------------------------------

/*

*/
uint16_t strlen1 (void const *str) { 
  uint16_t len = 0;
  uint8_t const *s;
  
  s = (uint8_t const*) str;
  while(*s++) {  
    len++;
    //if(len > MAX_LENGTH_STR) return(MAX_LENGTH_STR);
  }
  return(len);
}
//--------------------------------

/*
 buf: "\r\n\r\nAAA"
 pos = 4
*/
U8 trim_0d (U8 *buf, U16 *pos, U16 len) { 
  U8 res = 0;
  U16 i;

  for(i = 0; i < len; i++) { 
    if(!Is_0d(buf[i])) { 
      res = 1; 
      break;
    }
    //if(c == 0) break;
  }
  *pos = i;
  return(res);
}
//-----------------------------------------------------

/*
 src: cm"d1=val1&cmd2"=val2, sym='"'
 dst: d1=val1&cmd2 
*/
uint16_t substr_sym (void *dst, void const *src, uint8_t sym, uint16_t len_src, uint16_t max_len_dst) { 
  uint16_t i = 0;
  uint16_t len = 0;
  uint8_t *d;
  uint8_t const *s;
  uint8_t c;

  d = (uint8_t*) dst;
  s = (uint8_t const*) src;               //put0(0xd); LOGf(s, 0);
  for(i = 0; i < len_src; i++) { 
    c = s[i];
    if(c == sym) { i++; break; }
  }

  for(; i < len_src; i++) { 
    c = s[i];
    if((c == sym) || (c == 0xd) || (c == 0xa) || (c == 0)) break;
    if(len >= max_len_dst) break;
    d[len++] = c;
  }
  d[len] = 0;                             //put0(0xd); LOGf(d, 0);
  return(len);
}
//--------------------------------


/*
 buf: "xxx\r\n\r\nAAA"
 pos = 4
*/
U8 trim_x0d (U8 *buf, U16 *pos, U16 len) { 
  U8 res = 0;
  U16 i;

  for(i = 0; i < len; i++) { 
    if(Is_0d(buf[i])) { 
      break;
    }
  }
  for(; i < len; i++) { 
    if(!Is_0d(buf[i])) { 
      res = 1; 
      break;
    }
  }
  *pos = i;
  return(res);
}
//-----------------------------------------------------

U8 str_trim_0d (U8 *buf, U16 *pos, U16 *len, U16 max) { 
  U16 a;
  U16 len_ost;

  len_ost = *len;
  if(!trim_0d(buf, &a, len_ost)) return(0);
  len_ost = len_ost - a;
  if(!len_ost || (len_ost > max)) return(0);
  *pos = a;
  *len = len_ost;
  return(1);
}
//----------------------------------------------------

U8 str_trim_x0d (U8 *buf, U16 *pos, U16 *len, U16 max) { 
  U16 a;
  U16 len_ost;

  len_ost = *len;
  if(!trim_x0d(buf, &a, len_ost)) return(0);
  len_ost = len_ost - a;
  if(!len_ost || (len_ost > max)) return(0);
  *pos = a;
  *len = len_ost;
  return(1);
}
//----------------------------------------------------










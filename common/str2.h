
#ifndef  __STR2_H_
#define  __STR2_H_


U16 indexof1 (U8 *buf, U8 byte, U8 num, U16 max);
U16 substr1 (U8 *dst, U8 *src, U16 st, U16 len_src);
uint16_t strncmp3 (void const *str1, void const *str2, uint16_t len);
uint16_t substr_cmd (void *dst, void const *src, uint16_t len_src);
uint16_t strlen1 (void const *str);
uint16_t strncpy4 (void *dst, void const *src, uint16_t len);
uint16_t strncpy5 (void *dst, void const *src, uint16_t len);
uint16_t substr_sym (void *dst, void const *src, uint8_t sym, uint16_t max_len_dst, uint16_t len_src);
U8 trim_0d (U8 *buf, U16 *pos, U16 len);
U8 trim_x0d (U8 *buf, U16 *pos, U16 len);

U8 str_trim_0d (U8 *buf, U16 *pos, U16 *len, U16 max);
U8 str_trim_x0d (U8 *buf, U16 *pos, U16 *len, U16 max);

#define Is_0d(c) ((c == 0xd) || (c == 0xa))

#endif  // __STR2_H_

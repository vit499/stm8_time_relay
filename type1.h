
#ifndef  __TYPE207_H_
#define  __TYPE207_H_

typedef  union {
 uint32_t dword;
 struct {
  uint8_t f0:1, f1:1, f2:1, f3:1;
  uint8_t f4:1, f5:1, f6:1, f7:1;
  uint8_t f8:1, f9:1, f10:1, f11:1;
  uint8_t f12:1, f13:1, f14:1, f15:1;
  uint8_t f16:1, f17:1, f18:1, f19:1;
  uint8_t f20:1, f21:1, f22:1, f23:1;
  uint8_t f24:1, f25:1, f26:1, f27:1;
  uint8_t f28:1, f29:1, f30:1, f31:1;
 } fbit;
}  U_flags;

#define bit0   (1<<0)
#define bit1   (1<<1)
#define bit2   (1<<2)
#define bit3   (1<<3)
#define bit4   (1<<4)
#define bit5   (1<<5)
#define bit6   (1<<6)
#define bit7   (1<<7)
#define bit8   (1<<8)
#define bit9   (1<<9)
#define bit10   (1<<10)
#define bit11   (1<<11)
#define bit12   (1<<12)
#define bit13   (1<<13)
#define bit14   (1<<14)
#define bit15   (1<<15)
#define bit16   (1<<16)
#define bit17   (1<<17)
#define bit18   (1<<18)
#define bit19   (1<<19)
#define bit20   (1<<20)
#define bit21   (1<<21)


#define log  const uint8_t
#define U8 uint8_t
#define U16 uint16_t
#define U32 uint32_t
//#define Up U32
#define NULL  0
#define Bool  uint8_t
#define FALSE  0
#define TRUE   1

#define BSRRH              BRR 
#define BSRRL              BSRR
#define GPIO_Mode_OUT      GPIO_Mode_Out_PP

#endif


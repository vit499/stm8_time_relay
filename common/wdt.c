
#include "config1.h"
#include "lib_common.h"


void wdt_init () { 
  IWDG->KR = 0xcc;
  IWDG->KR = 0x55;
  IWDG->PR = 0x06;
  wdr();
}
//-------------------------------

void wdr () { 
  IWDG->KR = 0x55;
  IWDG->KR = 0xaa;
}
//-------------------------------

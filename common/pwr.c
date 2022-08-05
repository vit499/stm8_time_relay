
#include "config1.h"
#include "lib_common.h"


void clk_init () { 
  CLK_LSICmd(ENABLE);
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_MANUAL, 
                         CLK_SOURCE_LSI, 
                         DISABLE, 
                         CLK_CURRENTCLOCKSTATE_DISABLE);

 // CLK->ICKR |= CLK_ICKR_LSIEN;


 // CLK->SWCR |= CLK_SWCR_SWEN;
 // CLK->SWR = CLK_SOURCE_LSI;
 // while((CLK->SWCR & CLK_SWCR_SWBSY) != 0 );

 // CLK->SWR = CLK_SOURCE_LSI;
  //while((CLK->SWCR & CLK_SWCR_SWIF) == 0 );
  //CLK->SWCR |= CLK_SWCR_SWEN;

  // while(1);

  //CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
}








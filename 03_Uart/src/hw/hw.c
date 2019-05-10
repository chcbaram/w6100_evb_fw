/*
 * hw.c
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */




#include "hw.h"





void hwInit(void)
{
  bspInit();


  millisInit();
  delayInit();
  swtimerInit();

  ledInit();
  buttonInit();
  uartInit();
}

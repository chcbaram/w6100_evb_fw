/*
 * millis.c
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */




#include "millis.h"



bool millisInit(void)
{
  return true;
}

uint32_t millis(void)
{
  return HAL_GetTick();
}

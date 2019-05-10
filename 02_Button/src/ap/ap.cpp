/*
 * ap.cpp
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */




#include "ap.h"





void apInit(void)
{

}

void apMain(void)
{
  uint32_t pre_time;


  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }

    if (buttonGetPressed(_DEF_BUTTON1) == true)
    {
      ledOn(_DEF_LED2);
    }
    else
    {
      ledOff(_DEF_LED2);
    }
    if (buttonGetPressed(_DEF_BUTTON2) == true)
    {
      ledOn(_DEF_LED3);
    }
    else
    {
      ledOff(_DEF_LED3);
    }

  }
}

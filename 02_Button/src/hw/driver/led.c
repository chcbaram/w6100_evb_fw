/*
 * led.c
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */




#include "led.h"



#ifdef _USE_HW_LED


typedef struct
{
  GPIO_TypeDef *port;
  uint16_t      pin;
  GPIO_PinState on_state;
  GPIO_PinState off_state;
} led_tbl_t;


led_tbl_t led_tbl[LED_MAX_CH] =
{
  {GPIOC, GPIO_PIN_6,  GPIO_PIN_RESET, GPIO_PIN_SET},
  {GPIOC, GPIO_PIN_8,  GPIO_PIN_RESET, GPIO_PIN_SET},
  {GPIOC, GPIO_PIN_9,  GPIO_PIN_RESET, GPIO_PIN_SET},
};


void ledInit(void)
{
  uint32_t i;
  GPIO_InitTypeDef GPIO_InitStruct;


  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  for (i=0; i<LED_MAX_CH; i++)
  {
    GPIO_InitStruct.Pin = led_tbl[i].pin;
    HAL_GPIO_Init(led_tbl[i].port, &GPIO_InitStruct);

    ledOff(i);
  }
}

void ledOn(uint8_t ch)
{
  if (ch < LED_MAX_CH)
  {
    HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
  }
}

void ledOff(uint8_t ch)
{
  if (ch < LED_MAX_CH)
  {
    HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
  }
}

void ledToggle(uint8_t ch)
{
  if (ch < LED_MAX_CH)
  {
    HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].pin);
  }
}

#endif
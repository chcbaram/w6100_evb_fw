/*
 * led.c
 *
 *  Created on: 2019. 6. 3.
 *      Author: Baram
 */


#include "led.h"





typedef struct
{
  GPIO_TypeDef* GPIOx;
  uint16_t      GPIO_Pin;
  GPIO_PinState on_state;
  GPIO_PinState off_state;
} led_tbl_t;


static led_tbl_t led_tbl[LED_MAX_CH] =
    {
        {GPIOC, GPIO_PIN_6, GPIO_PIN_RESET, GPIO_PIN_SET},
        {GPIOC, GPIO_PIN_8, GPIO_PIN_RESET, GPIO_PIN_SET},
        {GPIOC, GPIO_PIN_9, GPIO_PIN_RESET, GPIO_PIN_SET},
    };



void ledInit(void)
{
  for (int i=0; i<LED_MAX_CH; i++)
  {
    ledOff(i);
  }
}

void ledOn(uint8_t ch)
{
  HAL_GPIO_WritePin(led_tbl[ch].GPIOx, led_tbl[ch].GPIO_Pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
  HAL_GPIO_WritePin(led_tbl[ch].GPIOx, led_tbl[ch].GPIO_Pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
  HAL_GPIO_TogglePin(led_tbl[ch].GPIOx, led_tbl[ch].GPIO_Pin);
}

/*
 * led.h
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */

#ifndef SRC_HW_DRIVER_LED_H_
#define SRC_HW_DRIVER_LED_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"

#ifdef _USE_HW_LED

#define LED_MAX_CH       HW_LED_MAX_CH


void ledInit(void);
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);


#endif

#ifdef __cplusplus
}
#endif


#endif /* SRC_HW_DRIVER_LED_H_ */

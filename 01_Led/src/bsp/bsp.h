/*
 * bsp.h
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "def.h"
#include "stm32f1xx_hal.h"


void bspInit(void);


extern void delay(uint32_t ms);
extern uint32_t micros(void);
extern uint32_t millis(void);

#ifdef __cplusplus
}
#endif

#endif /* SRC_BSP_BSP_H_ */

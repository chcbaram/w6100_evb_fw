/*
 * delay.h
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */

#ifndef SRC_HW_DRIVER_DELAY_H_
#define SRC_HW_DRIVER_DELAY_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "hw_def.h"

#ifdef _USE_HW_DELAY


bool delayInit();

void delay(uint32_t ms);
void delayNs(uint32_t ns);
void delayUs(uint32_t us);
void delayMs(uint32_t ms);

#endif


#ifdef __cplusplus
}
#endif


#endif /* SRC_HW_DRIVER_DELAY_H_ */

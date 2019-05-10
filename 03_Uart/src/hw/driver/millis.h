/*
 * millis.h
 *
 *  Created on: 2019. 5. 10.
 *      Author: Baram
 */

#ifndef SRC_HW_DRIVER_MILLIS_H_
#define SRC_HW_DRIVER_MILLIS_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"

#ifdef _USE_HW_MILLIS


bool millisInit(void);
uint32_t millis(void);


#endif


#ifdef __cplusplus
}
#endif


#endif /* SRC_HW_DRIVER_MILLIS_H_ */

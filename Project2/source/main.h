/*
 * PES2019.h
 *
 *  Created on: Sep 28, 2019
 *      Author: SURAJ THITE , ATHARV DESAI
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_rtc.h"

#include "clock_config.h"
#include "pin_mux.h"
#include "RGBled.h"
int main();
void rtc_get();
void rtc_Init();

#endif /* MAIN_H_ */

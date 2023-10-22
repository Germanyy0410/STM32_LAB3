/*
 * led7SEG.h
 *
 *  Created on: 17 thg 10, 2023
 *      Author: ProX
 */

#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_

#include "global.h"

extern int led_1;
extern int led_2;
extern int stat_led_1;
extern int stat_led_2;
extern int switch_mode_1;
extern int switch_mode_2;

void display7SEG(int count_1, int count_2);
void countdownLED();
void update7SEG();

#endif /* INC_LED7SEG_H_ */

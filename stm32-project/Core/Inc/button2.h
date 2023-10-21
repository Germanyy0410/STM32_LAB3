/*
 * button2.h
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#ifndef INC_BUTTON2_H_
#define INC_BUTTON2_H_

#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int TimerModify[3];
extern int setTraffic[3];

void handleKeyInput2();
void subKeyProcess2();
int isButton2Pressed();
void getKeyInput2();

#endif /* INC_BUTTON2_H_ */

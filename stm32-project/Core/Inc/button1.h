/*
 * button1.h
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#ifndef INC_BUTTON1_H_
#define INC_BUTTON1_H_

#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int KeyReg1Counter;

void handleKeyInput1();
void subKeyProcess1();
int isButton1Pressed();
void getKeyInput1();

#endif /* INC_BUTTON1_H_ */

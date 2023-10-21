/*
 * button3.h
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#ifndef INC_BUTTON3_H_
#define INC_BUTTON3_H_

#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void handleKeyInput3();
void subKeyProcess3();
int isButton3Pressed();
void getKeyInput3();

#endif /* INC_BUTTON3_H_ */

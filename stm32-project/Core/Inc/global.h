/*
 * global.h
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button1.h"
#include "button2.h"
#include "button3.h"
#include "fsm.h"
#include "led7SEG.h"

#define redTimer        6000
#define greenTimer      3000
#define yellowTimer     2000

#define RED             0
#define YELLOW          1
#define GREEN           2
#define INIT            3
#define AUTO_RED        100
#define AUTO_YELLOW     200
#define AUTO_GREEN      300
#define MAN_RED         700
#define MAN_YELLOW      800
#define MAN_GREEN       900

#define MODIFY          10
#define AUTOMATIC       20
#define MANUAL          30
#define WAIT            40

extern int status1;
extern int status2;
extern int status3;

#endif /* INC_GLOBAL_H_ */

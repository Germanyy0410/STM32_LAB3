/*
 * fsm.h
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "global.h"

extern int timer1, timer2;

void Red_1_On();
void Yellow_1_On();
void Green_1_On();
void Red_2_On();
void Yellow_2_On();
void Green_2_On();

void trafficOff();

void fsm_run();
void fsm_run_1();
void fsm_run_2();

#endif /* INC_FSM_H_ */

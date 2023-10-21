/*
 * button2.c
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#include "button2.h"

int button2_flag = 0;

static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;

static int KeyReg3 = NORMAL_STATE;

static int TimerForKeyPress = 200;

int TimerModify[3] = { redTimer, yellowTimer, greenTimer };
int setTraffic[3] = { redTimer, yellowTimer, greenTimer };

void handleKeyInput2() {
    status1 = MODIFY;
    status2 = MODIFY;
    status3 = MODIFY;
    
    if (KeyReg1Counter == 2) {
        TimerModify[RED] += 1000;

        if (TimerModify[RED] > 9000) {
            TimerModify[RED] = 0;
        }
    } 

    else if (KeyReg1Counter == 3) {
        TimerModify[YELLOW] += 1000;

        if (TimerModify[YELLOW] > 9000) {
            TimerModify[YELLOW] = 0;
        }
    } 

    else if (KeyReg1Counter == 4) {
        TimerModify[GREEN] += 1000;

        if (TimerModify[GREEN] > 9000) {
            TimerModify[GREEN] = 0;
        }
    }
}

void subKeyProcess2() {
    button2_flag = 1;
}

int isButton2Pressed() {
    if (button2_flag) {
        button2_flag = 0;
        return 1;
    } 
    return 0;
}

void getKeyInput2() {
    KeyReg0 = KeyReg1;
    KeyReg1 = KeyReg2;
    KeyReg2 = HAL_GPIO_ReadPin(Button_2_GPIO_Port, Button_2_Pin);

    if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
        if (KeyReg3 != KeyReg2) {
            KeyReg3 = KeyReg2;

            if (KeyReg2 == PRESSED_STATE) {
                subKeyProcess2();
                TimerForKeyPress = 200;
            }
        } else {
            TimerForKeyPress--;
            if (TimerForKeyPress == 0) {
                if (KeyReg2 == PRESSED_STATE) {
                    subKeyProcess2();
                }
                
                TimerForKeyPress = 200;
            }
        }
    }
}
/*
 * button3.c
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#include "button3.h"

int button3_flag = 0;

static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;

static int KeyReg3 = NORMAL_STATE;

static int TimerForKeyPress = 200;

void handleKeyInput3() {
    if (KeyReg1Counter == 2) {
        setTraffic[RED] = TimerModify[RED];
        KeyReg1Counter = 1;

        if (setTraffic[RED] - setTraffic[YELLOW] - 1 > 0) {
            setTraffic[GREEN] = setTraffic[RED] - setTraffic[YELLOW] - 1;
            TimerModify[GREEN] = setTraffic[GREEN];
        } else {

        }
    }

    else if (KeyReg1Counter == 3) {
        setTraffic[YELLOW] = TimerModify[YELLOW];
        KeyReg1Counter = 1;

        if (setTraffic[YELLOW] + setTraffic[GREEN] + 1 <= 9) {
            setTraffic[RED] = setTraffic[YELLOW] + setTraffic[GREEN] + 1;
            TimerModify[RED] = setTraffic[RED];
        } else {

        }
    }

    else if (KeyReg1Counter == 4) {
        setTraffic[GREEN] = TimerModify[GREEN];
        KeyReg1Counter = 1;

        if (setTraffic[YELLOW] + setTraffic[GREEN] + 1 <= 9) {
            setTraffic[RED] = setTraffic[YELLOW] + setTraffic[GREEN] + 1;
            TimerModify[RED] = setTraffic[RED];
        } else {

        }
    }

    HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DOT1_GPIO_Port, DOT1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DOT2_GPIO_Port, DOT2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DOT3_GPIO_Port, DOT3_Pin, GPIO_PIN_RESET);

    status1 = INIT;
    status2 = INIT;
    status3 = AUTOMATIC;

    led_1 = setTraffic[RED] / 1000;
    led_2 = setTraffic[GREEN] / 1000;
    stat_led_1 = RED;
    stat_led_2 = GREEN;
    switch_mode_1 = 0;
    switch_mode_2 = 0;
    setTimer_LED(1000);
}

void subKeyProcess3() {
    button3_flag = 1;
}

int isButton3Pressed() {
    if (button3_flag) {
        button3_flag = 0;
        return 1;
    } 
    return 0;
}

void getKeyInput3() {
    KeyReg0 = KeyReg1;
    KeyReg1 = KeyReg2;
    KeyReg2 = HAL_GPIO_ReadPin(Button_3_GPIO_Port, Button_3_Pin);

    if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
        if (KeyReg3 != KeyReg2) {
            KeyReg3 = KeyReg2;

            if (KeyReg2 == PRESSED_STATE) {
                subKeyProcess3();
                TimerForKeyPress = 200;
            }
        } else {
            TimerForKeyPress--;
            if (TimerForKeyPress == 0) {
                if (KeyReg2 == PRESSED_STATE) {
                    subKeyProcess3();
                }
                
                TimerForKeyPress = 200;
            }
        }
    }
}

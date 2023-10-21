/*
 * button1.c
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#include "button1.h"

int button1_flag = 0;
int KeyReg1Counter = 0;

static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;

static int KeyReg3 = NORMAL_STATE;

static int TimerForKeyPress = 200;

void handleKeyInput1() {
    KeyReg1Counter++;
    
    if (KeyReg1Counter == 1 || KeyReg1Counter > 4) {
        KeyReg1Counter = 1;

        status1 = INIT;
        status2 = INIT;
        status3 = AUTOMATIC;

        led_1 = setTraffic[RED] / 1000;
        led_2 = setTraffic[GREEN] / 1000;
        stat_led_1 = RED;
        stat_led_2 = GREEN;
        timer_LED_flag = 1;
    }

    if (KeyReg1Counter == 2 || KeyReg1Counter == 3|| KeyReg1Counter == 4) {
        status1 = MODIFY;
        status2 = MODIFY;
        status3 = MODIFY;
        setTimer3(500);
        setTimer4(500);
        trafficOff();
    }

    if (KeyReg1Counter == 1) {
        HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DOT1_GPIO_Port, DOT1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT2_GPIO_Port, DOT2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT3_GPIO_Port, DOT3_Pin, GPIO_PIN_RESET);
    } else if (KeyReg1Counter == 2) {
        HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT1_GPIO_Port, DOT1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DOT2_GPIO_Port, DOT2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT3_GPIO_Port, DOT3_Pin, GPIO_PIN_RESET);
    } else if (KeyReg1Counter == 3) {
        HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT1_GPIO_Port, DOT1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT2_GPIO_Port, DOT2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DOT3_GPIO_Port, DOT3_Pin, GPIO_PIN_RESET);
    } else if (KeyReg1Counter == 4) {
        HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT1_GPIO_Port, DOT1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT2_GPIO_Port, DOT2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT3_GPIO_Port, DOT3_Pin, GPIO_PIN_SET);
    }
}

void subKeyProcess1() {
    button1_flag = 1;
}

int isButton1Pressed() {
    if (button1_flag) {
        button1_flag = 0;
        return 1;
    } 
    return 0;
}

void getKeyInput1() {
    KeyReg0 = KeyReg1;
    KeyReg1 = KeyReg2;
    KeyReg2 = HAL_GPIO_ReadPin(Button_1_GPIO_Port, Button_1_Pin);

    if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
        if (KeyReg3 != KeyReg2) {
            KeyReg3 = KeyReg2;

            if (KeyReg2 == PRESSED_STATE) {
                subKeyProcess1();
                TimerForKeyPress = 200;
            }
        } else {
            TimerForKeyPress--;
            if (TimerForKeyPress == 0) {
                if (KeyReg2 == PRESSED_STATE) {
                    subKeyProcess1();
                }

                TimerForKeyPress = 200;
            }
        }
    }
}
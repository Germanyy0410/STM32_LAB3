/*
 * fsm.c
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#include "fsm.h"

void Red_1_On() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
}

void Yellow_1_On() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
}

void Green_1_On() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
}

void Red_2_On() {
    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

void Yellow_2_On() {
    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

void Green_2_On() {
    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void trafficOff() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

void fsm_run_1() {
    switch(status1) {
        case INIT:
            Red_1_On();

            status1 = AUTO_RED;
            setTimer1(setTraffic[RED]);
            break;

        case AUTO_RED:
            Red_1_On();

            if (timer1_flag ==  1) {
                status1 = AUTO_GREEN;
                setTimer1(setTraffic[GREEN]);
            }
            break;

        case AUTO_GREEN:
            Green_1_On();

            if (timer1_flag ==  1) {
                status1 = AUTO_YELLOW;
                setTimer1(setTraffic[YELLOW]);
            }
            break;

        case AUTO_YELLOW:
            Yellow_1_On();

            if (timer1_flag ==  1) {
                status1 = AUTO_RED;
                setTimer1(setTraffic[RED]);
            }
            break;
            
        case MODIFY:
            if (KeyReg1Counter == 2) {
                if (timer3_flag == 1) {
                    HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
                    setTimer3(500);
                }
            } else if (KeyReg1Counter == 3) {
                if (timer3_flag == 1) {
                    HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
                    setTimer3(500);
                }
            } else if (KeyReg1Counter == 4) {
                if (timer3_flag == 1) {
                    HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
                    setTimer3(500);
                }
            }
            break;
    }
}

void fsm_run_2() {
    switch(status2) {
        case INIT:
            Green_2_On();

            status2 = AUTO_GREEN;
            setTimer2(setTraffic[GREEN]);
            break;

        case AUTO_RED:
            Red_2_On();

            if (timer2_flag ==  1) {
                status2 = AUTO_GREEN;
                setTimer2(setTraffic[GREEN]);
            }
            break;
            
        case AUTO_GREEN:
            Green_2_On();

            if (timer2_flag ==  1) {
                status2 = AUTO_YELLOW;
                setTimer2(setTraffic[YELLOW]);
            }
            break;

        case AUTO_YELLOW:
            Yellow_2_On();

            if (timer2_flag ==  1) {
                status2 = AUTO_RED;
                setTimer2(setTraffic[RED]);
            }
            break;
        
        case MODIFY:
            if (KeyReg1Counter == 2) {
                if (timer4_flag == 1) {
                    HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
                    setTimer4(500);
                }
            } else if (KeyReg1Counter == 3) {
                if (timer4_flag == 1) {
                    HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
                    setTimer4(500);
                }
            } else if (KeyReg1Counter == 4) {
                if (timer4_flag == 1) {
                    HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
                    setTimer4(500);
                }
            }
            break;
    }
}

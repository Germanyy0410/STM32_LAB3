/*
 * fsm.c
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#include "fsm.h"

void Red_Green() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void Red_Yellow() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

void Green_Red() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

void Yellow_Red() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

void trafficOff() {
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}
/*
void fsm_run_1() {
    switch(status1) {
        case INIT:
            Red_1_On();
            status1 = AUTO_RED;
            break;

        case AUTO_RED:
            Red_1_On();

            if (switch_mode_1 == 1) {
                switch_mode_1 = 0;
                status1 = AUTO_GREEN;
            }
            break;

        case AUTO_GREEN:
            Green_1_On();

            if (switch_mode_1 == 1) {
                switch_mode_1 = 0;
                status1 = AUTO_YELLOW;
            }
            break;

        case AUTO_YELLOW:
            Yellow_1_On();

            if (switch_mode_1 == 1) {
                switch_mode_1 = 0;
                status1 = AUTO_RED;
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
            break;

        case AUTO_RED:
            Red_2_On();

            if (switch_mode_2 == 1) {
                switch_mode_2 = 0;
                status2 = AUTO_GREEN;
            }
            break;
            
        case AUTO_GREEN:
            Green_2_On();

            if (switch_mode_2 == 1) {
                switch_mode_2 = 0;
                status2 = AUTO_YELLOW;
            }
            break;

        case AUTO_YELLOW:
            Yellow_2_On();

            if (switch_mode_2 == 1) {
                switch_mode_2 = 0;
                status2 = AUTO_RED;
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
*/

void fsm_run() {
    switch (status) {
        case INIT:
            Red_Green();

            status = RED_GREEN;

            break;

        case RED_GREEN:
            Red_Green();

            if (isButtonPressed(0)) {
                handleKeyInput(0);
                status = MAN_RED;
            }

            if (switch_mode_2 == 1) {
                switch_mode_2 = 0;
                status = RED_YELLOW;
            }    

            break;

        case RED_YELLOW:
            Red_Yellow();

            if (isButtonPressed(0)) {
                handleKeyInput(0);
                status = MAN_RED;
            }

            if (switch_mode_1 == 1 && switch_mode_2 == 1) {
                switch_mode_1 = 0;
                switch_mode_2 = 0;
                status = GREEN_RED;
            }

            break;

        case GREEN_RED:
            Green_Red();

            if (isButtonPressed(0)) {
                handleKeyInput(0);
                status = MAN_RED;
            }

            if (switch_mode_1 == 1) {
                switch_mode_1 = 0;
                status = YELLOW_RED;
            }

            break;

        case YELLOW_RED:
            Yellow_Red();

            if (isButtonPressed(0)) {
                status = MAN_RED;
            }

            if (switch_mode_1 == 1 && switch_mode_2 == 1) {
                switch_mode_1 = 0;
                switch_mode_2 = 0;
                status = RED_GREEN;
            }

            break;

        case MAN_RED:
            if (timer3_flag == 1) {
                HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
                HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);

                setTimer3(500);
            }

            if (isButtonPressed(0)) {
                handleKeyInput(0);
                status = MAN_YELLOW;
            }

            if (isButtonPressed(1)) {
                handleKeyInput(1);
            }

            if (isButtonPressed(2)) {
                handleKeyInput(2);
                status = RED_GREEN;
            }

            break;

        case MAN_YELLOW:
            if (timer3_flag == 1) {
                HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
                HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);

                setTimer3(500);
            } 

            if (isButtonPressed(0)) {
                handleKeyInput(0);
                status = MAN_GREEN;
            }

            if (isButtonPressed(1)) {
                handleKeyInput(1);
            }

            if (isButtonPressed(2)) {
                handleKeyInput(2);
                status = RED_GREEN;
            }
            
            break;

        case MAN_GREEN:
            if (timer3_flag == 1) {
                HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
                HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);

                setTimer3(500);
            }

            if (isButtonPressed(0)) {
                handleKeyInput(0);
                status = RED_GREEN;
            }

            if (isButtonPressed(1)) {
                handleKeyInput(1);
            }

            if (isButtonPressed(2)) {
                handleKeyInput(2);
                status = RED_GREEN;
            }
    }
}
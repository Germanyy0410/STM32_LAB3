/*
 * button.c
 *
 *  Created on: Oct 23, 2023
 *      Author: ProX
 */

/*
 * button1.c
 *
 *  Created on: Oct 17, 2023
 *      Author: ProX
 */

#include "button.h"

int button_flag[3] = {0, 0, 0};
int KeyReg1Counter = 1;

static int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
static int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
static int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

static int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

static int TimerForKeyPress[3] = {200, 200, 200};

int TimerModify[3] = { redTimer, yellowTimer, greenTimer };
int setTraffic[3] = { redTimer, yellowTimer, greenTimer };

void handleKeyInput(int index) {
    if (index == 0) {
        KeyReg1Counter++;
        
        if (KeyReg1Counter == 1 || KeyReg1Counter > 4) {
            KeyReg1Counter = 1;

            status = INIT;

            led_1 = setTraffic[RED] / 1000;
            led_2 = setTraffic[GREEN] / 1000;
            stat_led_1 = RED;
            stat_led_2 = GREEN;
            switch_mode_1 = 0;
            switch_mode_2 = 0;
            setTimer_LED(1000);
        } else if (KeyReg1Counter == 2 || KeyReg1Counter == 3|| KeyReg1Counter == 4) {
            setTimer3(500);
            trafficOff();
        }

    }
    else if (index == 1) {        
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
    else if (index == 2) {
        if (KeyReg1Counter == 2) {
            KeyReg1Counter = 1;

            if (TimerModify[RED] - TimerModify[YELLOW] - 1000 > 0) {
                setTraffic[RED] = TimerModify[RED];
                setTraffic[GREEN] = setTraffic[RED] - setTraffic[YELLOW] - 1000;
                TimerModify[GREEN] = setTraffic[GREEN];
            }
        }

        else if (KeyReg1Counter == 3) {
            KeyReg1Counter = 1;

            if (TimerModify[YELLOW] + TimerModify[GREEN] + 1000 <= 9000) {
                setTraffic[YELLOW] = TimerModify[YELLOW];
                setTraffic[RED] = setTraffic[YELLOW] + setTraffic[GREEN] + 1000;
                TimerModify[RED] = setTraffic[RED];
                }
            }

            else if (KeyReg1Counter == 4) {
                KeyReg1Counter = 1;

                if (TimerModify[YELLOW] + TimerModify[GREEN] + 1000 <= 9000) {
                    setTraffic[GREEN] = TimerModify[GREEN];
                    setTraffic[RED] = setTraffic[YELLOW] + setTraffic[GREEN] + 1000;
                    TimerModify[RED] = setTraffic[RED];
                }
            }

        HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DOT1_GPIO_Port, DOT1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT2_GPIO_Port, DOT2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DOT3_GPIO_Port, DOT3_Pin, GPIO_PIN_RESET);

        status = INIT;

        led_1 = setTraffic[RED] / 1000;
        led_2 = setTraffic[GREEN] / 1000;
        stat_led_1 = RED;
        stat_led_2 = GREEN;
        switch_mode_1 = 0;
        switch_mode_2 = 0;
        setTimer_LED(1000);
    }
}

void subKeyProcess(int index) {
    button_flag[index] = 1;
}

int isButtonPressed(int index) {
    if (button_flag[index]) {
        button_flag[index] = 0;
        return 1;
    } 
    return 0;
}

void getKeyInput() {
    for (int i = 0; i < 3; i++) {
        KeyReg0[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg2[i];

        if (i == 0) KeyReg2[i] = HAL_GPIO_ReadPin(Button_1_GPIO_Port, Button_1_Pin);
        if (i == 1) KeyReg2[i] = HAL_GPIO_ReadPin(Button_2_GPIO_Port, Button_2_Pin);
        if (i == 2) KeyReg2[i] = HAL_GPIO_ReadPin(Button_3_GPIO_Port, Button_3_Pin);

        if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
            if (KeyReg3[i] != KeyReg2[i]) {
                KeyReg3[i] = KeyReg2[i];

                if (KeyReg2[i] == PRESSED_STATE) {
                    subKeyProcess(i);
                    TimerForKeyPress[i] = 200;
                }
            } else {
                TimerForKeyPress[i]--;
                if (TimerForKeyPress[i] == 0) {
                    if (KeyReg2[i] == PRESSED_STATE) {
                        subKeyProcess(i);
                    }

                    TimerForKeyPress[i] = 200;
                }
            }
        }
    }
    
}
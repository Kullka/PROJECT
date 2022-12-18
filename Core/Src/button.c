/*
 * button.c
 *
 *  Created on: Dec 16, 2022
 *      Author: loing
 */


#include "button.h"

int keyReg0[NO_BUTTONS];
int keyReg1[NO_BUTTONS];
int keyReg2[NO_BUTTONS];
int keyReg3[NO_BUTTONS];


void key0Process() {
	currentTick = DEAD_MODIFIED;
	sprintf(msg, "!BUTTON %d#\r\n", currentTick);
	HAL_UART_Transmit(&huart2, (uint8_t *)msg, sizeof(msg), 50);
	if (currentMode == AUTO) {
		currentMode = MODIFIED;
		state = MOD_RED;
		tempDuration = timeRed;
	}
	else if (currentMode == MODIFIED) {
		switch (state) {
		case MOD_RED:
			state = MOD_GREEN;
			tempDuration = timeGreen;
			break;
		case MOD_GREEN:
			state = MOD_YELLOW;
			tempDuration = timeYellow;
			break;
		case MOD_YELLOW:
			state = STATE0;
			currentMode = AUTO;
			break;
		}
	}
}
void key1Process() {
	if (currentMode == MODIFIED) {
		tempDuration += 100;
		currentTick = DEAD_MODIFIED;
	}
}

void key2Process() {
	if (currentMode == MODIFIED) {
		switch (state) {
		case MOD_RED:
			timeRed = tempDuration;
			currentTick = DEAD_MODIFIED;
			break;
		case MOD_GREEN:
			timeGreen = tempDuration;
			currentTick = DEAD_MODIFIED;
			break;
		case MOD_YELLOW:
			timeYellow = tempDuration;
			currentTick = DEAD_MODIFIED;
			break;
		}
		pivot[0] = timeGreen;
		pivot[1] = timeYellow;
		pivot[2] = timeGreen;
		pivot[3] = timeYellow;
	}
}
void key3Process(){
	pedestrianFlag = 1;
}

void getKeyInput(){
	for (int i=0; i<NO_BUTTONS; i++) {
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
		switch (i) {
		case 0:
			keyReg2[i] = HAL_GPIO_ReadPin(GPIOA, Mode_Button_Pin);
			break;
		case 1:
			keyReg2[i] = HAL_GPIO_ReadPin(GPIOA, Add_Button_Pin);
			break;
		case 2:
			keyReg2[i] = HAL_GPIO_ReadPin(GPIOB, Confirm_Button_Pin);
			break;
		case 3:
			keyReg2[i] = HAL_GPIO_ReadPin(GPIOA, Perdes_Button_Pin);
			break;
		}
		if ( (keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]) ){
			if (keyReg3[i] != keyReg2[i]) {
				keyReg3[i] = keyReg2[i];
				sprintf(msg, "!CHECK %d#\r\n", currentTick);
				HAL_UART_Transmit(&huart2, (uint8_t *)msg, sizeof(msg), 50);
				if (keyReg2[i] == PRESSED_STATE) {
					switch (i) {
					case 0:
						key0Process();
						break;
					case 1:
						key1Process();
						break;
					case 2:
						key2Process();
						break;
					case 3:
						key3Process();
						break;
					}
				}
			}
		}
	}
}



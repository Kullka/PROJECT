/*
 * pedestrian.c
 *
 *  Created on: Dec 17, 2022
 *      Author: loing
 */


#include "pedestrian.h"

int timeLeft = 0;
int currentTrafficLight;
int timeFSM = 0;
uint32_t PWM = 0;

void pedestrian_fsm(){
	if (pedestrianFlag == 1){
		switch (state) {
		case STATE0:
			HAL_GPIO_WritePin(GPIOB, PED0_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, PED1_Pin, 0);
			//sprintf(msg, "!PED0 %d!\r\n", currentTick);
			//HAL_UART_Transmit(&huart2, (uint8_t *)msg, sizeof(msg), 50);
			break;
		case STATE1:
			//sprintf(msg, "!PED1 %d!\r\n", currentTick);
			//HAL_UART_Transmit(&huart2, (uint8_t *)msg, sizeof(msg), 50);
			break;
		case STATE2:
			HAL_GPIO_WritePin(GPIOB, PED0_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, PED1_Pin, 1);
			//sprintf(msg, "!PED2 %d!\r\n", currentTick);
			//HAL_UART_Transmit(&huart2, (uint8_t *)msg, sizeof(msg), 50);
			break;
		case STATE3:
			HAL_GPIO_WritePin(GPIOB, PED0_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, PED1_Pin, 1);
			//sprintf(msg, "!PED3 %d!\r\n", currentTick);
			//HAL_UART_Transmit(&huart2, (uint8_t *)msg, sizeof(msg), 50);
			PWM += 5;
			if (PWM >= 100)
				PWM = 100;
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, PWM);
			if (currentTick <= 5) {
				HAL_GPIO_WritePin(GPIOB, PED0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, PED1_Pin, 1);
				pedestrianFlag = 0;
				PWM = 0;
			}
			break;
		}
	}
}

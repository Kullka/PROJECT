/*
 * button.h
 *
 *  Created on: Dec 16, 2022
 *      Author: loing
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"
#include "pedestrian.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define NO_BUTTONS 			5

void getKeyInput();
void key0Process();
void key1Process();
void key2Process();
void key3Process();

#endif /* INC_BUTTON_H_ */

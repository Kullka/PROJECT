/*
 * task.h
 *
 *  Created on: Dec 16, 2022
 *      Author: loing
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_

#include "global.h"
#include "main.h"
#include "button.h"


void fsm_auto();
void fsm_mode();
void fsm();
void init_task();
void update_state();

#endif /* INC_TASK_H_ */

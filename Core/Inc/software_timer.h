/*
 * software_timer.h
 *
 *  Created on: Dec 16, 2022
 *      Author: loing
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
#include "global.h"

extern int timer0Flag;
extern int timer0Counter;
extern int timer1Flag;
extern int timer1Counter;

extern int duration;

void set_timer1(int duration);
void set_timer0(int duration);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */

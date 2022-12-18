/*
 * software_timer.c
 *
 *  Created on: Dec 16, 2022
 *      Author: loing
 */


#include "software_timer.h"

int duration;
int timer0Flag = 0;
int timer0Counter = 0;
int timer1Flag = 0;
int timer1Counter = 0;

void set_timer0(int duration) {
	timer0Counter = duration;
	timer0Flag = 0;
}

void set_timer1(int duration) {
	timer1Counter = duration;
	timer1Flag = 0;
}

void timer_run() {
	if (timer0Counter>0) {
		timer0Counter--;
		if (timer0Counter==0) {
			timer0Flag = 1;
			set_timer0(50);
		}
	}
	if (timer1Counter>0) {
		timer1Counter--;
		if (timer1Counter==0) {
			timer1Flag = 1;
			set_timer1(1);
		}
	}
}

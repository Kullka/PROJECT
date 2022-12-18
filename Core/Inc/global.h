/*
 * global.h
 *
 *  Created on: Dec 16, 2022
 *      Author: loing
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define DEAD_MODIFIED 50
enum NORMAL_STATE {STATE0, STATE1, STATE2, STATE3};
enum MOD_STATE {MOD_RED = 5, MOD_GREEN = 6, MOD_YELLOW = 7};
enum MODE {AUTO, MODIFIED};

extern int noTasks;
extern int pivot[4];
extern int currentMode;
extern int state;
extern int tempDuration;
extern int timeRed;
extern int timeYellow;
extern int timeGreen;
extern int currentTick;
extern int pedestrianFlag;

extern char msg[20];
#endif /* INC_GLOBAL_H_ */

/*
 * scheduler.c
 *
 *  Created on: Dec 16, 2022
 *      Author: loing
 */

#include "scheduler.h"
#include "main.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
uint8_t currentID = 0;

void SCH_init(void) {
	uint8_t id;
	for (id=0; id<SCH_MAX_TASKS; id++) {
		SCH_delete_task(id);
	}
	currentID = 0;
//	error_code_G = 0;
}

void SCH_update(void) {
	uint8_t id;
	for (id=0; id<currentID; id++) {
		if (SCH_tasks_G[id].pTask) {
			if (SCH_tasks_G[id].delay==0) {
				SCH_tasks_G[id].runMe += 1;
				if (SCH_tasks_G[id].period)
					SCH_tasks_G[id].delay = SCH_tasks_G[id].period;
				else ;
			}
			else
				SCH_tasks_G[id].delay -= 1;
		}
	}
}

uint8_t SCH_add_task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD) {
	uint8_t id = 0;
	while ( (SCH_tasks_G[id].pTask != 0) && (id < SCH_MAX_TASKS) )
		id++;
	if (id==SCH_MAX_TASKS)
		return SCH_MAX_TASKS;
	SCH_tasks_G[id].pTask = pFunction;
	SCH_tasks_G[id].delay = DELAY;
	SCH_tasks_G[id].period = PERIOD;
	SCH_tasks_G[id].runMe = 0;
	SCH_tasks_G[id].taskID = currentID;
	currentID += 1;
//	noTasks++;
	return id;
}

void SCH_dispatch_tasks(void) {
	uint8_t id;
	for (id = 0; id<currentID; id++) {
		if (SCH_tasks_G[id].runMe>0) {
			(*SCH_tasks_G[id].pTask)();
			SCH_tasks_G[id].runMe -= 1;
			if (SCH_tasks_G[id].period==0)
				SCH_delete_task(id);
		}
	}
}

uint8_t SCH_delete_task(const uint8_t ID) {
	if (ID>currentID)
		return ID;
	SCH_tasks_G[ID].delay = 0;
	SCH_tasks_G[ID].pTask = 0x0000;
	SCH_tasks_G[ID].delay = 0;
	SCH_tasks_G[ID].runMe = 0;
	for (uint8_t id = ID+1; id<currentID; id++)
		SCH_tasks_G[id].taskID -= 1;
//	noTasks--;
	return ID;
}

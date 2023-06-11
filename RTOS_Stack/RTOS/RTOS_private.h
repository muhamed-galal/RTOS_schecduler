/*
 * RTOS_private.h
 *
 *  Created on: Apr 15, 2023
 *      Author: Muham
 */

#ifndef RTOS_STACK_RTOS_RTOS_PRIVATE_H_
#define RTOS_STACK_RTOS_RTOS_PRIVATE_H_

typedef struct
{
	u16 Periodicity;
	void(*TaskFunc)(void);
	u8 State;
	u16 FirstDelay;

}Task_t;


static void voidScheduler(void);

#define TASK_RESUMED 	0
#define TASK_SUSPENDED	1

#endif /* RTOS_STACK_RTOS_RTOS_PRIVATE_H_ */

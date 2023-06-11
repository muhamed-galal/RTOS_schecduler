/*
 * RTOS_interface.h
 *
 *  Created on: Apr 15, 2023
 *      Author: Muham
 */

#ifndef RTOS_STACK_RTOS_RTOS_INTERFACE_H_
#define RTOS_STACK_RTOS_RTOS_INTERFACE_H_

void RTOS_voidStart(void);

u8 RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FisrtDelay);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);


#endif /* RTOS_STACK_RTOS_RTOS_INTERFACE_H_ */

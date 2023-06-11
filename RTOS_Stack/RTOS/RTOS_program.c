/*
 * RTOS_program.c
 *
 *  Created on: Apr 15, 2023
 *      Author: Muham
 */
#include "std_types.h"
#include "defintion.h"
#include "Bit_Math.h"
#include "../Timer/Timer2_Interface.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"


Task_t SystemTasks[TASK_NUM]= {{Null}};

void RTOS_voidStart(void)
{
	TIMER2_voidSetCallBachFn(&voidScheduler);
	Set_Bit(SREG_REG,7);
	TIMER2_voidInit();
	OCR2_REG=125;
}

u8 RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FisrtDelay)
{
	u8 Local_u8ErrorState = OK;

	/*check if the required task priority is empty or used for another task*/
	if(SystemTasks[Copy_u8Priority].TaskFunc == Null)
	{
		SystemTasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;
		SystemTasks[Copy_u8Priority].State = TASK_RESUMED; // intialize the task
		SystemTasks[Copy_u8Priority].FirstDelay = Copy_u16FisrtDelay;

	}
	else
	{
		/*priority is reserved before dont create the task*/
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc= Null;
}


void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_RESUMED;
}

static void voidScheduler(void)
{

	u8 Local_u8TaskCounter;

	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
		if(SystemTasks[Local_u8TaskCounter].State == TASK_RESUMED)
		{
			if( SystemTasks[Local_u8TaskCounter].FirstDelay == 0 )
			{
				if(SystemTasks[Local_u8TaskCounter].TaskFunc != Null)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();
					/*Assign the first delay parameter to the periodicity minus 1*/
					SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity-1;
				}
				else
				{
					/* decrement the first delay*/
					SystemTasks[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}
		else
		{
			/* task is suspended do nothing*/
		}

	}
}

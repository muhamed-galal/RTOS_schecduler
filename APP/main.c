/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Galal
 *
 */


#include "Bit_Math.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../Common/defintion.h"
#include "../RTOS_Stack/RTOS/RTOS_interface.h"


void LED1(void);
void LED2(void);
void LED3(void);


void main ()
{

	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin1,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin2,DIO_Output);

	RTOS_voidCreateTask(0,1000,&LED1,0);
	RTOS_voidCreateTask(1,2000,&LED2,1);
	RTOS_voidCreateTask(2,3000,&LED3,2);
	RTOS_voidStart();

	while(1)
	{

	}
}
void LED1(void)
{
	static u8 ledstate0=0;
	Tog_Bit(ledstate0,0);
	DIO_ErrStateSetPinValue(DIO_GroupA,Pin0,ledstate0);

}
void LED2(void)
{
	static u8 ledstate1=0;
	Tog_Bit(ledstate1,0);
	DIO_ErrStateSetPinValue(DIO_GroupA,Pin1,ledstate1);

}
void LED3(void)
{
	static u8 ledstate2=0;
	Tog_Bit(ledstate2,0);
	DIO_ErrStateSetPinValue(DIO_GroupA,Pin2,ledstate2);
}


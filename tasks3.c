#include "StdTypes.h"
#include "Tasks.h"
#include "tasks3.h"
#include "OS.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "TIMER_Int.h"
#include "MemMap.h"
#include "ADC_Int.h"

u8 task_miliseconds=1;
u16 task_seconds=1;

void vMillis_Increment(void){
	TCNT0=156;
	task_miliseconds++;
	if(task_miliseconds>=10){
		task_miliseconds=1;
		task_seconds++;
	}
	if(task_seconds>=1000){
		task_seconds=1;
		OS_Task_Handler();
	}
	
};

void Scheduler_init(void){
	/*Init Timer*/
	/*Prescaled: 1M, Overflow, 100U */
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER1_SCALER_8);
	TIMER0_OC0Mode(OC0_DISCONNECTED);
	TIMER0_OV_InterruptEnable();
	TIMER0_OV_SetCallBack(vMillis_Increment);
	
	/*Step: Task Creation*/
	OS_Task_Creat(Task_1s_LcdUpdate,      1,BLOCKED);
	OS_Task_Creat(Task_3s_TempRead,       3,BLOCKED);
	OS_Task_Creat(Task_5s_PressureRead,   5,BLOCKED);
}

void ECU_tasks_init(void){
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,SCALLER_64);
	Enable_Global();
	LCD_SetCursor(1,1);
	LCD_WriteString("Seconds");
	LCD_SetCursor(1,10);
	LCD_WriteString("T:");
	LCD_SetCursor(2,10);
	LCD_WriteString("P:");
	/*DIO_WritePin(PIND2,LOW);
	DIO_WritePin(PIND3,LOW);*/
}
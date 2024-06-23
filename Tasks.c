#include "StdTypes.h"
#include "Tasks.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "SENSORS_Int.h"
u16 TaskSeconds=1;

void Task_1s_LcdUpdate(void){
	LCD_SetCursor(2,1);
	LCD_WriteNumber(TaskSeconds);
	TaskSeconds++;
	
}
void Task_2s_Blink1(void){
	DIO_TogglePin(PIND2);
}
void Task_3s_Blink2(void){
	DIO_TogglePin(PIND3);
}
void Task_3s_TempRead(void){
	u16 temp=TEMP_Read();
	LCD_SetCursor(1,12);
	LCD_WriteNumber(temp/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(temp%10);
	if(temp>=500){
		DIO_WritePin(PINC0,HIGH);
		DIO_WritePin(PINC1,LOW);
	}
	if(temp<=450){
		DIO_WritePin(PINC0,LOW);
		DIO_WritePin(PINC1,LOW);
	}
	
}
void Task_5s_PressureRead(void){
	u16 press=MPX4115_Pressure();
	LCD_SetCursor(2,12);
	LCD_WriteNumber(press/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(press%10);
}
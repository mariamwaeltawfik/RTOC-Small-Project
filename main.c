#include "MemMap.h"
#include "StdTypes.h"
#include "DIO_Int.h"
#include "MOTOR_Int.h"
//#include "ECU_Int.h"
//#include "STEPPER_Int.h"
#include "LCD_Int.h"
#include "KeyPad_Int.h"
//#include "CONVERTER.h"
#include "ADC_Int.h"
//#include "Calculator.h"
//#include "SENSORS_Int.h"
//#include "INTERPOLATOR.h"
//#include "Fire_System.h"
//#include "Filter.h"
#include "EX_Intrrupt_Int.h"
#include "TIMER_Int.h"
//#include "ULtraSonic_Int.h"
//#include "Dht22_Int.h"
#include "RGB_Int.h"
//#include "Timer_Services.h"
#include "UART_Int.h"
#include "UART_Service.h"
#include "SmartHome.h"
#include "tasks3.h"
int main(void)
{

	/*DIO_Init();
	LCD_Init();
	//ADC_Init(VREF_AVCC,SCALLER_64);
	Enable_Global();
   UART_Init();
/*Timer2_Init(TIMER2_FastPWM_Mode,TIMER2_Scaler_8);
Timer2_OC2Mode(OC2_Inverting);
Timer2_SetOCR(200);
smart_home_init();

u8 data,i=1;*/
	ECU_tasks_init();
	Scheduler_init();
	while(1){
	
		OS_TaskExecution();
		
		
//smart_home_runnable();

	/* if(push()==STACK_OK){
		 push();
	 }

 if(push()==STACK_FULL){
	LCD_SetCursor(1,1);
	
	LCD_WriteString("STACK FULL");
	LCD_WriteString("                        ");
}
if(!DIO_ReadPin(PINB7)){
	_delay_ms(25);
	if(pop(&data)==STACK_OK){
	
		LCD_SetCursor(2,i);
		LCD_WriteChar(data);
		i++;
		
	}
	else if(pop(&data)==STACK_EMPTY){
		i=1;
		
		LCD_SetCursor(1,1);
		
		LCD_WriteString("STACK EMPTY");
		LCD_WriteString("                        ");
		LCD_SetCursor(2,1);
		LCD_WriteString("                        ");
	}
	
	
}*/
}
}

#include "MemMap.h"
#include "StdTypes.h"
#include "DIO_Int.h"
#include "MOTOR_Int.h"
#include "LCD_Int.h"
#include "KeyPad_Int.h"
#include "ADC_Int.h"
#include "EX_Intrrupt_Int.h"
#include "TIMER_Int.h"
#include "RGB_Int.h"
#include "UART_Int.h"
#include "UART_Service.h"
#include "SmartHome.h"
#include "tasks3.h"
int main(void)
{

	
	ECU_tasks_init();
	Scheduler_init();
	while(1){
	
		OS_TaskExecution();
		

}
}

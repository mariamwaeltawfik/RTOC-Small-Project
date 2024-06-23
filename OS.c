#include "StdTypes.h"
#include "OS.h"


Tasks_TCB Task_Array[MAX_NUM_TASK];
u8 Task_Num=0;

OS_feedback OS_Task_Creat(fncPtr LocalFptr,u8 period,Task_State_t state){
	OS_feedback creat_task_state=NOK_UNKNOWN;
	if(LocalFptr== NULLPTR){
		creat_task_state=NOK_NULL_PTR;
	}
	else if(period>=HyperPeriod){
		creat_task_state= NOK_HYPER_PERIOD;
	}
	else if(Task_Num>=MAX_NUM_TASK){
		creat_task_state= NOK_COUNT_LIMIT;
	}
	else{
		Task_Array[Task_Num].function=LocalFptr;
		Task_Array[Task_Num].periodicity=period;
		Task_Array[Task_Num].state=state;
		Task_Array[Task_Num].task_counter=1;
		Task_Num++;
		creat_task_state=OKK;
		
	}
	return creat_task_state;
}


void OS_TaskExecution(void){
	for(u8 task_id=0;task_id<Task_Num;task_id++){
		if(Task_Array[task_id].state==READY){
			//run the task
			Task_Array[task_id].function();
			//return the task blocked
			Task_Array[task_id].state=BLOCKED;
		}
		else{
			
		}
	}
}
void OS_Task_Handler(void){
	//loop check time limit of tasks ->counter of handler
	// if OK task from Blocked to Ready

	for(u8 task_id=0;task_id<Task_Num;task_id++){
		
		if(Task_Array[task_id].state!= SUSPENDED){
			
			if( Task_Array [task_id].task_counter>=Task_Array[task_id].periodicity){
				
				Task_Array[task_id].state=READY;
				Task_Array[task_id].task_counter=1;
			}
			
			else{
				
				// else stay Blocked    -> count++
				Task_Array[task_id].task_counter++;
				
			}
		}
		else{
			//Nothing
		}
	}
	
	
	
}

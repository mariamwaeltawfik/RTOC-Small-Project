/*
 * OS.h
 *
 * Created: 6/22/2024 8:32:26 PM
 *  Author: NOTEBOOK
 */ 


#ifndef OS_H_
#define OS_H_

typedef void (*fncPtr)(void);

typedef enum {  
	BLOCKED,
	READY,
	SUSPENDED,
	DEFAULT
}Task_State_t;
typedef enum
{
	OKK,
	NOK_NULL_PTR,
	NOK_COUNT_LIMIT,
	NOK_HYPER_PERIOD,
	NOK_UNKNOWN
} OS_feedback;
typedef struct {
	//TCB info about the tasks
	// pointer to function
  fncPtr	function;
	//periodicity
	u8 periodicity;
	//task state
	Task_State_t state;
	//task counter for handler
	u8 task_counter;
}Tasks_TCB;


#define MAX_NUM_TASK 3
#define HyperPeriod  15

OS_feedback OS_Task_Creat(void(*LocalFptr)(void),u8 period,Task_State_t state);

void OS_TaskExecution(void);
void OS_Task_Handler(void);

#endif /* OS_H_ */
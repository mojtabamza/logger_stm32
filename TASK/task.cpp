#include "task.h"

void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
//	static int timer = 0;
//	if(timer >= 1) {
		taskManager_t::get_instance()->taskIsr();
//		timer = 0;
//	}
//	timer++;
	
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

taskManager_t* taskManager_t::get_instance(void) {
	static taskManager_t* instance = nullptr;
	if(instance == nullptr)
		instance = new taskManager_t();
	return instance;
}

taskManager_t::taskManager_t() {
	this->tick = 0;
}

void taskManager_t::addTask(void(*func)(void), int interval) {
	task_t* new_task = new task_t();
	new_task->interval = interval;
	new_task->task = func;
	new_task->exeTime = new_task->interval + this->tick;
	tasks.push_back(new_task);
	flags.push_back(0);
}

void taskManager_t::taskIsr(void) {
//	char str[15];
//	sprintf(str, "Tick : %05d\r\n", tick);
//	HAL_UART_Transmit(&huart3, (uint8_t*)str, sizeof(str), 100);
	this->tick++;
	for(int i = 0; i < tasks.size(); i++) {
		if(tasks[i]->exeTime == this->tick) {
			//tasks[i]->task();
			flags[i] = 1;
			tasks[i]->exeTime = tasks[i]->interval + this->tick;
//			sprintf(str, "flag[%d] = %d", i, flags[i]);
//			HAL_UART_Transmit(&huart3, (uint8_t*)str, sizeof(str), 100);
		}
	}
}

void taskManager_t::sysTick(void) {
	static int timer = 0;
	if(++timer >= 10000) {
		timer = 0;
		this->taskIsr();
	}
}


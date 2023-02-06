#ifndef __TASK_H
#define __TASK_H

#include "main.h"
#include "stm32f7xx_it.h"

#include <vector>
#include <string>
#include "usart.h"
#include "gpio.h"
using std::string;
using std::vector;

struct task_t {
	int interval;
	int exeTime;
	void(*task)(void);
	};

class taskManager_t {
	public:
		static taskManager_t* get_instance(void);
		void addTask(void(*func)(void), int interval);
		void sysTick();
		void taskIsr();
	private:
		taskManager_t();
		vector<task_t*> tasks;
		int tick;
};



#endif
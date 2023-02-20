#ifndef __LOGGER_H_
#define __LOGGER_H_

#include "main.h"
#include "stm32f7xx_it.h"

#include <vector>
#include <string>
#include "usart.h"
#include "gpio.h"
#include "rtc.h"
#include "time.hpp"

using std::string;
using std::vector;

class Logger_t {
	public:
		static Logger_t* get_instance();
		void task(void);
	private:
		Logger_t();
};







#endif
#include "logger.hpp"


Logger_t* Logger_t::get_instance(void) {
	static Logger_t* instance = nullptr;
	if(instance == nullptr)
		instance = new Logger_t();
	return instance;
}
	
Logger_t::Logger_t(void) {
}

void Logger_t::task(void) {
	char str[11];
	TimeDate now;
	Time_t::get_instance()->get_time(now);
	
	sprintf(str, "%02d:%02d:%02d\r\n", now.time_obj.hours, now.time_obj.minutes, now.time_obj.seconds);
	HAL_UART_Transmit(&huart3, (uint8_t*)str, sizeof(str), 1);
}
	




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
	RTC_TimeTypeDef stime = {0};
  RTC_DateTypeDef sdate = {0};
	
	HAL_RTC_GetTime(&hrtc, &stime, RTC_FORMAT_BCD);
	HAL_RTC_GetDate(&hrtc, &sdate, RTC_FORMAT_BCD);
	
	stime.Hours = ((stime.Hours & 0xF0) >> 4) * 10 + (stime.Hours & 0x0F);
	stime.Minutes = ((stime.Minutes & 0xF0) >> 4) * 10 + (stime.Minutes & 0x0F);
	stime.Seconds = ((stime.Seconds & 0xF0) >> 4) * 10 + (stime.Seconds & 0x0F);
	
	sprintf(str, "%02d:%02d:%02d\r\n", stime.Hours, stime.Minutes, stime.Seconds);
	HAL_UART_Transmit(&huart3, (uint8_t*)str, sizeof(str), 10);
}
	




#include "time.hpp"


Time_t::Time_t(void) {
}

Time_t* Time_t::get_instance(void) {
	static Time_t* instance = nullptr;
	if(instance == nullptr)
		instance = new Time_t();
	return instance;
}

void Time_t::get_time(TimeDate& now) {
	
//	TimeDate time_date_obj;
	RTC_TimeTypeDef stime = {0};
  RTC_DateTypeDef sdate = {0};
	
	HAL_RTC_GetTime(&hrtc, &stime, RTC_FORMAT_BCD);
	HAL_RTC_GetDate(&hrtc, &sdate, RTC_FORMAT_BCD);
	
	now.time_obj.seconds = stime.Seconds;
	now.time_obj.minutes = stime.Minutes;
	now.time_obj.hours = stime.Hours;
	
	now.date_obj.day = sdate.Date;
	now.date_obj.month = sdate.Month;
	now.date_obj.year = sdate.Year;
	
	//bcdToDec(now);
	for(uint8_t i = 0; i < sizeof(TimeDate) / sizeof(uint8_t); i++) {
		uint8_t* ptr = &now.time_obj.seconds;
		bcdToDec(*(ptr + i));
	}
}

	
void Time_t::get_time(string now) {
}

void Time_t::set_time(const TimeDate& time) {
}

void Time_t::set_time(const string time) {
}
//void Time_t::bcdToDec(TimeDate& val) {
//	val.time_obj.hours = ((val.time_obj.hours & 0xF0) >> 4) * 10 + (val.time_obj.hours & 0x0F);
//	val.time_obj.minutes = ((val.time_obj.minutes & 0xF0) >> 4) * 10 + (val.time_obj.minutes & 0x0F);
//	val.time_obj.seconds = ((val.time_obj.seconds & 0xF0) >> 4) * 10 + (val.time_obj.seconds & 0x0F);
//	val.date_obj.day = ((val.date_obj.day & 0xF0) >> 4) * 10 + (val.date_obj.day & 0x0F);
//	val.date_obj.month = ((val.date_obj.month & 0xF0) >> 4) * 10 + (val.date_obj.month & 0x0F);
//	val.date_obj.year = ((val.date_obj.year & 0xF0) >> 4) * 10 + (val.date_obj.year & 0x0F);
//}

void Time_t::bcdToDec(uint8_t& val) {
	val = ((val & 0xF0) >> 4) * 10 + (val & 0x0F);
}
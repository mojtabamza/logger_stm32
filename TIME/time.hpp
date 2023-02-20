#ifndef __TIME_H_
#define __TIME_H_

#include "main.h"
#include "stm32f7xx_it.h"
#include "rtc.h"
#include <string>
using std::string;

struct TimeDate {
	struct timeStruct {
		uint8_t seconds;
		uint8_t minutes;
		uint8_t hours;
	}time_obj;
	struct dateStruct {
		uint8_t day;
		uint8_t month;
		uint8_t year;
	}date_obj;
};
	
	

class Time_t {
	public:
		static Time_t* get_instance(void);
		static void bcdToDec(TimeDate& val);
		static void bcdToDec(uint8_t& val);
		void get_time(string now);
		void get_time(TimeDate& now);
		void set_time(const TimeDate& time);
		void set_time(const string time);
		
	private:
		Time_t();
			
};

#endif
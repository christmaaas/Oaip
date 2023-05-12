#include "log.h"
#include "resources.h"

void push_log(const char* log_variety, const char* log_info, const char* file_mode) {
	FILE* logbook = file_open("logbook.txt", file_mode);
	time_t current_time = time(NULL);
	struct tm time_info;

	localtime_s(&time_info, &current_time);

	fprintf(logbook, "[%02d.%02d.%04d %02d:%02d:%02d] [%s] %s\n",
		time_info.tm_mday, 
		time_info.tm_mon + 1, 
		time_info.tm_year + 1900, 
		time_info.tm_hour, 
		time_info.tm_min, 
		time_info.tm_sec,
		log_variety,
		log_info);

	fclose(logbook);
}
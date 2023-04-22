
#include "log.h"

void push_log(FILE* log_file, char* log_variety, char* log_info) {
	time_t current_time = time(NULL);
	struct tm time_info;

	localtime_s(&time_info, &current_time);

	fprintf(log_file, "[%d.%d.%d %d:%d:%d] ", 
		time_info.tm_mday, 
		time_info.tm_mon + 1, 
		time_info.tm_year + 1900, 
		time_info.tm_hour, 
		time_info.tm_min, 
		time_info.tm_sec);
	fprintf(log_file, "[%s] ", log_variety);
	fprintf(log_file, "%s\n", log_info);
}
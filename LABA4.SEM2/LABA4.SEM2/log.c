#include "log.h"

void push_log(FILE* log_file, char* log_info, char* log_variety) {
	time_t current_time = time(NULL);
	struct tm time_info;
	
	localtime_s(&time_info, &current_time);
	
	fprintf(log_file, "%s", "----------------------------------------------------\n");
	fprintf(log_file, "Date: %d.%d.%d\n", time_info.tm_mday, time_info.tm_mon + 1, time_info.tm_year + 1900);
	fprintf(log_file, "Time: %d:%d:%d\n", time_info.tm_hour, time_info.tm_min, time_info.tm_sec);
	fprintf(log_file, "[%s]\n", log_variety);
	fprintf(log_file, "\n%s\n", log_info);
	fprintf(log_file, "%s\n", "----------------------------------------------------\n");
}

void push_game_log(FILE* log_file, char* log_info, char* log_variety, char* question_or_answer) {
	time_t current_time = time(NULL);
	struct tm time_info;
	
	localtime_s(&time_info, &current_time);
	
	fprintf(log_file, "%s", "----------------------------------------------------\n");
	fprintf(log_file, "Date: %d.%d.%d\n", time_info.tm_mday, time_info.tm_mon + 1, time_info.tm_year + 1900);
	fprintf(log_file, "Time: %d:%d:%d\n", time_info.tm_hour, time_info.tm_min, time_info.tm_sec);
	fprintf(log_file, "[%s]\n", log_variety);
	
	if (question_or_answer[0] == QUESTION) {
		fprintf(log_file, "\n%s: %s?\n", question_or_answer, log_info);
	}
	else if (question_or_answer[0] == ANSWER) {
		fprintf(log_file, "\n%s: %s\n", question_or_answer, log_info);
	}
	else if (question_or_answer[0] == OBJECT) {
		fprintf(log_file, "\nUser-specified object \"%s\" was added.\n", log_info);
	}
	
	fprintf(log_file, "%s\n", "----------------------------------------------------\n");
}
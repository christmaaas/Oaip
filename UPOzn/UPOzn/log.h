#pragma once

#include <stdio.h>
#include <time.h>

typedef enum LOG_TYPE {
	APPLICATION,
	WARNING,
	ERROR,
} LOG_TYPE;

char* log_type[];

void push_log(const char* log_variety, const char* log_info, const char* file_mode);

void push_log_for_files(const char* log_variety, const char* file_name, const char* file_mode);
#pragma once

#include <stdio.h>
#include <time.h>

typedef enum LOG_TYPE {
	APPLICATION,
	ERROR,
	MORSE
} LOG_TYPE;

char* log_type[];

void push_log(const char* log_variety, const char* log_info, const char* file_mode);
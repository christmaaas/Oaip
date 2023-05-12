#pragma once

#include <stdio.h>
#include <time.h>

typedef enum LOG_TYPE {
	APPLICATION,
	WARNING,
	ERROR,
} LOG_TYPE;

static char* log_type[] = {
	"APP",
	"WARNING",
	"ERROR"
};

void push_log(const char* log_variety, const char* log_info, const char* file_mode);
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_OF_STRING 1024
#define FILE_ERROR -3

char* input_string();

FILE* file_open(const char* file_name, const char* mode);

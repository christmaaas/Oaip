#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_ERROR -3

FILE* file_open(const char* file_name);

FILE* file_create(const char* file_name);
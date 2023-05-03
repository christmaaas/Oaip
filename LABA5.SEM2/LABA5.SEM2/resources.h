#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_STRING 256
#define FILE_ERROR -2

char* input_str();

int find_pattern(char* str, char* ptr);

int choice_domen_type();

FILE* file_open(const char* file_name);

FILE* file_open2(const char* file_name);
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_ERROR -3
#define MEMORY_ERROR -2

int error_check(errno_t err);

int if_letter(char symbol);
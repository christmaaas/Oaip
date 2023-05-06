#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_ERROR -3

typedef struct words words;

typedef struct dictionary dictionary;

typedef struct stack stack;

int error_check(errno_t err);

void puts_file(const char* str);

int if_letter(char symbol);

void output(words** array, int* size);

void dictionary_output(dictionary** array, int* size);
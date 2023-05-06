#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_BUFFER 4096

typedef struct words words;

typedef struct dictionary dictionary;

typedef struct stack stack;

int compare_sort(const void* first_pointer, const void* second_pointer);

void push_dictionary(dictionary** arr, const int* size_of_dictionary);

void archiever();
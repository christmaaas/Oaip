#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAM_ERROR 0

typedef struct Laptop Laptop;

typedef enum sort_menu {
	SORT_BY_NAME = 1,
	SORT_BY_COST,
	SORT_BY_SSD,
	SORT_BY_RAM
} sort_menu;

typedef enum sort_by_fields_menu {
	SORT_BY_ONE_FIELD = 1,
	SORT_BY_TWO_FIELDS
} sort_by_fields_menu;

void sort_one_field(Laptop** array, const int* size);

void sort_two_fields(Laptop** array, const int* size);

void sort(Laptop** array, int* size);

int symbol_check(const char* str);

void str_swap(Laptop** array, const char* str1, const char* str2, int index);

void digit_swap(Laptop** array, const int num1, const int num2, int index);
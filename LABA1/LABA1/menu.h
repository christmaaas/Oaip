#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_CODE 2
#define PROGRAMM_ERROR 0

typedef struct Laptop Laptop;

typedef enum menu_items {
	OUTPUT_ARRAY = 1,
	ADD_LAPTOP,
	DELETE_LAPTOP,
	SORT_ARRAY,
	NEW_ARRAY,
	EXIT
} menu_items;

void menu_info();

void menu(Laptop** array, int* size);
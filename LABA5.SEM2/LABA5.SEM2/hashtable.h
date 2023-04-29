#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_HASHTABLE 50000
#define EMPTY_TABLE 0

typedef struct hashtable_object {
	char* key;
	char* value;
} hashtable_object;

typedef struct hashtable {
	hashtable_object** items;
	int size;
	int count;
} hashtable;


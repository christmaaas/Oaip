#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum RAM {
	LOW = 4,
	MEDIUM = 8,
	HIGH = 16
};

typedef enum RAM ram;

typedef struct Laptop {
	char* name;
	int cost;
	int ssd_mem;
	ram ram_mem;
} Laptop;



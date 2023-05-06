#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Laptop Laptop;

void delete(Laptop** array, int* size);

void init_laptop(Laptop** array, int* size);

void init_new_array(Laptop** array, int* size);

void push_laptop_in_array(Laptop lap, Laptop** array, int* size);

Laptop* mem_for_struct_array(int size);
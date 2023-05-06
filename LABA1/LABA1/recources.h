#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_STRING 256

typedef struct Laptop Laptop;

char* input_str();

int choice_menu();

int choice_for_sort();

int choice_for_sort_menu();

int input_k_num(const int* size);

int input_cost();

int input_ssd();

int input_ram();

void output(Laptop** array, const int* size);

void output_sort_menu();

int enum_push(int num);
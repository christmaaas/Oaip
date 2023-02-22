#pragma once

#include"Func.h"

int calculate_size(Laptop** array);

void push_laptop_in_array(Laptop lap, Laptop** array, int* size);

Laptop* mem_for_struct_array(int size);

void memory_allocate(int size, char*** string);

void memory_realloc(int size, char*** string);

int find_pattern(char* str_with_ptr, char ptr[]);

int len_of_ptr(char* str_with_ptr, int* index, int shift);

int find_pattern_for_fields(char* str_with_ptr, char ptr[], int shift_for_len, int shift_for_pos);

char* take_ptr(char* buf, int pos);

char* take_ptr_cost(char* buf, int pos);

int* parse_ram(Laptop** array, FILE* file);

char** parse_name(Laptop** array, FILE* file, int* size);

int* parse_ssd(Laptop** array, FILE* file);

int* parse_cost(Laptop** array, FILE* file);

void memorystr(char** str);

void parse(Laptop** array, FILE* file, int* size);
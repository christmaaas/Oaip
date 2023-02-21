#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Struct.h"

ram enum_push(int num);

Laptop* mem_for_struct_array(int size);

void push_laptop_in_array(Laptop lap, Laptop** array, int* size);

void sort(Laptop** array, int* size);

int symbol_check(char* str);

int input_k_num(int* size);

char* input_str();

int choice_menu();

int choice_for_sort();

int choice_for_sort_menu();

int input_cost();

int input_ssd();

int input_ram();

void menu_info();

void delete(Laptop** array, int* size);

void output(Laptop** array, int* size);

void sort_one_field(Laptop** array, int* size);

void sort_two_fields(Laptop** array, int* size);

void sort(Laptop** array, int* size);

void init_new_array(Laptop** array, int* size);

void init_laptop(Laptop** array, int* size);

void menu(Laptop** array, int* size);

void str_swap(Laptop** array, const char* str1, const char* str2, int index);

void digit_swap(Laptop** array, const int num1, const int num2, int index);
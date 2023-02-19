#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Struct.h"

ram enum_push(int num);

void push_laptop_in_array(Laptop lap, Laptop** array, int* size);

void sort(Laptop** array, int* size);

void input_str(char** string);

int choice_menu(int choice);

int choice_for_sort(int choice);

int choice_for_sort_menu(int choice);

int symbol_check(char* str);

int input_k_num(int num, int* size);

int input_cost(int num);

int input_ssd(int num);

int input_ram(int num);

Laptop* mem_for_struct_array(int size);

void delete(Laptop** array, int* size);

void output(Laptop** array, int* size);

void sort_one_field(Laptop** array, int* size);

void sort_two_fields(Laptop** array, int* size);

void sort(Laptop** array, int* size);

void menu_info();

void init_new_array(Laptop** array, int* size);

void init_laptop(Laptop** array, int* size);

void menu(Laptop** array, int* size);
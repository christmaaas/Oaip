#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"bmp.h"

#define NORMAL_EXIT 2
#define ERROR_EXIT 0

char* input_file_name();

void menu_info(char* file_name);

double gamma_degree_check();

int choice_menu();

void change_bmp_file(char** file_name);

void menu(char** file_name);
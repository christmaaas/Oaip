#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_TERMINATOR '\0'
#define MAX_SIZE_OF_STRING 256
#define FILE_ERROR -2
#define PROGRAMM_ERROR -3
#define NOT_FOUNDED 0
#define WRONG_INPUT 0
#define RIGHT_IP_ADRESS 1
#define MAX_IP_COMPONENTS 4
#define MAX_IP_VALUE 255

typedef enum menu {
	SEARCH_BY_DOMEN = 1,
	SEARCH_BY_IP,
	EXIT
} menu;

FILE* file_open(const char* file_name, const char* mode);

char* input_str();

int find_pattern(char* str, char* ptr);

int valid_ip_check(char* str);

int choice_domen_type();

void menu_info();

int choice_menu();
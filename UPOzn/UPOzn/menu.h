#pragma once

#include <stdio.h>

#define PROGRAMM_ERROR -2

typedef enum MENU {
	ENCRYPT_STRING = 1,
	DECRYPT_STRING,
	ENCRYPT_FILE,
	DECRYPT_FILE,
	EXIT
} MENU;

int choice_menu();

void menu_info();

void menu();
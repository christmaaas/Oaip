#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE ' '
#define NULL_CHARACTER '\0'
#define NEWLINE '\n'
#define FIRST_ELEMENT 0
#define SIZE_OF_ALPHABET 82
#define MAX_SIZE_OF_ENCRYPTED_STRING 8
#define SIZE_OF_STRING 1024

typedef struct morse_code {
	char* code;
	char symbol;
} morse_code;

morse_code alphabet[];

typedef enum CYCLE {
	BREAK_CYCLE,
	CONTINUE_CYCLE
} CYCLE;

void morse_encrypt_user_string();

void morse_decrypt_user_string();

void print_file(const char* file_name);

void space_or_newline_check(FILE* file, char space_or_newline);

void morse_encrypt_file();

void morse_decrypt_file();
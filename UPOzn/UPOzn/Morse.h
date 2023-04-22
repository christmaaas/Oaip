#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE ' '

#define NULL_CHARACTER '\0'

#define THREE_SPACES 3

#define SIZE_OF_ALPHABET 82

typedef struct morse_code {
	char* code;
	char symbol;
} morse_code;

morse_code alphabet[];

void morse_encrypt(morse_code* table);

void morse_decrypt(morse_code* table);

void print_file(char* file_name);

char* read_file(char* file_name);

void check_for_three_spaces(char* string, int* index);

void morse_encrypt_file(morse_code* table);

void morse_decrypt_file(morse_code* table);
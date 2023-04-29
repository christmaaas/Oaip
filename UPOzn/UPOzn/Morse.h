#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SPACE ' '
#define NULL_CHARACTER '\0'
#define NEWLINE '\n'
#define FIRST_ELEMENT 0
#define HIGH_TO_LOWER 32
#define SIZE_OF_ALPHABET 56
#define SIZE_OF_LETTER_AND_NULL_CHARACTER 2
#define MAX_SIZE_OF_ENCRYPTED_STRING 8
#define SPACE_INDEX 26

typedef struct morse_code {
	char* code;
	char symbol;
} morse_code;

morse_code alphabet[];

char* string_encryptation(const char* string);

char* string_decryptation(const char* string);

char* file_encryption(const char* file_name);

char* file_decryption(const char* file_name);

void string_letters_to_lower(char** string);

void letter_to_lower(char* letter);

void morse_encrypt_string();

void morse_decrypt_string();

void print_file(const char* file_name);

void space_or_newline_check(FILE* active_file, FILE* destination_file, char space_or_newline);

void morse_encrypt_file();

void morse_decrypt_file();
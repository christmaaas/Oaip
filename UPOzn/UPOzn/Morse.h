#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct morse_code {
	char* code;
	char symbol;
} morse_code;

morse_code Table[];

void morse_encrypt(morse_code* table);

void morse_decrypt(morse_code* table);

void print_file(morse_code* table);

void morse_encrypt_file(morse_code* table);

void morse_decrypt_file(morse_code* table);
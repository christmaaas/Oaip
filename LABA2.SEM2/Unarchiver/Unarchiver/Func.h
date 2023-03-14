#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Struct.h"

int error_check(errno_t err);

void words_output(words** array, const int* size);

void push_words_in_array(words word, words** array, int* size);

int if_letter(char symbol);

int find_word(char* string, int* index);

char* take_word(char* str, int start);

char* word_from_dictionary(words** array, char* word, int* size);

void push_dictionary(words** array, char* str, int* size);

void push_word_from_dictionary(char** str, char* word, char* new_word, int* index);

void puts_file(char* str);

void unarchiver(words** array, int* size);
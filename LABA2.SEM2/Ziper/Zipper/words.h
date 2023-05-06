#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_BUFFER 4096
#define AVERAGE_SIZE_OF_BUFFER 1024
#define MAX_SIZE_OF_STRING 256
#define OPTIMAL_LENGTH_OF_SEARCH 4

typedef struct words words;

typedef struct dictionary dictionary;

typedef struct stack stack;

void push_words_in_array(words lap, words** array, int* size);

void push_dictionary_in_array(dictionary word, dictionary** array, int* size);

char* take_word_after_slash(const char* str, int index);

char* take_word_up_slash(const char* str);

char* find_word_in_dictionary(const char* str, const char* ptr_word);

int count_word(const char* str, const char* ptr, int* index);

int find_word(const char* string, int* index);

char* take_word(const char* str, int start);

void check_words(stack** head, words** array, int* size, const char* word, int counter);

void words_for_change(words** array, dictionary** arr, const int* size_of_words, int* size_of_dictionary);

void transfer_words(stack** head, words** array, int* size_of_words);

void words_for_dictionary(stack** head, words** array, dictionary** arr, int* size_of_words, int* size_of_dictionary);

char* word_from_dictionary(const char* word);

void push_word_from_dictionary(char** str, const char* word, const char* new_word, int* index);
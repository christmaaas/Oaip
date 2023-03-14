#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Struct.h"
#include"Stack.h"

int error_check(errno_t err);

void sort(words** array, const int* size);

void output(words** array, const int* size);

void dictionary_output(dictionary** array, const int* size);

void push_words_in_array(words lap, words** array, int* size);

void push_dictionary_in_array(dictionary word, dictionary** array, int* size);

char* take_word_after_slash(char* str, int index);

char* take_word_up_slash(char* str);

char* find_word_in_dictionary(char* str, char* ptr_word);

int count_word(char* str, char* ptr, int* index);

int if_letter(char symbol);

int find_word(char* string, int* index);

char* take_word(char* str, int start);

void check_words(stack** head, words** array, int* size, char* word, int counter);

void words_for_change(words** array, dictionary** arr, int* size_of_words, int* size_of_dictionary);

void words_for_dictionary(stack** head, words** array, dictionary** arr, int* size_of_words, int* size_of_dictionary);

void push_dictionary(dictionary** arr, int* size_of_dictionary);

char* word_from_dictionary(char* word);

void push_word_from_dictionary(char** str, char* word, char* new_word, int* index);

void puts_file(char* str);

void archiever();

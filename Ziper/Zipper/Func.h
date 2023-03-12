#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Struct.h"

#define ARR_SIZE(arr) (sizeof(arr)/sizeof(**arr))

void push_words_in_array(words lap, words** array, int* size);

int find_pattern(char* str, char* ptr);

int count_word(char* str, char* ptr, int* index);

int if_letter(char symbol);

int find_word(char* string, int* index);

char* take_word(char* str, int start);

void check_words(words** array, int* size, char* word, int counter);

void wordiki(words** array, zamena** arr, int* size_of_words, int* size_of_zamena);

void output(words** array, const int* size);

void sort(words** array, const int* size);

void push_slovar(zamena** arr);

void archiever();
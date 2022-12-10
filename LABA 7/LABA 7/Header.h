#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int len_string(char** string);

int max_len_word(char* string, int len_of_string, int* second_len_of_string);

void output(char* string, int max_word_start, int second_len_of_string);

void input(char** string);

int choice_fun(int choice);

int find_first_word(char** string, int len_of_string);

void back_to_menu();

void delete_word(char** string1, char** string2, int len_of_string1, int len_of_string2);

void change_to_space(char** string, int len_of_string);

int task1();

int task2();

int end();
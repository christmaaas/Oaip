#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct words words;

typedef struct dictionary dictionary;

typedef struct stack {
	char* word;
	int size;
	struct stack* next;
} stack;

void push_node(stack** head, char* word, int size);

stack* pop_node(stack** head);

void free_stack(stack** head);

char* check_stack(stack* head, const char* word, int size_of_word);
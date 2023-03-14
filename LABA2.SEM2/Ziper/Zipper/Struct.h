#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct words {
	char* word;
	int size;
} words;

typedef struct dictionary {
	char* word_for_change;
	char* word_that_change;
} dictionary;
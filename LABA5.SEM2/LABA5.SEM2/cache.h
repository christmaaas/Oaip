#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_CACHE 5

typedef struct node {
	char* key;
	char* value;
	struct node* next;
	struct node* prev;
} node;

typedef struct lru_cache {
	hashtable* table;
	node* head;
	node* tail;
	int count;
} lru_cache;


void delete_tail(node** head, node** tail);

node* create_node(char* key, char* value);

void add_to_head(node** head, node** tail, char* key, char* value);

lru_cache* create_cache(int size_of_cache);

void cache_insert(lru_cache* cache, char* key, char* value);

void free_cache(lru_cache* cache);
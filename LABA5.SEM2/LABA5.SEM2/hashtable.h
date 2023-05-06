#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_TABLE 0

typedef struct node node;

typedef struct hashtable_object {
	char* key;
	node* node;
} hashtable_object;

typedef struct list {
	hashtable_object* object;
	struct list* next;
} list;

typedef struct hashtable {
	hashtable_object** objects;
	list** chains;
	int size;
	int count;
} hashtable;

list* create_list();

list* insert_list(list* head, hashtable_object* object);

list* create_chains(hashtable* table);

hashtable_object* create_object(const char* key, node* node);

hashtable* create_table(int size_of_table);

int hash_function(const char* key);

void free_object(hashtable_object* object);

void free_hashtable(hashtable* table);

void collision_prevention(hashtable* table, int index, hashtable_object* object);

void hashtable_insert(hashtable* table, const char* key, node* node);

char* hashtable_search(hashtable* table, const char* key);

void free_list(list* head);

void free_chains(hashtable* table);

void hashtable_delete(hashtable* table, const char* key);








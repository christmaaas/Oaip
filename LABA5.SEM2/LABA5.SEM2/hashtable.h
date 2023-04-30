#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_HASHTABLE 30
#define EMPTY_TABLE 0

typedef struct hashtable_object {
	char* key;
	char* value;
} hashtable_object;

typedef struct hashtable {
	hashtable_object** objects;
	list** chains;
	int size;
	int count;
} hashtable;

typedef struct list {
	hashtable_object* object;
	list* next;
} list;

hashtable_object* create_object(char* key, char* value);

hashtable* create_table(int size_of_table);

int hash_function(char* key);

void free_object(hashtable_object* object);

void free_hashtable(hashtable* table);

void collision_prevention(hashtable* table, int index, hashtable_object* object);

void hashtable_insert(hashtable* table, char* key, char* value);

void print_search_resault(hashtable* table, char* key);

void print_hashtable(hashtable* table);

char* hashtable_search(hashtable* table, char* key);

list* create_list();

list* insert_list(list* head, hashtable_object* object);

void free_list(list* head);

list* create_chains(hashtable* table);

void free_chains(hashtable* table);








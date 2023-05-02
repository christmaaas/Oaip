#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_HASHTABLE 5
#define EMPTY_TABLE 0

typedef struct node node;

typedef struct hashtable_object
{
	char* key;
	node* head;
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

hashtable_object* create_object(char* key, node* head);

hashtable* create_table(int size_of_table);

int hash_function(char* key);

void free_object(hashtable_object* object);

void free_hashtable(hashtable* table);

void collision_prevention(hashtable* table, int index, hashtable_object* object);

void hashtable_insert(hashtable* table, char* key, node* head);

char* hashtable_search(hashtable* table, char* key);

void free_list(list* head);

void free_chains(hashtable* table);

void hashtable_delete(hashtable* table, char* key);








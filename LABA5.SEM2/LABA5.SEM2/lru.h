#pragma once

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct hashtable hashtable;

typedef struct lru_cache lru_cache;

typedef enum code {
	A = 1,
	CNAME = 2
} code;

typedef enum domen_type_length {
	IN_A = 4,
	IN_CNAME = 8
} domen_type_length;

char* valid_ip_input();

void add_database(char* domen);

int database_search(char* key, char** domain, char** ip);

char* cache_search(lru_cache* cache, char* key, int flag);



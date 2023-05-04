#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE_A_SEARCH 0
#define TYPE_CNAME_SEARCH 1
#define INDENT_FOR_NEWLINE 1
#define INDENT_FOR_SPACE 1

typedef struct hashtable hashtable;

typedef struct lru_cache lru_cache;

typedef enum code {
	TYPE_A = 1,
	TYPE_CNAME = 2
} code;

typedef enum domen_type_length {
	IN_A = 4,
	IN_CNAME = 8
} domen_type_length;

void add_database(char* domen);

int database_search(char* key, char** domain, char** ip);

char* cache_search(lru_cache* cache, char* key, int flag);

void ip_search_by_domain(lru_cache* cache);


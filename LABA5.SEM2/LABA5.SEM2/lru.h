#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORIGINAL_DOMAIN_NOT_FOUNDED 0
#define ORIGINAL_DOMAIN_FOUNDED 1
#define TYPE_A_SEARCH 0
#define TYPE_CNAME_SEARCH 1
#define INDENT_FOR_NEWLINE 1
#define INDENT_FOR_SPACE 1

#pragma warning(disable: 4996)

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

void add_database(const char* domen);

int database_search(const char* key, char** domain, char** ip);

char* cache_search(lru_cache* cache, const char* key, int flag);

void ip_search_by_domain(lru_cache* cache);

void domain_search_by_ip();


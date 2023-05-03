
#include "hashtable.h"
#include "cache.h"

void free_cache(lru_cache* cache) { 
	free_hashtable(cache->table);
	free(cache->head);
	free(cache->tail);
	free(cache);
}

void delete_tail(node** head, node** tail) {
	node* temp = (*head);
	if ((*tail) != (*head)) {
		while (temp->next != (*tail))
			temp = temp->next;
		(*tail) = temp;
		(*tail)->next = NULL;
	}
	else {
		(*tail) = NULL;
		(*head) = NULL;
	}
}

node* create_node(char* key, char* value) {
	node* temp = (node*)malloc(sizeof(node));
	temp->key = key;
	temp->value = value;
	
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

void add_to_head(node** head, node** tail, char* key, char* value) {
	node* temp = create_node(key, value);
	if ((*head) == NULL) {
		(*head) = temp;
		(*tail) = temp;
	}
	else {
		temp->next = (*head);
		(*head)->prev = temp;
		(*head) = temp;
	}
}

lru_cache* create_cache(int size_of_cache) {
	lru_cache* cache = (lru_cache*)malloc(sizeof(lru_cache));

	cache->table = create_table(SIZE_OF_CACHE);
	
	cache->head = NULL;
	cache->tail = NULL;

	cache->count = EMPTY_TABLE;

	return cache;
}

void cache_insert(lru_cache* cache, char* key, char* value) {
	if (cache->count >= SIZE_OF_CACHE) {
		hashtable_delete(cache->table, cache->tail->key);
		delete_tail(&cache->head, &cache->tail);
	}
	add_to_head(&cache->head, &cache->tail, key, value);
	hashtable_insert(cache->table, key, cache->head);
	cache->count++;
}

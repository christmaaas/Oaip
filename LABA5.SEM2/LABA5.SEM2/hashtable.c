
#include "hashtable.h"

int hash_function(char* key) {
	int accumulator = 0;
	for (int i = 0; i < strlen(key); i++) {
		accumulator += key[i];
	}
	return accumulator % SIZE_OF_HASHTABLE;
}

hashtable_object* create_object(char* key, char* value) {
	hashtable_object* object = (hashtable_object*)malloc(sizeof(hashtable_object));
	object->key = (char*)malloc(strlen(key) + 1);
	object->value = (char*)malloc(strlen(value) + 1);

	strcpy(object->key, key);
	strcpy(object->value, value);

	return object;
}

hashtable* create_table(int size_of_table) {
	hashtable* table = (hashtable*)malloc(sizeof(hashtable));
	table->size = size_of_table;
	table->count = EMPTY_TABLE;
	table->items = (hashtable**)malloc(size_of_table * sizeof(hashtable_object*));
	for (int i = 0; i < size_of_table; i++) {
		table->items[i] = NULL;
	}

}
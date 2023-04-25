
#include "hashmap.h"

int hash_function(char* key) {
	int accumulator = 0;
	for (int i = 0; i < strlen(key); i++) {
		accumulator += key[i];
	}
	return accumulator % SIZE_OF_HASHTABLE;
}

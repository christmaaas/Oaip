
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "hashtable.h"
#include "cache.h"
#include"lru.h"
#include"resources.h"

#define EXIT '0'

int main() {
	lru_cache* cache = create_cache(SIZE_OF_CACHE);
	
	char* cache_search_result = NULL;
	char* domen_name = NULL;
	
	while (true) {
		printf("\nInput a domain of enter 0 to exit: ");
			
		domen_name = input_str();ç
			
		if (domen_name[0] == EXIT)
			break;
			
		cache_search_result = cache_search(cache, domen_name, 0);
			
		if (cache_search_result != NULL)
			printf("Searched IP-adress: %s\n", cache_search_result);
	}

	free_cache(cache);

	return 0;
}
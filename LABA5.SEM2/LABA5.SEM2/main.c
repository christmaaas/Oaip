
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "hashtable.h"
#include "cache.h"
#include "lru.h"
#include "resources.h"

int main() {
	lru_cache* cache = create_cache(SIZE_OF_CACHE);
	
	int choice = 0;

	do {
		menu_info();

		choice = choice_menu();

		switch (choice) {
			case SEARCH_BY_DOMEN:
				ip_search_by_domain(cache);
				break;
			case SEARCH_BY_IP:
				//domain_search_by_ip;
				break;
			case EXIT:
				break;
			default:
				exit(PROGRAMM_ERROR);
		}
	} while (choice != EXIT);

	free_cache(cache);

	return 0;
}
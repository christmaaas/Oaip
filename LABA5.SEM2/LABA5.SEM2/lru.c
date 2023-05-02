
#include "lru.h"
#include "cache.h"
#include "hashtable.h"
#include "resources.h"

char* database_search(char* key) {
	char* buf1 = (char*)malloc(MAX_SIZE_OF_STRING);
	char* buf2 = (char*)malloc(MAX_SIZE_OF_STRING);

	int index = 0;

	FILE* file = file_open("database.txt");

	fgets(buf1, MAX_SIZE_OF_STRING, file);
	while (!feof(file)) {
		index = find_pattern(buf1, "IN A");
		buf2 = // сюда придет индекс с которого начинается айпи адрес и считать с этого индекса айпи адрес
		//return buf2;
		//fgets
	}

}

char* cache_search(hashtable* table, char* key) {
	char* search_result = hashtable_search(table, key);

	if (search_result != NULL) {
		printf("\nHIT\n");
		return search_result;
	}
	else {
		printf("\nMISS\n");
		//функция поиска по файлу
	}
}

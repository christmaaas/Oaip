
#include <stdio.h>
#include <string.h>

#include "hashtable.h"
#include "cache.h"

int main() {
	/*hashtable* table = create_table(SIZE_OF_HASHTABLE);

	hashtable_insert(table, "Artem", "+375-29-320-47-40");
	hashtable_insert(table, "Artem", "+375-33-212-13-22");
	hashtable_insert(table, "Atrem", "+375-33-212-13-22");
	hashtable_insert(table, "Armet", "+375-33-212-11-45");
	hashtable_insert(table, "Capitan Burmalda", "+375-44-777-66-55");
	hashtable_insert(table, "Geo", "+375-29-123-33-12");

	print_hashtable(table);

	hashtable_delete(table, "Atrem");

	print_hashtable(table);

	free_hashtable(table);*/

	lru_cache* cache = create_cache(SIZE_OF_CACHE);
	
	char* buf1 = (char*)malloc(100);
	char* buf2 = (char*)malloc(100);
	char* buf3 = (char*)malloc(100);
	char* buf4 = (char*)malloc(100);
	char* buf5 = (char*)malloc(100);
	char* buf6 = (char*)malloc(100);
	char* buf7 = (char*)malloc(100);
	char* buf8 = (char*)malloc(100);
	char* buf9 = (char*)malloc(100);
	char* buf10 = (char*)malloc(100);
	char* buf11 = (char*)malloc(100);
	char* buf12 = (char*)malloc(100);
	char* buf13 = (char*)malloc(100);
	char* buf14 = (char*)malloc(100);
	char* buf15 = (char*)malloc(100);
	char* buf16 = (char*)malloc(100);
	char* buf17 = (char*)malloc(100);
	char* buf18 = (char*)malloc(100);
	char* buf19 = (char*)malloc(100);
	char* buf20 = (char*)malloc(100);
	gets_s(buf1, 100);
	gets_s(buf2, 100);
	gets_s(buf3, 100);
	gets_s(buf4, 100);
	gets_s(buf5, 100);
	gets_s(buf6, 100);
	gets_s(buf7, 100);
	gets_s(buf8, 100);
	gets_s(buf9, 100);
	gets_s(buf10, 100);
	gets_s(buf11, 100);
	gets_s(buf12, 100);
	gets_s(buf13, 100);
	gets_s(buf14, 100);
	gets_s(buf15, 100);
	gets_s(buf16, 100);



	cache_insert(cache, buf1, buf9);
	cache_insert(cache, buf2, buf10);
	cache_insert(cache, buf3, buf11);
	cache_insert(cache, buf4, buf12);
	cache_insert(cache, buf5, buf13);
	cache_insert(cache, buf6, buf14);
	cache_insert(cache, buf7, buf15);
	cache_insert(cache, buf8, buf16);

	free_cache(cache);

	return 0;
}
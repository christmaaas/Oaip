
#include <stdio.h>

#include "hashtable.h"

int main() {
	hashtable* table = create_table(SIZE_OF_HASHTABLE);

	hashtable_insert(table, "Artem", "+375-29-320-47-40");
	hashtable_insert(table, "Atrem", "+375-33-212-13-22");
	hashtable_insert(table, "Armet", "+375-33-212-11-45");
	hashtable_insert(table, "Capitan Burmalda", "+375-44-777-66-55");
	hashtable_insert(table, "Geo", "+375-29-123-33-12");

	print_hashtable(table);

	hashtable_delete(table, "Atrem");

	print_hashtable(table);

	free_hashtable(table);
	return 0;
}
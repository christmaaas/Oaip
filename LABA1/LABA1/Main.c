#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Parse.h"
#include"Func.h"
#include"Struct.h"


int main() {
	Laptop* array = NULL;
	int size = 0, size_for_parse = 0;;
	size_for_parse = calculate_size(&array);
	array = mem_for_struct_array(size_for_parse);
	menu(&array, &size);
	free(array);
	return 0;
}


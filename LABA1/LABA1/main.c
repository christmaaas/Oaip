#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "struct.h"
#include "recources.h"
#include "array.h"
#include "sort.h"

int main() {
	Laptop* array = NULL;
	
	int size = 0;
	
	menu(&array, &size);
	
	free(array);
	
	return 0;
}


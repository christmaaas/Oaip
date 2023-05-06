#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resources.h"
#include "decompress.h"
#include "struct.h"

int main() {
	words* arr = NULL;
	
	int size = 0;
	
	unarchiver(&arr, &size);
	
	free(arr);
	
	return 0;
}
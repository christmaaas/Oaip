
#include "resources.h"

char* input_str() {
	char* string = (char*)calloc(MAX_SIZE_OF_STRING, sizeof(char));

	gets_s(string, MAX_SIZE_OF_STRING);

	int size = strlen(string);

	string = (char*)realloc(string, size + 1);

	return string;
}

int find_pattern(char* str, char* ptr) {
	int i, j, k;
	for (i = 0; str[i] != '\0'; i++) {
		for (j = i, k = 0; ptr[k] != '\0' && str[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0') {
			return j;
		}
	}
	return 0;
}

FILE* file_open(const char* file_name) {
	FILE* file = NULL;
	errno_t error;
	
	error = fopen_s(&file, file_name, "r");
	
	if (error != 0) {
		exit(FILE_ERROR);
	}
	
	return file;
}
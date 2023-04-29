
#include "resources.h"

char* input_string() {
	char* string = (char*)malloc(MAX_SIZE_OF_STRING);
	gets_s(string, MAX_SIZE_OF_STRING);
	int size = strlen(string);
	string = (char*)realloc(string, size + 1);
	
	return string;
}

FILE* file_open(const char* file_name, const char* mode) {
	FILE* file = NULL;
	errno_t error;

	error = fopen_s(&file, file_name, mode);

	if (error != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}

	return file;
}

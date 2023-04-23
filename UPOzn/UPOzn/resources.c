
#include "resources.h"

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
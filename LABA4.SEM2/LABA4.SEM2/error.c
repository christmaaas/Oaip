#include"error.h"

FILE* file_create(const char* file_name) {
	FILE* file = NULL;
	errno_t error;
	error = fopen_s(&file, file_name, "w");
	if (error != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}
	return file;
}

FILE* file_open(const char* file_name) {
	FILE* file = NULL;
	errno_t error;
	error = fopen_s(&file, file_name, "r");
	if (error != 0) {
		return NULL;
	}
	return file;
}
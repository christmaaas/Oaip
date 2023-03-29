#include"error.h"

FILE* file_open(char* file_name) {
	FILE* bmp_file = NULL;
	errno_t error;
	error = fopen_s(&bmp_file, file_name, "rb");
	if (error != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}
	return bmp_file;
}

FILE* new_file_open(char* file_name) {
	FILE* bmp_file = NULL;
	errno_t error;
	error = fopen_s(&bmp_file, file_name, "wb");
	if (error != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}
	return bmp_file;
}
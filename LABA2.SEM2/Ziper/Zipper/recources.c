#include "recources.h"
#include "struct.h"

int error_check(errno_t err) {
	if (err != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}
	return 1;
}

void puts_file(const char* str) {
	FILE* file = NULL;
	errno_t err;

	err = fopen_s(&file, "D:/Zipfiles/Archive.txt", "a");
	error_check(err);

	fputs(str, file);

	fclose(file);
}

int if_letter(char symbol) {
	if (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z') return 1;
	return 0;
}

void output(words** array, int* size) {
	for (int i = 0; i < (*size); i++) {
		printf("----------------------\n");
		printf("Word: %s\n", (*array)[i].word);
		printf("Size: %d\n", (*array)[i].size);
		printf("----------------------\n");
	}
}

void dictionary_output(dictionary** array, const int* size) {
	for (int i = 0; i < (*size); i++) {
		printf("----------------------\n");
		printf("Word1: %s\n", (*array)[i].word_for_change);
		printf("Word2: %s\n", (*array)[i].word_that_change);
		printf("----------------------\n");
	}
}
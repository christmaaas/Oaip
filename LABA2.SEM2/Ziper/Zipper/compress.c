#include "compress.h"
#include "struct.h"
#include "recources.h"
#include "words.h"

int compare_sort(const void* first_pointer, const void* second_pointer) {
	const words* first_word = (const words*)first_pointer;
	const words* second_word = (const words*)second_pointer;
	
	if ((*first_word).size > (*second_word).size) {
		return 1;
	}
	else if ((*first_word).size < (*second_word).size) {
		return -1;
	}
	
	return 0;
}

void push_dictionary(dictionary** arr, const int* size_of_dictionary) {
	FILE* file = NULL;
	errno_t err;

	err = fopen_s(&file, "D:/Zipfiles/Archive.txt", "w");
	error_check(err);

	for (int i = 0; i < (*size_of_dictionary); i++) {
		fprintf(file, "%s", (*arr)[i].word_for_change);
		fprintf(file, "%c", '/');
		fprintf(file, "%s\n", (*arr)[i].word_that_change);
	}
	fprintf(file, "%c\n", '$');

	fclose(file);
}

void archiever() {
	FILE* file = NULL;
	errno_t err;
	
	char* word = NULL;
	char* new_word = NULL;
	char* buf = (char*)malloc(MAX_SIZE_OF_BUFFER);
	
	int index = 0;
	int start = 0;

	err = fopen_s(&file, "D:/Zipfiles/Zip.txt", "r");
	error_check(err);

	fgets(buf, MAX_SIZE_OF_BUFFER, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			
			word = take_word(buf, start);
			
			new_word = word_from_dictionary(word);
			
			push_word_from_dictionary(&buf, word, new_word, &index);
			
			index++;
		}
		
		puts_file(buf);
		
		index = 0;
		
		fgets(buf, MAX_SIZE_OF_BUFFER, file);
	}

	fclose(file);
	
	printf("\nFile was archived\n");
	
	free(buf);
	free(word);
	free(new_word);
}
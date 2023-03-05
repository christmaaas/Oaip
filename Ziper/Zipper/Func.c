#include"Func.h"

void sort(words** array, const int* size) {
	words buf;
	for (int i = 0; i < (*size) - 1; i++) {
		for (int j = 0; j < (*size) - 1; j++) {
			if (((*array)[j].size > (*array)[j + 1].size)) {
				buf = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = buf;
			}
		}
	}
}

void output(words** array, const int* size) {
	for (int i = 0; i < (*size); i++) {
		printf("----------------------\n");
		printf("Word: %s\n", (*array)[i].word);
		printf("Size: %d\n", (*array)[i].size);
		printf("----------------------\n");
	}
}

void push_words_in_array(words lap, words** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (words*)malloc((*size) * sizeof(lap));
	}
	else {
		(*array) = (words*)realloc((*array), (*size) * sizeof(lap));
	}
	(*array)[(*size) - 1] = lap;
}
//str[j + 1] == '.' || str[j + 1] == ',' || str[j + 1] == ':' || str[j + 1] == ';'
int find_pattern(char* str, char* ptr, int* index) {
	int i = (*index) + strlen(ptr), j, k, counter = 0;
	for (; str[i] != '\0'; i++) {
		for (j = i, k = 0; ptr[k] != '\0' && str[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0' && (str[i - 1] == ' ' || str[i] == str[0]) && str[j + 1] == ' ') {
			counter++;
		}
	}
	if (counter != 0) {
		return counter;
	}
	return 0;
}

int if_letter(char symbol) {
	if (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z') return 1;
	return 0;
}

int find_word(char* string, int* index) {
	while (string[(*index)] != '\0') {
		if ((*index) == 0 && if_letter(string[(*index)]) != 0 || if_letter(string[(*index) - 1]) == 0 && if_letter(string[(*index)]) != 0) {
			return (*index);
		}
		(*index)++;
	}
	return -1;
}

char* take_word(char* str, int start) {
	int index = 0;
	char* buf = (char*)calloc(256, 1);
	while (str[start] != ' ' && str[start] != '\0' && str[start] != '\n' && str[start] != ',' && str[start] != ':' && str[start] != ';' && str[start] != '.') {
		buf[index] = str[start];
		start++;
		index++;
	}
	buf = (char*)realloc(buf, strlen(buf) + 1);
	return buf;
}

void check_words(words** array, int* size, char* word, int counter) {
	words buf;
	int size_of_word = 0;
	if (strlen(word) >= 2) {
		if (counter == 0) {
			size_of_word = strlen(word);
		}
		else {
			size_of_word = counter * strlen(word);
		}
		for (int i = 0; i < (*size); i++) {
			if (!strcmp(word, (*array)[i].word)) {
				(*array)[i].size += size_of_word;
				return;
			}
		}
		buf.word = word;
		buf.size = size_of_word;
		push_words_in_array(buf, array, size);
	}
	else {
		return;
	}
}

void wordiki(words** array, int* size) {
	FILE* file = NULL;
	char* buf = (char*)calloc(1024, 1);
	char* word = (char*)calloc(1024, 1);
	int index = 0, start = 0, counter = 0;

	fopen_s(&file, "Zip.txt", "r");

	fgets(buf, 1024, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			word = take_word(buf, start);
			counter = find_pattern(buf, word, &index);
			check_words(array, size, word, counter);
			index++;
		}
		index = 0;
		fgets(buf, 1024, file);
	}

	fclose(file);

	free(buf);
	free(word);
	sort(array, size);
	output(array, size);
}
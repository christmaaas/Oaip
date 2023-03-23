#include"Func.h"

#define FILE_ERROR -3
#define MEMORY_ERROR -2

int error_check(errno_t err) {
	if (err != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}
	return 1;
}

void words_output(words** array, int* size) {
	for (int i = 0; i < (*size); i++) {
		printf("----------------------\n");
		printf("Word1: %s\n", (*array)[i].word_for_change);
		printf("Word2: %s\n", (*array)[i].word_that_change);
		printf("----------------------\n");
	}
}

void push_words_in_array(words word, words** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (words*)malloc((*size) * sizeof(word));
	}
	else {
		(*array) = (words*)realloc((*array), (*size) * sizeof(word));
	}
	(*array)[(*size) - 1] = word;
}

int if_letter(char symbol) {
	if (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z') return 1;
	return 0;
}

int find_word(const char* string, int* index) {
	while (string[(*index)] != '\0') {
		if ((*index) == 0) {
			if (if_letter(string[(*index)]) != 0) {
				return (*index);
			}
		}
		else if ((*index) > 0) {
			if (string[(*index) - 1] != '-' && if_letter(string[(*index) - 1]) == 0 && if_letter(string[(*index)]) != 0) {
				return (*index);
			}
		}
		(*index)++;
	}
	return -1;
}

char* take_word(const char* str, int start) {
	int index = 0;
	char* buf = (char*)calloc(256, 1);
	while (str[start] != ' ' && str[start] != '\0' && str[start] != '\n' && str[start] != ',' && str[start] != ':' && str[start] != ';' && str[start] != '.' && str[start] != '\"' && str[start] != '!' && str[start] != '?' && str[start] != ')') {
		buf[index] = str[start];
		start++;
		index++;
	}
	buf = (char*)realloc(buf, strlen(buf) + 1);
	if (buf == NULL) {
		exit(MEMORY_ERROR);
	}
	return buf;
}

char* word_from_dictionary(words** array, const char* word, const int* size) {
	char* new_word = NULL;
	for (int i = 0; i < (*size); i++) {
		if (!strcmp(word, (*array)[i].word_for_change)) {
			new_word = (*array)[i].word_that_change;
			break;
		}
		if (!strcmp(word, (*array)[i].word_that_change)) {
			new_word = (*array)[i].word_for_change;
			break;
		}
	}
	return new_word;
}

void push_dictionary(words** array, const char* str, int* size) {
	words word;
	char* word1 = (char*)calloc(256, 1);
	char* word2 = (char*)calloc(256, 1);
	int i = 0;
	int j = 0;
	while (str[i] != '/') {
		word1[i] = str[i];
		i++;
	}
	i++;
	while (str[i] != '\n') {
		word2[j] = str[i];
		i++;
		j++;
	}
	word1 = (char*)realloc(word1, (strlen(word1) + 1));
	word2 = (char*)realloc(word2, (strlen(word2) + 1));
	word.word_for_change = word1;
	word.word_that_change = word2;
	push_words_in_array(word, array, size);
}

void push_word_from_dictionary(char** str, const char* word, const char* new_word, int* index) {
	if (new_word == NULL) {
		return;
	}
	int diff = strlen(word) - strlen(new_word); 
	int count = 0; 
	int start = (*index); 
	int second_start = 0;
	if (diff > 0) {
		while (count != strlen(new_word)) {
			(*str)[start] = new_word[count];
			start++;
			count++;
		}
		second_start = start;
		for (int i = 0; i < diff; i++) {
			while ((*str)[start] != '\0') {
				(*str)[start] = (*str)[start + 1];
				start++;
			}
			start = second_start;
		}
		(*index) += strlen(new_word) - 1;
	}
	else {
		diff = strlen(new_word) - strlen(word);
		start = (strlen((*str)) + 1);
		for (int i = 0; i < diff; i++) {
			while (start != (*index)) {
				(*str)[start] = (*str)[start - 1];
				start--;
			}
			start = strlen((*str)) + 1;
		}
		start = (*index);
		while (count != strlen(new_word)) {
			(*str)[start] = new_word[count];
			start++;
			count++;
		}
		(*index) += strlen(new_word) - 1;
	}
}

void puts_file(const char* str) {
	FILE* file = NULL;
	errno_t err;

	err = fopen_s(&file, "D:/Zipfiles/Unarchived.txt", "a");
	error_check(err);

	fputs(str, file);

	fclose(file);
}

void unarchiver(words** array, int* size) {
	FILE* file = NULL;
	errno_t err;
	char* buf = (char*)calloc(4096, 1);
	char* word = NULL;
	char* new_word = NULL;
	int index = 0; 
	int start = 0;

	err = fopen_s(&file, "D:/Zipfiles/Archive.txt", "r");
	error_check(err);

	fgets(buf, 4096, file);
	while (buf[0] != '$') {
		push_dictionary(array, buf, size);
		fgets(buf, 4096, file);
	}
	fgets(buf, 4096, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			word = take_word(buf, start);
			new_word = word_from_dictionary(array, word, size);
			push_word_from_dictionary(&buf, word, new_word, &index);
			index++;
		}
		puts_file(buf);
		index = 0;
		fgets(buf, 4096, file);
	}
	
	fclose(file);
	printf("\nFile was archived\n");
	free(buf);
	free(word);
	free(new_word);
}
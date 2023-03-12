#include"Func.h"

void sort(words** array, const int* size) {
	words buf;
	for (int i = 0; i < (*size) - 1; i++) {
		for (int j = 0; j < (*size) - 1; j++) {
			if ((*array)[j].size > (*array)[j + 1].size) {
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

void zamena_output(zamena** array, const int* size) {
	for (int i = 0; i < (*size); i++) {
		printf("----------------------\n");
		printf("Word1: %s\n", (*array)[i].word_for_change);
		printf("Word2: %s\n", (*array)[i].word_that_change);
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

void push_zamena_in_array(zamena lap, zamena** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (zamena*)malloc((*size) * sizeof(lap));
	}
	else {
		(*array) = (zamena*)realloc((*array), (*size) * sizeof(lap));
	}
	(*array)[(*size) - 1] = lap;
}

char* take_word_after_slash(char* str, int index) {
	char* word = (char*)calloc(256, 1);
	int count = 0;
	while (str[index] != '\n') {
		word[count] = str[index];
		index++;
		count++;
	}
	word = (char*)realloc(word, (strlen(word) + 1));
	return word;
}

char* take_word_up_slash(char* str) {
	char* word = (char*)calloc(256, 1);
	int count = 0;
	while (str[count] != '/') {
		word[count] = str[count];
		count++;
	}
	word = (char*)realloc(word, (strlen(word) + 1));
	return word;
}

char* find_word_in_slovar(char* str, char* ptr_word) {
	int i, j, k;
	char* word = NULL;
	for (i = 0; str[i] != '\0'; i++) {
		for (j = i, k = 0; ptr_word[k] != '\0' && str[j] == ptr_word[k]; j++, k++)
			;
		if (ptr_word[k] == '\0' && ((str[i] == str[0] && str[j] == '/') || (str[i - 1] == '/' && str[j] == '\n'))) {
			if (str[i] == str[0] && str[j] == '/') {
				word = take_word_after_slash(str, (j + 1));
				break;
			}
			else {
				word = take_word_up_slash(str);
				break;
			}
		}
	}
	return word;
}

int count_word(char* str, char* ptr, int* index) {
	int i = (*index) + strlen(ptr), j, k, counter = 0;
	for (int t = 0; t < (*index); t++) {
		for (j = t, k = 0; ptr[k] != '\0' && str[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0' && (str[t - 1] == ' ' || str[t - 1] == '\"' || str[t - 1] == '\'' || str[t] == str[0]) && str[j + 1] == ' ') {
			return -1;
		}
	}
	for (; str[i] != '\0'; i++) {
		for (j = i, k = 0; ptr[k] != '\0' && str[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0' && (str[i - 1] == ' ' || str[i - 1] == '\"' || str[i - 1] == '\'' || str[i] == str[0]) && str[j + 1] == ' ') {
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
	while (str[start] != ' ' && str[start] != '\0' && str[start] != '\n' && str[start] != ',' && str[start] != ':' && str[start] != ';' && str[start] != '.' && str[start] != '\"' && str[start] != '\'' && str[start] != '!' && str[start] != '?') {
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
		else if (counter == -1) {
			size_of_word = 0;
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
		if (counter == -1) {
			buf.word = word;
			buf.size = strlen(word);
			push_words_in_array(buf, array, size);
		}
		else {
			buf.word = word;
			buf.size = size_of_word;
			push_words_in_array(buf, array, size);
		}
	}
	else {
		return;
	}
}

void words_for_change(words** array, zamena** arr, int* size_of_zamena) {
	zamena word;
	int start = 37721;
	int end = 0;
	while (strlen((*array)[end].word) <= 4) {
		while (strlen((*array)[start].word) > strlen((*array)[end].word)) {
			if ((*array)[start].size > (*array)[end].size) {
				word.word_for_change = (*array)[start].word;
				word.word_that_change = (*array)[end].word;
				push_zamena_in_array(word, arr, size_of_zamena);
				start--;
				end++;
			}
		}
		if (strlen((*array)[start].word) <= strlen((*array)[end].word)) {
			start--;
		}
	}
	zamena_output(arr, size_of_zamena);
}

void wordiki(words** array, zamena** arr, int* size_of_words, int* size_of_zamena) {
	FILE* file = NULL;
	char* buf = (char*)calloc(1024, 1);
	char* word = (char*)calloc(1024, 1);
	char* buf1 = NULL;
	int index = 0, start = 0, counter = 0;

	fopen_s(&file, "Zip.txt", "r");

	fgets(buf, 1024, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			word = take_word(buf, start);
			counter = count_word(buf, word, &index);
			check_words(array, size_of_words, word, counter);
			index++;
		}
		index = 0;
		fgets(buf, 1024, file);
	}
	fclose(file);

	free(buf);
	free(word);
	sort(array, size_of_words);
	output(array, size_of_words);
	words_for_change(array, arr, size_of_zamena);
}

void push_slovar(zamena** arr) {
	FILE* file = NULL;

	fopen_s(&file, "Archive.txt", "w");

	for (int i = 0; i < 1177; i++) {
		fprintf(file, "%s", (*arr)[i].word_for_change);
		fprintf(file, "%c", '/');
		fprintf(file, "%s\n", (*arr)[i].word_that_change);
	}
	fprintf(file, "%c", '$');
	fclose(file);
}

char* word_to_zamena(char* word) {
	FILE* file = NULL;
	char* buf = (char*)calloc(1024, 1);
	char* new_word = NULL;
	int count = 0;

	fopen_s(&file, "Archive.txt", "r");

	fgets(buf, 1024, file);
	while (buf[0] != '$') {
		if ((new_word = find_word_in_slovar(buf, word)) != NULL) {
			break;
		}
		fgets(buf, 1024, file);
	}

	fclose(file);

	free(buf);
	return new_word;
}

void perepis_file(char** str, char* word, char* new_word, int* index) {
	if (new_word == NULL) {
		return;
	}
	int diff = strlen(word) - strlen(new_word), count = 0, start = (*index), second_start = 0;
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
		(*index) += strlen(word) - 1;
		//(*str) = (char*)realloc((*str), strlen((*str)) - 1);
	}
	else {
		diff = strlen(new_word) - strlen(word);
		//(*str) = (char*)realloc((*str), (strlen((*str)) + diff));
		start = strlen((*str));
		for (int i = 0; i < diff; i++) {
			while (start != (*index)) {
				(*str)[start] = (*str)[start - 1];
				start--;
			}
			start = strlen((*str));
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

void puts_file(char* str) {
	FILE* file = NULL;

	fopen_s(&file, "Archive.txt", "a");

	fputs(str, file);

	fclose(file);
}

void archiever() {
	FILE* file = NULL;
	char* buf = (char*)calloc(2048, 1);
	char* word = (char*)calloc(256, 1);
	char* new_word = NULL;
	int index = 0, start = 0;

	fopen_s(&file, "Zip.txt", "r");

	fgets(buf, 2048, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			word = take_word(buf, start);
			new_word = word_to_zamena(word);
			perepis_file(&buf, word, new_word, &index);
			index++;
		}
		puts_file(buf);
		//printf("\n%s\n", buf);
		index = 0;
		fgets(buf, 2048, file);
	}
	fclose(file);
}
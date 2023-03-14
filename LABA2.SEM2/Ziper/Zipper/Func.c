#include"Func.h"

#define FILE_ERROR -3

int error_check(errno_t err) {
	if (err != 0) {
		printf("\nFile open error\n");
		exit(FILE_ERROR);
	}
	return 1;
}

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

void output(words** array, int* size) {
	for (int i = 0; i < (*size); i++) {
		printf("----------------------\n");
		printf("Word: %s\n", (*array)[i].word);
		printf("Size: %d\n", (*array)[i].size);
		printf("----------------------\n");
	}
}

void dictionary_output(dictionary** array, int* size) {
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

void push_dictionary_in_array(dictionary word, dictionary** array, int* size) {
	(*size)++;
	if ((*array) == NULL) {
		(*array) = (dictionary*)malloc((*size) * sizeof(word));
	}
	else {
		(*array) = (dictionary*)realloc((*array), (*size) * sizeof(word));
	}
	(*array)[(*size) - 1] = word;
}

char* take_word_after_slash(const char* str, int index) {
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

char* take_word_up_slash(const char* str) {
	char* word = (char*)calloc(256, 1);
	int count = 0;
	while (str[count] != '/') {
		word[count] = str[count];
		count++;
	}
	word = (char*)realloc(word, (strlen(word) + 1));
	return word;
}

char* find_word_in_dictionary(const char* str, const char* ptr_word) {
	int i = 0;
	int j = 0;
	int k = 0;
	char* word = NULL;
	for (i = 0; str[i] != '\0'; i++) {
		for (j = i, k = 0; ptr_word[k] != '\0' && str[j] == ptr_word[k]; j++, k++)
			;
		if (ptr_word[k] == '\0' && ((i == 0 && str[j] == '/') || (str[i - 1] == '/' && str[j] == '\n'))) {
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

int count_word(const char* str, const char* ptr, int* index) {
	int i = 0;
	int j = 0;
	int k = 0; 
	int counter = 0; 
	int start = (*index) + strlen(ptr);
	for (i = 0; i < (*index); i++) {
		for (j = i, k = 0; ptr[k] != '\0' && str[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0' && (str[i - 1] == ' ' || str[i - 1] == '\"' || str[i - 1] == '\''  || str[i] == str[0]) && str[j + 1] == ' ') {
			return -1;
		}
	}
	for (i = start; str[i] != '\0'; i++) {
		for (j = i, k = 0; ptr[k] != '\0' && str[j] == ptr[k]; j++, k++)
			;
		if (ptr[k] == '\0' && (str[i - 1] == ' ' || str[i - 1] == '\"' || str[i - 1] == '\''  || str[i] == str[0]) && str[j + 1] == ' ') {
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

int find_word(const char* string, int* index) {
	while (string[(*index)] != '\0') {
		if ((*index) == 0 && if_letter(string[(*index)]) != 0 || string[(*index) - 1] != '-' && if_letter(string[(*index) - 1]) == 0 && if_letter(string[(*index)]) != 0) {
			return (*index);
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
	return buf;
}

char* check_stack(stack* head, const char* word, int size_of_word) {
	stack* p = head;
	while (p) {
		if (!strcmp(word, p->word)) {
			p->size += size_of_word;
			return head;
		}
		p = p->next;
	}
	return NULL;
}

void check_words(stack** head, words** array, int* size, const char* word, int counter) {
	char* check = NULL;
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
		if ((check = check_stack((*head), word, size_of_word)) != NULL) {
			(*head) = check;
			return;
		}
		if (counter == -1) {
			push_node(head, word, strlen(word));
		}
		else {
			push_node(head, word, size_of_word);
		}
	}
	else {
		return;
	}
}

void words_for_change(words** array, dictionary** arr, const int* size_of_words, int* size_of_dictionary) {
	dictionary word;
	int start = ((*size_of_words) - 1);               
	int end = 0;
	while (strlen((*array)[end].word) <= 4) {
		if (strlen((*array)[start].word) > strlen((*array)[end].word) && (*array)[start].size > (*array)[end].size) {
			word.word_for_change = (*array)[start].word;
			word.word_that_change = (*array)[end].word;
			push_dictionary_in_array(word, arr, size_of_dictionary);
			start--;
			end++;
		}
		if (strlen((*array)[start].word) <= strlen((*array)[end].word)) {
			start--;
		}
	}
	dictionary_output(arr, size_of_dictionary);
}

void transfer_words(stack** head, words** array, int* size_of_words) {
	words buf;
	while (*head) {
		buf.word = (*head)->word;
		buf.size = (*head)->size;
		push_words_in_array(buf, array, size_of_words);
		(*head) = (*head)->next;
	}
}

void words_for_dictionary(stack** head, words** array, dictionary** arr, int* size_of_words, int* size_of_dictionary) {
	FILE* file = NULL;
	errno_t err;
	char* word = NULL;
	char* buf = (char*)calloc(4096, 1);
	int index = 0;
	int start = 0; 
	int counter = 0;

	err = fopen_s(&file, "D:/Zipfiles/Zip.txt", "r");
	error_check(err);

	fgets(buf, 4096, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			word = take_word(buf, start);
			counter = count_word(buf, word, &index);
			check_words(head, array, size_of_words, word, counter);
			index++;
		}
		index = 0;
		fgets(buf, 4096, file);
	}
	
	fclose(file);

	free(buf);
	free(word);
	transfer_words(head, array, size_of_words);
	qsort((*array), (*size_of_words), sizeof(words), compare_sort);
	output(array, size_of_words);
	words_for_change(array, arr, size_of_words, size_of_dictionary);
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

char* word_from_dictionary(const char* word) {
	FILE* file = NULL;
	errno_t err;
	char* buf = (char*)calloc(1024, 1);
	char* new_word = NULL;
	int count = 0;

	err = fopen_s(&file, "D:/Zipfiles/Archive.txt", "r");
	error_check(err);

	fgets(buf, 1024, file);
	while (buf[0] != '$') {
		if ((new_word = find_word_in_dictionary(buf, word)) != NULL) {
			break;
		}
		fgets(buf, 1024, file);
	}
	
	fclose(file);

	free(buf);
	return new_word;
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

	err = fopen_s(&file, "D:/Zipfiles/Archive.txt", "a");
	error_check(err);

	fputs(str, file);

	fclose(file);
}

void archiever() {
	FILE* file = NULL;
	errno_t err;
	char* word = NULL;
	char* new_word = NULL;
	char* buf = (char*)calloc(4096, 1);
	int index = 0; 
	int start = 0;

	err = fopen_s(&file, "D:/Zipfiles/Zip.txt", "r");
	error_check(err);

	fgets(buf, 4096, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {
			word = take_word(buf, start);
			new_word = word_from_dictionary(word);
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
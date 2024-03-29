#include "words.h"
#include "struct.h"
#include "stack.h"
#include "recources.h"
#include "compress.h"

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
	char* word = (char*)calloc(MAX_SIZE_OF_STRING, 1);

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
	char* word = (char*)calloc(MAX_SIZE_OF_STRING, 1);

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
		if (ptr_word[k] == '\0' && ((i == 0 && str[j] == '/') || (str[i] == '/' && str[j] == '\n'))) { // str[i - 1]
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
		if (ptr[k] == '\0' && (str[i] == ' ' || str[i - 1] == '\"' || str[i - 1] == '\'' || str[i] == str[0]) && str[j + 1] == ' ') { // str[i - 1]
			return -1;
		}
	}
	for (i = start; str[i] != '\0'; i++) {
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

int find_word(const char* string, int* index) {
	while (string[(*index)] != '\0') {
		if ((*index) == 0 && if_letter(string[(*index)]) != 0 || string[(*index)] != '-' && if_letter(string[(*index)]) == 0 && if_letter(string[(*index)]) != 0) {
			return (*index);
		}
		(*index)++;
	}
	return -1;
}

char* take_word(const char* str, int start) {
	int index = 0;

	char* buf = (char*)calloc(MAX_SIZE_OF_STRING, 1);

	while (str[start] != ' ' && str[start] != '\0' && str[start] != '\n' && str[start] != ',' && str[start] != ':' && str[start] != ';' && str[start] != '.' && str[start] != '\"' && str[start] != '!' && str[start] != '?' && str[start] != ')') {
		buf[index] = str[start];
		start++;
		index++;
	}

	buf = (char*)realloc(buf, strlen(buf) + 1);

	return buf;
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

	while (strlen((*array)[end].word) <= OPTIMAL_LENGTH_OF_SEARCH) {
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
	char* buf = (char*)calloc(MAX_SIZE_OF_BUFFER, 1);

	int index = 0;
	int start = 0;
	int counter = 0;

	err = fopen_s(&file, "D:/Zipfiles/Zip.txt", "r");
	error_check(err);

	fgets(buf, MAX_SIZE_OF_BUFFER, file);
	while (!feof(file)) {
		while ((start = find_word(buf, &index)) != -1) {

			word = take_word(buf, start);

			if (word != NULL) {
				counter = count_word(buf, word, &index);
			}

			if (word != NULL) {
				check_words(head, array, size_of_words, word, counter);
			}

			index++;
		}
		index = 0;
		fgets(buf, MAX_SIZE_OF_BUFFER, file);
	}

	fclose(file);

	free(buf);
	free(word);

	transfer_words(head, array, size_of_words);

	qsort((*array), (*size_of_words), sizeof(words), compare_sort);

	output(array, size_of_words);

	words_for_change(array, arr, size_of_words, size_of_dictionary);
}

char* word_from_dictionary(const char* word) {
	FILE* file = NULL;
	errno_t err;
	char* buf = (char*)calloc(AVERAGE_SIZE_OF_BUFFER, 1);
	char* new_word = NULL;
	int count = 0;

	err = fopen_s(&file, "D:/Zipfiles/Archive.txt", "r");
	error_check(err);

	fgets(buf, AVERAGE_SIZE_OF_BUFFER, file);
	while (buf[0] != '$') {
		if ((new_word = find_word_in_dictionary(buf, word)) != NULL) {
			break;
		}
		fgets(buf, AVERAGE_SIZE_OF_BUFFER, file);
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
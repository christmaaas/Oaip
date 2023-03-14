#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Func.h"
#include"Struct.h"
#include"Stack.h"

int main() {
	stack* head = NULL;
	words* array = NULL;
	dictionary* arr = NULL;
	int size_of_words = 0;
	int size_of_dictionary = 0;
	words_for_dictionary(&head, &array, &arr, &size_of_words, &size_of_dictionary);
	push_dictionary(&arr, &size_of_dictionary);
	archiever();
	free_stack(&head);
	free(array);
	free(arr);
	return 0;
}
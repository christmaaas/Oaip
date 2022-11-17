#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"array.h"
#include<time.h>
int main() {
	int** array;
	int sizeofrows = 0, sizeofcols = 0, choice = 0, k = 0;
	printf("Enter size of rows of array: ");
	sizeofrows = array_size_input(sizeofrows);
	printf("\nEnter size of cols of array: ");
	sizeofcols = array_size_input(sizeofcols);
	array = memory(sizeofrows, sizeofcols);
	choice = choice_0_or_1(choice);
	completion_choice(choice, &array, sizeofrows, sizeofcols);
	print_array(&array, sizeofrows, sizeofcols);
	k = input_k(k);
	row_sort(&array, sizeofrows, sizeofcols, k);
	printf("\n");
	print_array(&array, sizeofrows, sizeofcols);
	free(array);
	return 0;
}
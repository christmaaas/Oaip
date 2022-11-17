#include"array.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
int main() {
	int* array = NULL;
	int arraysize = 0, choice = 0, start = 0, end = 0, start1 = 0, end1 = 0;
	printf("Enter a size of the array: ");
	arraysize = array_size_input(arraysize);
	memory_allocate(&array, arraysize);
	array_input_choice_and_output(array, arraysize, choice);
	int first = 0, last = arraysize - 1;
	Hoar_sort_and_time(array, arraysize, first, last, start, end);
	Bouble_sort_time(array, arraysize, start1, end1);
	free(array);
	return 0;
}
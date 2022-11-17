#include"array.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include<time.h>
void Hoar_sort(int* array, int first, int last) {
	if (first < last) {
		int left = first;
		int right = last;
		int pivot = array[(left + right) / 2];
		do {
			while (array[left] < pivot)
				left++;
			while (array[right] > pivot)
				right--;
			if (left <= right) {
				int buf = array[left];
				array[left] = array[right];
				array[right] = buf;
				left++;
				right--;
			}
		} while (left < right);
		Hoar_sort(array, first, right);
		Hoar_sort(array, left, last);
	}
}
void Bouble_sort(int* array, int arraysize) {
	int i, j, buf;
	for (i = 0; i < arraysize - 1; i++) {
		for (j = 0; j < arraysize - 1; j++) {
			if (array[j] > array[j + 1]) {
				buf = array[j];
				array[j] = array[j + 1];
				array[j + 1] = buf;
			}
		}
	}
}
int array_size_input(int arraysize) {
	while (scanf_s("%d", &arraysize) == 0 || arraysize < 1 || getchar() != '\n') {
		printf("\nYou need to write a right numbers\n");
		rewind(stdin);
	}
	return arraysize;
}
void memory_allocate(int** array, int arraysize) {
	*array = (int*)malloc(arraysize * sizeof(int));
}
void array_input_manually(int* array, int arraysize) {
	for (int i = 0; i < arraysize; i++) {
		printf("Enter a %d number of array: ", i + 1);
		while (scanf_s("%d", &array[i]) == 0 || array[i] < 1 || getchar() != '\n') {
			printf("\nYou need to write only a natural numbers\n");
			rewind(stdin);
		}
	}
}
void array_output(int* array, int arraysize) {
	for (int i = 0; i < arraysize; i++)
		printf("%d ", array[i]);
}
int choice_0_or_1(int choice) {
	printf("\n0 - manually input, 1 - random input: ");
	while (scanf_s("%d", &choice) == 0 || choice < 0 || choice > 1 || getchar() != '\n') {
		printf("\nYou need to write a correct numbers\n");
		rewind(stdin);
	}
	return choice;
}
void array_input_random(int* array, int arraysize) {
	srand(time(NULL));
	for (int i = 0; i < arraysize; i++)
		array[i] = rand() % 10;
}
void Hoar_sort_and_time(int* array, int arraysize, int first, int last, int start, int end) {
	start = clock();
	Hoar_sort(array, first, last);
	end = clock();
	printf("\nNew array: \n");
	array_output(array, arraysize);
	printf("\nHoar sort time: %d\n", end - start);
}
void Bouble_sort_time(int* array, int arraysize, int start1, int end1) {
	start1 = clock();
	Bouble_sort(array, arraysize);
	end1 = clock();
	printf("\nBouble sort time: %d\n", end1 - start1);
}
void array_input_choice_and_output(int* array, int arraysize, int choice) {
	choice = choice_0_or_1(choice);
	if (choice == 0) array_input_manually(array, arraysize);
	else array_input_random(array, arraysize);
	array_output(array, arraysize);
}
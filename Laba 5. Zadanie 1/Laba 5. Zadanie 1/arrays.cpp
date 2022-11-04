#include"arrays.h"
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
int array_size_input(int arraysize) {
	while (scanf_s("%d", &arraysize) == 0 || arraysize < 1 || getchar() != '\n') {
		printf("\nYou need to write a natural number\n");
		rewind(stdin);
	}
	return arraysize;
}
void create_array(int** array, int arraysize) {
	*array = (int*)malloc(arraysize * sizeof(int));
}
void delete_prime_number(int** array, int* arraysize) {
	for (int i = 0; i < *arraysize; i++) {
		if ((*array)[i] > 1) {
			for (int j = 2; j < (*array)[i]; j++) {
				if ((*array)[i] % j == 0) {
					int index = i;
					for (int k = index; k < *arraysize; k++) {
						(*array)[k] = (*array)[k + 1];
					}
					i--;
					*arraysize = *arraysize - 1;
					*array = (int*)realloc(*array, *arraysize * sizeof(int));
				}
			}
		}
	}
}
void array_otput(int* array, int arraysize) {
	for (int i = 0; i < arraysize; i++)
		printf("%d ", array[i]);
}
void array_input(int* array, int arraysize) {
	for (int i = 0; i < arraysize; i++) {
		printf("Enter a %d number of array: ", i + 1);
		while (scanf_s("%d", &array[i]) == 0 || array[i] < 1 || getchar() != '\n') {
			printf("\nYou need to write only a natural numbers\n");
			rewind(stdin);
		}
	
	}
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int randArray(int* array, int arraysize) {
	for (int i = 0; i < arraysize; i++)
	{
		array[i] = -100 + rand() % 200;
	}
	return 0;
}
int main() {
	int array1[100], array2[100], array3[200], choiñe = 0, array1size = 0, array2size = 0, array3size = 0, i = 0, j = 0;
	srand(time(NULL));
	printf("Enter the size of the first array: ");
	if (scanf_s("%d", &array1size) == 0 || array1size <= 1 || array1size > 100) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	printf("\nInput 0 to set the first array manually or Input 1 to set the first array with random numbers: ");
	if (scanf_s("%d", &choiñe) == 0 || choiñe < 0 || choiñe > 1) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	if (choiñe == 0) {
		for (int i = 0; i < array1size; i++) {
			printf("Array 1 Number %d: ", i + 1);
			if (scanf_s("%d", &array1[i]) == 0) {
				printf("\nYou need to write a correct numbers\n");
				return 0;
			}
		}
	}
	else if (choiñe == 1) {
		randArray(array1, array1size);
	}
	printf("Array 1: ");
	for (int i = 0; i < array1size; i++)
		printf("%d ", array1[i]);
	for (int i = 0; i < array1size; i++) {
		for (int j = 0; j < array1size - i - 1; j++) {
			if (array1[j] < array1[j + 1]) {
				int buf = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = buf;
			}
		}
	
	}
	printf("\nSort array 1: ");
	for (int i = 0; i < array1size; i++)
		printf("%d ", array1[i]);
	printf("\nEnter the size of the second array: ");
	if (scanf_s("%d", &array2size) == 0 || array2size <= 1 || array2size > 100) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	printf("\nInput 0 to set the second array manually or Input 1 to set the second array with random numbers: ");
	if (scanf_s("%d", &choiñe) == 0 || choiñe < 0 || choiñe > 1) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	if (choiñe == 0) {
		for (int i = 0; i < array2size; i++) {
			printf("Array 2 Number %d: ", i + 1);
			if (scanf_s("%d", &array2[i]) == 0) {
				printf("\nYou need to write a correct numbers\n");
				return 0;
			}
		}
	}
	else if (choiñe == 1) {
		randArray(array2, array2size);
	}
	printf("\nArray 2: ");
	for (int i = 0; i < array2size; i++)
		printf("%d ", array2[i]);
	for (int i = 0; i < array2size; i++) {
		for (int j = 0; j < array2size - i - 1; j++) {
			if (array2[j] < array2[j + 1]) {
				int buf = array2[j];
				array2[j] = array2[j + 1];
				array2[j + 1] = buf;
			}
		}
	}
	printf("\nSort array 2: ");
	for (int i = 0; i < array2size; i++)
		printf("%d ", array2[i]);
	array3size = array1size + array2size;
	for (; i < array1size && j < array2size;) {
		if (array1[i] < array2[j]) {
			array3[i + j] = array2[j];
			j++;
		}
		else {
			array3[i + j] = array1[i];
			i++;
		}
	}
	for (; i < array1size; i++) array3[i + j] = array1[i];
	for (; j < array2size; j++) array3[i + j] = array2[j];
	printf("\nArray 3: ");
	for (int i = 0; i < array3size; i++) printf("%d ", array3[i]);
	return 0;
}

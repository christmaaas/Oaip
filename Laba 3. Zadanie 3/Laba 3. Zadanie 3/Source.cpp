#include<stdio.h>
int main() {
	int array1[100], array2[100], array3[200], array1size = 0, array2size = 0, array3size = 0, i = 0, j = 0;
	printf("Enter the size of the first array: ");
	if (scanf_s("%d", &array1size) == 0 ||  array1size <= 1 || array1size > 100) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	printf("\nEnter the size of the second array: ");
	if (scanf_s("%d", &array2size) == 0 || array2size <= 1 || array2size > 100) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	array3size = array1size + array2size;
	for (int i = 0; i < array1size; i++) {
		printf("Array 1 Number %d: ", i + 1);
		if (scanf_s("%d", &array1[i]) == 0) {
			printf("\nYou need to write a correct numbers\n");
			return 0;
		}
	}
	for (int i = 0; i < array2size; i++) {
		printf("Array 2 Number %d: ", i + 1);
		if (scanf_s("%d", &array2[i]) == 0) {
			printf("\nYou need to write a correct numbers\n");
			return 0;
		}
	}
	for (int i = 0; i < array1size; i++) {
		for (int j = 0; j < array1size - i - 1; j++) {
			if (array1[j] < array1[j + 1]) {
				int buf = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = buf;
			}
		}
	}
	for (int i = 0; i < array2size; i++) {
		for (int j = 0; j < array2size - i - 1; j++) {
			if (array2[j] < array2[j + 1]) {
				int buf = array2[j];
				array2[j] = array2[j + 1];
				array2[j + 1] = buf;
			}
		}
	}
	for (;i < array1size && j < array2size;) {
		if (array1[i] < array2[j]) {
			array3[i + j] = array2[j];
			j++;
		}
		else {
			array3[i + j] = array1[i];
			i++;
		}
	}
	for (;i < array1size; i++) array3[i + j] = array1[i];
	for (;j < array2size; j++) array3[i + j] = array2[j];
	printf("Array 3: ");
	for (int i = 0; i < array3size; i++) printf("%d ", array3[i]);
	return 0;
}

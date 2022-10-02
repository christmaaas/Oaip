#include<stdio.h>
int main() {
	int array1[100], array1size = 0, array2[100], lastminindex = 0, firstmaxindex = 0, extraelements = 0;
	printf("Enter the size of the array: ");
	if (scanf_s("%d", &array1size) == 0 || array1size <= 1 || array1size > 100) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}	
	for (int i = 0; i < array1size; i++) {
		printf("Number %d: ", i + 1);
		if (scanf_s("%d", &array1[i]) == 0) {
			printf("\nYou need to write a correct numbers\n");
			return 0;
		}
	}
	int firstmax = array1[0], lastmin = array1[0];
	for (int i = 0; i < array1size; i++) {
		if (array1[i] <= lastmin) {
			lastmin = array1[i];
			lastminindex = i;
		}
		if (array1[i] > firstmax) {
			firstmax = array1[i];
			firstmaxindex = i;
		}
	}
	if (lastminindex > firstmaxindex) {
		for (int i = 0; i < firstmaxindex + 1; i++) array2[i] = array1[i];
		int array2elements = firstmaxindex + 1;
		for (int i = lastminindex; i < array1size; i++) {
			array2[array2elements] = array1[i];
			array2elements++;
		}
		for (int i = firstmaxindex + 1; i < lastminindex; i++) extraelements++;
	}
	if (lastminindex < firstmaxindex) {
		for (int i = 0; i < lastminindex + 1; i++) array2[i] = array1[i];
		int array2elements = lastminindex + 1;
		for (int i = firstmaxindex; i < array1size; i++) {
			array2[array2elements] = array1[i];
			array2elements++;
		}
		for (int i = lastminindex + 1; i < firstmaxindex; i++) extraelements++;
	}
	printf("\nArray with no elements between last min and first max: ");
	for (int i = 0; i < array1size - extraelements; i++) printf("% d", array2[i]);
	return 0;
}
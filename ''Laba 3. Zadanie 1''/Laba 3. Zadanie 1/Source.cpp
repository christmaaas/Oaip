#include <stdio.h>
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
	int array[100], choice = 0, arraysize = 0, sum1 = 0, sum2 = 0, firstnegative = 0, lastnegative = 0;
	srand(time(NULL));
	printf("Enter the size of the array: ");
	if (scanf_s("%d", &arraysize) == 0 || arraysize < 1 || arraysize > 100) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	printf("\nInput 0 to set the array manually or Input 1 to set the array with random numbers: ");
	if (scanf_s("%d", &choice) == 0 || choice < 0 || choice > 1) {
		printf("\nYou need to write a correct numbers\n");
		return 0;
	}
	if (choice == 0) {
		for (int i = 0; i < arraysize; i++) {
			printf("Number %d: ", i + 1);
			if (scanf_s("%d", &array[i]) == 0) {
				printf("\nYou need to write a crorrect numbers\n");
				return 0;
			}
			if (i % 2 != 0) sum1 += array[i];
		}
		printf("\nArray: ");
		for (int i = 0; i < arraysize; i++) {
			printf("%d ", array[i]);
		}		
	}
	else if (choice == 1) {
		randArray(array, arraysize);
		for (int i = 0; i < arraysize; i++) {
			if (i % 2 != 0) sum1 += array[i];
		}
		printf("\nArray: ");
		for (int i = 0; i < arraysize; i++) {
			printf("%d ", array[i]);
		}
	}
	for (firstnegative = 0; firstnegative < arraysize; firstnegative++) {
		if (array[firstnegative] < 0) break;
	}
	for (lastnegative = arraysize - 1; lastnegative > firstnegative; lastnegative--) {
		if (array[lastnegative] < 0) break;
	}
	for (int i = firstnegative + 1; i < lastnegative; i++) {
		sum2 += array[i];
	}
	printf("\nSum of odd elements: %d\n", sum1);
	printf("\nSum of elements between first negative and last negative: %d\n", sum2);
	return 0;
}
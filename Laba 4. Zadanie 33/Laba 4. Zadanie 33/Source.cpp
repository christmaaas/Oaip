#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int randArray(int* array, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			array[i * 100 + j] = -10 + rand() % 30;
		}
	}
	return 0;
}
int zapolnenie(int* array, float arraysizerow, float arraysizecol) {
	for (int row = 0; row < arraysizerow; row++) {
		for (int col = 0; col < arraysizecol; col++) {
			printf("Number of %d row and %d col: ", row + 1, col + 1);
			while (scanf_s("%d", &array[row * 100 + col]) == 0 || getchar() != '\n') {
				printf("\nYou need to write correct numbers\n");
				rewind(stdin);
			}
		}
	}
	return 0;
}
int vivod(int* array, int arraysizerow, int arraysizecol) {
	for (int row = 0; row < arraysizerow; row++) {
		for (int col = 0; col < arraysizecol; col++) {
			printf("%d ", array[row * 100 + col]);
		}
		printf("\n");
	}
	return 0;
}
int arraysize() {
	int rowcol;
	while (scanf_s("%d", &rowcol) == 0 || rowcol < 1 || rowcol > 100 || getchar() != '\n') {
		printf("\nYou need to write correct numbers\n");
		rewind(stdin);
	}
	return rowcol;
}
int choice() {
	int choice;
	while (scanf_s("%d", &choice) == 0 || choice < 0 || choice > 1 || getchar() != '\n') {
		printf("\nYou need to write a correct numbers\n");
		rewind(stdin);
	}
	return choice;
}
int main() {
	int array[100][100], choice1, choice2, max = 0;
	float arraysizerow = 0, arraysizecol = 0;
	srand(time(NULL));
	printf("Input 0 to set the array manually or Input 1 to set the array with random numbers: ");
	choice1 = choice();
	printf("You need to write the same sizes because of square matrix");
	printf("\nEnter the number of rows: ");
	arraysizerow = arraysize();
	printf("\nEnter the number of cols: ");
	arraysizecol = arraysize();
	while (arraysizerow != arraysizecol) {
		printf("\nYou need to write the same sizes\n");
		printf("\nEnter the number of rows: ");
		arraysizerow = arraysize();
		printf("\nEnter the number of cols: ");
		arraysizecol = arraysize();
	}
	printf("Round up an odd array size? 0 - yes 1 - no ");
	choice2 = choice();
	if (choice1 == 0) zapolnenie(&array[0][0], arraysizerow, arraysizecol);
	else if (choice1 == 1) randArray(&array[0][0], arraysizerow, arraysizecol);
	vivod(&array[0][0], arraysizerow, arraysizecol);
	if (choice2 == 0) {
		int arraysizerow1 = (int)(arraysizerow / 2 + 0.5);
		int arraysizecol1 = (int)(arraysizecol / 2 + 0.5);
		for (int row = 0; row < arraysizerow1; row++) {
			for (int col = 0; col < arraysizecol1; col++) {
				if (array[row][col] > max) {
					max = array[row][col];
				}
			}
		}
		printf("\nThe max element of the first area is: %d\n", max);
	}
	if (choice2 == 1) {
		int arraysizerow1 = (int)(arraysizerow / 2);
		int arraysizecol1 = (int)(arraysizecol / 2);
		for (int row = 0; row < arraysizerow1; row++) {
			for (int col = 0; col < arraysizecol1; col++) {
				if (array[row][col] > max) {
					max = array[row][col];
				}
			}
		}
		printf("\nThe max element of the first area is: %d\n", max);
	}
	return 0;
}
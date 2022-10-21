#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int randArray(int* array, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			array[i * 100 + j] = -8 + rand() % 20;
		}
	}
	return 0;
}
int main() {
	int array[100][100], choiñe, arraysizecol = 0, arraysizerow = 0;
	srand(time(NULL));
	printf("Input 0 to set the array manually or Input 1 to set the array with random numbers: ");
	while (scanf_s("%d", &choiñe) == 0 || choiñe < 0 || choiñe > 1 || getchar() != '\n') {
		printf("\nYou need to write a correct numbers\n");
		rewind(stdin);
	}
	printf("Enter the number of rows: ");
	while (scanf_s("%d", &arraysizerow) == 0 || arraysizerow <= 1 || arraysizerow > 100 || getchar() != '\n') {
		printf("\nYou need to write correct numbers\n");
		rewind(stdin);
	}
	printf("\nEnter the number of cols: ");
	while (scanf_s("%d", &arraysizecol) == 0 || arraysizecol <= 1 || arraysizecol > 100 || getchar() != '\n') {
		printf("\nYou need to write correct numbers\n");
		rewind(stdin);
	}
	if (choiñe == 0) {
		for (int row = 0; row < arraysizerow; row++) {
			for (int col = 0; col < arraysizecol; col++) {
				printf("Number of %d row and %d col: ", row + 1, col + 1);
				while (scanf_s("%d", &array[row][col]) == 0 || getchar() != '\n') {
					printf("\nYou need to write correct numbers\n");
					rewind(stdin);
				}
			}
		}
	}
	else if (choiñe == 1) randArray(&array[0][0], arraysizerow, arraysizecol);
	for (int row = 0; row < arraysizerow; row++) {
		for (int col = 0; col < arraysizecol; col++) {
			printf("%d ", array[row][col]);
		}
		printf("\n");
	}
	int column = -1;
	for (int col = 0; col < arraysizecol; col++) {
		for (int row = 0; row < arraysizerow; row++) {
		if (array[row][col] < 0) break;
			else if (row == arraysizerow - 1) column = col;
		}
		if (column != -1) break;
	}
	if (column == -1) {
		printf("\nThere is no column with positive elements in this matrix\n");
		return 0;
	}
	else printf("\nFirst column with positive elements: %d\n", column + 1);
	if (column == 0) {
		printf("\nSince the column with positive numbers is the first the previous one cannot be changed\n");
		return 0;
	}
	for (int col = column - 1; col < column; col++) {
		for (int row = 0; row < arraysizerow; row++) {
			array[row][col] = array[row][col] * (-1);
		}
	}
	printf("\nNew matrix:\n");
	for (int row = 0; row < arraysizerow; row++) {
		for (int col = 0; col < arraysizecol; col++) {
			printf("%d ", array[row][col]);
		}
		printf("\n");
	}
	return 0;
}
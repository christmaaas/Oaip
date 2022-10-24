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
int choice() {
	int choice;
	while (scanf_s("%d", &choice) == 0 || choice < 0 || choice > 1 || getchar() != '\n') {
		printf("\nYou need to write a correct numbers\n");
		rewind(stdin);
	}
	return choice;
}
int arraysize() {
	int rowcol;
	while (scanf_s("%d", &rowcol) == 0 || rowcol < 1 || rowcol > 100 || getchar() != '\n') {
		printf("\nYou need to write correct numbers\n");
		rewind(stdin);
	}
	return rowcol;
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
int main() {
	int array[100][100], choiñe1, arraysizecol = 0, arraysizerow = 0;
	srand(time(NULL));
	printf("Input 0 to set the array manually or Input 1 to set the array with random numbers: ");
	choiñe1 = choice();
	printf("Enter the number of rows: ");
	arraysizerow = arraysize();
	printf("\nEnter the number of cols: ");
	arraysizecol = arraysize();
	if (choiñe1 == 0) zapolnenie(&array[0][0], arraysizerow, arraysizecol);
	else randArray(&array[0][0], arraysizerow, arraysizecol);
	vivod(&array[0][0], arraysizerow, arraysizecol);
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
	vivod(&array[0][0], arraysizerow, arraysizecol);
	return 0;
}
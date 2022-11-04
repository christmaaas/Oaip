#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"arrays.h"
#include<time.h>
int main() {
	int** array = 0;
	int rowmax_and_colindex = 0, colminindex = 0;
	int sizeofrows = 0, sizeofcols = 0, choice = 0, rowmax = 0, colmin = 0, rowmax1 = 0, colmin1 = 0;
	printf("Enter size of rows of array: ");
	sizeofrows = array_size_input(sizeofrows);
	printf("\nEnter size of cols of array: ");
	sizeofcols = array_size_input(sizeofcols);
	array = memory(sizeofrows, sizeofcols);
	choice = choice_0_or_1(choice);
	if (choice == 0) array_input_manually(array, sizeofrows, sizeofcols);
	else array_input_random(array, sizeofrows, sizeofcols);
	print_array(array, sizeofrows, sizeofcols);
	for (int i = 0; i < sizeofrows; i++) {
		rowmax = array[i][0];
		for (int j = 0; j < sizeofcols; j++) {
			if (rowmax < array[i][j]) {
				rowmax = array[i][j];
				rowmax_and_colindex = j;
			}
		}
		colmin = array[0][rowmax_and_colindex];
		for (int k = 0; k < sizeofrows; k++) {
			if (colmin > array[k][rowmax_and_colindex]) {
				colmin = array[k][rowmax_and_colindex];
				colminindex = k;
			}
		}
		if (rowmax == colmin) {
			sizeofrows--;
			for (int n = colminindex; n < sizeofrows; n++) {
				for (int j = 0; j < sizeofcols; j++)
					array[n][j] = array[n + 1][j];
			}
			array = (int**)realloc(array, sizeofrows * sizeof(int*));
			printf("\nNew array: \n");
			print_array(array, sizeofrows, sizeofcols);
			break;
		}
	}
	if (rowmax != colmin) printf("\nSedlovoya tochka wasn't find\n");
	free(array);
	return 0;
}
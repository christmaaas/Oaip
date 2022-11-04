#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int delete_after_element(int element_delete_after) {
	printf("Delete elements of a row greater than this number: ");
	while (scanf_s("%d", &element_delete_after) == 0 || element_delete_after < 1 || getchar() != '\n') {
		printf("\nYou need to write only right numbers\n");
		rewind(stdin);
	}
	return  element_delete_after;
}
void print_array(int** array, int sizeofrows) {
    for (int i = 0; i < sizeofrows; i++) {
        int j = 0;
        while (array[i][j] != 0) {
            printf("%4d ", array[i][j]);
            j++;
        }
        printf("\n");
    }
}
int array_size_input(int arraysize) {
    while (scanf_s("%d", &arraysize) == 0 || arraysize < 1 || getchar() != '\n') {
        printf("\nYou need to write a right numbers\n");
        rewind(stdin);
    }
    return arraysize;
}
void allocate_memory_one_element(int** array, int sizeofrows) {
    for (int i = 0; i < sizeofrows; i++) {
        array[i] = (int*)calloc(1, sizeof(int));
    }
}
void input_array(int** array, int sizeofrows) {
    for (int i = 0; i < sizeofrows; i++) {
        int j = 0;
        while (scanf_s("%d", &array[i][j]) != 0 && array[i][j] != 0) {
            printf("Input element array[%d][%d]: ", i, j);
            array[i] = (int*)realloc(array[i], (j + 2) * sizeof(int));
            j++;
        }
    }
}
void delete_element(int** array, int sizeofrows, int element_delete_after) {
    for (int i = 0; i < sizeofrows; i++) {
        int col = 0;
        int j = 0;
        while (array[i][j] != 0) {
            col++;
            j++;
        }
        col++;
        for (int k = 0; k < col; k++) {
            if (array[i][k] > element_delete_after) {
                col--;
                for (int g = k; g < col; g++) {
                    array[i][g] = array[i][g + 1];
                }
                array[i] = (int*)realloc(array[i], col * sizeof(int));
                k--;
            }
        }
    }
}
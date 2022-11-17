#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"array.h"
#include<time.h>
int** memory(int sizeofrows, int sizeofcols) {
    int** mas;
    mas = (int**)calloc(sizeofrows, sizeof(int*));
    for (int i = 0; i < sizeofrows; i++)
    {
        mas[i] = (int*)calloc(sizeofcols, sizeof(int));
    }
    return mas;
}
void array_input_manually(int*** mas, int sizeofrows, int sizeofcols) {
    for (int i = 0; i < sizeofrows; i++) {
        for (int j = 0; j < sizeofcols; j++) {
            printf("Enter element mas[%d][%d]: ", i, j);
            while (scanf_s("%d", &(*mas)[i][j]) == 0 || getchar() != '\n') {
                printf("\nYou need to write a right numbers\n");
                rewind(stdin);
            }
        }
    }
}
void array_input_random(int*** mas, int sizeofrows, int sizeofcols) {
    srand(time(NULL));
    for (int i = 0; i < sizeofrows; i++) {
        for (int j = 0; j < sizeofcols; j++)
            (*mas)[i][j] = -10 + rand() % 20;
    }
}
int choice_0_or_1(int choice) {
    printf("\n0 - manually input, 1 - random input: ");
    while (scanf_s("%d", &choice) == 0 || choice < 0 || choice > 1 || getchar() != '\n') {
        printf("\nYou need to write a correct numbers\n");
        rewind(stdin);
    }
    return choice;
}
void print_array(int*** array, int sizeofrows, int sizeofcols) {
    for (int i = 0; i < sizeofrows; i++) {
        for (int j = 0; j < sizeofcols; j++) {
            printf("%4d ", (*array)[i][j]);
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
void completion_choice(int choice, int*** array, int sizeofrows, int sizeofcols) {
    if (choice == 0) array_input_manually(array, sizeofrows, sizeofcols);
    else array_input_random(array, sizeofrows, sizeofcols);
}
int row_sum(int*** array, int row, int sizeofcols) {
    int sum = 0;
    for (int i = 0; i < sizeofcols; i++) {
        if ((*array)[row][i] > 0)
            sum += (*array)[row][i];
    }
    return sum;
}
void row_sort(int*** array, int sizeofrows, int sizeofcols, int k) {
    for (int i = k - 1; i < sizeofrows; i += k) {
        for (int j = i + k; j < sizeofrows; j += k) {
            if (row_sum(array, i, sizeofcols) < row_sum(array, j, sizeofcols)) {
                for (k = 0; k < sizeofcols; k++) {
                    int buf = (*array)[i][k];
                    (*array)[i][k] = (*array)[j][k];
                    (*array)[j][k] = buf;
                }
            }
        }
    }
}
int input_k(int k) {
    printf("\nEnter a number k (you can't enter 0 and numbers less then zero): ");
    while (scanf_s("%d", &k) == 0 || k <= 0 || getchar() != '\n') {
        printf("\nYou need to write a correct numbers\n");
        rewind(stdin);
    }
    return k;
}
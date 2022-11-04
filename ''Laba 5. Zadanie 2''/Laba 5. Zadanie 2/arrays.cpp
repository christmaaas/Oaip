#include"arrays.h"
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
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
void array_input_random(int** mas, int sizeofrows, int sizeofcols) {
    srand(time(NULL));
    for (int i = 0; i < sizeofrows; i++) {
        for (int j = 0; j < sizeofcols; j++)
            mas[i][j] = rand() % 30;
    }
}
void array_input_manually(int** mas, int sizeofrows, int sizeofcols) {
    for (int i = 0; i < sizeofrows; i++) {
        for (int j = 0; j < sizeofcols; j++) {
            printf("Enter element mas[%d][%d]: ", i, j);
            while (scanf_s("%d", &mas[i][j]) == 0 || getchar() != '\n') {
                printf("\nYou need to write a right numbers\n");
                rewind(stdin);
            }
        }
    }
}
void print_array(int** array, int sizeofrows, int sizeofcols) {
    for (int i = 0; i < sizeofrows; i++) {
        for (int j = 0; j < sizeofcols; j++) {
            printf("%4d ", array[i][j]);
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
int choice_0_or_1(int choice) {
    printf("\n0 - manually input, 1 - random input: ");
    while (scanf_s("%d", &choice) == 0 || choice < 0 || choice > 1 || getchar() != '\n') {
        printf("\nYou need to write a correct numbers\n");
        rewind(stdin);
    }
    return choice;
}

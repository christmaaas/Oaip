#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include"array.h"
int main() {
    int** array = 0;
    int sizeofrows = 0, element_delete_after = 0;
    printf("Enter a size of the rows: ");
    sizeofrows = array_size_input(sizeofrows);
    element_delete_after = delete_after_element(element_delete_after);
    array = (int**)calloc(sizeofrows, sizeof(int*));
    allocate_memory_one_element(array, sizeofrows);
    input_array(array, sizeofrows);
    print_array(array, sizeofrows);
    delete_element(array, sizeofrows, element_delete_after);
    printf("\nNew Array: \n");
    print_array(array, sizeofrows);
    free(array);
    return 0;
}

#pragma once
int** memory(int sizeofrows, int sizeofcols);
void array_input_manually(int*** mas, int sizeofrows, int sizeofcols);
void array_input_random(int*** mas, int sizeofrows, int sizeofcols);
int choice_0_or_1(int choice);
void print_array(int*** array, int sizeofrows, int sizeofcols);
int array_size_input(int arraysize);
void completion_choice(int choice, int*** array, int sizeofrows, int sizeofcols);
void row_sort(int*** array, int sizeofrows, int sizeofcols, int k);
int row_sum(int*** array, int row, int sizeofcols);
int input_k(int k);
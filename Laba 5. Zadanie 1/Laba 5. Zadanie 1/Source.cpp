#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"arrays.h"
int main() {
	int* array = NULL;
	int arraysize = 0;
	printf("Enter a size of array (You need to write only a natural numbers): ");
	arraysize = array_size_input(arraysize);
	create_array(&array, arraysize);
	array_input(array, arraysize);
	array_otput(array, arraysize);
	printf("\n");
	delete_prime_number(&array, &arraysize);
	printf("New array: ");
	array_otput(array, arraysize);
	printf("\n");
	free(array);
	return 0;
}
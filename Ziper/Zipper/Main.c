#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Func.h"
#include"Struct.h"

int main() {
	words* array = NULL;
	zamena* arr = NULL;
	int size_of_words = 0;
	int size_of_zamena = 0;
	wordiki(&array, &arr, &size_of_words, &size_of_zamena);
	push_slovar(&arr);
	archiever();
	return 0;
}
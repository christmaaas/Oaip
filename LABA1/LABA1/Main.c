#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Func.h"
#include"Struct.h"


int main() {
	Laptop* array = NULL;
	int size = 0;
	menu(&array, &size);
	free(array);
	return 0;
}
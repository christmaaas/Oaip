#include<stdio.h>
#include<stdlib.h>
#include"Func.h"

int main(int argc, char** argv) {
	FILE* file;

	check(argc);
	create_file(&file, argc, argv);
	print_file(file, argv);
	swap(file, argc, argv);
	printf("\nFile after swap: \n");
	print_file(file, argv);
	return 0;
}
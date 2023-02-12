#include<stdio.h>
#include<stdlib.h>
#include"Func.h"

int main(int argc, char** argv) {
	
	FILE* file;

	check(argc);
	create_file(&file, argc, argv);
	print_file(file, argv);
	calculate_average(file, argv);
		
		
	return 0;
}
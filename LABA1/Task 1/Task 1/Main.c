#include<stdio.h>
#include"Func.h"

int main(int argc, char** argv) {
	FILE* file;
	
	check(argc);
	create_file(&file, argc, argv);
	print_file(file, argv);


	return 0;
}
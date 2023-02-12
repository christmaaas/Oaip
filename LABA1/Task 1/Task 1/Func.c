#include<stdio.h>
#include"Func.h"

void check(int argc) {
	if (argc <= 2) printf("\nYou havent enough arguments\n");
	return;
}

void create_file(FILE** file, int argc, char** argv) {

	fopen_s(file, argv[1], "w");
	
	for (int i = 2; i < argc; i++) {
		int num = atoi(argv[i]);
		fprintf(*file, "%d ", num);
	}

	fclose(*file);
}

void print_file(FILE* file, char** argv) {
	int num = 0;
	fopen_s(file, argv[1], "r");
	
	while (!feof(file)) {
		fscanf_s(file, "%d\n", &num);
		printf("%d\n", num);
	}
	
	fclose(file);
}

#include<stdio.h>
#include<stdlib.h>
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

void swap(FILE* file, int argc, char** argv) {
	int num1 = 0, num2 = 0;
	fopen_s(&file, argv[1], "r");
	fscanf_s(file, "%d", &num1);
	while (!feof(file)) {
		fscanf_s(file, "%d", &num2);
	}
	fclose(file);
	fopen_s(&file, argv[1], "w");
	fprintf(file, "%d ", num2);
	for (int i = 3; i < argc-1; i++) {
		int num = atoi(argv[i]);
		fprintf(file, "%d ", num);
	}
	fprintf(file, "%d", num1);
	fclose(file);
}
#include"functions.h"

char* input_file_name() {
	printf("Input file name (like \"Sea.bmp\"): ");
	char* string = (char*)calloc(256, sizeof(char));
	gets_s(string, 255);
	int size = strlen(string);
	string = (char*)realloc(string, size + 1);
	return string;
}

void menu_info(char* file_name) {
	printf("\n------------- MENU -------------\n");
	printf("1 - Main info about \"%s\"\n", file_name);
	printf("2 - Convert \"%s\" to Black-While\n", file_name);
	printf("3 - Convert \"%s\" to Negative\n", file_name);
	printf("4 - Gamma-correction of \"%s\"\n", file_name);
	printf("5 - Median-filtration of \"%s\"\n", file_name);
	printf("6 - Pick another BMP-File\n");
	printf("7 - Exit\n");
	printf("--------------------------------\n");
	printf("Your choice: ");
}

double gamma_degree_check() {
	double degree = 0;
	while (scanf_s("%lf", &degree) == 0 || degree < 0.0 || getchar() != '\n') {
		printf("\nWrong degree input! Try again: ");
		rewind(stdin);
	}
	return degree;
}

int filter_check() {
	int filter = 0;
	while (scanf_s("%d", &filter) == 0 || filter < 0 || getchar() != '\n') {
		printf("\nWrong filter input! Try again: ");
		rewind(stdin);
	}
	return filter;
}

int choice_menu() {
	int choice = 0;
	while (scanf_s("%d", &choice) == 0 || choice <= 0 || choice > 7 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 7: ");
		rewind(stdin);
	}
	return choice;
}

void change_bmp_file(char** file_name) {
	printf("\n");
	(*file_name) = input_file_name();
}

void menu(char** file_name) {
	menu_info((*file_name));
	int choice = choice_menu();
	switch (choice) {
	case 1:
		print_bmp((*file_name));
		menu(file_name);
		break;
	case 2:
		bw_conversion((*file_name));
		menu(file_name);
		break;
	case 3:
		negative_conversion((*file_name));
		menu(file_name);
		break;
	case 4:
		gamma_correction((*file_name));
		menu(file_name);
		break;
	case 5:
		median_filtration((*file_name));
		menu(file_name);
		break;
	case 6:
		change_bmp_file(file_name);
		menu(file_name);
		break;
	case 7:
		exit(NORMAL_EXIT);
	default:
		exit(ERROR_EXIT);
	}
}

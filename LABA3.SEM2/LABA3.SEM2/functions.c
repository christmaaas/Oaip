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
	printf("\n----- MENU -----\n");
	printf("1 - Convert %s to Black-While\n", file_name);
	printf("2 - Convert %s to Negative\n", file_name);
	printf("3 - Pick another BMP-File\n");
	printf("4 - Exit\n");
	printf("----------------\n");
	printf("Your choice: ");
}

int choice_menu() {
	int choice = 0;
	while (scanf_s("%d", &choice) == 0 || choice <= 0 || choice > 4 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 4: ");
		rewind(stdin);
	}
	return choice;
}

void change_bmp_file(char** file_name) {
	(*file_name) = input_file_name();
}

void menu(char** file_name) {
	menu_info((*file_name));
	int choice = choice_menu();
	switch (choice) {
	case 1:
		bw_conversion((*file_name));
		menu(file_name);
		break;
	case 2:
		negative_conversion((*file_name));
		menu(file_name);
		break;
	case 3:
		change_bmp_file(file_name);
		menu(file_name);
		break;
	case 4:
		exit(NORMAL_EXIT);
	default:
		exit(ERROR_EXIT);
	}
}
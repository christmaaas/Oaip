
#include"Func.h"
#include"Morse.h"

char* input_str() {
	char* string = (char*)calloc(1024, sizeof(char));
	gets_s(string, 1024);
	int size = strlen(string);
	string = (char*)realloc(string, size + 1);
	return string;
}

int choice_menu() {
	int choice = 0;
	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 5 || getchar() != '\n') {
		printf("\nYou need to pick 1 - 2: ");
		rewind(stdin);
	}
	return choice;
}

void menu_info() {
	printf("\n----- MENU -----\n");
	printf("1 - Encrypt string\n");
	printf("2 - Decrypt string\n");
	printf("3 - Encrypt file\n");
	printf("4 - Decrypt file\n");
	printf("5 - Exit\n");
	printf("----------------\n");
	printf("Your choice: ");
}

void menu() {
	int choice = 0;
	menu_info();
	choice = choice_menu();
	switch (choice) {
	case 1:
		morse_encrypt(Table);
		menu();
		break;
	case 2:
		morse_decrypt(Table);
		menu();
		break;
	case 3:
		morse_encrypt_file(Table);
		menu();
		break;
	case 4:
		morse_decrypt_file(Table);
		menu();
		break;
	case 5:
		exit(2);
	default:
		exit(0);
	}
}
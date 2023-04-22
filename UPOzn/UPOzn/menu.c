
#include "menu.h"
#include "morse.h"

int choice_menu() {
	int choice = 0;

	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 5 || getchar() != '\n') {
		printf("\nWRONG INPUT: You need to pick 1 - 5: ");
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

void menu(FILE* logbook) {
	int choice = 0;

	menu_info();

	choice = choice_menu();

	switch (choice) {
	case 1:
		morse_encrypt(alphabet);
		menu(logbook);
		break;
	case 2:
		morse_decrypt(alphabet);
		menu(logbook);
		break;
	case 3:
		morse_encrypt_file(alphabet);
		menu(logbook);
		break;
	case 4:
		morse_decrypt_file(alphabet);
		menu(logbook);
		break;
	case 5:
		exit(NORMAL_EXIT);
	default:
		exit(PROGRAMM_ERROR);
	}
}